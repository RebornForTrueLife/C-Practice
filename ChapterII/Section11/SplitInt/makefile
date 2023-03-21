
# makefile for splitting an integer into 4-bit values

CC=g++
CFLAGS=-g -Wall
all: splitInt

splitInt: splitInt.cc 
	$(CC) $(CFLAGS) -o splitInt.o splitInt.cc

clean:
	rm splitInt.o

run:
	./splitInt.o