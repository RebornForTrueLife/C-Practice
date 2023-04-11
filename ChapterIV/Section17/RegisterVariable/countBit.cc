/********************************************
 * countBit - count the number of bits in a character 
 * array
 * Uage: 
	- run the program, pass the input data file path
	- the program will print out the number of bits in 
	the string
	* Note: the program will print out the executed time in 
	coding mode
 ********************************************/

#include <iostream>
#include <fstream>
#include <ctime>


// MODE
#define CODING
// #undef CODING


// FUNC DECLARE

/*	count bit(char*)
	* The func to count number of bits in given character
	array
	- input: the character array
	- output: the number of bits of the array */
int count_bit(char *arr);

/*	read file
	* The func to get the character array from a given file
	- input: file path
	- output: character array */
char *read_file(char const *fileName);


// MAIN
int main(int argc, char const *argv[]) {
	std::cout << "The program count the number of bits in a character array in given file\n";
	// get file name
	if (argc != 2) {
		std::cerr << "Wrong number of arguments: .../countBit.o [fileName]\n";
		exit(8);
	}	// close if
	// read file
	char *arr = read_file(argv[1]);
	// count bit
	int count = count_bit(arr);
	// print result
	std::cout << "The number of bits = " << count << "\n";
	return 0;
}	// end  main 


// FUNC DEFINE

// read file
char *read_file(char const *fileName) {
	std::ifstream file(fileName);
	// check if file is valid
	if (!file.is_open()) {
		std::cerr << "Unable to read file: " << fileName << "\n";
		exit(-1);
	}	// close if
	// read string
		// count number of byte needed
	file.seekg(0, file.end);
	int count = file.tellg();
	file.seekg(0, file.beg);
	char *arr = new char [count];
		// read file
	file.read(arr, count);
	return arr;
}	// close read_file


// count bit
int count_bit(char *arr) {
	std::clock_t time = std::clock();
	int count = 0;
	while (true) {
		if (*arr == '\0')	// end of string
			break;
		count += 8;
		// move to next character
		arr += 1;
	}	// close while
	// print time executed in coding mode
	#ifdef CODING
		time = std::clock() - time;
		float sec = (float) time / CLOCKS_PER_SEC;
		std::clog << "## Executed counting time: " << sec << " seconds\n";
	#endif // CODING
	return count;
}	// close count_bit