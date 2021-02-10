CC = g++
CFLAGS = -c -Wall
XXFLAGS = -lgtest -lpthread

all: prog2 test

prog2: main.o Dialog.o Cassini.o
	$(CC) main.o Dialog.o Cassini.o -o prog2

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

Dialog.o: Dialog.cpp
	$(CC) $(CFLAGS) Dialog.cpp

Cassini.o: Cassini.cpp
	$(CC) $(CFLAGS) Cassini.cpp

test: test.cpp
	$(CC) test.cpp -o test $(XXFLAGS)

clean:
	rm -rf *.o prog2 test