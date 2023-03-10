/********************************************
 * boolDeclare - declare bool type
 * Uage: 
	- run the object file
 ********************************************/

#include <iostream> 

#define BOOLEAN bool 		// define bool type
#define TRUE 	true			// define true value
#define FALSE 	false		// define true value


// Main
int main(int argc, char const *argv[]) {
	BOOLEAN value;		// declare a bool type
	value = TRUE;

	if (value != FALSE) 
		std::cout << "The value is true\n";
	return 0;
}	// end  main 