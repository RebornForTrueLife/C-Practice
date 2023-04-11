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
/*	read_file(string) 
	- to read input file and return float array 
	- input: 
		- name of data file
		- size: number of elements in the array, value
		will be change after reading file
	- output: pointer to the array */
float sum_array(char const *fileName);


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
	// sum array
		// set start time
	std::clock_t t = std::clock();
	float sum = sum_array(argv[1]);
		// set end time
	t = std::clock() - t;
	// print result
	std::cout << "The sum of array = " << sum << "\n";
	std::cout << "Total executed time: " << (float) t / CLOCKS_PER_SEC << "\n";
	return 0;
}	// end  main 


// read file
float sum_array(char const *fileName) {
	std::ifstream inFile(fileName);
	if (inFile.is_open() == false) {
		std::cerr << "Unable to open file: " << fileName << "\n";
		exit(8);
	}	// close if
	// read file
		// allocate memory for array
	float value;		// a holder
	float sum = 0;
	// count the number of float
	while (inFile.good()) {		// while not reach EOF
		inFile >> value;
		sum += value;
	}	// close while
	return sum;
}	// close sum_array
