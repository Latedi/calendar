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
	Event();
	Event(BTime time, std::string data, std::string title);
	Event(std::string path);
	Event(const Event &ev);
	std::string getTitle() const;
	std::string getData() const;
	std::string getTimeString();
	BTime getTime() const;
	std::string constructPath();
	void setTitle(std::string title);
	void setData(std::string data);
	void setTime(BTime time);
	void printEvent();
};

#endif /* EVENT_H */
