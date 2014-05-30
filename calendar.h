#ifndef CALENDAR_H
#define CALENDAR_H

#define DEFAULT_BUFF_LENGTH 2048

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <list>
#include <map>
#include <stdlib.h>
#include <dirent.h>

#include "event.h"
#include "fileHandler.h"
#include "btime.h"

class Calendar
{
private:
	std::string root;
	std::list<Event> eventList;
	FileHandler fileHandler;
public:
	Calendar();
	Calendar(std::string str);
	std::map<int, Event> showAll();
	BTime createBTime();
	int editEvent(Event oldEvent, Event newEvent);
	int getAllEvents();
	int createEvent();
	int deleteEvent(Event ev);
	std::string getRoot();
};

#endif /* CALENDAR_H */
