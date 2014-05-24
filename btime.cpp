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

BTime::BTime(int year, int month, int day, int hour, int minute)
{
	this->year = year;
	this->month = month;
	this->day = day;
	this->hour = hour;
	this->minute = minute;
	removeExcess();
}

//Normalize values
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
	std::string str;

	str = formatString(year, 5, false, '-');
	str += formatString(month, 3, true, '-');
	str += formatString(day, 3, true, '-');
	str += formatString(hour, 3, true, '_');
	str += formatString(minute, 3, true, ':');

	return str;
}

//Add the variable to the res array along with extra zeros and delimiter characters.
std::string BTime::formatString(int var, int len, bool insertDelimiter, char delimiter)
{
	std::ostringstream os;
	os << var;
	std::string str = os.str();
	str = insertZeros(str, len);
	if(insertDelimiter)
		str = delimiter + str;
	return str;
}

//Insert extra zeros in front of the value if it's not long enough.
//Ex. 2014 -> 2014 but 56 -> 0056
std::string BTime::insertZeros(std::string str, int len)
{
	while(str.length() < len - 1)
	{
		str = "0" + str;
	}
	return str;
}
