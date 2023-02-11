/********************************************
 * unitConverter - convert English units to metric unit
 * 
 * Uage - run object file
 * 		- Choose an unit option by typing corresponding integer
 * 		- Enter the amount in chosen unit
 * 		- The program will print out a number in corresponding metric unit
 ********************************************/


#include <iostream>
#include <string>


// **Declare data**
// Number of units that program can convert
const short int NUMBER_UNIT = 4;			
// List names of English units, first dim for long name
// second dim for short name
std::string engUnitList[NUMBER_UNIT][2];	
// List names of metric
std::string metricList[NUMBER_UNIT][2];		
// List of corresponding factors needed to convert
float factorList[NUMBER_UNIT];


// Function to initialize data 
void initializeData() {
	// The number of units defined by const NUMBER_UNIT
	// 1st unit
	engUnitList[0][0]	= "Pounds Per Square Inch";	// long name english unit
	engUnitList[0][1]	= "psig";					// short name for EU
	metricList[0][0]	= "Kilo Pascals";			// long name for metric
	metricList[0][1] 	= "kPa";					// short name for metric
	factorList[0] 		= 6.897;					// factor to convert psig to kPa

	// 2nd unit
	engUnitList[1][0]	= "Pounds Per Foot^3";		// long name english unit
	engUnitList[1][1]	= "lb/ft3";					// short name for EU
	metricList[1][0]	= "Kilograms Per Meter^3";	// long name for metric
	metricList[1][1] 	= "kg/m3";					// short name for metric
	factorList[1] 		= 16;						// factor needed for convert

	// 3rd unit
	engUnitList[2][0]	= "Foot";		// long name english unit
	engUnitList[2][1]	= "\'";			// short name for EU
	metricList[2][0]	= "Meter";		// long name for metric
	metricList[2][1] 	= "m";			// short name for metric
	factorList[2] 		= 0.305;		// factor needed for convert

	// 4th unit
	engUnitList[3][0]	= "Pound";		// long name english unit
	engUnitList[3][1]	= "lb";			// short name for EU
	metricList[3][0]	= "Kilogram";	// long name for metric
	metricList[3][1] 	= "kg";			// short name for metric
	factorList[3] 		= 0.045;		// factor needed for convert
}	//end initializeData


// Function to print out the list of convertable units
void printUnitList() {
	// Print successively convertable units
	std::cout << "The program can convert english unit to metric in the list below:\n";
	for (int i = 0; i < NUMBER_UNIT; i++) {
		std::cout << "[" << i + 1 << "] ";	// cuz choice start from 1
		std::cout << engUnitList[i][0] << "(" << engUnitList[i][1] << ")";
		std::cout << "\t->\t";
		std::cout << metricList[i][0] << "(" << metricList[i][1] << ")\n";
	}	// end for
	std::cout << "\n";
}	//end printUnitList


// Function that convert english unit to metric
float convertUnit(short int choice, float amount) {
	// choice is an integer start by 1
	// so, it need to -1 to get corresponding index
	// Return amount in metric unit
	return factorList[choice - 1] * amount;
}	// end convertUnit


// Function to ask user enter unit index choice
short int inputChoice() {
	short int choice;
	std::cout << "Enter an corresponding integer to choose unit want to convert: ";
	std::cin >> choice;
	return choice;
}	//end inputChoice


// Function to ask user enter amount in chosen unit
float inputAmount(short int choice) {
	float amount;
	std::cout << "Enter amount in " << engUnitList[choice - 1][1] << ": ";
	std::cin >> amount;
	return amount;
}	//end inputAmount

// Main, where to show program to user
int main(int argc, char const *argv[]) {
	short int choice;		// [index + 1] of particular unit
	float amount;			// number in chosen unit
	float result;			// convert amount in metric unit

	// Fetch data in variable
	initializeData();

	// Print out the convertable unit list
	printUnitList();

	// Ask user to enter choice and amout
	choice = inputChoice();
	amount = inputAmount(choice);

	// Converting
	result = convertUnit(choice, amount);

	// Print out result
	std::cout << amount << " (" << engUnitList[choice - 1][1] << ") = "
				<< result << " (" << metricList[choice - 1][1] << ")\n";
	std::cout << "Thank for your using, have a good day fellow.\n";
	return 0;
}	// end  main 