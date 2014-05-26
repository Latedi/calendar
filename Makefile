CC = gcc
CFLAGS = -lstdc++

MAIN = main.cpp
SRC = event.cpp calendar.cpp btime.cpp fileHandler.cpp
OBJ = $(SRC:.cpp=.o) $(MAIN:.cpp=.o)
HDR = $(SRC:.cpp=.h)
EXE = planner

all:
	$(CC) -o $(EXE) $(SRC) $(MAIN) $(CFLAGS)

uninstall:
	rm $(EXE) 
