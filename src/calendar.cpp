#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <list>
#include <stdlib.h>

#include "event.h"
#include "calendar.h"

Calendar::Calendar()
{
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

	printf("PATH: %s\n", root);
}

int Calendar::getAllEvents()
{
	return 0;
}

int Calendar::createEvent()
{
	return 0;
}

int Calendar::deleteEvent()
{
	return 0;
}
