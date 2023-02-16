/********************************************
 * e - print out E by astericks * with 7 chars high and 5 chars wide
 * 
 * Usage - run the program then it will print out character E
 * 
 ********************************************/


#include <iostream>


// print [length] number of char [c] in one line 
// and go to new line
void printCharWithLength(char c, int length) {
	for (int i = 0; i < length; i++) {
		std::cout << c;
	}	// end for
	std::cout << "\n";
}	// end printCharWithLength


int main(int argc, char const *argv[]) {
	// print 7 lines because of 7 chars high
	printCharWithLength('*', 5);		// print line 1
	printCharWithLength('*', 1);		// print line 2
	printCharWithLength('*', 1);		// print line 3
	printCharWithLength('*', 5);		// print line 4
	printCharWithLength('*', 1);		// print line 5
	printCharWithLength('*', 1);		// print line 6
	printCharWithLength('*', 5);		// print line 7
	return 0;
}	// end main