/********************************************
 * rectanglePerimeter - calculate perimeter of given rectangle
 * 
 * Uage - run object file
 * 		- enter the length and the width of the rectangle
 * 		- the program will print out the perimeter
 ********************************************/


#include <iostream>


// function to calculate perimeter
float rectanglePerimeterCal(float length, float width) {
	return 2 * (length + width );		// calculate perimeter = 2 * (width + length)
}	//end rectanglePerimeterCal

// main to enter rectangle figures, and print result
int main(int argc, char const *argv[]) {
	float length;		// length of rectangle
	float width;		// width of rectangle

	std::cout << "Program to calculate perimeter of given rectangle\n";
	std::cout << "Enter length: ";		// ask user to enter length
	std::cin >> length;		
	std::cout << "Enter width: ";		// ask user to enter width
	std::cin >> width;

	// calculate and print result
	std::cout << "Rectangle perimeter: " << rectanglePerimeterCal(length, width) << "\n";
	return 0;
}	// end  main i