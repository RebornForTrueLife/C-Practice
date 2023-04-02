/********************************************
 * busySignal - define a func to check if 2 classes are
 * using the shared file
 * Uage: 
	- run the object file
	- the program will print the service of this program
 ********************************************/

#include <iostream>
#include <string>


// MODE
#define CODING		// coding mode
// #undef CODING		// turn off 


// CONST
const std::string FILE_NAME = "data.txt";	// file name


// DECLARE CLASS
// first class to demo using shared files
class ClassOne {
private:
	std::string file;		// name of shared file
	static int count;		// number of objects existing

public:
	// constructor to initialize file and count
	ClassOne(void);

	// check if any objects using the file
	static int check_usage(void);
};	// close ClassOne

// second class to demo shared file
class ClassTwo {
private:
	std::string file;		// name of shared file
	static int count;		// number of objects existing

public:
	// constructor to initialize file and count
	ClassTwo(void);

	// check if any objects using the file
	static int check_usage(void);
};	// close ClassTwo


// DECLARE FUNC
/*	check(void)
	- to check if either of 2 classes is using the file
	- Input: none
	- Output: 
		1. 1 if file is being used
		2. 0 if file is not being used*/
int check(void);


// main
int main(int argc, char const *argv[]) {
	// print the program service
	std::cout << "The program is used to define a function to check if "
				<< "any classes are using the same shared file\n";
	// CODING mode
	#ifdef CODING
		// ClassOne one;
		// check if either of 2 classes is using the file
		if (check() == 1)		// file is busy
			std::cout << "File is being used\n";
		else
			std::cout << "File is available right now!\n";
	#endif	// CODING

	return 0;
}	// end  main 


// IMPLEMENT

// CLASSONE
// Initialize static variable
int ClassOne::count = 0;

/*	ClassOne:: constructor
	- to initialize file and count*/
ClassOne::ClassOne(void) {
	// increase the number of obj
	count += 1;
	// initialize file
	file = FILE_NAME;
}	// close constructor

/*	ClassOne:: check_usage(void)
	- a static func to check if any object is using the file
	- Input: void
	- Output: 
		1. 1 if file is being used
		2. 0 if file is not being used*/
int ClassOne::check_usage(void) {
	if (count == 0)		// NO object exist
		return 0;
	// if there is object existing, the file is being used
	return 1;
}	// close check_usage


// CLASSTWO
// Initialize static variable
int ClassTwo::count = 0;

/*	ClassTwo:: constructor
	- to initialize file and count*/
ClassTwo::ClassTwo(void) {
	// increase number of obj
	count += 1;
	// initialize file
	file = FILE_NAME;
}	// close constructor

/*	ClassTwo:: check_usage(void)
	- a static func to check if any object is using the file
	- Input: void
	- Output: 
		1. 1 if file is being used
		2. 0 if file is not being used*/
int ClassTwo::check_usage(void) {
	if (count == 0)		// NO object exist
		return 0;
	// if there is object existing, the file is being used
	return 1;
}	// close check_usage


// FUNC DEFINE
// to check if file is being used 
int check(void) {
	if (ClassOne::check_usage() == 1)
		return 1;
	if (ClassTwo::check_usage() == 1)
		return 1;
	// pass 2 check, the file is not being used
	return 0;
}	// close check