CC = g++
CFLAGS = -c -Wall
XXFLAGS = -lgtest -lpthread

all: prog3B test

prog3B: main.o dialog.o train.o
	$(CC) main.o dialog.o train.o -o prog3B

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

dialog.o: dialog.cpp
	$(CC) $(CFLAGS) dialog.cpp

train.o: train.cpp
	$(CC) $(CFLAGS) train.cpp

test: test.cpp
	$(CC) test.cpp -o test $(XXFLAGS)

clean:
	rm -rf *.o prog3B test