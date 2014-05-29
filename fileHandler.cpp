#include "fileHandler.h"

//This class handles reading and writing to event files

FileHandler::FileHandler()
{
	rootDir = "";
}

FileHandler::FileHandler(std::string rootDir)
{
	rootDir += FILE_DIR;
	this->rootDir = rootDir;
}

//This function is responsible for loading all event folders into a list which is then returned
std::list<std::string> FileHandler::getDirList()
{
	std::list<std::string> dirList;
	DIR *dir;
	struct dirent* ent;

	const char* c = rootDir.c_str();
	dir = opendir(c);

	if(dir == NULL)
	{
		printf("Error in getDirList. %s\n", strerror(errno));
		exit(1);
	}

	//Find all subdirectories to the event directory and watch out for . and ..
	while((ent = readdir(dir)) != NULL)
	{
		if(ent->d_type == DT_DIR && strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0)
		{
			std::string fullPath = rootDir + "/" + ent->d_name;
			dirList.push_back(fullPath.c_str());
		}
	}

	return dirList;
}

//This function loads up all events from a directory and returns them in a list
std::list<Event> FileHandler::getDirContents(std::string directory)
{
	std::list<Event> res;

	DIR *dir;
	struct dirent* ent;

	dir = opendir(directory.c_str());
	if(dir == NULL)
	{
		printf("Error in getDirContents. %s\n", strerror(errno));
		printf("%s\n", directory.c_str());
		exit(1);
	}

	//Go through all files and try to parse any regular files
	while((ent = readdir(dir)) != NULL)
	{
		if(ent->d_type == DT_REG)
		{
			Event ev = Event(std::string(directory + "/" + ent->d_name));
			res.push_back(ev);
		}
	}

	return res;
}

int FileHandler::saveEvent(Event ev)
{
	std::string dirName = ev.getTimeString();
	DIR *dir;
	struct dirent* ent;	

	dir = opendir(rootDir.c_str());
	if(dir == NULL)
	{
		printf("Error in saveEvent. %s\n", strerror(errno));
		printf("%s\n", rootDir.c_str());
		return 1;
	}

	bool directoryExists = false;

	//Check to see if the directory already exists
	while((ent = readdir(dir)) != NULL)
	{
		if(ent->d_type == DT_DIR && strcmp(ent->d_name, dirName.c_str()) == 0)
		{
			directoryExists = true;
		}
	}

	std::string fullPath = rootDir;
	fullPath += "/";
	fullPath += ev.getTimeString();

	//Check if the file exists, or create the directory
	if(directoryExists)
	{	
		dir = opendir(fullPath.c_str());

		if(dir == NULL)
		{
			printf("Something went terribly wrong. %s\n", strerror(errno));
			printf("%s\n", fullPath.c_str());
			exit(1);
		}

		//Does the file exist
		while((ent = readdir(dir)) != NULL)
		{
			if(ent->d_type == DT_REG && strcmp(ent->d_name, ev.getTitle().c_str()) == 0)
			{
				printf("The event already exists (duplicate?)\n");
				return -1;
			}
		}
	}
	else
	{
		//Create the directory
		int res = mkdir(fullPath.c_str(), 0777);
		if(res != 0)
		{
			printf("Error in saveEvent. %s\n", strerror(errno));
			return -1;
		}
	}

	//Create the file
	std::string fullFileName = fullPath + "/" + ev.getTitle();
	std::ofstream eventFile(fullFileName.c_str());
	eventFile << ev.getData();

	return 0;
}

//Find an Event and return the path
std::string FileHandler::findEvent(Event ev)
{
	std::string res = "";

	return res;
}

//Edit an existing event
int FileHandler::editEvent(Event oldEvent, Event newEvent)
{
	std::string fullPath = rootDir;
	fullPath += "/";
	fullPath += oldEvent.getTimeString();
	fullPath += "/";
	fullPath += oldEvent.getTitle();

	if(strcmp(oldEvent.getTitle().c_str(), newEvent.getTitle().c_str()) != 0)
	{
		std::string newPath = rootDir;
		newPath += "/";
		newPath += newEvent.getTimeString();
		newPath += "/";
		newPath += newEvent.getTitle();
		return rename(fullPath.c_str(), newPath.c_str());
	}
	else if(strcmp(oldEvent.getData().c_str(), newEvent.getData().c_str()) != 0)
	{
		
	}
	else if(strcmp(oldEvent.getTimeString().c_str(), newEvent.getTimeString().c_str()) != 0)
	{
		
	}
	else
		return -1;

	return 0;
}

//Used for debugging purposes
void FileHandler::printList(std::list<std::string> l)
{
	std::list<std::string>::iterator it;
	for(it = l.begin(); it != l.end(); it++)
	{
		std::cout << *it << "\n";
	}
}
