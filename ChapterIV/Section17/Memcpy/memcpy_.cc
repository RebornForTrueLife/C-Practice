/********************************************
 * memcpy_ - copy substring from source to destination
 * with given size
 * Uage: 
	- run object file
	- the program will print the time compared with memcpy
	of library
 ********************************************/

#include <iostream>
#include <ctime>
#include <cstring>
#include <fstream>


// FUNC DECLARE
/*	memcpy
	* a func to copy [size] bytes from src to des 
	- input
		1. des: destination pointer
		2. src: source pointer
		3. size: number of bytes copying */
char *memcpy_(char *des, char *src, std::size_t size);


/*	read data
	* a function to get a character array from a given file
	- input: file name
	- output: character pointer */
char *read_data(char const *fileName);


// MAIN
int main(int argc, char const *argv[]) {
	std::cout << "The program to compare 2 memcpy funcs\n";
	std::clock_t time;
	// read data
	if (argc != 2) {
		std::cerr << "Wrong number of arguments: .../memcpy_ [fileName]\n";
		exit(8);
	}	// close if
	char *arr = read_data(argv[1]);
	char *des = new char;
	float sec;
	// using defined memcpy_
	time = std::clock();
	memcpy_(des, arr, 10000);
	time = std::clock() - time;
	sec = (float) time / CLOCKS_PER_SEC;
	std::cout << "Executed time for defined memcpy_: " << sec << " s\n";
	// using library memcpy
	time = std::clock();
	std::memcpy(des, arr, 10000);
	time = std::clock() - time;
	sec = (float) time / CLOCKS_PER_SEC;
	std::cout << "Executed time for library memcpy_: " << sec << " s\n";
	// print result
	return 0;
}	// end  main 


// FUNC DEFINE

// memcpy
char *memcpy_(char *des, char *src, std::size_t size) {
	register char *desR = des;
	// allocate mem for desR
	desR = new char [size];
	register char *srcR = src;
	register long i = 0;
	for ( ; i < size; i ++ ) {
		// copy a byte
		*(desR) = *(srcR);
		// move to next byte
		desR += 1;
		srcR += 1;
	}	// close for
	return desR;
}	// close memcpy_


// read data
char *read_data(char const *fileName) {
	std::ifstream file(fileName);
	// check if being able to open file
	if (!file.is_open()) {
		std::cerr << "Unable to open file: " << fileName << "\n";
		exit(-1);
	}	// close if
	// read file
		// count number of bytes
	file.seekg(0, file.end);
	long count = file.tellg();
	file.seekg(0, file.beg);
		// allocate mem
	char *arr = new char [count];
	file.read(arr, count);
	return arr;
}	// close read_data