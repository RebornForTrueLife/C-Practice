/********************************************
 * weeklyPayment - take a number of hours working of a worker and tell the weekly pay
 * 
 * Uage - run the weeklyPayment file
 * 		- enter number of hour working in a week and the hourly wage
 * 		- the program will print our the payment of weekly working
 ********************************************/


#include <iostream>

const float OVERTIME_RATE = 1.5;


// function to check if the hour is valuable
bool checkWeeklyHour(short int numberHour) {
	bool result = true; 	// result of checking
	// the total number of hour in a week is 168
	// so the number of hour in range 0 - 168
	// if number hour < 0
	if (numberHour < 0) {
		result = false;
		std::cout << "\nHey, go to work, your working hour is negative!!!\n";
	} 
	// if number > 168
	else if (numberHour > 168) {
		result = false;
		std::cout << "\nMhm, do you think the number hours of a week can > 168?\n";
	}
	
	// else accepted
	return result;
}	//end checkWeeklyHour


// function to calculate the payment
float paymentCalculate(short int numberHour, float hourlyWage) {
	float payment = 0;		// the weekly payment
	// calculate the payment of work under or equal to 40
	if (numberHour <= 40) {
		payment = numberHour * hourlyWage;
	} // calculate if the person has overtime hour
	else {
		short int overtimeHour = numberHour - 40;
		payment = 40 * hourlyWage;								// payment at first 40 hours
		payment += overtimeHour * OVERTIME_RATE * hourlyWage;	// payment of overtime
	}	// end else

	return payment;
}	//end paymentCalculate


// enter number of working hour, hourly wage & compute payment & print out result
int main(int argc, char const *argv[]) {
	std::cout << "A program to calculate weekly payment\n";
	short int numberHour;		// number work in a week
	float hourlyWage;			// wage for an hour of working

	// ask user to enter number of working hour and amount of wage per hour
	std::cout << "Enter number of working hour in a week: ";
	std::cin >> numberHour;
	std::cout << "Enter the wage per hour: ";
	std::cin >> hourlyWage;

	// checking if the number of hour is valid
	if ( checkWeeklyHour(numberHour) == true) {
		// calculate the payment and print out the result
		std::cout << "You've worked for " << numberHour 
					<< " hours this week, here is your payment: " << paymentCalculate(numberHour, hourlyWage) << "\n";
	} // if the number of hour is not valid, just end the program

	return 0;
}	// end  main 