/********************************************
 * animalTrack - provide func to get the total number of 
 * animals which are being treated
 * Uage: 
	- run the object file
	- the program will print out the number of animal 
	are being treated
 ********************************************/

#include <iostream>


// MODE
#define CODING		// coding mode
// #undef CODING		// turn off coding mode


// CLASS DECLARE
// Class animal for pig
class AnimalPig {
private:
	static int count;		// number of pig are being treated
public:
	// constructor
	AnimalPig(void);

	// to get the total number of animal treated
	friend int get_total(void);
};	// close AnimalPig

// Class animal for Horse
class AnimalHorse {
private:
	static int count;		// number of Horse are being treated
public:
	// constructor
	AnimalHorse(void);

	// to get the total number of animal treated
	friend int get_total(void);
};	// close AnimalHorse

// Class animal for Dog
class AnimalDog {
private:
	static int count;		// number of Dog are being treated
public:
	// constructor
	AnimalDog(void);

	// to get the total number of animal treated
	friend int get_total(void);
};	// close AnimalDog


// FUNC DECLARE
// to get total number of animal are being treated
int get_total(void);


// main
int main(int argc, char const *argv[]) {
	// print the instruction of the program
	std::cout << "The program is used to get the number of animals are being treated\n";
	// coding mode
	#ifdef CODING
		AnimalDog dog;		// register 1 dog
		AnimalDog pig;		// register 1 pig
	#endif 	// CODING
	std::cout << "The number of animal being treated = " << get_total() << "\n";
	return 0;
}	// end  main 


// STATIC INITIALIZE
int AnimalDog::count = 0;
int AnimalPig::count = 0;
int AnimalHorse::count = 0;


// CLASS DEFINE
/*	AnimalHorse:: construction
	- increase number of object when created*/
AnimalHorse::AnimalHorse(void) {
	count += 1;
}	// close constructor

/*	AnimalDog:: construction
	- increase number of object when created*/
AnimalDog::AnimalDog(void) {
	count += 1;
}	// close constructor

/*	AnimalPig:: construction
	- increase number of object when created*/
AnimalPig::AnimalPig(void) {
	count += 1;
}	// close constructor


// FUNCTION DEFINE
/*	get_total(void)
	- to get the total number of animals which are being treated
	- Input: none
	- Output: number of animals*/
int get_total(void) {
	int total = 0;	// total number of animals
	// add number of Pig
	total += AnimalPig::count;
	// add number of Dog
	total += AnimalDog::count;
	// add number of Horse
	total += AnimalHorse::count;
	// return
	return total;
}	// close get_total