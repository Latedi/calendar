#include "fileHandler.h"
#include "calendar.h"
#include "event.h"
#include "btime.h"

#include <stdio.h>
#include <string>

int main(int argc, char* argv[])
{
	printf("FileHandler test started\n");
	Calendar cal = Calendar();
	std::string str;
	printf("Getting root directory...\n");
	//str = cal.getRoot();
	//printf("Retrieved root directory as: %s\n", str.c_str());
	//FileHandler handler = FileHandler(str);
	//std::list<std::string> dirs = handler.getDirList();
	//std::list<std::string>::iterator it = dirs.begin();
	//handler.getDirContents(*it);

	FileHandler handler = FileHandler("/home/ltdi/Projects/projectideas/planner");

	printf("\nTesting saveEvent:\n");
	Event ev = Event(BTime("2014-09-23_13:22"), "stuff\netc", "title");
	handler.saveEvent(ev);
}
