/********************************************
 * KpH2MpH - convert kilometer/hour to mile/hour
 * 
 * Uage - run object file
 * 		- enter a double number in Km/H 
 * 		- program will return equal number in Mile/Hour
 ********************************************/


#include <iostream>

const double ALPHA = 0.6213712;


// function to convert km/h to mile/h
double convertKpH2MpH(double kph) {
	return kph * ALPHA;		// formula: Miles = Kilometers * ALPHA
}	//end convertKpH2MpH


int main(int argc, char const *argv[])
{
	double kph; 		// km/h

	std::cout << "Program to convert km/h to mile/h\n";
	std::cout << "Enter double number with unit km/h: ";		// ask user to enter number in km
	std::cin >> kph;

	// convert and print result
	std::cout << kph << " Km/H = " << convertKpH2MpH(kph) << " miles/h\n";
	return 0;
}


