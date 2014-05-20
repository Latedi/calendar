#include "event.h"

Event::Event(BTime time, char* data, char* title)
{
	this->time = time;
	this->data = data;
	this->title = title;
}

Event::Event(char* path)
{
	
}

void Event::printData()
{

}
