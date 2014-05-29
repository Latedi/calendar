#include "calendar.h"

Calendar::Calendar(std::string str)
{
	printf("%s\n", str.c_str());
}

Calendar::Calendar()
{
	printf("Created\n");
}

/*Calendar::Calendar()
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
}*/

std::string Calendar::getRoot()
{
	return root;
}

//Load all events into a list
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
	//Get a lot of input and put it in a BTime object
	int y, mo, d, h, mi;	

	printf("Input year: "); scanf("%d", &y);
	printf("Input month: "); scanf("%d", &mo);
	printf("Input day: "); scanf("%d", &d);
	printf("Input hour: "); scanf("%d", &h);
	printf("Input minute: "); scanf("%d", &mi);

	BTime time = BTime(y, mo, d, h, mi);

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

//Remove an event
int Calendar::deleteEvent()
{
	return 0;
}
