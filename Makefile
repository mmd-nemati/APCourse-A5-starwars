CC := g++
CCFLAGS += -l SDL2 -l SDL2_image -l SDL2_ttf -l SDL2_mixer

all: starwars.out

starwars.out: rsdl.o game.o spaceship.o bullet.o main.o 
	$(CC) main.o rsdl.o game.o spaceship.o $(CCFLAGS) -o starwars.out

rsdl.o: src/rsdl.hpp src/rsdl.cpp
	$(CC) -c src/rsdl.cpp -o rsdl.o

game.o: src/rsdl.hpp game/game.hpp game/spaceship.hpp game/game.cpp
	${CC} -c game/game.cpp -o game.o

spaceship.o: src/rsdl.hpp game/bullet.hpp game/spaceship.hpp game/spaceship.cpp
	${CC} -c game/spaceship.cpp -o spaceship.o

bullet.o: src/rsdl.hpp game/bullet.hpp game/bullet.cpp
	${CC} -c game/bullet.cpp -o bullet.o

main.o: src/rsdl.hpp main.cpp
	$(CC) -c main.cpp -o main.o


.PHONY: clean
clean:
	rm -r *.o