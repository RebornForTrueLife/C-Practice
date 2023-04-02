/********************************************
 * CheckBook - define CheckBook class
 * Uage: 
	- CheckBook provides 2 service: add_item and total
 ********************************************/

#include <iostream>

// MODE
#define CODING		// coding mode
// #undef CODING

// CONST
const int MAX_SIZE = 100;	// max number of entries

// CLASS
class CheckBook {
private:
	int count;	// number of entries in checkbook
	int list[MAX_SIZE];		// list of entries
public:
	// constructor: initialize count
	CheckBook();

	// destructor: let default
	// ~CheckBook();

	// put new entry into list
	void add_item(int entry);

	// get total number of entries in checkbook
	int total(void);
};


// main
int main(int argc, char const *argv[]) {
	// print the services of CheckBook class
	std::cout << "Program is used to define class CheckBook\n";
	std::cout << "CheckBook has 2 services:\n";
	std::cout << "\t1. Add new entry to checkbook\n";
	std::cout << "\t2. Get the number of entries in checkbook\n";
	// coding mode
	#ifdef CODING
		CheckBook checkbook;	// create a check book
		checkbook.add_item(100);
		checkbook.add_item(14);
		checkbook.add_item(1340);
		// print the number of entries
		std::cout << "Number of entries added: " << checkbook.total() << "\n";
	#endif	// CODING
	return 0;
}	// end  main 


// IMPLEMENT

/*	CheckBook: construction
	- initialize [count] */
CheckBook::CheckBook(void) {
	count = 0;
}	// end construction


/*	CheckBook: add_item
	- Warning: this does not check for overflow number
	of entries
	- input: the new entry
	- output: add new entry to the list*/
void CheckBook::add_item(int entry) {
	// put new entry to the list
	list[count] = entry;		
	count += 1;		// increment count
}	// end add_item


/*	CheckBook: total
	- input: none
	- output: return number of entries in the list */
int CheckBook::total(void) {
	return count;
}	// end total
