/********************************************
 * totalParallel - calculate total resistor of the given series of parallel resistors
 * Uage: 
 * 		- run the object file
 * 		- enter the number of resistors in parallel
 * 		- the program will print out the total resistor
 ********************************************/


#include <iostream>


int main(int argc, char const *argv[]) {
	 // Print out the instrution for the program
	std::cout << "The program is used for calculate the total resistor of the given series of resistors in parallel";
	int number; 			// the number of parallel resistor
	float total = 0;		// the total resistor
	float value;				// the value of each parallel resistor
	// Ask user to enter the number of resistor in parallel
	std::cout << "Please enter the number of parallel resistors: ";
	std::cin >> number;
	// Prompt user to enter the series of resistor value
	std::cout << "Please enter the float series of resistors: ";
	// for each value in the series
	for (int count = 0; count < number; count ++) {
		std::cin >> value;
		total += 1 / value;
	}	// close for
	// Calcualte total resistor
	total = 1 / total;
	// print out the result
	std::cout << "Total resistor: " << total << "\n";
	return 0;
}	// end  main 

