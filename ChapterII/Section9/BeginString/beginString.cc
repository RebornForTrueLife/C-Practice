/********************************************
 * beginString - check if the first string begins the second string
 * Uage: 
	- run the object file
	- enter 2 strings
	- the program state out if the first string begins the second string
 ********************************************/

#include <iostream>
#include <string>

// FUNCTION DECLARE
/*
	- The function is used to check whether the first string begins 
	the seconds string or not
	- Input: 2 strings
	- Output: true if the first string begins the second string*/
bool checkBegin(std::string stringA, std::string stringB);

// Main
int main(int argc, char const *argv[]) {
	std::string stringA;		// the first string
	std::string stringB;		// the second string
	// print out the instruction of the program
	std::cout << "The program is used to check if the first string begins the second string\n";
	// ask user to enter 2 string
	std::cout << "Please enter the first string: ";
	std::getline(std::cin, stringA);
	std::cout << "Please enter the second string: ";
	std::getline(std::cin, stringB);
	// check if stringA begins stringB
	bool result = checkBegin(stringA, stringB);
	// Print out the result
	if (result == true) 
		std::cout << "The first string begins the second string\n";
	else
		std::cout << "The first string does NOT begin the second string\n";
	return 0;
}	// end  main 


// function to check if the first string begins the second string
bool checkBegin(std::string stringA, std::string stringB) {
	// check if size of stringA greater than size of string B
	if (sizeof(stringA) > sizeof(stringB))
		return false;			// stringA must be smaller or equal stringB in size
	// find position of string A in string B if it exist
	std::size_t pos = stringB.find(stringA);
	if (pos != 0) 
		return false;			// stringA must be found at index 0 of stringB
	// if string A passes 2 cases
	return true;			// string A begins string B
}	//end checkBegin
