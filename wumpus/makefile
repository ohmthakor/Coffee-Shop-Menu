CC=g++ -std=c++11 -g
EXE_FILE = run

all: $(EXE_FILE)

$(EXE_FILE): main.o game.o game.h room.o room.h event.o event.h bats.o bats.h gold.o gold.h stalactites.o stalactites.h wumpus.o stalactites.h
	$(CC) main.o game.o room.o event.o bats.o gold.o stalactites.o wumpus.o -o $(EXE_FILE)

main.o: main.cpp game.h room.h event.h bats.h gold.h stalactites.h wumpus.h
	$(CC) -c main.cpp

game.o: game.cpp game.h gold.h stalactites.h bats.h wumpus.h event.h room.h
	$(CC) -c game.cpp

room.o: room.cpp room.h event.h bats.h stalactites.h wumpus.h gold.h
	$(CC) -c room.cpp

event.o: event.cpp event.h
	$(CC) -c event.cpp

bats.o: bats.cpp bats.h event.h
	$(CC) -c bats.cpp

gold.o: gold.cpp gold.h event.h
	$(CC) -c gold.cpp

stalactites.o: stalactites.cpp stalactites.h event.h
	$(CC) -c stalactites.cpp

wumpus.o: wumpus.cpp wumpus.h event.h
	$(CC) -c wumpus.cpp
	

clean:
	rm -f *.o $(EXE_FILE)
