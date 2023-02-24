/********************************************
 * numberToWord - convert a non-negative number <= 100 in to words
 * Uage: 
	- run the object file
	- enter a non-negative number
	- the program will print convert the number into writing form
 ********************************************/

#include <iostream>
#include <string>

// Array to convert index number to word by its correspondind element value
const std::string ONE_WORD[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
// String array of word of number from 10 to 19
const std::string TEEN_WORD[10] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
// String array of word of tens: 20, 30, 40, ... 90
const std::string TEN_WORD[8] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
// the string of 100
const std::string HUNDRED = "one hundred";
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
	// Convert number into word
	// with each case of size
	switch (size) {
		case 1: {						// number has only 1 digit
			int number = array[index];			// get the number
			word = ONE_WORD[number];		// convert to word
			break;
		}
		case 2:	{					// number has 2 digits
			int tensPlace = array[index];			// take tens place of number
			int onesPlace = array[index + 1];		// take last ones place of number
			if (tensPlace == 1) 							// if number is in[10..19]
				word = TEEN_WORD[onesPlace];	// take word from teen-array
			else {									// if number >= 20
				word += TEN_WORD[tensPlace - 2]; 		// because ten-array start from word of 20
				if (onesPlace != 0) 		// if ones place of number != 0
					word += " " + ONE_WORD[onesPlace]; 		// add writing of last digit 
			}	// close else
			break;
		}
		case 3:	{					// number is 100
			word = HUNDRED;
			break;
		}
		default: {
			// Do nothing with other case, so word is empty
			break;
		}
	}	// close case
	// return result
	return word; 
}	//end convertArrayToString


// function to validate input
bool validateInput(int number) {
	bool result = true;
	if ( (number < 0) || (number > 100) ) {
		if (number < 0)					 // if number is negative
			std::cout << "The number must be a non-negative integer\n";
		else if (number > 100) 		// if number > 100
			std::cout << "The number must be smaller or equal to 100\n";
		std::cout << "... Have a nice day~\n";	
		result = false;
	}	// close if
	return result;
}	//end validateInput


// main
int main(int argc, char const *argv[]) {
	int number;			// input number
	// print instruction about the program
	std::cout << "The program is used to convert a non-negative integer (<= 100) into words\n";
	// ask user to enter the number
	std::cout << " Please enter the number: ";
	std::cin >> number;
	// validate the number
	if (validateInput(number) == false) 
		return 1;			// exit 
	// convert the number to array of digits
	convertNumberToArray(number);
	// convert array of digits into string
	std::string word = convertArrayToString(arrayReturn);
	// print out the result
	std::cout << number << " : " << word << "\n";
	return 0;
}	// end  main 