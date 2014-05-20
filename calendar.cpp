#include "calendar.h"

Calendar::Calendar()
{
	//Get the path to the current directory and save in the root variable.
	//Linux dependent.
	char buff[1024];
	ssize_t len = readlink("/proc/self/exe", buff, sizeof(buff)-1);
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
		strcpy(root, buff);
	}
	else { printf("Error reading path\n"); exit(1); }
}

int Calendar::getAllEvents()
{
	//Load all events into the list
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

	char data[1024];
	printf("Input information on the event:\n"); scanf(" %s", data);

	Event newEvent = Event(time, data, title);
	printf("-------------------\n");
	newEvent.printEvent();

	return 0;
}

int Calendar::deleteEvent()
{
	//Remove an event
	return 0;
}
