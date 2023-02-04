/********************************************
 * baseTest - test octal and hexadecimal base 
 ********************************************/


#include <iostream>


int main(int argc, char const *argv[]) {
	long int zip;		// zip code
	zip = 02137L;		// zip value is octal-based

	std::cout << "zip = " << zip << "\n";		// print out zip on the terminal

	int value = 1; 		// an int for testing for operations
	std::cout << + (value++ *3) + (value++ * 5) << '\n';
	return 0;
}	// end  main 