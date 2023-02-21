/********************************************
 * averageNumber - print out the average of a float series
 * Uage: 
	- run the program
	- enter the size of series
	- enter the series 
	- the program will print out the average the series
 ********************************************/

#include <iostream>

int main(int argc, char const *argv[]) {
	int number; 			// the size of series
	float value; 				// value of each float of series
	float average = 0;	// the average of the series
	// ask user to enter the size of the series
	std::cout << "Please enter the size of the float series: "; 
	std::cin >> number;
	// Pronpt to user to enter the series
	std::cout << "Please enter the seiries: ";
	// take sum for each float entered
	for (int i = 0; i < number; i++) {
		std::cin >> value;
		average += value;
	}	// close for
	// take average of sum by dividing the size of the series
	average /= number;			
	// Print out the result
	std::cout << "The average value = " << average << "\n";
	return 0;
}	// end  main 
