/********************************************
 * shiftBit - shift all set bit in a number to the left end
 * Uage: 
	- run the object file
	- enter an integer number
	- the program will print out the number after being
	shifted
 ********************************************/

#include <iostream>
#include <bitset>

// MODE
#define CODING		// coding mode
// #undef CODING

// CONST
const int SIZE_INT = 16;

// FUNCTION DECLARE
/*A function to shift all set bit of the given number 
to its left end
	- Input: a number
	- Output: the number after being shifted*/
int shift_bit(const int number);


// main
int main(int argc, char const *argv[]) {
	int number; 	// the input number
	int result = 0;		// the number after being shifted
	// print the instruction of the program
	std::cout << "The program is used to shift all set bit" 
				<< " to the left end of a given number\n";
	// ask user to enter the number
	std::cout << "Please enter an integer: ";
	std::cin >> number;
	// shift bit in the number
	result = shift_bit(number);
	// print result
	std::cout << "The number after being shifted is: " << result << "\n";
	#ifdef CODING
		std::bitset<SIZE_INT> biNumber(number);
		std::bitset<SIZE_INT> biResult(result);
		std::cout << "Number in binary: " << biNumber << "\n";
		std::cout << "Result in binary: " << biResult << "\n";
	#endif	// end CODING
	return 0;
}	// end  main 


// function to shift all set bit to the left end of a number
int shift_bit(const int number) {
	int result = 0x0000;		// the number after being shifted
	int pos = 0;			// the position point to current bit of result
	// go through each bit in number
	for (int bit = 0; bit < SIZE_INT; bit ++) 
		// if bit is set
		if ( (number & (0x8000 >> bit)) != 0 ) {
			result |= (0x8000 >> pos);	// set bit at pos of result
			pos += 1;				// go to next bit in resutl
		}	// close if
		// close for
	return result;
}	//end shift_bit
