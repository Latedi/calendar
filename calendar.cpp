#include "calendar.h"

Calendar::Calendar(std::string str)
{
	printf("%s\n", str.c_str());
}

Calendar::Calendar()
{
	printf("Got into the constructor\n");
	//Get the path to the current directory and save in the root variable.
	//Linux dependent.
	char buff[DEFAULT_BUFF_LENGTH];
	ssize_t len = readlink("/proc/self/exe", buff, DEFAULT_BUFF_LENGTH - 1);	

	if(len != -1)
	{
		buff[len] = '\0';
		for(int i = len; i > 0; i--)
		{
			if(buff[i] == '/')
			{
				buff[i] = '\0';
				break;
			}
		}
		root = std::string(buff);
	}
	else { printf("Error reading path\n"); exit(1); }

	fileHandler = FileHandler(root);
}

std::string Calendar::getRoot()
{
	return root;
}

std::map<int, Event> Calendar::showAll()
{
	getAllEvents();
	std::map<int, Event> res;
	int i = 1;

	std::list<Event>::iterator it;
	for(it = eventList.begin(); it != eventList.end(); it++)
	{
		printf("%s%20s%3d\n", it->getTimeString().c_str(), it->getTitle().c_str(), i);
		res[i] = *it;
		i++;
	}

	return res;
}

//Load all events into the list
int Calendar::getAllEvents()
{
	eventList.clear();
	std::list<std::string> dirList = fileHandler.getDirList();
	std::list<std::string>::iterator it;

	for(it = dirList.begin(); it != dirList.end(); it++)
	{
		std::list<Event> ev = fileHandler.getDirContents(*it);
		eventList.splice(eventList.end(), ev);
	}

	return 0;
}

//Take input to create a new Event
int Calendar::createEvent()
{
	BTime time = createBTime();

	//Put event title and information in buffers
	char title[32];
	printf("Input event title: "); scanf("%s", title);

	char data[DEFAULT_BUFF_LENGTH];
	printf("Input information on the event:\n"); scanf(" %s", data);

	Event newEvent = Event(time, data, title);
	printf("-------------------\n");
	newEvent.printEvent();

	return 0;
}

void Calendar::editEvent(Event oldEvent, Event newEvent)
{
	fileHandler.editEvent(oldEvent, newEvent);
}

//Get a lot of input and put it in a BTime object
BTime Calendar::createBTime()
{
	int y, mo, d, h, mi;	

	printf("Input year: "); scanf("%d", &y);
	printf("Input month: "); scanf("%d", &mo);
	printf("Input day: "); scanf("%d", &d);
	printf("Input hour: "); scanf("%d", &h);
	printf("Input minute: "); scanf("%d", &mi);

	return BTime(y, mo, d, h, mi);
}

//Remove an event
int Calendar::deleteEvent(Event ev)
{
	return 0;
}
