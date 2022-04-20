CC := g++
CCFLAGS += -l SDL2 -l SDL2_image -l SDL2_ttf -l SDL2_mixer

all: starwars.out

starwars.out: rsdl.o game.o spaceship.o main.o 
	$(CC) main.o rsdl.o game.o spaceship.o $(CCFLAGS) -o starwars.out

rsdl.o: src/rsdl.hpp src/rsdl.cpp
	$(CC) -c src/rsdl.cpp -o rsdl.o

game.o: src/rsdl.hpp game/game.hpp game/player/spaceship.hpp game/game.cpp
	${CC} -c game/game.cpp -o game.o

spaceship.o: src/rsdl.hpp game/player/spaceship.hpp game/player/spaceship.cpp
	${CC} -c game/player/spaceship.cpp -o spaceship.o

main.o: src/rsdl.hpp main.cpp
	$(CC) -c main.cpp -o main.o


.PHONY: clean
clean:
	rm -r *.o