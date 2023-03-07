/********************************************
 * hashCode - generate a hash code for given string
 * Uage: 
	- run the object file
	- enter the string
	- the program will compute and print out the hash code of 
	the string
 ********************************************/

#include <iostream>
#include <string>

// FUNCTION DECLARE
/*A function to compute hash code of a string by summing 
all characters in the string
	- Input: a string
	- Output: the hash code of the string*/
int computeHash(std::string inputString);


// Main
int main(int argc, char const *argv[]) {
	std::string inputString;			// the input string
	int hashCode = 0;				// the hash code of string
	// print the instruction of the program
	std::cout << "The program is used to compute hash code of the"
					<< " input string\n";
	// Ask user to enter the string
	std::cout << "Please enter the string: ";
	std::getline(std::cin, inputString);
	// compute hash code of the string
	hashCode = computeHash(inputString);
	// print the result
	std::cout << "Hash code of the string: " << hashCode << "\n";
	return 0;
}	// end  main 


// function to compute the hash code of the  given string
int  computeHash(std::string inputString) {
	int hashCode = 0;			// hash code of string
	std::string::iterator it;		// a interator for reading string
	// reading each char in the string
	for (it = inputString.begin(); it != inputString.end(); it ++) 
		hashCode += *it;		// add each char to hashCode
	// return value
	return hashCode;
}	//end computeHash
