CC := g++ -std=c++11
CCFLAGS += -l SDL2 -l SDL2_image -l SDL2_ttf -l SDL2_mixer
OBJECTS := rsdl.o gui.o map.o general.o game.o spaceship.o bullet.o enemy.o movingenemy.o hostage.o main.o
EXECUTABLE := starwars.out

all: ${EXECUTABLE}

${EXECUTABLE}: ${OBJECTS}
	$(CC) ${OBJECTS} $(CCFLAGS) -o ${EXECUTABLE}

rsdl.o: src/rsdl.hpp src/rsdl.cpp
	$(CC) -c src/rsdl.cpp -o rsdl.o

gui.o: game/gui.hpp game/gui.cpp
	${CC} -c game/gui.cpp -o gui.o

map.o: game/constants.hpp game/map.hpp game/map.cpp
	${CC} -c game/map.cpp -o map.o

general.o: src/rsdl.hpp game/general.hpp game/general.cpp
	${CC} -c game/general.cpp -o general.o

game.o: src/rsdl.hpp game/game.hpp game/spaceship.hpp game/game.cpp
	${CC} -c game/game.cpp -o game.o

spaceship.o: src/rsdl.hpp game/constants.hpp game/spaceship.hpp game/spaceship.cpp
	${CC} -c game/spaceship.cpp -o spaceship.o

bullet.o: src/rsdl.hpp game/constants.hpp game/bullet.hpp game/bullet.cpp
	${CC} -c game/bullet.cpp -o bullet.o

enemy.o: src/rsdl.hpp game/constants.hpp game/enemy.hpp game/enemy.cpp
	${CC} -c game/enemy.cpp -o enemy.o

movingenemy.o: game/enemy.hpp game/movingenemy.hpp game/movingenemy.cpp
	${CC} -c game/movingenemy.cpp -o movingenemy.o

hostage.o: src/rsdl.hpp game/hostage.hpp game/hostage.cpp
	${CC} -c game/hostage.cpp -o hostage.o

main.o: src/rsdl.hpp main.cpp
	$(CC) -c main.cpp -o main.o


.PHONY: clean
clean:
	rm -r *.o