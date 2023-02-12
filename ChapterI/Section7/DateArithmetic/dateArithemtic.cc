/********************************************
 * dateArithmetic - performs some operation wiht dates
 * 
 * Uage - Run object file
 * 		- Choose the wanted operation on date
 * 		- Follow program instruction for that operation
 * 		- The program will print out the result of the operation
 * 
 * More detail is in specification file
 ********************************************/


#include <iostream>


// Function to give instruction for each user choice of operation
void instructor(short int choice);
// Abstract Function to perform each operation
// void operationProcedure() -> abstraction
// Function to validate a date and raise warning if the date is not valid
bool validate(short int * date);
// Function to compare between 2 date, the detail comparison is defined in specification file
short int compare(short int* dateA, short int *dateB);


int main(int argc, char const *argv[]) {
	std::cout << "This program can perform some operations on date that are listed below\n";
	std::cout << "[1] Count number of days between 2 dates\n";
	std::cout << "[2] Print the date after [number] days of a given date\n";
	std::cout << "[3] Print the date before [number] days of a given date\n";

	return 0;
}	// end  main 