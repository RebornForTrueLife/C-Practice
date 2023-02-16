/********************************************
 * convertTime - convert Hours and Minutes to total Minutes
 * 
 * Uage - run the program
 * 		- enter hour and minnute
 * 		- program will print out the equal amount of time in minutes
 ********************************************/


#include <iostream>

const short int MPH = 60;		// number of minutes in 1 hour


// convert function: Hour and Minute to minute
int convertTime(int hour, int minute) {
	return hour * MPH + minute;
}	//end convertTime


// enter hour, minute and print the result
int main(int argc, char const *argv[]) {
	int hour;		// hour var
	int minute;		// minute var

	std::cout << "Program to convert hour and minutes to mintutes\n";
	std::cout << "Enter hour: ";		// ask user to enter hour
	std::cin >> hour;
	std::cout << "Enter minute: "; 		// ask user to enter minute
	std::cin >> minute;

	// convert and print result
	std::cout << hour << " hour & " << minute << " mins = " << convertTime(hour, minute) << "\n";
	return 0;
}	// end  main 