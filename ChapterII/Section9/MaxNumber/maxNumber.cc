/********************************************
 * maxNumber - find the maximum value of a float array
 * Uage: 
	- run the object file
	- enter the size of the array: an positive  integer
	- enter the array
	- The program will print out the maximum value of the array
 ********************************************/

#include <iostream>
#include <limits>

// get minimum value for float type
const float MIN_FLOAT = std::numeric_limits<float>::min();

// Main
int main(int argc, char const *argv[]) {
	int size;				// array size
	float value;			// value array's element
	float maxValue = MIN_FLOAT;		//  max value of the array
	// print the instruction of the program
	std::cout << "The program is used to find the maximum value of "
				<< "a float array\n";
	// Ask user to enter the size of the array
	std::cout << "Please enter the size of the float array: ";
	std::cin >> size;
	// Ask user to enter the array
	std::cout << "Please enter the array: ";
	for (int i = 0; i < size; i++) {
		std::cin >> value;			// get the element
		if (maxValue < value)		// find the max value
			maxValue = value;
	}	// close for
	// print out the max value
	std::cout << "The maximum value of the array is: " << maxValue << "\n";
	return 0;
}	// end  main 