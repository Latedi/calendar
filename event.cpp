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
	int lastSlash = -1;
	int nextLastSlash = -1;
	for(int i = path.length(); i >= 0; i--)
	{
		if(lastSlash == -1 && path[i] == '/')
		{
			lastSlash = path.length() - i;
		}
		else if(nextLastSlash == -1 && path[i] == '/')
		{
			nextLastSlash = path.length() - i;
			break;
		}
	}

	if(lastSlash != -1 && lastSlash != path.length())
	{
		title = path.substr(path.length() - lastSlash + 1);
		time = BTime(path.substr(path.length() - nextLastSlash + 1, nextLastSlash - lastSlash - 1));

		std::ifstream eventFile;
		eventFile.open(path.c_str());
		std::string line;

		if(eventFile.is_open())
		{
			data = "";
			while(getline(eventFile, line))
			{
				data += line + "\n";
			}
			eventFile.close();
		}
		else
			printf("Could not open file %s\n", path.c_str());
	}
	else
		printf("Could not find path in %s\n", path.c_str());

	printEvent();
}

//Print all information on the event to stdout
void Event::printEvent()
{
	std::string t = time.toString();

	printf("%s\t%s\n", title.c_str(), t.c_str());
	printf("%s\n", data.c_str());
}
