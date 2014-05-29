#ifndef BTIME_H
#define BTIME_H

#include <string>
#include <sstream>
#include <cstdlib>
#include <stdio.h>

class BTime
{
private:
	int year;
	int month;
	int day;
	int hour;
	int minute;

	std::string insertZeros(std::string str, int len);
	void normalize();
	std::string formatString(int var, int len, bool insertDelimiter, char delimiter);
public:
	BTime();
	BTime(int year, int month, int day, int hour, int minute);
	BTime(std::string str);
	BTime(const BTime &time);
	std::string toString();
	int getYear() const;
	int getMonth() const;
	int getDay() const;
	int getHour() const;
	int getMinute() const;
};

#endif /* BTIME_H */
