/********************************************
 * countSetBit - count the number of set bit in an integer
 * Uage: 
	- run the object file
	- enter an integer
	- the program will print the number of set bit in the given integer
 ********************************************/

#include <iostream>

// FUNCTION DECLARE
/*a function to count the number of set bit in the integer
	- input: an integer
	- output: the number of set bit in the integer*/
int count_set_bit(const int number);


// Main
int main(int argc, char const *argv[]) {
	int number;			// input integer
	int count = 0;		// number of set bit in the input integer
	// print instruction of the program
	std::cout << "The program is used to count the number of set bit in the given integer\n";
	// ask user to enter an integer
	std::cout << "Please enter the integer: ";
	std::cin >> number;
	// count the number of bit in the integer
	count = count_set_bit(number);
	// print the result
	std::cout << "The number of set bit in " << number << " is: " << count << "\n";
	return 0;
}	// end  main 


// function to count the number of set bit in an integer
int count_set_bit(const int number) {
	int count = 0; 		// number of set bit in the integer
	// go through each bit of an integer from the 15th to 0th posotion
	for (int bit = 0x8000; bit > 0; bit = bit >> 1) 
		if ((number & bit) != 0)		// if current bit is set
			count += 1;			// increment count by 1
		// close for
	return count;		// return result
}	// end count_set_bit