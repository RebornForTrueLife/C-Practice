/********************************************
 * printCheckboard - print a square check board with a given size
 * Uage - run the program
 * - enter a positive integer, which is the size of the square
 * - the program will print out the checkboard with the given size
 ********************************************/

#include <iostream>


// Procedure to print out the square check board with given size
void printCheckboard(int size) {
	// the number of rows that need to print
	// because each square unit need 5 characters
	int numberRow = 1 + 4 * size; 			
	for (int row = 0; row < numberRow; row ++) {
		if (row % 4 == 0) {				// if row is divisible by 4
			std::cout << "+"; 				// print out the checkboard
			// unitSC - unit square count: print each line for each unit square on a line
			for (int unitSC = 0; unitSC < size; unitSC ++) 
				std::cout << "-----+";
				// close for
		}	else { 							// if row is not divisible by 4
			std::cout << "|"; 				// print out the middle of checkboard
			for (int unitSC = 0; unitSC < size; unitSC ++) 
				std::cout << "     |";
				// close for 
		}	// close if
		std::cout << "\n"; 			// go to next line
	}	// close for
}	//end printCheckboard


// main
int main(int argc, char const *argv[]) {
	int size;  		// size of check board > 0
	// print out the info of the program
	std::cout << "The program is used to print a square check board with a given size\n";
	// Ask user to enter the size of check board
	std::cout << "Please enter the positive integer size of check board: "; 	
	std::cin >> size;
	// Print the check board
	printCheckboard(size);
	return 0;
}	// end  main 