/********************************************
 * sphereVolume - calculate the volume of the given sphere
 * 
 * Uage - run object file
 * 		- enter the radius of the sphere
 * 		- then the program will print out the volume
 ********************************************/


#include <iostream>

const float PI = 3.14;		// PI number


// function to calculate sphere volume 
float sphereVolumeCal(float radius) {
	return 4.0/3.0 * PI * radius * radius * radius;		// sphere volume formula: 4/3 * Pi * R^3
}	//end sphereVolumeCal


// main function to enter radius and calculate
int main(int argc, char const *argv[]) {
	float radius; 		// radius of the sphere

	std::cout << "Program to calculate volume of given sphere\n";
	std::cout << "Enter the radius of the sphere: ";		// ask user to enter radius
	std::cin >> radius;

	std::cout << "The volume of the sphere: " << sphereVolumeCal(radius) << "\n";		// print the result 

	return 0;
}	// end  main 