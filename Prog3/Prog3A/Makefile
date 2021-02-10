CC = g++
CFLAGS = -c -Wall
XXFLAGS = -lgtest -lpthread

all: prog3A test

prog3A: main.o dialog.o train.o
	$(CC) main.o dialog.o train.o -o prog3A

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

dialog.o: dialog.cpp
	$(CC) $(CFLAGS) dialog.cpp

train.o: train.cpp
	$(CC) $(CFLAGS) train.cpp

test: test.cpp
	$(CC) test.cpp -o test $(XXFLAGS)

clean:
	rm -rf *.o prog3A test