/********************************************
 * bigHello - print out the HELLO word in big block letters
 * 
 * Usage - run and it print out HELLO
 * 
 * NOTE - I am doing a dump dump way, it can be coded better by using array(but I might lay it later)
 ********************************************/


#include <iostream>


const int SPACE = 4;		// amount of ' ' between each char


// function to print [number] of character [c]
void printCharWithLength(char c, int length) {
	for (int i = 0; i < length; i++) {
		std::cout << c;
	}	// end for
}	// end printCharWithLength


// print space between chars
// space = [number] of char ' '
void printSpace() {
	printCharWithLength(' ', SPACE);
}	// end printSpace


// print 1st line
void printLine1() {
	std::cout << "*   *";			// first line of char: H
	printSpace();
	printCharWithLength('*', 5); 	// E
	printSpace();
	std::cout << "*    ";			// L
	printSpace();
	std::cout << "*    ";			// L
	printSpace();
	std::cout << " *** ";			// O
	std::cout << "\n";  			// end of line
}	// end printLine1


// print 2nd line(3rd, 5th, 6th are the same)
void printLine2() {
	std::cout << "*   *";			// H
	printSpace();
	std::cout << "*    "; 			// E
	printSpace();
	std::cout << "*    ";			// L
	printSpace();
	std::cout << "*    ";			// L
	printSpace();
	std::cout << "*   *";			// O
	std::cout << "\n";  			// end of line
}	// end printLine2


// print 4th line
void printLine4() {
	printCharWithLength('*', 5);	// H
	printSpace();
	printCharWithLength('*', 5);	// E
	printSpace();
	std::cout << "*    ";			// L
	printSpace();
	std::cout << "*    ";			// L
	printSpace();
	std::cout << "*   *";			// O
	std::cout << "\n";  			// end of line
}	// end printLine4


// print 7th line
void printLine7() {
	std::cout << "*   *";			// H
	printSpace();
	printCharWithLength('*', 5);	// E
	printSpace();
	printCharWithLength('*', 5);	// L
	printSpace();
	printCharWithLength('*', 5);	// L
	printSpace();
	std::cout << " *** ";			// O
	std::cout << "\n";  			// end of line
}	// end printFirstLine


// because dont know how to move the cursor to particular position
// So I print each line of the word "HELLO"
int main(int argc, char const *argv[]) {
	printLine1();		// print 1st line
	printLine2(); 		// print 2nd line
	printLine2(); 		// print 3rd line
	printLine4(); 		// print 4th line
	printLine2();		// print 5th line
	printLine2();		// print 6th line
	printLine7();		// print 7th line
	return 0;
}	// end main