#include "event.h"

Event::Event(BTime time, std::string data, std::string title)
{
	this->time = time;
	this->data = data;
	this->title = title;
}

//Load data from a file
Event::Event(std::string path)
{
	std::list<int> indexes;
	for(int i = path.length(); i > 0; i--)
	{
		printf("is %d = / ?", path.at(i));
		if(path.at(i) == '/')
		{
			indexes.push_back(i);
			printf("Index found at: %d\n", i);
		}
		else printf(" No\n");
	}

	std::list<int>::iterator it = indexes.begin();
	this->title = path.substr(*it);
}

//Print all information on the event to stdout
void Event::printEvent()
{
	int size = 16;
	char buff[size];
	time.toString(buff, size);

	printf("%s\t%s\n", title.c_str(), buff);
	printf("%s\n", data.c_str());
}
