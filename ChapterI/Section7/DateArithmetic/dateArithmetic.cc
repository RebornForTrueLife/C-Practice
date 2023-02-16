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
const int MONTH_ARRAY[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
// a global array to return date
int dateReturn[3]; 


// **MAIN FUNCTION DECLARE**

// Function to give instruction for each user choice of operation
void instructor(int choice);

// Abstract Function to perform each operation
// void operationProcedure() -> abstraction

// Function to validate a date and raise warning if the date is not valid
bool validate(int * date);

// Function to compare between 2 date, the detail comparison is defined in specification file
int compare(int* dateA, int *dateB);

// Function to measure the number of days between 2 given dates
int measureDistance(int * dateA, int * dateB);

// Procedure to implement measure distance operation
void measureDistanceProcedure();

// Funtion to return the date after/before a given number of date from  a given date
int * addSubDay(int* date, int numberDay);

// Procedure for add and sub operation xD
void addSubProcedure();


// **SUPPORT FUNCTION DECLARE

// Function that check if a year is a leap year
bool checkLeapYear(int year);

// Function to raise warning and exit program
void raiseError(std::string message);

// Function to numbering comparison result of 2 integer
int numberCompare(int number1, int number2) ;

// Function to convert the given day into number of days from base_date(0/0/0) to the given date
int dayStamp(int * date);

// Function to convert the given day stamp into corresponding date
int * toDate(int daystamp);

// Function to calculate the number of day from 1/1 to the end of given month in the same year
// need to know the year in order to check if it is a leap year
int daySigmaMonth(int month, int year);

// Function to return string value of date
std::string toString(int * date);


// **MAIN FUNCTION CODE

// Validate input date
bool validate(int * date) {
	// user other var to hold data for easily understanding
	int day = date[0];
	int month = date[1];
	int year = date[2];
	// copy the MONTH_ARRAY, cuz the value of array can be changed
	int monthArray[12];
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
int compare(int* dateA, int *dateB) {
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
void instructor(int choice){
	// If choice == 1: measure distance operation
	if (choice == 1) {
		std::cout << "Program will count number of days between 2 dates, the begin date need to happen before the end date\n";
		std::cout << "Date should be entered in this format [day month year], example for 25/06/2023: 25 6 2023\n";
		// CALL measure Distance Procedure
		measureDistanceProcedure();
	} // If choice == 2: Addition operation
	else if (choice == 2) {
		std::cout << "Program will print the date after [number] days after given date\n";
		std::cout << "Date should be entered in this format [day month year], example for 25/06/2023: 25 6 2023\n";
		std::cout << "The number is an non-negative integer\n";
		// CALL addition operation procedure
		addSubProcedure();
	} // If choice == 3: Subtraction operation
	else if (choice == 3) {
		std::cout << "Program will print the date before [number] days of the given date\n";
		std::cout << "Date should be entered in this format [day month year], example for 25/06/2023: 25 6 2023\n";
		std::cout << "The number is a non-positive integer\n";
		// CALL subtraction operation procedure
		addSubProcedure();
	} // Else raise Error
	else
		raiseError("Choice must be an integer in [id] listed above");
}   // end instructor


// Funtion to measure the number of days between 2 given dates
int measureDistance(int * dateA, int * dateB) {
	int totalDay = 0;        // total day between dateA and dateB
	int dayStampA; 			//  day stamp of the first date
	int dayStampB; 			//  day stamp of the second date
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
	int dateA[3];          // begin date
	int dateB[3];          // end date
	int result;               // number of days between 2 dates
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


// Funtion to return the date after/before a given number of date from  a given date
int * addSubDay(int* date, int numberDay) {
	int daystamp = dayStamp(date);			// day stamp of given date
	// calculate new day stamp
	daystamp += numberDay;
	// convert new day stamp to corresponding date
	toDate(daystamp);
	// return result, cuz result already stored in global var [dateReturn]
	return dateReturn;
}	// end addSubDay


// Procedure for add and sub operation xD
void addSubProcedure() {
	int date[3];			// the date to operate on
	int numberDay;		// the number of day to be added, if it < 0, same mean of sub
	// ask user to enter the date and the integer
	std::cout << "Enter the date: ";
	std::cin >> date[0] >> date[1] >> date[2];
	std::cout << "Enter the integer: ";
	std::cin >> numberDay;
	// Operating and stored result in dateReturn
	addSubDay(date, numberDay);
	// print result out
	std::cout << "The date needs to be found is: " << toString(dateReturn) << "\n";
}	// end addSubDay


// **SUPPORT FUNCTION CODE**

// function that check if a year is a leap year
// a leap year is any year divisible by 4 
// unless it is divisible by 100, but not 400
bool checkLeapYear(int year) {
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


// Function to numbering comparison result of 2 integer
int numberCompare(int number1, int number2) {
	if (number1 > number2)          // result == 1 if numb1 > numb2
		return 1;
	else if (number1 < number2)     // result == -1 if numb1 < numb2
		return -1;
	// else result == 0 if numb1 == numb2
	return 0;
}   // end numberCompare


// Function to convert the given day into number of days from base_date(1/1/0) to the given date
int dayStamp(int * date) {
	// explicitly use date data
	int day = date[0];            	// date's day
	int month = date[1];       	// date's month
	int year = date[2];				// date's year
	int sign;								// to show if year is before or after base_date
	int totalDay = 0; 				// number of days = day stamp
	int dayCurrentYear = 0;		// number of days happened in date's year
	// copy the MONTH_ARRAY, cuz the value of array can be changed
	int monthArray[12];
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


// Function to convert the given day stamp into corresponding date
int * toDate(int daystamp) {
	int sign;		// sign of daystamp
	int year;		// year of date
	int month;	// month of date
	int day;			// day of date
	if (daystamp < 0) 
		sign = -1;
	else 
		sign = 1;
	// FIND YEAR
	// calcualte abs of daystamp
	daystamp *= sign;
	// the minimum number of years that date with daystamp might fall to
	year = daystamp / 366;
	// increase year until dayStamp of the begin date of [year] greater than
	while (1) {
		int beginDateYear[] = {1, 1, year};		// the begin date of [year]
		if (daystamp < dayStamp(beginDateYear))
			break;
		year += 1;
	}	// close while
	// so the year of date is the year before [year]
	year -= 1;
	// if year is negative
	if (sign == -1) {
		year += 1;			// cuz negative year start by -1;
		year *= sign;		// change sign of year
	}	// close if
	// FIND MONTH
	// calculate number of day between date and the begin of the same year
	int leftDay;			// the number of days 
	// the way finding [number of days] is different between 2 value of sign
	int beginDate[] = {1, 1, year};
	if (sign == 1) {
		leftDay = daystamp - dayStamp(beginDate) + 1; 
	} else {
		// Because day stamp of the begin date of negative year is negative, 
		//  and daystamp has been already  done absolute
		// increment 1 so that [leftDay] also include the needed date
		leftDay = (- dayStamp(beginDate)) - daystamp + 1; 
	}	// close if
	// Find the minimum month that greater or equal to date's month
	month = 1;
	while (1) {
		if (daySigmaMonth(month, year) >= leftDay) 
			break;
		month++;
	}	// close while
	// FIND DAY
	day = leftDay - daySigmaMonth(month - 1, year);
	if (day == 0)	{		// day is the last day of previous month
		day = daySigmaMonth(month, year) - daySigmaMonth(month - 1, year);
		month--;
	}	// close if
	// return date
	dateReturn[0] = day;
	dateReturn[1] = month;
	dateReturn[2] = year;
	return dateReturn;
}	// end toDate


// Function to calculate the number of day from 1/1 to the end of given month in the same year
// need to know the year in order to check if it is a leap year
int daySigmaMonth(int month, int year) {
	int monthArray[12];		// array of number days of month
	int totalDay = 0;			// number of days 
	std::copy(std::begin(MONTH_ARRAY), std::end(MONTH_ARRAY), std::begin(monthArray));
	if (checkLeapYear(year) == true) 
		monthArray[1] = 29;			// FEB has 29 days in leap year
	for (int monthIdx = 0; monthIdx < month; monthIdx++) {
		totalDay += monthArray[monthIdx];
	}	// close for
	return totalDay;
}	// end daySigmaMonth


// Function to return string value of date
std::string toString(int * date) {
	std::string result = std::to_string(date[0]) + "/" ;
	result += std::to_string(date[1]) + "/";
	result += std::to_string(date[2]);
	return result;
}	// end toString


int main(int argc, char const *argv[]) {
	int choice;       // operation choice
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
}	// end  main 