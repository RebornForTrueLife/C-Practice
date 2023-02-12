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


// **MAIN FUNCTION DECLARE**

// Function to give instruction for each user choice of operation
void instructor(short int choice);

// Abstract Function to perform each operation
// void operationProcedure() -> abstraction

// Function to validate a date and raise warning if the date is not valid
bool validate(short int * date);

// Function to compare between 2 date, the detail comparison is defined in specification file
short int compare(short int* dateA, short int *dateB);


// **SUPPORT FUNCTION DECLARE

// Function that check if a year is a leap year
bool checkLeapYear(short int year);

// Function to raise warning and exit program
void raiseError(std::string message);


// **MAIN FUNCTION CODE

// Validate input date
bool validate(short int * date) {
    // user other var to hold data for easily understanding
    short int day = date[0];
    short int month = date[1];
    short int year = date[2];
    // list number of day each month in a year
    short int monthArray[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

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
}    //end validate


// Instructor
void instructor(short int choice){
    // If choice == 1: measure distance operation
    if (choice == 1) {
        std::cout << "Program will count number of days between 2 dates, the begin day need to happen before the end day\n";
        std::cout << "Date should be enter in this format [day month year], example for 25/06/2023: 25 6 2023\n";
        // CALL measure Distance Procedure

        //////////////////////////////////////////////
        // validate test
        short int date[3];
        std::cout << "Enter a date: ";
        std::cin >> date[0] >> date[1] >> date[2];
        validate(date);
        //////////////////////////////////////////////
    } // If choice == 2: Addition operation
    else if (choice == 2) {
        std::cout << "Program will print the date after [number] days after given date\n";
        std::cout << "Date should be enter in this format [day month year], example for 25/06/2023: 25 6 2023\n";
        // CALL addition operation procedure
    } // If choice == 3: Subtraction operation
    else if (choice == 3) {
        std::cout << "Program will print the date before [number] days of the given date\n";
        std::cout << "Date should be enter in this format [day month year], example for 25/06/2023: 25 6 2023\n";
        // CALL subtraction operation procedure
    } // Else raise Error
    else
        raiseError("Choice must be an integer in [id] listed above");
}   // end instructor


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
}	// end  main 