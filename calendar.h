#ifndef CALENDAR_H
#define CALENDAR_H

#define DEFAULT_BUFF_LENGTH 2014

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <list>
#include <stdlib.h>
#include <dirent.h>

#include "event.h"
#include "fileHandler.h"

class Calendar
{
private:
	std::string root;
	std::list<Event> eventList;
	FileHandler fileHandler;
public:
	Calendar();
	int getAllEvents();
	int createEvent();
	int deleteEvent();
	std::string getRoot();
};

#endif /* CALENDAR_H */
