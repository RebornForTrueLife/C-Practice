/********************************************
 * replaceChar - replace '-' with '_' in a given string
 * Uage: 
	- run the object file
	- enter a string
	- the program will replace '-' with '_' in the input string
	and print out the replaced string
 ********************************************/

#include <iostream>
#include <string>

// FUNCTION DECLARE
/*a function to replace '-' with '_' in a given string
	- input: a string
	- output: the string after being replaced*/
std::string replaceChar(std::string inputString);


// Main
int main(int argc, char const *argv[]) {
	std::string inputString;		// the input string
	// print the instruction of the program
	std::cout << "The program is used to replace '-' with '_' in the input string\n";
	// Ask user to enter the string
	std::cout << "Please enter the string: ";
	std::getline(std::cin, inputString);
	// get replaced string
	inputString = replaceChar(inputString);
	// print out the result
	std::cout << "The replaced String: " << inputString << "\n";
	return 0;
}	// end  main 


// function to replace '-' with '_' in the given string
std::string replaceChar(std::string inputString) {
	std::string::iterator it;		// an iterator for reading inputString
	// read each char
	for (it = inputString.begin(); it != inputString.end(); it++) 
		if (*it == '-')
			*it = '_';
		// close for
	return inputString;
}	//end replaceChar
