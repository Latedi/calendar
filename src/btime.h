#ifndef BTIME_H
#define BTIME_H

#include <string>
#include <cstring>
#include <stdio.h>

class BTime
{
private:
	int year;
	int month;
	int day;
	int hour;
	int minute;
public:
	BTime();
	BTime(int year, int month, int day, int hour, int minute);
	void removeExcess();
	std::string toString();
	void insertZeros(char *buff, int len);
	void insertChar(char *buff, char ch);
	void addCharArrays(char *res, int var, int len, bool insertDelimiter, char delimiter);
};

#endif /* BTIME_H */
