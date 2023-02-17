/********************************************
 * countPosNeg - count the number of positive and  negative values in a series of float numbers
 * Uage - run the object
 * - enter the number of float in the series
 * - enter each float
 * - program will print out the number of positive and negative values in that series
 ********************************************/

#include <iostream>


int main(int argc, char const *argv[]) {
	int size;		 				// the size of the series
	float value;				// the value of element in the series
	int posCount = 0;		// the number of positive values
	int negCount = 0;		// the number of negitive values
	// give instruction to user
	std::cout << "The program is used to count the number of positive and negative values in a series of floats\n";
	// ask user to enter the size of series
	std::cout << "Please enter the number of number in the series: ";
	std::cin >> size;
	std::cout << "Please enter the series of floats: ";
	for (int count = 0; count < size; count++) {
		// enter the current float
		std::cin >> value;
		// if value is positive, 
		if (value > 0) {
			posCount ++;			// positive count + 1
			continue;				// continue for without finishing the current loop
		}	// close if
		// if value is negative
		if (value < 0) 
			negCount ++;			// negative count + 1
	}	// close for
	// print out result
	std::cout << "The number of positive values is: " << posCount << "\n";
	std::cout << "The number of negative values is: " << negCount << "\n";
	std::cout << "Exit... Have a nice day ^^\n";
	return 0;
}	// end  main 