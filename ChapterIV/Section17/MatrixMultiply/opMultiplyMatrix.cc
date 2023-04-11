/********************************************
 * multiplyMatrix - define a function to read 2 matrices
 * and do a multiplication of 2 matrices
 * Uage: 
	- the program provide 2 services:
	(1) Read 2 square matrices from a file with given name
	(2) Do multiplication between 2 given square matrices of the
	same size
 ********************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>


// FUNC DECLARE

/*	read a matrix in a given file, which has the below format
	- Format: 
		- 1st line: size of matrix
		- next [size] lines: matrix
	- input: file name
	- output: the matrix */
int **read_matrix(std::string file, int &size);

/*	multiply 2 given square matrices having the same size
	- input: 2 matrices, the size
	- output: the product */
int **multiply_matrix(int **matrixA, int **matrixB, int size);

// print a matrix
void print_matrix(int **matrix, int size);


// MAIN
int main(int argc, char const *argv[]) {
	std::cout << "Program provide 2 services:\n";
	std::cout << "\t1. Reading a matrix from the given file\n";
	std::cout << "\t2. Multiply 2 square matrices\n";
	// Testing
	int size;
	int **matrixA = read_matrix("data", size);
	int **matrixB = read_matrix("data", size);
	// set start time
	std::clock_t t = std::clock();
	int **product = multiply_matrix(matrixA, matrixB, size);
	// set finish time
	t = std::clock() - t; 
	float sec = (float) t / CLOCKS_PER_SEC;
	// print_matrix(product, size);
	std::cout << "Calculating time: " << sec << "\n";
	return 0;
}	// end  main 


// FUNC DEFINE

int **read_matrix(std::string file, int &size) {
	std::ifstream inFile(file, std::ifstream::in);
	// check if being able to open file
	if (inFile.is_open() == false) {
		std::cerr << "Unable to open file : '" << file << "'.\n";
		return NULL;
	}	// close
	// read file
		// read size of matrix
	inFile >> size;
		// allocate memory for matrix
	static int **matrix = new int* [size];
		// read each line of matrix
	for (int i = 0; i < size; i ++ ) {
		*(matrix + i) = new int [size];
		for (int j = 0; j < size; j ++ ) 
			inFile >> (*(*(matrix + i) + j));
	}	// close for
	return matrix;
}	// close read_matrix


// print matrix
void print_matrix(int **matrix, int size) {
	for (int i = 0; i < size; i ++ ) {
		for (int j = 0; j < size; j ++ ) 
			std::cout << (*(*(matrix + i) + j)) << " ";
		std::cout << "\n";
	}	// close for
}	// close print_matrix


// multiply matrix
int **multiply_matrix(int **matrixA, int **matrixB, int size) {
	// allocate product
	int **product = new int* [size];
	for (int i = 0; i < size; i ++ ) {
		*(product + i) = new int [size];
		for (int j = 0; j < size; j ++ ) 
			(*(*(product + i) + j)) = (*(*(matrixA + i) + j)) * (*(*(matrixB + i) + j));
	}	// close for
	return product;
}	// close multiply_matrix