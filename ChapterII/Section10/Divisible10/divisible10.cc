/********************************************
 * divisible10 - check if the input value is divisible by 10
 * Uage: 
	- run the object file
	- enter a value
	- the program will print out if the value is divisible by 10
 ********************************************/

#include <iostream>
#include <string>

#define DIV10(number) ( (((number) / 10) * 10 == (number)) ) // check if number divisible by 10


// Main
int main(int argc, char const *argv[]) {
	int value;		// the input value
	bool result;				// the result of checking
	// print the instruction of the program
	std::cout << "The program is used to check if a value is divisible by 10\n";
	// Ask user to enter the value
	std::cout << "Please enter the value of the program: ";
	std::cin >> value;
	// check if value is divisible by 10 
	result = DIV10(value);
	// print the check
	if (result == true) 
		std::cout << value << " is divisible by 10\n";
	else
		std::cout << value << " is NOT divisible by 10\n";
		// close if
	return 0;
}	// end  main 
