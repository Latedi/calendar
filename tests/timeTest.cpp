#include "btime.h"

int main(int argc, char *argv[])
{
	BTime time = BTime(14, 6, 0, 32, 30);
	time.removeExcess();
	time.toString();
}
