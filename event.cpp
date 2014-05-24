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
	int firstSlash = -1;
	for(int i = path.length(); i >= 0; i--)
	{
		if(path[i] == '/')
		{
			firstSlash = path.length() - i;
			break;
		}
	}

	if(firstSlash != -1)
	{
		this->title = path.substr(firstSlash);

		std::ifstream eventFile;
		eventFile.open(path.c_str());
		std::string line;

		if(eventFile.is_open())
		{
			data = "";
			while(getline(eventFile, line))
			{
				data += line;
			}
			eventFile.close();
		}
		else
			printf("Could not open file %s\n", path.c_str());
	}
	else
		printf("Could not find path in %s\n", path.c_str());

	printf("EVENT LOADED\n");
	printEvent();
}

//Print all information on the event to stdout
void Event::printEvent()
{
	time.toString(title);

	printf("%s\t%s\n", title.c_str(), buff);
	printf("%s\n", data.c_str());
}
