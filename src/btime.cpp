#include "btime.h"

//This class keep date/time values and operates a little of them
//Most notably the class will create a string for the pathname.

BTime::BTime()
{
	year = 0;
	month = 0;
	day = 0;
	hour = 0;
	minute = 0;
}

BTime::BTime(int y, int mo, int d, int h, int mi)
{
	year = y;
	month = mo;
	day = d;
	hour = h;
	minute = mi;
}

//Normalize values somewhat
void BTime::removeExcess()
{
	if(year > 9999)
		year = 9999;
	else if(year < 0)
		year = 0;

	if(month > 12)
		month = 12;
	else if(month < 1)
		month = 1;

	if(day > 31)
		day = 31;
	else if(day < 1)
		day = 1;

	if(hour > 23)
		hour = 23;
	else if(hour < 0)
		hour = 0;

	if(minute > 59)
		minute = 59;
	else if(minute < 0)
		minute = 0;
}

//Create a string from the values in the class
std::string BTime::toString()
{
	char res[16];

	addCharArrays(res, year, 5, false, '-');
	addCharArrays(res, month, 3, true, '-');
	addCharArrays(res, day, 3, true, '-');
	addCharArrays(res, hour, 3, true, '_');
	addCharArrays(res, minute, 3, true, ':');

	printf("res: %s\n", res);
}

//Add the variable to the res array along with extra zeros and delimiter characters.
void BTime::addCharArrays(char *res, int var, int len, bool insertDelimiter, char delimiter)
{
	char buff[len];
	snprintf(buff, len, "%d", var);
	insertZeros(buff, len);
	if(insertDelimiter)
		insertChar(res, delimiter);
	strcpy(&res[strlen(res)], buff);
}

//Insert extra zeros in front of the value if it's not long enough.
//Ex. 2014 -> 2014 but 56 -> 0056
void BTime::insertZeros(char *buff, int len)
{
	int buffLen = strlen(buff);
	while(buffLen < len - 1)
	{
		for(int i = buffLen; i > -1; i--)
		{
			if(i > 0)
				buff[i] = buff[i-1];
			else
				buff[i] = '0';
		}
		buffLen = strlen(buff);
	}
	buff[len-1] = '\0';
}

//Insert a character at the end of the array and move the null terminator accordingly.
void BTime::insertChar(char *buff, char ch)
{
	int len = strlen(buff);
	buff[len] = ch;
	buff[len+1] = '\0';
}
