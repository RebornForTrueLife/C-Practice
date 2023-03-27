/********************************************
 * TimeDate - declare a data structure to store time
 * and date, and its operator
 * Uage: 
	- run the object file to see the interface of data
	type
 ********************************************/

#include <iostream>

// DATA declareE
struct TimeDate {
	// 0 may be not valid value but to show that current
	// value is not set
	int min = 0;		// minute
	int hour = 0;	// hour
	int day = 0;		// day
	int month = 0;	// month
	int year = 0;		// year
	// Operator
	// time_diff
};	// close TimeDate

// FUNCTION DECLARE
/*	a function to find the difference between time1
	and time2 in minutes
		- input: 2 timeDates
		- output: time difference in minutes, can be 
		negative if time1 earlier than time2*/
int time_diff(TimeDate timeDate1, TimeDate timeDate2);


// main
int main(int argc, char const *argv[]) {
	// print the interface of TimeDate type
	std::cout << "The program provide a data structure to store time and date\n";
	std::cout << "TimeDate:\n";
	std::cout << "Fields:\n";
	std::cout << "\tmin: minute, in range [1, 60]\n";
	std::cout << "\thour: hour, in range [0, 23]\n";
	std::cout << "\tday: day of month, in range [1, 31]\n";
	std::cout << "\tmonth: month, in range [1, 12]\n";
	std::cout << "\tyear: year\n";
	std::cout << "Operator:\n";
	std::cout << "\ttime_diff: return difference of time in minutes of 2 TimeDate variables\n";
	// CODING
	struct TimeDate timeDate1 = { 30, 8, 1, 1 , 2000};
	struct TimeDate timeDate2 = { 30, 10, 1, 1 , 2023};
	std::cout << "Time diff: " << time_diff(timeDate1, timeDate2) << "\n";
	return 0;
}	// end  main 


// Operator of TimeDate: find difference between 2 time
// 		in minutes
int time_diff(TimeDate timeDate1, TimeDate timeDate2) {
	// calculate total minutes of 2 timeDate
	int min1 = timeDate1.min + timeDate1.hour * 60;
	int min2 = timeDate2.min + timeDate2.hour * 60;
	// calcualte difference of time in minutes
	int timeDiff = min1 - min2;
	return timeDiff;
}	// end time_diff