#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#define FILE_DIR "/events"
#define PATH_DEFAULT_BUFFER_LENGTH 512

#include <list>
#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

#include "event.h"

class FileHandler
{
private:
	std::string rootDir;
public:
	FileHandler(std::string rootDir);
	std::list<std::string> getDirList();
	std::list<Event> getDirContents(std::string directory);
	Event getEvent(char* path);
};

#endif /* FILEHANDLER_H */
