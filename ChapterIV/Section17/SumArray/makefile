
# makefile for sum array 

CC=g++
CFLAGS=-g -Wall
all: sumArray

sumArray: 
	$(CC) $(CFLAGS) -o sumArray.o sumArray.cc 
	$(CC) $(CFLAGS) -o opSumArray.o opSumArray.cc 

clean:
	rm sumArray.o
	rm opSumArray.o

run:
	./opSumArray.o data.in
	./sumArray.o data.in
	