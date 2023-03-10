/********************************************
 * checkDigit - check if a character is a hex-digit
 * Uage: 
	- run the object file
	- enter a character
	- the program will  print out the check if 
	the char is a digit, a hex-digit
 ********************************************/

#include <iostream>

// MACRO
// a macro to check if a char is a digit [0..9]
#define IS_DIGIT(c)	( ((c) >= 48) && ((c) <= 57) )	// end macro
// a macro to check if a char is a hex-digit [0..9] [a..f] [A..F]
#define IS_HEX(c)	( ( ((c) >= 65) && ((c) <= 90) ) || \
						( ((c) >= 97) && ((c) <= 122) ) || \
						IS_DIGIT(c) )		// end macro


// Main
int main(int argc, char const *argv[]) {
	char c;		// input char
	// print the instruction of the program
	std::cout << "The program is used to check if a char is a hex-digit\n";
	// Ask user to enter the character
	std::cout << "Please enter a char: ";
	std::cin >> c;
	// Check if c is a digit or a hex-digit
	if (IS_HEX(c) == true) 	// if c is a hex-digit
		std::cout << c << " is a hex-digit\n";
	else			// c is not a digit
		std::cout << c << " is NOT a hex-digit\n";
	return 0;
}	// end  main 