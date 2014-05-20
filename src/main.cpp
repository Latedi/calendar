#include "calendar.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
	Calendar cal = Calendar();

	char input = 'x';

	while(input != 'q')
	{
		printf("What do you want to do? [n]ew [o]pen [l]ist [q]uit\n");
		scanf(" %c", &input);

		switch(input)
		{
		case 'n': cal.createEvent();
			break;
		case 'o':
			break;
		case 'l':
			break;
		}
	}

	return 0;
}
