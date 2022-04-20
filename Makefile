CC := g++
CCFLAGS += -l SDL2 -l SDL2_image -l SDL2_ttf -l SDL2_mixer

all: starwars.out

starwars.out: main.o rsdl.o game.o
	$(CC) main.o rsdl.o $(CCFLAGS) -o starwars.out

main.o: src/rsdl.hpp game/game.hpp main.cpp
	$(CC) -c main.cpp -o main.o

game.o : src/rsdl.hpp game/game.hpp game.cpp
	${CC} -c game.cpp -o game.o

rsdl.o: src/rsdl.hpp src/rsdl.cpp
	$(CC) -c src/rsdl.cpp -o rsdl.o


.PHONY: clean
clean:
	rm -r *.o