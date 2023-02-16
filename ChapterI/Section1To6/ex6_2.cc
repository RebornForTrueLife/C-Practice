/********************************************
 * gradeLetter - convert numeric grade into alphabetic grade
 * 
 * Uage - run file: gradeLetter 
 * 		- enter grade in integer number from 0 - 100
 * 		- the program will print out the alphabetic grade
 ********************************************/


#include <iostream>


// function to convert grade
char numberToLetter(short int grade) {		// grade is a number from 0 - 100
	char letter;		// cooresponding grade in letter
	// if grade <= 60 	   : F
	if (grade <= 60)
		letter = 'F';
	// if grade [61 .. 70] : D
	else if (grade <= 70)
		letter = 'D';
	// if grade [71 .. 80] : C
	else if (grade <= 80)
		letter = 'C';
	// if grade [81 .. 90] : B
	else if (grade <= 90)
		letter = 'B';
	// if grade > 90 	   : A
	else
		letter = 'A';

	// return the letter
	return letter;
}	//end numberToLetter


// enter numeric grade, convert and print out alphabetic grade
int main(int argc, char const *argv[]) {
	short int grade;		// numeric grade

	std::cout << "A program to convert numeric grade to alphabetic grade\n";

	// ask user to enter numeric grade
	std::cout << "Enter grade in number: ";
	std::cin >> grade;

	// convert and print out the alphabetic grade
	std::cout << grade << " is equal to " << numberToLetter(grade) << "\n";
	return 0;
}	// end  main 