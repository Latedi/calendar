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
	std::string toString();
};

#endif /* BTIME_H */
