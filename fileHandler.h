#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#define FILE_DIR "/events"

#include <list>
#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <sys/stat.h>
#include <sys/types.h>

#include "event.h"

class FileHandler
{
private:
	std::string rootDir;
public:
	FileHandler();
	FileHandler(std::string rootDir);
	std::list<std::string> getDirList();
	std::list<Event> getDirContents(std::string directory);
	int saveEvent(Event ev);
	Event getEvent(char* path);
	void printList(std::list<std::string> l);
};

#endif /* FILEHANDLER_H */
