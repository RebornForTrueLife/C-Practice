/********************************************
 * dateArithmetic - performs some operation wiht dates
 * 
 * Uage - Run object file
 * 		- Choose the wanted operation on date
 * 		- Follow program instruction for that operation
 * 		- The program will print out the result of the operation
 * 
 * More detail is in specification file
 ********************************************/


#include <iostream>
#include <string>
#include <algorithm>


//  **DATE USED**
// list number of day each month in a year
const short int MONTH_ARRAY[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


// **MAIN FUNCTION DECLARE**

// Function to give instruction for each user choice of operation
void instructor(short int choice);

// Abstract Function to perform each operation
// void operationProcedure() -> abstraction

// Function to validate a date and raise warning if the date is not valid
bool validate(short int * date);

// Function to compare between 2 date, the detail comparison is defined in specification file
short int compare(short int* dateA, short int *dateB);

// Function to measure the number of days between 2 given dates
short int measureDistance(short int * dateA, short int * dateB);

// Procedure to implement measure distance operation
void measureDistanceProcedure();

// Function to convert the given day into number of days from base_date(0/0/0) to the given date
short int dayStamp(short int * date);


// **SUPPORT FUNCTION DECLARE

// Function that check if a year is a leap year
bool checkLeapYear(short int year);

// Function to raise warning and exit program
void raiseError(std::string message);

// Function to numbering comparison result of 2 short integer
short int numberCompare(short int number1, short int number2) ;


// **MAIN FUNCTION CODE

// Validate input date
bool validate(short int * date) {
	// user other var to hold data for easily understanding
	short int day = date[0];
	short int month = date[1];
	short int year = date[2];
	// copy the MONTH_ARRAY, cuz the value of array can be changed
	short int monthArray[12];
	std::copy(std::begin(MONTH_ARRAY), std::end(MONTH_ARRAY), std::begin(monthArray));
	// Check if year is a leap year
	if (checkLeapYear(year) == true)
		monthArray[1] = 29;     // In leap year, Feb has 29 days
	// Check if month is valid(in range 1 - 12)
	if ( (month < 1) || (month > 12) )
		raiseError("Invalid month, should be in range from 1 to 12");
	// Check if day is valid by corresponding number of in month
	if ( (day < 1) || (day > monthArray[month - 1]) ) {
		// create the error message
		std::string message = "Invalid day, this month has ";
		message += std::to_string(monthArray[month - 1]);
		message += " days, so day should be from 1 to ";
		message += std::to_string(monthArray[month - 1]);
		raiseError(message);
	}   // close if

	// If the date passed all condition
	return true;
}    // end validate


// Function to compare between 2 date, the detail comparison is defined in specification file
short int compare(short int* dateA, short int *dateB) {
	//  check if dateA and dateB are valid 
	validate(dateA);
	validate(dateB);
	//  Compare years
	if (dateA[2] != dateB[2]) 
		return numberCompare(dateA[2], dateB[2]);
	// Compare month
	if (dateA[1] != dateB[1]) 
		return numberCompare(dateA[1], dateB[1]);
	// Compare day
	return numberCompare(dateA[0], dateB[0]);
}   // end  compare


// Instructor
void instructor(short int choice){
	// If choice == 1: measure distance operation
	if (choice == 1) {
		std::cout << "Program will count number of days between 2 dates, the begin date need to happen before the end date\n";
		std::cout << "Date should be entered in this format [day month year], example for 25/06/2023: 25 6 2023\n";
		// CALL measure Distance Procedure
		measureDistanceProcedure();
		////////////////////////////////////////////////////////
		// Test day stamp
		// short int date[3];
		// std::cout << "Enter a date: ";
		// std::cin >> date[0] >> date[1] >> date[2];
		// std::cout << "Day stamp: " << dayStamp(date) << "\n";
		////////////////////////////////////////////////////////
	} // If choice == 2: Addition operation
	else if (choice == 2) {
		std::cout << "Program will print the date after [number] days after given date\n";
		std::cout << "Date should be entered in this format [day month year], example for 25/06/2023: 25 6 2023\n";
		// CALL addition operation procedure
	} // If choice == 3: Subtraction operation
	else if (choice == 3) {
		std::cout << "Program will print the date before [number] days of the given date\n";
		std::cout << "Date should be entered in this format [day month year], example for 25/06/2023: 25 6 2023\n";
		// CALL subtraction operation procedure
	} // Else raise Error
	else
		raiseError("Choice must be an integer in [id] listed above");
}   // end instructor


// Funtion to measure the number of days between 2 given dates
short int measureDistance(short int * dateA, short int * dateB) {
	short int totalDay = 0;         	// total day between dateA and dateB
	short int dayStampA; 			//  day stamp of the first date
	short int dayStampB; 			//  day stamp of the second date
	// check: dateA must happen before or same as dateB
	if (compare(dateA, dateB) == 1)
		raiseError("The first date must happen before or same as second date");
	// calculate day_stamp of 2 dates
	dayStampA = dayStamp(dateA);
	dayStampB = dayStamp(dateB);
	// calculate number of days between 2 dates
	totalDay = dayStampB - dayStampA + 1;
	// return result
	return totalDay;
}   // end measureDistance


// Procedure to implement measure distance operation
void measureDistanceProcedure() {
	short int dateA[3];          // begin date
	short int dateB[3];          // end date
	short int result;               // number of days between 2 dates
	// Ask user to enter 2 dates 
	std::cout << "Enter the begin date: ";
	std::cin >> dateA[0] >> dateA[1] >> dateA[2];
	std::cout << "Enter the end date: ";
	std::cin >> dateB[0] >> dateB[1] >> dateB[2];
	// measure distance between 2 dates:
	result = measureDistance(dateA, dateB);
	// print out number of days
	std::cout << "Number of days between 2 given date is: " << result << "\n";
}   // end measureDistanceProcedure


// **SUPPORT FUNCTION CODE**

// function that check if a year is a leap year
// a leap year is any year divisible by 4 
// unless it is divisible by 100, but not 400
bool checkLeapYear(short int year) {
	bool result = false;        // result of the check, initial is false - not a leap year
	// check if year is divisible by 4
	if (year % 4 == 0) {
		// if yes, check if it is divisible by 100
		if (year % 100 == 0) {
			// if yes, check if it divisible by 400
			if (year % 400 == 0)
				// if yes, it's a leap year
				result = true;
		} else // else yes
			result = true;
	}   // end if
		
	return result;
}   //end checkLeapYear

// Function to raise warning and exit program
// Input error message and print out 
void raiseError(std::string message) {
	std::cout << "ERROR: " << message << "\n";
	std::cout << "Exit program... Have a nice day fellow!\n";
	exit(0);
}   // end raiseError


// Function to numbering comparison result of 2 short integer
short int numberCompare(short int number1, short int number2) {
	if (number1 > number2)          // result == 1 if numb1 > numb2
		return 1;
	else if (number1 < number2)     // result == -1 if numb1 < numb2
		return -1;
	// else result == 0 if numb1 == numb2
	return 0;
}   // end numberCompare


// Function to convert the given day into number of days from base_date(1/1/0) to the given date
short int dayStamp(short int * date) {
	// explicitly use date data
	short int day = date[0];            	// date's day
	short int month = date[1];       	// date's month
	short int year = date[2];			// date's year
	short int sign;							// to show if year is before or after base_date
	short int totalDay = 0; 				// number of days = day stamp
	short int dayCurrentYear = 0;	// number of days happened in date's year
	// copy the MONTH_ARRAY, cuz the value of array can be changed
	short int monthArray[12];
	std::copy(std::begin(MONTH_ARRAY), std::end(MONTH_ARRAY), std::begin(monthArray));
	// validate the given date
	validate(date);
	// check if date is before or after base_date
	if (year < 0) 	{
		sign = -1;			// mean date is before base_date
		year = - year;		// convert year to absolute value
	}	// if date is equal or after base_date
	else
		sign = 1; 			// mean date is equal or after base_date
	// Count number of days from base_date to the end_date of the year before date's year
	for (int yearIdx = 0; yearIdx < year; yearIdx++) {
		if (checkLeapYear(yearIdx) == true) 
			totalDay += 366;			// leap year has 366 days
		else
			totalDay += 365;			// normal year has 365 days
	}	// close for
	// Count number of days fromthe begin of date's year to the date
	//// count number of days from start-day to the day before the first day in the motnh of date
	for (int monthIdx = 1; monthIdx < month; monthIdx++) {
		dayCurrentYear += monthArray[monthIdx - 1];
	}   // close for
	//// if month of date > 2: check if this is a leap year or not
	if (month > 2) 
		if (checkLeapYear(year) == true)         // if date in a leap year
			dayCurrentYear += 1;                     // add one more day in totolDay
	//// Add number of from begin of month of date to the day before date
	dayCurrentYear += day;
	//// if the date is before base_date
	if (sign == -1) {
		// subtract [number of days in year 0] from totalDay
		totalDay -= 366;
		// because dates that are before base_date: have abs(year) in reversed direction 
		// but day and month increase in same direction with time
		// mean the larger day and month, the closer day_stamp to the base_date
		// calculate the number of days left in date's year inclusively
		if (checkLeapYear(year) == true) 		// number of days depend on if year is a leap year
			dayCurrentYear = 366 - dayCurrentYear + 1;
		else
			dayCurrentYear = 365 - dayCurrentYear + 1;
	}	// else dayCurrentYear decreases 1, because day stamp start by 0
	else
		dayCurrentYear -= 1;
	// add [number of days in current year] to [totalDay]
	totalDay += dayCurrentYear;
	// day stamp need to have the same sign with year
	totalDay *= sign;
	// return day stamp
	return totalDay;
}   // end dayStamp


int main(int argc, char const *argv[]) {
	// Declare
	short int choice;       // operation choice

	// Print out the list of operations
	std::cout << "This program can perform some operations on date that are listed below\n";
	std::cout << "[1] Count number of days between 2 dates\n";
	std::cout << "[2] Print the date after [number] days of a given date\n";
	std::cout << "[3] Print the date before [number] days of a given date\n";

	// Ask user to enter operation choice
	std::cout << "Enter [ID] of chosen operation: ";
	std::cin >> choice;

	// Give instruction to user about user's chosen operation
	// and also call the operationProcedure to operate
	instructor(choice);

	return 0;
	// > `Take` 2 dates: date [A] and date [B]
}	// end  main 