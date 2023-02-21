/********************************************
 * multiplicationTable - print the multiplication table given the greatest number
 * Uage: 
	- run the program
	- enter the greatest number of the table
	- the program will print out the multiplication number
 ********************************************/

#include <iostream>

// Procedure to print out the multiplication of the table
void printMulTable(int size) {
	// print the first line of the table
	std::cout << '\t';
	for (int number = 1; number <= size; number ++) 
		std::cout << number << '\t';
		// close for
	std::cout << '\n';			// go to next line
	// print each row in the table
	for (int row = 1; row <= size; row ++) {
		std::cout << row << '\t';
		for (int number = 1; number <= size; number ++) 
			std::cout << row * number<< '\t';
			// close for
		std::cout << '\n';			// go to next line
	}	// close for
}	// end printMulTable

int main(int argc, char const *argv[]) {
	// print the instruction of the program
	std::cout << "The program is used to print out the nultiplication table\n";
	std::cout << "Please enter the greatest number of the table: ";
	int size;  		// the greatest number of the table
	std::cin >> size;
	// print out the table
	printMulTable(size);
	return 0;
}	// end  main 