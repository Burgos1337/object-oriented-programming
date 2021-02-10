CC = g++
CFLAGS = -c -Wall

all: prog3C

prog3C: main.o dialog.o
	$(CC) -o prog3C main.o dialog.o -Llib -ltrain

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp
	
dialog.o: dialog.cpp
	$(CC) $(CFLAGS) dialog.cpp

clean:
	rm -rf *.o prog3C