/********************************************
 * rectangle - calculate the area of a rectangle given length and width
 * 
 * Usage - run the program, enter length and width then program will print out the area of given rectangle
 ********************************************/


#include <iostream>


float rectangleAreaCal(float length, float width) {
	return length * width;
}	//end rectangleAreaCal


int main(int argc, char const *argv[]) {
	float length;		// length of the rectangle
	float width;		// width of the rectangle
	std::cout << "This program is used to calculate area of given rectangle\n";
	std::cout << "Enter length: "; 
	std::cin >> length;
	std::cout << "Enter width: ";
	std::cin >> width;
	std::cout << "Area: " << rectangleAreaCal(length, width) << "\n";		// print out the area of rectangle
	return 0;
}	// end  main 