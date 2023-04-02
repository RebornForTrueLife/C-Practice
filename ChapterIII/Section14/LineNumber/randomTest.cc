/********************************************
 * test - test random library
 * Uage: 
	- run object file
 ********************************************/

#include <iostream>
#include <cstdlib>


// main
int main(int argc, char const *argv[]) {
	srand(1);
	for (int i = 0; i < 10; i ++ ) {
		std::cout << "At index " << i << " : " << rand() % 100 << "\n";
	}	// close for
	
	const int* get_array(int size);
	const int *array = get_array(10);
	return 0;
}	// end  main 


const int* get_array(int size) {
	static int array[10];
	return array;
}	// close get_array