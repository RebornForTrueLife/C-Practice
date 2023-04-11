
# makefile for multiplying matrices

CC=g++
CFLAGS=-g -Wall
all: multiplyMatrix

multiplyMatrix: # multiplyMatrix.cc 
	$(CC) $(CFLAGS) -o multiplyMatrix.o multiplyMatrix.cc 
	$(CC) $(CFLAGS) -o opMultiplyMatrix.o opMultiplyMatrix.cc 

run:
	./multiplyMatrix.o
	./opMultiplyMatrix.o

runI:
	./opMultiplyMatrix.o
	./multiplyMatrix.o

clean:
	rm multiplyMatrix.o
	rm opMultiplyMatrix.o