/********************************************
 * distance2Points - calcualte the distance between 2 points
 * 
 * Uage - run the object file
 * 		- enter coordiates of Two points: [coor11, coor12] and [coor21, coor22]
 * 		- return the distance between two points
 ********************************************/


#include <iostream>

const float PRECISION = 0.00001;		// the precision of finding square root of a float number


// function to find absolute value of a float number
float absFloat(float number) {
	// if number is positive or zero return it
	if (number >= 0)	
		return number;
	// if number is negative, return negative of it
	else 
		return (-1) * number;
}	//end absFloat


// function to calculate the square root of a float number
// by decrease from starting point to find the most exactly square root of the number
float squareRoot(float number) {
	float startFindingPoint;		// start number to find square root
	float currentSquareRoot;		// current testing square root
	float nextSquareRoot;			// next testing square root
	// the error (distance) between current square root and the exact square root
	// tryna minimize the error
	float err;			
	float nextErr;		// error of the next testing square root

	// find the starting point
	// if number >=4 then starting point = number / 2
	if (number >= 4)
		startFindingPoint = number / 2;
	// if number < 4 then starting point = number
	else
		startFindingPoint = number;

	// start finding from starting point
	currentSquareRoot = startFindingPoint;
	err = absFloat(currentSquareRoot * currentSquareRoot - number);		// err is non negative
	// minimizing the err
	while (1) {
		nextSquareRoot = currentSquareRoot - PRECISION;		// decrease the testing square root
		nextErr = absFloat(nextSquareRoot * nextSquareRoot - number);
		// If next test square root is not close to true square root than current test value, then stop the loop
		if (nextErr > err) 
			break;
		// if it still on the optimizing process, continue, assign next err to current err
		else {
			currentSquareRoot = nextSquareRoot;
			err = nextErr;
		}	// end if
	}	// end while

	return currentSquareRoot;
}	//end squareRoot


// recurrence function to search the square root in a range [low ... high]
// and minimize the range until find closest accepted square root
float seachInRange(float number, float low, float high) {
	float middle = (high + low) / 2; 		// the middle point of the range

	// if middle is accepted according to our PRECISION
	if (((middle - PRECISION) * (middle - PRECISION) <= number) && ((middle + PRECISION) * (middle + PRECISION) >= number))
		return middle;
	// if middle is not accepted 
	else {
		// if middle is greater than the square root
		if (middle * middle > number)
			return seachInRange(number, low, middle);
		// if middle is less than the square root
		else
			return seachInRange(number, middle + PRECISION, high);
	}	// end else
}	//end seachInRange

// BETTER SOLUTION to find square root of a float number
float betterSquareRoot(float number) {
	// start to search from 0 to the number
	return seachInRange(number, 0, number);
}	//end betterSquareRoot


// function to calculate the distance between 2 points
// formula: sqrt of ((x2 - x1)^2 + (y2 - y1)^2)
float distance2Point(float coorXPoint1, float coorYPoint1, float coorXPoint2, float coorYPoint2) {
	float expression1 = (coorXPoint2 - coorXPoint1) * (coorXPoint2 - coorXPoint1);
	float expression2 = (coorYPoint2 - coorYPoint1) * (coorYPoint2 - coorYPoint1);
	return betterSquareRoot(expression1 + expression2);
}	//end distance2Point


// read figures, calculate, print result
int main(int argc, char const *argv[]) {
	float point1[2];		// coordinate of point 1
	float point2[2];		// coordinate of point 2

	std::cout << "The program to calculate the distance between 2 point[x, y]\n";
	std::cout << "Enter coordinate of point 1 [x][space][y]: ";
	std::cin >> point1[0];		// ask user enter coordinate of point 1
	std::cin >> point1[1];
	std::cout << "Enter coordinate of point 2 [x][space][y]: ";
	std::cin >> point2[0];		// ask user enter coordinate of point 2
	std::cin >> point2[1];

	// calculate and print the result
	std::cout << "Distance between 2 point = " << distance2Point(point1[0], point1[1], point2[0], point2[1]) << "\n";
	return 0;
}	// end  main 