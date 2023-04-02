/********************************************
 * Parity - define class Parity
 * Uage: 
	- Parity provide 2 services: put and test
	- Define CODING in mode to test
 ********************************************/

#include <iostream>

// MODE
#define CODING		// coding mode
#undef CODING


// CLASS
class Parity {
private:
	int count;	// number of items in storage

public:
	Parity();	// construction

	// ~Parity();	// destruction: make default

	// put an item into storage
	void put(int item);

	// test whether the number of items is even or odd
	bool test(void);
};	// close Parity


int main(int argc, char const *argv[]) {
	// print the services of the Parity class
	std::cout << "The program is used to define class Parity\n";
	std::cout << "Parity provides 2 services:\n";
	std::cout << "\t1. Put item into its storage\n";
	std::cout << "\t1. Test whether the number of items is even or odd\n";
	// coding mode
	#ifdef CODING
		Parity parity;
		// put item
		parity.put(12);
		parity.put(12);
		// check number of items
		if (parity.test() == true)
			std::cout << "Number of items is even\n";
		else
			std::cout << "Number of items is odd\n";
	#endif // CODING
	return 0;
}	// end  main 


// IMPLEMENT

/*	Parity: construction
	- initialize [count] */
Parity::Parity(void) {
	count = 0;	// initialize count
}	// close Parity


/*	Parity: put
	- to put an integer into its storage and increase its count
	- input: item
	- output: increament [count] by 1 */
void Parity::put(int item) {
	count++;
}	// end put


/*	Parity: test
	- check if the number of items is even
	- input: none
	- output: TRUE if number of items is even, 
	vice versa*/
bool Parity::test(void) {
	return ( (count % 2) == 0 );
}	// end test