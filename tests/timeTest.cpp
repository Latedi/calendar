#include "btime.h"
#include <string>
#include <stdio.h>

int main(int argc, char *argv[])
{
	BTime time = BTime(14, 6, 0, 32, 30);
	std::string s = time.toString();
	printf("%s\n", s.c_str());

	BTime time2 = BTime("2014-09-23_13:20");
	s = time2.toString();
	printf("%s\n", s.c_str());
}
