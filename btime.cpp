#include "btime.h"

//This class keep date/time values and operates a little of them
//Most notably the class will create a string for the pathname.

BTime::BTime()
{
	year = 0;
	month = 1;
	day = 1;
	hour = 0;
	minute = 0;
}

BTime::BTime(const BTime &time)
{
	year = time.getYear();
	month = time.getMonth();
	day = time.getDay();
	hour = time.getHour();
	minute = time.getMinute();
}

BTime::BTime(int year, int month, int day, int hour, int minute)
{
	this->year = year;
	this->month = month;
	this->day = day;
	this->hour = hour;
	this->minute = minute;
	normalize();
}

//Create object using directory name created by the Event class
BTime::BTime(std::string str)
{
	if(str.length() == 16 && str[4] == '-' && str[7] == '-' && str[10] == '_' && str[13] == ':')
	{
		year = atoi(str.substr(0, 4).c_str());
		month = atoi(str.substr(5, 7).c_str());
		day = atoi(str.substr(8, 10).c_str());
		hour = atoi(str.substr(11, 13).c_str());
		minute = atoi(str.substr(14, 16).c_str());
		normalize();
	}
	else
	{
		printf("Could not create BTime object from the following data: %s\n", str.c_str());
		BTime();
	}
}

//Normalize values
void BTime::normalize()
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

//Add extra zeros and delimiter characters to the values.
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

int BTime::getYear() const
{
	return year;
}

int BTime::getMonth() const
{
	return month;
}

int BTime::getDay() const
{
	return day;
}

int BTime::getHour() const
{
	return hour;
}

int BTime::getMinute() const
{
	return minute;
}
