#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <list>

#include "event.h"

class FileHandler
{
private:
	char* rootDir;
public:
	FileHandler(char* rootDir);
	//list getDirList();
	//list getDirContents(char* dir);
	Event getEvent(char* path);
};

#endif /* FILEHANDLER_H */
