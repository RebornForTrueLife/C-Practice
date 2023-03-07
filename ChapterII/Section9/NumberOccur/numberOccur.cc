/********************************************
 * numberOccur - count number of times a given number
 * appears in a given array
 * Uage: 
	- run the object file
	- enter the size of the array
	- enter the list of integer elements in the array
	- enter the integer number that is needed to count
	- the program will return the number of times the number
	apears in the array
 ********************************************/

#include <iostream>

const int MAX_SIZE = 32767;			// max size of array


// FUNCTION DECLARE
/*A funtion to count the number of times a given number appears
in the given array with a given size
- Input: a number, an array, the size of the array
- Output: the number of times the number appears in the array*/
int countOccur(int number, int * array, int size);


// Main
int main(int argc, char const *argv[]) {
	int size; 		// array size
	int number;	// the counting number
	int array[MAX_SIZE];		// the array, given max_size
	int count = 0; 			// the number of occurence of the array
	// print the instruction of the program
	std::cout << "The program is used to count the occurence of a given number in a given array with the given size\n";
	// Ask user to enter size of array
	std::cout << "Please enter the size of the array: ";
	std::cin >> size;
	// Ask user to enter the array
	std::cout << "Please enter the list of elements: ";
	for (int i = 0; i < size; i++) {
		std::cin >> array[i];
	}	// close for
	// Ask user to enter the number
	std::cout << "Please enter the number: ";
	std::cin >> number;
	// count the occurence of number in the array
	count = countOccur(number, array, size);
	// print out the result
	if (count == 0)			// if the number does NOT appear in the array
		std::cout << "Number: " << number << " does NOT appear in the array\n";
	else
		std::cout << "Number: " << number << " appears " << count 
						<< " times in the array\n" ;
	return 0;
}	// end  main 


// function to count the occurence of a number in the given array
int countOccur(int number, int* array, int size) {
	if (size == 0) 			// end point
		return 0;
	else {
		if (number == array[size - 1]) 		// if number is the last element of current array
			// plus 1 to the result and count for next sub array
			return 1 + countOccur(number, array, size - 1);
		else		// number is NOT the last elements
			// (plus 0 to result) and count for next sub array
			return countOccur(number, array, size - 1);
	}	// close if
}	//end countOccur
