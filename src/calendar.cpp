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
	return 0;
}

//Take input to create a new Event
int Calendar::createEvent()
{
	//Get a lot of input and put it in a time object
	Time time = Time();
	
	printf("Input year: "); scanf("%d", &time.year);
	printf("Input month: "); scanf("%d", &time.month);
	printf("Input day: "); scanf("%d", &time.day);
	printf("Input hour: "); scanf("%d", &time.hour);
	printf("Input minute: "); scanf("%d", &time.minute);

	char title[32];
	printf("Input event title: "); scanf("%s", title);

	char data[1024];
	printf("Input information on the event:\n"); scanf("%s", data);

	Event newEvent = Event(time, data, name);

	return 0;
}

int Calendar::deleteEvent()
{
	return 0;
}
