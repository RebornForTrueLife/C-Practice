/********************************************
 * airline - find list of planes that leave at 2 input 
 * airport
 * Uage: 
	- run the object file
	- enter 2 originating airport code
	- the program will search on the list of planes
	and list all planes that leave from 2 input airport 
 ********************************************/

#include <iostream>

// MODE
#define CODING		// while coding
#undef CODING

// CONST
const int PLANE_SIZE = 10;
const int CODE_SIZE = 3 + 1;

// DATA
// Airline: data structure to store airline info
struct Airline {
	long int number;				// flight number
	char oriPort[CODE_SIZE];	// originating airport code
	char desPort[CODE_SIZE];	// destination airport code
	int depTime[2];				// departture time: hour, minute
	int arrTime[2];				// arrival time
	// Operator
	// 		bool check_ori: check if oriPort is input airport
};	// close Airline

// PlaneList: store list of airline
struct PlaneList {
	Airline array[PLANE_SIZE];	// list of airline
	int size = 0;					// actual size
};	// clost PlaneList

// FUNCTION
/*	initialize infor of 10 planes in a list of plane
	- input: list of plane
	- output: give info of 10 planes in the list*/
PlaneList initial_plane_list();

/*	function to check if the orPort given plane is
	the input airport
	- input: an airline(plane), an airport
	- output: true if oriPort of plane is airport, 
	vice versa*/
bool check_ori(Airline plane, char airport[]);

/*	function to find all planes that leave from 2 input
	airports, in a list of planes
	- input: a list of planes, airport1, airport2
	- output: a list of planes that leave from 2 input
	airports*/
PlaneList find_plane(PlaneList list, char airport1[], char airport2[]);


// main
int main(int argc, char const *argv[]) {
	PlaneList list;	// list of planes
	char airport1[CODE_SIZE];	// originating airport code 1
	char airport2[CODE_SIZE];	// airport 2
	// print the instruction of program
	std::cout << "The program is used to find all plane that "
				<< "leave from 2 input airport in the list of planes\n";
	// initialize plane list
	list = initial_plane_list();
	// print the number of planes in the list
	std::cout << "The list contain " << list.size << " planes\n";
	// ask user to enter 2 airports
	std::cout << "Please enter the first airport: ";
	std::cin >> airport1;
	std::cout << "Please enter the second airport: ";
	std::cin >> airport2;
	#ifdef CODING
		std::cout << "### Enter CODING MODE: \n";
		// print list of plane
		for (int i = 0; i < list.size; i++) {
			std::cout << "### Plane with flight number: " << list.array[i].number << "\n";
		}	// close for
	#else
		// find all planes that leave from 2 airport
		PlaneList foundPlane = find_plane(list, airport1, airport2);
		// print out the list of planes
		if (foundPlane.size != 0) {
			std::cout << "List of all planes that leave from " << airport1 << " and " << airport2 << " :\n";
			for (int i = 0; i < foundPlane.size; i ++) 
				std::cout << "Plane with flight number: " << foundPlane.array[i].number << "\n";
				// close for
		} else	// Not found
			std::cout << "There no plane that leave from 2 given airports\n"; 
			// close if
	#endif // CODING
	return 0;
}	// end  main 


// IMPLEMENT

// initialize plane list
PlaneList initial_plane_list() {
	PlaneList list;
	char letter[PLANE_SIZE] = {'a', 'b', 'c', 'd', 'e',
								'f', 'g', 'h', 'j', 'i'};
	for (int i = 0; i < PLANE_SIZE; i++) {
		list.array[i].number = 1000 + i;
		list.array[i].oriPort[0] = 'a';
		list.array[i].oriPort[1] = 'a';
		list.array[i].oriPort[2] = letter[i];
	}	// close for
	// give actual size of list
	list.size = PLANE_SIZE;
	// return list
	return list;
}	// end initial_plane_list


// check if the oriPort of given plane is input airport
bool check_ori(Airline plane, char airport[]) {
	// check each char in the 3 oriPort code
	for (int c = 0; c < CODE_SIZE - 1; c++) 
		if (plane.oriPort[c] != airport[c])
			return false;
		// close for
	// passed 3 code char
	return true;
}	// end check_ori


// find planes that leave from given airport
PlaneList find_plane(PlaneList list, char airport1[], char airport2[]) {
	PlaneList foundList;		// finding list result
	int count = 0;			// index of foundList
	// search all plane in list
	for (int plane = 0; plane < list.size; plane ++ ) {
		// compare plane oriPort with 2 given airport
		bool check1 = check_ori( list.array[plane], airport1 );
		bool check2 = check_ori( list.array[plane], airport2 );
		// true if oriPort match one of 2 
		if ( check1 || check2) {
			foundList.array[count] = list.array[plane];
			count += 1;		// increment count
		}	// close if
	}	// close for
	foundList.size = count;	// set actual size for foundList
	return foundList;
}	// end find_plane