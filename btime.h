#ifndef BTIME_H
#define BTIME_H

#include <string>
#include <cstring>
#include <stdio.h>
#include <sstream>

class BTime
{
private:
	int year;
	int month;
	int day;
	int hour;
	int minute;

	std::string insertZeros(std::string str, int len);
	void removeExcess();
	std::string formatString(int var, int len, bool insertDelimiter, char delimiter);
public:
	BTime();
	BTime(int year, int month, int day, int hour, int minute);
	std::string toString();
};

#endif /* BTIME_H */
