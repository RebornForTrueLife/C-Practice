/********************************************
 * taxAdding.o - return the price after added tax
 * Uage - run the object file
 * 			- enter the amount of price
 * 			- the program will print out the price after added tax
 ********************************************/


#include <iostream>
#include <iomanip>


const float TAX_PERCENTAGE = 0.08;			// percentage of price when adding tax


// Funtion to calculate the price after added tax
float calTaxPrice(float price) {
	float taxPrice;			// the price after added tax
	// calculate tax and added to price
	taxPrice = price * TAX_PERCENTAGE + price;
	// Rounded taxPrice with 2 numbers in fraction part
	// return the result
	return taxPrice;
}	//end calTaxPrice

// Main
int main(int argc, char const *argv[]) {
	float price;			// the original price
	// Instruction to the user
	std::cout << "The program to calculate price after added sales tax\n";
	std::cout << "Default tax percentage is: " << int(TAX_PERCENTAGE * 100 ) << "%\n";
	// Ask user to enter the price
	std::cout << "Please enter the price in $: " ;
	std::cin >> price;
	// calculate and print out the price
	std::cout << std::fixed; 			// use fixed floating point notation
	std::cout << std::setprecision(2);
	// // set 2 precision for the result(nearest penny, 1$ = 100 pennies)
	std::cout << "Price added tax: " << calTaxPrice(price) << "$\n";
	return 0;
}	// end  main 