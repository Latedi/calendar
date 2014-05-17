#ifndef CALENDAR_H
#define CALENDAR_H

#include "event.h"
#include <list>

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
