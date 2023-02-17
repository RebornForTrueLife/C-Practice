/********************************************
 * primeCheck - a program to check if a number is a prime
 * Uage - run the object file
 * 			- enter an integer
 * 			- the program will print out if the number is a prime or not
 ********************************************/

#include <iostream>
#include <math.h>


// Fucntion to check if an integer is a prime
bool checkPrime(int number) {
	// a prime has to be greater than 1
	if (number <= 1)
		return false;
	// a prime must not be product of 2 smaller natural number
	// so check from 2 to square root of number
	for (int count = 2; count <= int(std::sqrt(number)); count++) {
		if (number % count == 0) 			// check if number is divisible by any smaller numbers
			return false;							// if true, it's not a prime
	}	// close for
	// after the number pass through 2 conditions of a prime
	// it's a prime
	return true;
}	//end checkPrime


// main
int main(int argc, char const *argv[]) {
	int number;			// the integer want to check
	// Tell user what this program does
	std::cout << "The program is used to check if a number is a prime\n";
	// Ask user to enter an integer
	std::cout << "Please enter an integer: ";
	std::cin >> number;
	// check and print out the result
	if (checkPrime(number) == true) 
		std::cout << number << " is a prime\n";
	else
		std::cout << number << " is not a prime\n";
	return 0;
}	// end  main 