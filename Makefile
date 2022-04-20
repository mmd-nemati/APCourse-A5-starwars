CC := g++
CCFLAGS += -l SDL2 -l SDL2_image -l SDL2_ttf -l SDL2_mixer

all: test.out

test.out: main.o rsdl.o
	$(CC) main.o rsdl.o $(CCFLAGS) -o test.out

main.o: src/rsdl.hpp ss/main.cpp
	$(CC) -c ss/main.cpp -o main.o

rsdl.o: src/rsdl.hpp src/rsdl.cpp
	$(CC) -c src/rsdl.cpp -o rsdl.o

.PHONY: clean
clean:
	rm -r *.o