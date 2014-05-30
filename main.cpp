#include "calendar.h"
#include "event.h"
#include "btime.h"

#include <stdio.h>
#include <map>
#include <string>

int main(int argc, char *argv[])
{
	Calendar cal = Calendar();

	char input = 'x';

	while(input != 'q')
	{
		printf("What do you want to do? [n]ew, [o]pen, show [a]ll upcoming, [q]uit\n");
		scanf(" %c", &input);

		switch(input)
		{
		case 'n':
		{
			cal.createEvent();
			break;
		}
		case 'o':
		{
			std::map<int, Event> events = cal.showAll();
			int openInput = -2;

			while(openInput == -2)
			{
				printf("Which event would you like to open? insert the number or -1 to go back.\n");
				scanf(" %d", &openInput);
			}

			if(openInput == -1)
				break;

			std::map<int, Event>::iterator it;
			for(it = events.begin(); it != events.end(); it++)
			{
				if(it->first == openInput)
				{
					Event ev = it->second;
					ev.printEvent();

					printf("What do you want to do? edit [t]itle, edit [d]ata, edit d[a]te, d[e]lete, [b]ack\n");
					scanf(" %c", &input);
					std::string editInput;
					Event evNew = Event(ev);

					switch(input)
					{
					case 't':
					{
						printf("Enter new title: ");
						std::cin.get();
						std::getline(std::cin, editInput);
						std::cin.sync();
						evNew.setTitle(editInput);
						cal.editEvent(ev, evNew);
						break;
					}
					case 'd':
					{
						printf("Enter new data: ");
						std::cin.get();
						std::getline(std::cin, editInput);
						std::cin.sync();
						evNew.setData(editInput);
						cal.editEvent(ev, evNew);
						break;
					}
					case 'a':
					{
						BTime time = cal.createBTime();
						evNew.setTime(time);
						cal.editEvent(ev, evNew);
						break;
					}
					case 'e':
					{
						printf("Are you sure you want to delete this event? [y/n]\n");
						char deleteYN;
						scanf(" %c", &deleteYN);

						switch(deleteYN)
						{
						case 'y':
						{
							cal.deleteEvent(ev);
							break;
						}
						default:
							break;
						}

						break;
					}
					default:
						break;
					}
					break;
				}
			}

			break;
		}
		case 'a':
		{
			printf("From what time do you want to list events?\n");
			BTime time = cal.createBTime();
			cal.showUpcoming(time);
			break;
		}
		}
	}

	return 0;
}
