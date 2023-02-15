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


//  **DATE USED**
// list number of day each month in a year
short int monthArray[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


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


// **SUPPORT FUNCTION DECLARE

// Function that check if a year is a leap year
bool checkLeapYear(short int year);

// Function to raise warning and exit program
void raiseError(std::string message);

// Function to numbering comparison result of 2 short integer
short int numberCompare(short int number1, short int number2) ;

// Function to count number of day from start-day to a date in the same year exclusively
short int countBeginDay(short int* date);

// Function to count number of day from a date the end-day in the same year exclusively
short int countEndDay(short int * date);


// **MAIN FUNCTION CODE

// Validate input date
bool validate(short int * date) {
    // user other var to hold data for easily understanding
    short int day = date[0];
    short int month = date[1];
    short int year = date[2];
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
    short int totalDay = 0;         // total day between dateA and dateB
    // if date A greater than date B
    if (compare(dateA, dateB) == 1)        
        // raise Error and Exit
        raiseError("The first date must happen before or same as the second date"); 
    // Count number of days from yearA to yearB inclusively
    for (int year = dateA[2]; year <= dateB[2]; year++) {
        if (checkLeapYear(year) == true)        // year is a leap year
            totalDay += 366;                            // leap year has 366 days
        else
            totalDay += 365;                            // normal year has 365 days
    }   // close for
    // Calculate the number of day from start-day of yearA to dateA exclusively
    // and subtract this number from totalDay, cuz these days are not counted in between dateA and dateB
    totalDay -= countBeginDay(dateA);
        // calculate the number of day from dateB to the day-end of yearB exclusively
    // and subtract this number from totalDay, cuz these days are not counted in between dateA and dateB
    totalDay -= countEndDay(dateB);
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


// Function to count number of day from start-day to a date in the same year exclusively
short int countBeginDay(short int* date) {
    short int totalDay = 0;         // number of days - result
    // count number of days from start-day to the day before the first day in the motnh of date
    for (int month = 1; month < date[1]; month++) {
        totalDay += monthArray[month - 1];
    }   // close for
    // if month of date > 2: check if this is a leap year or not
    if (date[1] > 2) 
        if (checkLeapYear(date[2]) == true)         // if date in a leap year
            totalDay += 1;                                      // add one more day in totolDay
    // Add number of from begin of month of date to the day before date
    totalDay += date[0] - 1;
    // return result
    return totalDay;
}   // end countBeginDay


// Function to count number of day from a date the end-day in the same year exclusively
short int countEndDay(short int * date) {
    short int totalDay = 0;             // number of days = result
    // count the number of days from the begin of month after date's month to the end of date's year
    for (int month = date[1] + 1; month <= 12; month++) {
        totalDay += monthArray[month - 1];
    }   // close for
    // count number of days from the date to end of date's month exclusively
    totalDay += monthArray[date[1] - 1] - date[0];
    // if date's year is a leap year
    if (date[1] <= 2)                   // check if month of the date contain Feb
        if (checkLeapYear(date[2]) == true) 
            totalDay += 1;              // in leap year, there is one more extra day in Feb
    // return result
    return totalDay;
}   // end countEndDay     


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