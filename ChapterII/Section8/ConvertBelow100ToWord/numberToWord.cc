/********************************************
 * numberToWord - convert a non-negative number in to words
 * Uage: 
	- run the object file
	- enter a non-negative number
	- the program will print convert the number into word of each digit
 ********************************************/

#include <iostream>
#include <string>

// Array to convert index number to word by its correspondind element value
const std::string NUMBER_WORD[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
// a global integer array to hold the return value
const int MAX_SIZE = 11;			// size of the arrayReturn
int arrayReturn[MAX_SIZE];


// Function to convert a non-negative number to array of its digits: [arrayReturn]
// return array format: [element 0] = number of digits in the number
//// digits in number will be stored in the last of the array 
//// in left to right order
int* convertNumberToArray(int number) {
	int index = MAX_SIZE - 1; 		// last index of return array
	// take each digit of the number and put it into the array
	while (1) {
		int lastDigit = number % 10; 		// take last digit of number
		arrayReturn[index] = lastDigit;	// put digit into array
		index --;										// move index to next digit location
		number /= 10;								// remove last index from number
		if (number == 0) 							// when number is empty
			break;										// end loop
	}	// close while
	int numberDigit = MAX_SIZE - 1 - index; 		// number digits in the number
	arrayReturn[0] = numberDigit;							//// put it in to first element of array
	// return array
	return arrayReturn;
}	//end convertNumberToArray


// Function to convert an array in format of [arrayReturn] 
// // to a string of words corresponding to the digits in the array
std::string convertArrayToString(int * array) {
	std::string word; 			// an empty string to hold the return value
	int size = array[0];		// number of digits in the number
	int index = MAX_SIZE - size;		// the first digit location in the array
	// convert each digit in array to word
	for (index; index < MAX_SIZE; index ++) {
		int digit = array[index];							// the digit of number
		word += NUMBER_WORD[digit] + " "; 		// the word corresponding to the digit
	}	// close for
	return word; 
}	//end convertArrayToString


// main
int main(int argc, char const *argv[]) {
	int number;			// input number
	// print instruction about the program
	std::cout << "The program is used to convert a non-negative integer into words of its digits\n";
	// ask user to enter the number
	std::cout << " Please enter the number: ";
	std::cin >> number;
	// validate the number
	if (number < 0) {
		// print error
		std::cout << "The number must be a non-negative integer... Have a nice day~\n";
		return 1;			// exit 
	}	// close if
	// convert the number to array of digits
	convertNumberToArray(number);
	// convert array of digits into string
	std::string word = convertArrayToString(arrayReturn);
	// print out the result
	std::cout << number << " : " << word << "\n";
	return 0;
}	// end  main 