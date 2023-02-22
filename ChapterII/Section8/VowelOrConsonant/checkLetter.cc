/********************************************
 * checkLetter - check whether a letter is a vowel, a consonant, or not in alphabet
 * Uage: 
	- run the object file
	- enter a character
	- the program will print whether the character is a vowel, a consonant or not in
	the alphabet
 ********************************************/

#include <iostream>

const char VOWEL_LIST[5] = {'a', 'e', 'i', 'o', 'u'};			// list of vowels
const short int VOWEL_SIZE = 5;						// number of vowels in alphabet


// Function to check whether a given character is a vowel, a consoant, or
// not in alphabet by return 2, 1, 0 respectively
short int check(char c) {
	// check if c is in alphabet: both upper and lower cases
	if ( (c >= 65 && c <= 90)  || (c >= 97 && c <= 122) ) {
		if (c <= 90)			// c is in upper case 
			c += 32;			// convert c into lower case
		for (int i = 0; i < VOWEL_SIZE; i++) 
			if (c == VOWEL_LIST[i])			// if c is a vowel
				return 2;								// then return 2
			// close for
		return 1; 				// cuz c is not in vowel list, so c is a consonant
	}	// close if
	return 0; 					// cuz c is not in alphabet
}	//end check


// main
int main(int argc, char const *argv[]) {
	char c;			// the input character
	// instruction about the program
	std::cout << "The program is used to check if the given letter is a vowel or a consonant\n";
	// ask user to enter a character
	std::cout << "Please enter a letter: ";
	std::cin >> c;
	// check the type of input character
	int result = check(c); 			// the result of checking the character
	switch (result) {
		case 2:  		// which mean the letter is a vowel
			std::cout << c << " is a vowel\n";
			break;
		case 1:			// which mean the letter is a consonant
			std::cout << c << " is a consonant\n";
			break;
		default:			// which mean the letter is not in alphabet
			std::cout << c << " is not in alphabet...have a great day~\n";
	}	// close switch
	return 0;
}	// end  main 