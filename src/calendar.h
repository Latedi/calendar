#ifndef CALENDAR_H
#define CALENDAR_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <list>
#include <stdlib.h>
#include <dirent.h>

#include "event.h"

class Calendar
{
private:
	char* root;
	std::list<Event> eventList;
public:
	Calendar();
	int getAllEvents();
	int createEvent();
	int deleteEvent();
};

#endif /* CALENDAR_H */
