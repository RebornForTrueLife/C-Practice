/********************************************
 * changeMoney - change from dollar to number of quarter, dime, nickle, penny
 * 
 * Uage - run changeMoney file
 * 		- enter float number of dollar (have upper limit: 1$)
 * 		- The program will change number of dollar into euqual coins
 ********************************************/


#include <iostream>

const float UPPER_LIMIT = 1.00;


// fucntion to convert dollar to coins 
// 1$ 			= 100 	cents
// 1 quarter 	= 25  	cents
// 1 dime		= 10 	cents
// 1 nickle 	= 5 	cents 
// 1 penny 		= 1 	cent
short int * dollarToCoin(float dollar) {		// money in dollar 	
	// convert dollar to cent (an integer)
	short int cent = dollar * 100;
	// an array of coins: quarter, dime, nickle, penny in cent respectively
	short int coinValue[] = {25, 10, 5, 1};
	// an array to contain number of coins respectively
	static short int numberCoin[4];	// this is a static array because it is the return value
	short int index = 0;			// order of coin type, start with 0: quarter
	short int centLeft = cent;		// the number of cent after divide with one type of coin, initial = start amount

	// take divide of dollar with quarter, dime, nickle penny until get equal change
	while (1) {
		numberCoin[index] = centLeft / coinValue[index];
		centLeft = centLeft % coinValue[index];
		if (centLeft == 0) 		// mean we finish the converting
			break;
		// if still have cent left, we continue
		index++;
	}	// end while

	// return number coin of each coin needed to convert the initial dollar
	return numberCoin;
}	//end dollarToCoin

// enter amount of dollar, convert, print out result
int main(int argc, char const *argv[]) {
	std::cout << "A program to convert dollar to coins: quarter, dime, nickle, penny\n";
	float dollar; 				// amount of money
	short int * numberCoin;	// number of each coin: quarter, dime, nickle, penny respectively

	// ask user to enter amount of dollar less than the UPPER_LIMIT
	std::cout << "Enter a float number is amount of dollar that less than " << UPPER_LIMIT << ": ";
	std::cin >> dollar;

	// convert to coins
	numberCoin = dollarToCoin(dollar);

	// print out the result
	std::cout << dollar << " = ";
	// we dont print out coin type if number of that coin is 0
	if (numberCoin[0] != 0)		// quarter
		std::cout << numberCoin[0] << " quarters ";
	if (numberCoin[1] != 0)		// quarter
		std::cout << numberCoin[1] << " dimes ";
	if (numberCoin[2] != 0)		// quarter
		std::cout << numberCoin[2] << " nickles ";
	if (numberCoin[3] != 0)		// quarter
		std::cout << numberCoin[3] << " pennies";
	std::cout << "\n";

	return 0;
}	// end  main 