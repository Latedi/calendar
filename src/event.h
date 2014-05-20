#ifndef EVENT_H
#define EVENT_H

class Event
{
private:
	time_t time;
	char* title;
	char* data;
public:
	Event(BTime time, char* data, char* title);
	Event(char* path);
	void printData();
};

#endif /* EVENT_H */
