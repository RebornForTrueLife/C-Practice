/********************************************
 * countWord - count number of words in a string
 *  A word is a segment of adjacent letters, which are number or in alphabet
 *  Except for ' and - : cuz some word may contain them: I'm, ice-scream... 
 *  they are counted as 1 word
 * Uage: 
	- run the object file
	- enter a string
	- the program will print out the number of words in that string
 ********************************************/

#include <iostream>
#include <string>

// Const declare
// this array contains characters that is not a letter 
// // but might be included in a word
const char Exception_Char[] = {'\'', '-'};

// FUNCTION DECLARE
/* A Function to count the number of word in a string
	Input: a string
 	Output: the number of words in a string */
int countWord(std::string inputString);
/* A Function check if a character is a letter, which is a number or in alphabet
	Input: a character
	Output: a TRUE if the character is a letter, vice versa */
bool checkLetter(char c);
/* A function to check if a char is in Exception_Char array 
	Input: a character
	Output: a True if the input char is in Exception_Char array, vice versa*/
bool checkExceptChar(char c);

// MAIN
int main(int argc, char const *argv[]) {
	std::string inputString; 		// user input string
	int wordCount = 0;				// number of words in the input string
	// print instruction of the program
	std::cout << "The program is used to count the number of words in the given string\n";
	std::cout << "A word is a segment of adjacent letters, which are number or in alphabetic\n";
	std::cout << "Except for: I'm, ice-scream... is count as 1 word\n";
	// Ask user to enter the string
	std::cout << "Please enter the string: ";
	std::getline(std::cin, inputString, '\n');
	// Count the number of words in the string
	wordCount = countWord(inputString);
	// Print out the result
	std::cout << "Number of words in the given string is: " << wordCount << "\n";
	return 0;
}	// end  main 


// function to count words in the given string
int countWord(std::string inputString) {
	// initialize an itorator of the string
	std::string::iterator it = inputString.begin();
	char currentChar;			// char variable to read the string
	int count = 0;					// counter of word in string
	// read each char of the string
	while(1) {
		if (it == inputString.end())		// if iterator reach the end of string
			break;									// end loop
		currentChar = *it;
		// check if current char is a letter
		if (checkLetter(currentChar) == true) {
			count += 1;			// increment 1 word in counter
			// wordReadingState: a value that show if currentChar is in a word
			bool wordReadingState = true;			// current char is in a word
			// Reading until the current word end
			while (1) {
				if (it == inputString.end())				// if current char is end of string
					break;											// end loop
				if (wordReadingState == false) 		// if current char gets out the word
					break;											// end loop
				// check if currentChar is a letter
				if (checkLetter(currentChar) == false) {
					wordReadingState = false;
					// There are some special cases that not end a word
					if (checkExceptChar(currentChar) == true) {
						// if next char in string is not end_of_string
						if ((it + 1) != inputString.end()) {
							char nextChar = *(it + 1);		// next char in string
							if (checkLetter(nextChar) == true) 	// if nextChar is a letter
								wordReadingState = true;				// means still reading a word
						}	// close if #3
					}	// close if #2
				}	// close inner if
				it +=1; 						// go to next char
				currentChar = *it;
			}	// close inner while
			// back to start of loop, cuz it already go to next char when reading a word
			continue;		
		}	// close if
		// When not reading a word
		it += 1; 			// go to next char
	}	// close while
	return count;		// return the number of word in the string
}	// end countWord


// function to check if a char is a letter
bool checkLetter(char c) {
	// check if c in alphabet
	if ( (c >= 65 && c <= 90) || (c >= 97 && c <= 122) ) 	
		return true;
	// check if c is number
	if ((c >= 48) && (c <= 57))
		return true;
	// other case: c not a letter
	return false;
}	// end checkLetter


// function to check if a char is in Exception_Char array
bool checkExceptChar(char c) {
	// get size of Exception_Char array
	// use byte-size of array and divide to byte-size of element
	int size = sizeof(Exception_Char) / sizeof(char);		
	// check each char in Exception_Char array
	for (int i = 0; i < size; i ++) 
		if (c == Exception_Char[i]) 		// if c is in array
			return true; 							// return true
	// in other case: c is not in array
	return false;
}	// end checkExceptChar
