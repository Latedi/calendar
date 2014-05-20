#include "event.h"

Event::Event(BTime time, char* data, char* title)
{
	this->time = time;
	this->data = data;
	this->title = title;
}

Event::Event(char* path)
{
	//Load data from a file
}

void Event::printEvent()
{
	int size = 16;
	char buff[size];
	time.toString(buff, size);

	printf("%s\t%s\n", title, buff);
	printf("%s\n", data);
}
