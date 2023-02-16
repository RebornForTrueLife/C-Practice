/********************************************
 * profile - print out the name, social security number, date of birth
 * 
 * Uage - run the program and it will print the information
 * 
 ********************************************/

#include <iostream>

int main(int argc, char const *argv[]) {
	std::string name = "Minh";					// my name
	std::string id = "033200002041"; 			// my social security number
	std::string birthDay = "08/12/2000"; 		// my birth day

	// print out all information
	std::cout << "My name is " << name << "\n";
	std::cout << "My social security number is " << id << "\n";
	std::cout << "My date of birth is " << birthDay << "\n";
	return 0;
} // end main