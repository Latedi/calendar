#ifndef EVENT_H
#define EVENT_H

#include <string>
#include <fstream>
#include <cstring>

#include "btime.h"

class Event
{
private:
	BTime time;
	std::string title;
	std::string data;
public:
	Event(BTime time, std::string data, std::string title);
	Event(std::string path);
	std::string getTimeString();
	void printEvent();
};

#endif /* EVENT_H */
