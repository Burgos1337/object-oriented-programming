CC = g++
CFLAGS = -c -Wall

all: bonus

bonus: main.o dialog.o
	$(CC) -o bonus main.o dialog.o -Llib -lDice

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp
	
dialog.o: dialog.cpp
	$(CC) $(CFLAGS) dialog.cpp

clean:
	rm -rf *.o bonus