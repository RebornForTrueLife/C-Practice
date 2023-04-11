/********************************************
 * sumArray - to sum all float in an array
 * Uage: 
	- run the object file, pass name of file storing float
	array
	- the program will print out the sum of the array
 ********************************************/

#include <iostream>
#include <fstream>
#include <ctime>


// FUNC DECLARE
/*	sum(float*, int)
	- a func to sum all number in a float array
	- input: 
		- float array
		- the number of float in the array
	- output: the sum of array */
float sum_array(float *array, int size);

/*	read_file(string) 
	- to read input file and return float array 
	- input: 
		- name of data file
		- size: number of elements in the array, value
		will be change after reading file
	- output: pointer to the array */
float *read_file(char const *fileName, int &size);


// MAIN
int main(int argc, char const *argv[]) {
	std::cout << "THe program is used calculate the sum of a given float array\n";
	// Read the file
		// get file name from argument
	if (argc != 2) {
		std::cerr << "Invalid argument format:\n";
		std::cerr << "\t[dir]/sumArray [filePath]\n";
		exit(8);
	}	// close if	
		// open file
	int size = 0;		// size of array
		// set start time
	std::clock_t t = std::clock();
	float *array = read_file(argv[1], size);
	// sum array
	float sum = sum_array(array, size);
		// set end time
	t = std::clock() - t;
	// print result
	std::cout << "The sum of array = " << sum << "\n";
	std::cout << "Total executed time: " << (float) t / CLOCKS_PER_SEC << "\n";
	return 0;
}	// end  main 


// read file
float *read_file(char const *fileName, int &size) {
	std::ifstream inFile(fileName);
	if (inFile.is_open() == false) {
		std::cerr << "Unable to open file: " << fileName << "\n";
		return NULL;
	}	// close if
	// read file
		// allocate memory for array
	float value;		// a holder
	size = 0;
	// count the number of float
	while (inFile.good()) {		// while not reach EOF
		size += 1;
		inFile >> value;
	}	// close while
	// read file and put float into array
	inFile.close();
	inFile.open(fileName);
	int count = 0;
	static float *array = new float [size];
	while (inFile.good()) {		// while not reach EOF
		inFile >> *(array + count);
		count += 1;
	}	// close while
	return array;
}	// close read_file


// sum array
float sum_array(float *array, int size) {
	float sum = 0;	// sum of array	
	// add each number in array to sum
	for (int i = 0; i < size; i ++ ) {
		sum += *(array + i);
	}	// close for
	return sum;
}	// sum_array