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

	void insertZeros(char *buff, int len);
	void insertChar(char *buff, char ch);
	void removeExcess();
	void addCharArrays(char *res, int var, int len, bool insertDelimiter, char delimiter);
public:
	BTime();
	BTime(int year, int month, int day, int hour, int minute);
	int toString(char* buff, int size);
};

#endif /* BTIME_H */
