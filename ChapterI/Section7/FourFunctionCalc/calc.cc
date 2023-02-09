/********************************************
 * calc - provide user a four-function calcul
 * 
 * Uage - Run the program
 * 		- Result initially set to 0
 * 		- Enter an operator and number
 * 		- the program will calculate and display the Result
 * 		- Press 'q' to exit
 * 
 * More details is in "specification" file
 ********************************************/


#include <iostream>


// Function to take an error message and print out the error
void raiseError(char * errorMessage) {
	std::cout << "ERROR: " << errorMessage << "!\n";
}	//end raiseError


// Function that take the: current result, an operator, and number
// and return the result 
int calculate(int result, char op_char, int number) {
	// First prototype: do for only addition operation
	// if operation is +
	if (op_char == '+') 
		result += number;
	// else raise ERROR
	else
		raiseError("Unknown operator");

	return result;
}	//end calculate


// Main, where the program display, ask user, and print result
int main(int argc, char const *argv[]) {
	// Declare result, operator and number
	int result;		// the result of the calculation
	char op_char;	// operator character
	int number;		// the second operands of the calculation

	// Initially display result = 0
	result = 0;
	std::cout << "RESULT:\t" << result << "\n";

	// Loop until user want to exit - typing 'q'
	while (1) {
		// Ask user for an operator and number
		std::cout << "Enter an operator and number: ";
		std::cin >> op_char;	// enter operator
		// when user want to exit 
		if (op_char == 'q') {
			std::cout << "Calculator shutdown, have a nice day sir!\n";
			break;
		}	// end if
		std::cin >> number;		// enter number
		// Do the calculation
		result = calculate(result, op_char, number);
		// Display the result
		std::cout << "RESULT\t" << result << "\n";
	}	// end while

	return 0;
}	// end  main 