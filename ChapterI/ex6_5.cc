/********************************************
 * leapYear - tell that if a year is a leap year or not
 * 
 * Uage - run leapYear file
 * 		- enter a particular year, an integer
 * 		- program will tell if the year is a leap year or not
 ********************************************/


#include <iostream>


// function that check if a year is a leap year
// a leap year is any year divisible by 4 
// unless it is divisible by 100, but not 400
bool checkLeapYear(short int year) {
	bool result = false; 		// result of the check, initial is false - not a leap year
	// check if year is divisible by 4
	if (year % 4 == 0) {
		// if yes, check if it is divisible by 100
		if (year % 100 == 0) {
			// if yes, check if it divisible by 400
			if (year % 400 == 0)
				// if yes, it's a leap year
				result = true;
		} else // else yes
			result = true;
	}	// end if
		
	return result;
}	//end checkLeapYear

// enter year, check and print the result
int main(int argc, char const *argv[]) {
	std::cout << "A program to check if a year is a leap year or not\n";
	short int year;		// the year need to be check
	bool result; 		// the result after check

	// ask user to enter the year
	std::cout << "Enter year: ";
	std::cin >> year;

	// check and print out the result
	result = checkLeapYear(year);
	if (result == true)
		std::cout << year << " is a leap year\n";
	else
		std::cout << year << " is not a leap year\n";

	return 0;
}	// end  main 