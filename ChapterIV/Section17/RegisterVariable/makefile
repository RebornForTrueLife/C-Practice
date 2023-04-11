
# makefile for count bit

CC=g++
CFLAGS=-g -Wall
all: countBit

countBit: 
	$(CC) $(CFLAGS) -o countBit.o countBit.cc
	$(CC) $(CFLAGS) -o opCountBit.o opCountBit.cc

clean:
	rm countBit.o
	rm opCountBit.o

run:
	./countBit.o data.in 
	./opCountBit.o data.in 