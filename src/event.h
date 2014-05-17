#ifndef EVENT_H
#define EVENT_H

class Event
{
private:
	char* date;
	char* data;
public:
	Event(char* date, char* data);
	Event(char* path);
	void printData();
};

#endif /* EVENT_H */
