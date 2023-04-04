/********************************************
 * divideFile - read a file containing a list of integers
 * divide the file into 2 files: one store all numbers divisible by 3
 * other file store the other numbers
 * Uage: 
	- run object file, pass the name of file which containing integer list
	- the program will prompt if successfully dividing files
	or raise warning otherwise
 ********************************************/

#include <iostream>
#include <fstream>

// FUNC DECLARE
/*	divide_file(string)
	- to read list of integer from the input file; 
	store all numbers divisible by 3 in file: divisible.out
	store other numbers in file: notDivisible.out*/
void divide_file(const char* fileName);


// main
int main(int argc, char const *argv[]) {
	std::cout << "The program is used to divide the file containing "
		<< "a list of integers and create 2 files: divisible.out and notDivisible.out\n"
		<< "\tdivisible.out stores all number divisible by 3\n"
		<< "\tnotDivisible.out stores other numbers\n\n";
	// check argument
	if (argc < 2) {
		std::cerr << "Missing to give [input file] argument\n";
		exit(8);
	}	// close if
	// divide file
	divide_file(argv[1]);
	return 0;
}	// end  main 


// divide file
void divide_file(const char* fileName) {
	// check opening file
	std::ifstream inFile(fileName, std::ifstream::in);
	if (inFile.is_open() == false) {
		std::cerr << "Unable to open file: '" << fileName << "'.\n";
		exit(-1);
	}	// close if
	// open 2 destination files
	std::ofstream yesOutFile("divisible.out", std::ofstream::out);
	std::ofstream noOutFile("notDivisible.out", std::ofstream::out);
	// read each number in input file
	int number;		// reading number in file
	while (true) {
		// terminate condition
		if (inFile.good() == false) 
			break;
		inFile >> number;
		// check if number is divisible by 3
		if ((number % 3) == 0)
			// write to divisible file
			yesOutFile << number << ' ';
		else // not divisible
			noOutFile << number << ' ';
			// close if
	}	// close while
	std::clog << "Successfully divide file into 2 files!\n";
}	// close divide_file