/********************************************
 * splitInt - split an integer into eight 4-bit values
 * Uage: 
	- run the object file
	- enter an integer
	- the program will print the list of 4-bit values split
 ********************************************/

#include <iostream>
#include <bitset>

// MODE
#define CODING		// signal of coding mode

// CONST DECLARE
const int SIZE = 8;

// FUNCTION DECLARE
/*a function to split an long integer into eight 4-bit values 
into an array
	- input: an integer
	- output: put list of 4-bit values into the input array*/
void split_int(int* array, const long int number);


// main
int main(int argc, char const *argv[]) {
	long int number;		// the input long int number
	int array[SIZE];		// result array
	// print the instruction of the program
	std::cout << "The program is used to split an integer into "
				<< " eight 4-bit values\n";
	// ask user to enter the integer
	std::cout << "Please enter an integer: ";
	std::cin >> number;		
	#ifdef CODING
		std::bitset<32> binaryNumber(number);	// binary form of number
		// Print binary form of input number
		std::cout << "Number in binary: " << binaryNumber << "\n";
	#endif	// CODING
	// Splitting the number
	split_int(array, number);
	// print out the array, size = 8
	for (int i = 0; i < SIZE; i++ ) 
		std::cout << array[i] << "\t" ;
	std::cout << '\n';
	return 0;
}	// end  main 


// function to split an integer into 4-bit values
void split_int(int* array, const long int number) {
	int pb = 0;  	// position current bit
	// for each chunk of 4-bits
	for  (int chunk = 0; chunk < SIZE; chunk ++) {
		pb = chunk * 4;			// current bit
		int byteHolder;			// a byte to hold value of a chunk
		// check the sign bit
		if ( (number & ( 0x80000000 >> pb )) != 0 ) 	// sign - bit is 1
			byteHolder = - 0x1; 	// byte is -1
		else 	// sign-bit is 0
			byteHolder = 0x0;
			// close if
		// set next 3 bit into last 3 bit in byte
		for (int i = 1; i < 4; i ++) {
			if (	( number & ( 0x80000000 >> (pb + i) ) )  != 0	)  // if the bit set
				byteHolder |= ( 0x8 >> i );
			else 		// the bit is not set
				byteHolder &= ~( 0x8 >> i );
		}	// close for 1
		// put value into array
		array[chunk] = byteHolder;
	}	// close for
}	// end split_int
