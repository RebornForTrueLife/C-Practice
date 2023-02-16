/********************************************
 * C2F - a program converts Celsius to Fahrenheit
 * 
 * Uage - run program, enter an float number in Celsius 
 * 		- then it will print the result in Fahrenheit
 ********************************************/


#include <iostream>


int main(int argc, char const *argv[]) {
	float celsiusDegree;		// degree in celsius 
	char degSymbol = 248;		// degree symbol

	std::cout << "Enter degree in Celsius: "; 		// ask user to enter degree
	std::cin >> celsiusDegree;

	// calculate and print the result
	std::cout << "Equal degree in Fahrenheit: " << celsiusDegree * 9 / 5 + 32 << degSymbol <<"F\n";
	return 0;
}	// end  main 