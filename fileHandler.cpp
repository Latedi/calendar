#include "fileHandler.h"

//This class handles reading and writing to event files

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

	//Find all subdirectories to the event directory
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

void FileHandler::printList(std::list<std::string> l)
{
	std::list<std::string>::iterator it;
	for(it = l.begin(); it != l.end(); it++)
	{
		std::cout << *it << "\n";
	}
}

Event FileHandler::getEvent(char* path)
{

}
