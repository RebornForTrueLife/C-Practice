/********************************************
 * Set - define a class Set to hold a range of integer
 * Uage: 
	- use the class in file
	- or run the object file
	- The program will print out the services of Set
 ********************************************/

#include <iostream>

// MODE
#define CODING		// coding mode
// #undef CODING		// turn off code mode

// CONST
const int SIZE = 32;	// pre-set range of set

// CLASS
class Set {
private:
	int array[SIZE];		// array to hold state of int in set(equal to index)
	int size; 			// range of set: 0 .. size - 1

	// to check if a number is in set's range
	bool check(int number);

public:
	// to initialize array and size
	Set();

	// ~Set();		// let destructor default

	// to active an integer in the set
	void set(int number);

	// to deactive an integer in the set
	void clear(int number);

	// to check if an integer in the set is active
	int test(int number);
};	// close Set


// main
int main(int argc, char const *argv[]) {
	// print the services of Set class
	std::cout << "The program defines a class: Set\n";
	std::cout << "Set is used to store set of integer in range[0..31]\n";
	std::cout << "\t1. Set an integer to the set; only valid integer will be set.\n";
	std::cout << "\t2. Clear an integer out the set; only valid integer will be cleared.\n";
	std::cout << "\t3. Test an integer if it is in the set.\n";
	// coding mode
	#ifdef CODING
		Set set;
		set.set(1);
		set.set(-33);
		set.clear(1);
		set.set(4);
		set.test(5);
	#endif // CODING
	return 0;
}	// end  main 


// /////// IMPLEMENT

/*	Set:: constructor
	- initialize all elements of array to 0
	- initialize size with pre-set SIZE*/
Set::Set() {
	size = SIZE;
	for (int i = 0; i < size; i ++) {
		array[i] = 0;
	}	// close for
}	// close constructor


/*	Set:: set(int)
	- to set an integer to the set; 
	- Input: the integer
	- Output: 2 cases:
		1. Integer is valid: Set 1 to corresponding integer(index) in the array
		2. Integer is not valid: raise waning */
void Set::set(int number) {
	if (check(number) == false) {
		// raise warning
		std::cout << number << " is not valid!\n";
	} else {
		// set the number state
		array[number] = 1;
		// promt to use
		std::cout << number << " is set!\n";
	}	// close if
}	// close set


/*	Set:: clear(int)
	- to clear an integer out of the set
	- Input: an integer
	- Output: 2 case:
		1. The integer is valid: set the array with index is number to 0
		1. The integer is not valid: raise warning*/
void Set::clear(int number) {
	if (check(number) == false) {
		// raise warning
		std::cout << number << " is not valid!\n";
	} else {
		// clear the number state
		array[number] = 0;
		// promt to user
		std::cout << number << " is clear!\n";
	}	// close if
}	// close clear


/*	Set:: test(int)
	- to check if an integer is set in the set
	- Input: an integer
	- Output: 2 cases
		1. if the integer is valid:
			- if integer is set: return 1
			- if integer is Not set: return 0
		2. if the inteer is not valid
			> raise warning*/
int Set::test(int number) {
	if (check(number) == false) {
		// raise warning
		std::cout << number << " is not valid!\n";
		return -1;
	}	// close if
	// prompt to user
	if (array[number] == 1) 
		std::cout << number << " is set!\n";
	else
		std::cout << number << " is Not set!\n";
		// close if 
	return array[number];
}	// close test


/*	Set::check(int)
	- to check if an integer is in the range of set*/
bool Set::check(int number) {
	if (number < 0 )
		return false;
	if (number >= size)
		return false;
	// if passed all cases
	return true;
}	// close check