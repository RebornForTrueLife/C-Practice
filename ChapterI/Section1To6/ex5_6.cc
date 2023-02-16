/********************************************
 * convertTimeHM - convert from minutes to hour and minutes
 * 
 * Uage - run object file
 * 		- enter minutes then program will convert to hour and minute and print the result
 ********************************************/


#include <iostream>

const short int MPH = 60;		// number of minutes per hour


// function to convert minute to hour and mins
int * convertM2HM(int minute) {
	int hour;		// hour part
	int min; 		// minute left part

	hour = minute / MPH;
	min = minute - hour * MPH;

	// declare 1 demension array demension 2 to store the result [hour, min]
	// the array has to be static because it won't be deleted when the function return
	static int array[2] = {hour, min};
	return array;
}	//end convertM2HM


int main(int argc, char const *argv[]) {
	int minute;
	int *result;		// an integer array to store the result

	std::cout << "Program to convert minute to Hour and Minute\n";
	std::cout << "Enter minute: ";		// ask user to enter minute
	std::cin >> minute;

	result = convertM2HM(minute);
	if (result[0] == 0) {		// in case number of hour = 0
		std::cout << minute << " mins = " << minute << " mins\n";

	} else if (result[1] != 0) {		// in case number of hour > 0 and min != 0
		std::cout << minute << " mins = " << result[0] << " hours & " << result[1] << " mins\n";

	} else {
		std::cout << minute << " mins = " << result[0] << " hours\n";
	}	// end if

	return 0;
}	// end  main 

