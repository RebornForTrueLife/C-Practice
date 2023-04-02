/********************************************
 * zeroOut - to set all elements in an integer array to 0
 * Uage: 
	- run object file
	- enter the size of array
	- enter the array
	- the program will set all element in given array
	to 0
 ********************************************/

#include <iostream>


// FUNC DECLARE
// to set all elements in given array to 0
void set_zero(int *array_, int size);


// main
int main(int argc, char const *argv[]) {
	int size;		// size of array
	int *array;
	std::cout << "The program is used to set all elements in given array to 0\n";
	// ask user to enter the size of array
	std::cout << "Please enter the number integer of the array: ";
	std::cin >> size;
	// allocate memory for the number of integer of the array
	array = new int [size];
	// ask user to enter array
	std::cout << "Please enter the array: ";
	for (int i = 0; i < size; i++ ) {
		std::cin >> *(array + i);
	}	// close for
	// zero out array
	set_zero(array, size);
	return 0;
}	// end  main 


// FUNC DEFINE
/*	set_zero(int*, int)
	-  to set all elements in an array to 0
	- input: the array address and the size of array
	- output: zero out the array and prompt to user*/
void set_zero(int *array_, int size) {
	int count = 0; 	// a count for iterating
	while (true) {
		// set element to 0
		*array_ = 0;
		// increase array pointer
		array_ += 1;
		// increase counter
		count += 1;
		// end loop when set all elements
		if (count >= size)
			break;
	}	// close while
	// prompt to user
	std::cout << "The array is set to 0\n";
}	// close set_zero	