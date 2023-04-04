/********************************************
 * binaryConvert - read an integer list from a file and
 * write to file: list.dat in binary format
 * Uage: 
	- run object file, pass [inputFileName]
	- the program  will print file name: list.dat if converting 
	successfully
 ********************************************/

#include <iostream>
#include <fstream>
#include <bitset>


// FUNC DECLARE
/*	read an integer list of the given file
	and write the list to "list.dat" file in binary format
	- input: name of file containing the list of integer
	- output:
		1. raise error: if unable to open the input file
		2. prompt successfully write: otherwise*/
void write_binary(const char* fileName);


// main
int main(int argc, char const *argv[]) {
	std::cout << "The program is used to read a list of integer in a given file\n"
		<< "Then write the list into the 'list.dat' file in binary format\n\n";
	// validate number of arguments
	if (argc < 2) {
		std::cerr << "Missing to pass [input file]\n";
		exit(8);
	}	// close if
	// write in binary
	write_binary(argv[1]);
	return 0;
}	// end  main 


// FUNC DEFINE

// write file in binary
void write_binary(const char *fileName) {
	// check if being able to open file
	std::ifstream inFile(fileName, std::ifstream::in);
	if (inFile.is_open() == false) {
		std::cerr << "Unable to open file: '" << fileName << "'.\n";
		exit(-1);
	}	// close if
	// open output file
	std::ofstream outFile("list.dat", std::ofstream::out);
	// read each number of inFile
	int number; 	// place to hold read value
	while (true) {
		// terminate cond
		if (inFile.good() == false) 
			break;
		// read a number
		inFile >> number;
		// convert number to binary
		std::bitset<16> bi(number);
		// write binary number to file
		outFile << bi << ' ';
	}	// close while
	std::clog << "Successfully write to 'list.dat' in binary format\n";
}	// close write_binary