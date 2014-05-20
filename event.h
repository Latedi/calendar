#ifndef EVENT_H
#define EVENT_H

#include "btime.h"

class Event
{
private:
	BTime time;
	char* title;
	char* data;
public:
	Event(BTime time, char* data, char* title);
	Event(char* path);
	void printEvent();
};

#endif /* EVENT_H */
