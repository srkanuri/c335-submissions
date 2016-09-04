#Name 1: Srikanth Kanuri
#Name 2: Samual Eleftheri
CC = gcc
CFLAGS = -g
LDFLAGS = 

mywc: mywc.o
	$(CC) $(LDFLAGS) -o mywc mywc.o
mywc.o: mywc.c
	$(CC) $(CFLAGS) -c mywc.c
clean:
	rm mywc.o mywc
