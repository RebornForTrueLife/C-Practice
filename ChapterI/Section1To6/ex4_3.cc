/********************************************
 * rectangle - calculate the area and circumference 
 * 
 * usage - run the program then it will print out area and circumference of 3-5 inches rectangle, and 6.8-2.3 rectangle 
 ********************************************/

#include <iostream>


// function to calculate area of a rectangle given length and height
float areaCal(float length, float height) {
	return length * height;
}	// end areaCal


// function to calculate circumference of a rectangle given length and height
float circumferenceCal(float length, float height) {
	return (length + height) * 2;
}	// end circumferenceCal


// calculate specific rectangle of the problem and print the result
int main(int argc, char const *argv[]) {
	// print result for 3-5 rectangle
	std::cout 	<< "The area and circumference of 3 - 5 inches retangle relatively are " 
				<< areaCal(5, 3) << " & " << circumferenceCal(5, 3) << "\n";

	// print result for 6.8-2.3 rectangle
	std::cout 	<< "The area and circumference of 6.8 - 2.3 inches retangle relatively are "
				<< areaCal(6.8, 2.3) << " & " << circumferenceCal(6.8, 2.3) << "\n";
	return 0;
}	// end main

