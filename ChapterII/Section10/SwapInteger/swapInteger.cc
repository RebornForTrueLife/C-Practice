/********************************************
 * swapInteger - swap 2 integers
 * Uage: 
	- run the object file
	- enter 2 integers
	- the program will swap the values of 2 integer and 
	print out the result
 ********************************************/

#include <iostream>

// MACRO
// a macro to swap 2 integers
#define SWAP_INT(a, b)	{ 	( (a) = ( (a) + (b) ) );\
				( (b) = ( (a) - (b) ) ); \
				( (a) = ( (a) - (b) ) ); \
			}	// end SWAP_INT


// Main
int main(int argc, char const *argv[]) {
	int int1, int2; 		// 2 input integers
	// print instruction of the program
	std::cout << "The program is used to sap 2 integers\n";
	// Ask user to enter 2 integers
	std::cout << "Please enter 2 integers: ";
	std::cin >> int1;
	std::cin >> int2;
	// Swap the values of 2 integers
	SWAP_INT(int1, int2);
	// Print out the values of 2 integers
	std::cout << "2 integers in order are: " << int1 << " " << int2 << "\n";
	return 0;
}	// end  main 