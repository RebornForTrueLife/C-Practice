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
#include <string>


// Function to take an error message and print out the error
void raiseError(std::string errorMessage) {
	std::cout << "ERROR: " << errorMessage << "!\n";
}	//end raiseError


// Function that take the: current result, an operator, and number
// and return the result 
int calculate(int result, char op_char, int number) {
	// First prototype: do for only addition operation
	// if operator is +
	if (op_char == '+') 
		result += number;
	// if operator is -
	else if (op_char == '-')
		result -= number;
	// if operator is *
	else if (op_char == '*')
		result *= number;
	// if operator is /, then have to check the number if it equal to 0
	else if (op_char == '/') {
		if (number == 0)	// can not divide 0, raise error
			raiseError("Can not divide by 0");
		else
			result /= number;
	} // else do nothing, cuz operator is already checked
	

	return result;
}	//end calculate


// Main, where the program display, ask user, and print result
int main(int argc, char const *argv[]) {
	// Declare result, operator and number
	int result;		// the result of the calculation
	char op_char;	// operator character
	int number;		// the second operands of the calculation
	// This buffer is to read the rest of an invalid input
	// so that input doesn't affect other loops
	std::string inputBuffer; 	 

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
		} // if operator is not valid, raise error, 
		  // and goto next loop
		else if ( (op_char != '+') && (op_char != '-') 
					&& (op_char!= '*') && (op_char != '/')) {
			raiseError("Unknown operator");
			std::cin >> inputBuffer;
			continue;
		} 	// end if
		std::cin >> number;		// enter number

		// Do the calculation & display
		result = calculate(result, op_char, number);

		// Display the result
		std::cout << "RESULT\t" << result << "\n";
	}	// end while

	return 0;
}	// end  main 