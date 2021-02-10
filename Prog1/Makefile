CC = g++
CFLAGS = -c -Wall

all: prog1

prog1: main.o Prog1.o
	$(CC) main.o Prog1.o -o prog1

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

Prog1.o: Prog1.cpp
	$(CC) $(CFLAGS) Prog1.cpp

clean:
	rm -rf *.o prog1