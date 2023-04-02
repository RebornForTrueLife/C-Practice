/********************************************
 * LineNumber - define a class to read a file
 * Uage: 
	- run the object file
	- the program will print out the services of the class
 ********************************************/

#include <iostream>
#include <cstdlib>

// MODE
#define CODING		// code mode
// #undef CODING		// turn off code mode


// CONST
const int FILE_SIZE = 100;		// number of line in the reading file
const int MAX_INSTANCE = 20;	// maximum instances can be created 
const int MAX_CHAR_LINE = 100;	// maximum number of char per line


// FUNC DECLARE
// To generate an array of number of characters in the line(equal to index)
// 		in the file
const int* generate_file(void);


// CLASS DECLARE
// the class to read a single file(for all instances)
class LineNumber {
private:
	static int count;		// the number of instances created
	static LineNumber** readerList;	// list of created instances
	const int INDEX;	// the id of an instances
	static const int* file;	// the reading file
	int line;		// the current reading line index
	int charPos;	// the current reading char position
	const LineNumber* find_nearest_line(int lineAddress) const;

public:
	// constructor
	LineNumber(void);

	// destructor
	~LineNumber(void);

	// to read at given line
	void go_to_line(int lineAddress);

	// to get the current reading line index
	int get_current_line(void) const;

	// to get the current reading char position
	long int get_char_pos(void) const;
};	// close LineNumber


// // // // MAIN
int main(int argc, char const *argv[]) {
	std::cout << "The program is used to define a class to read a single file\n";
	// print services of the LineNumber class
	std::cout << "LineNumber class provide below services:\n";
	std::cout << "\t1. Go to the given line index\n";
	std::cout << "\t2. Get the current reading line index\n";
	std::cout << "\t3. Get the current reading character posistion\n";
	// coding mode
	#ifdef CODING 
		LineNumber reader1;
		reader1.go_to_line(13);
		std::cout << "Current line: " << reader1.get_current_line() << "\n";
		std::cout << "Current char pos: " << reader1.get_char_pos() << "\n";
		LineNumber reader2;
		reader2.go_to_line(34);
		std::cout << "Current char pos: " << reader2.get_char_pos() << "\n";
	#endif 	// CODING
	return 0;
}	// end  main 


// FUNC DEFINE
const int* generate_file(void) {
	static int file[FILE_SIZE];
	// initialize random number of char each line
	for (int i = 0; i < FILE_SIZE; i ++ ) {
		file[i] = (rand() % MAX_CHAR_LINE) + 1;
	}	// close for
	return file;
}	// close generate_file


// CLASS LineNumber

// INITIALIZE static
int LineNumber::count = 0;
LineNumber** LineNumber::readerList = new LineNumber* [MAX_INSTANCE];
const int* LineNumber::file = generate_file();

// FUNC MEMBER DEFINE
/*	constructor(void)
	- to initialize variable members*/
LineNumber::LineNumber(void) : INDEX(count + 1){
	// increase number of instances created
	count += 1;
	// initialize line with -1: means has not read anything yet
	line = -1;
	// initialize char position
	charPos = -1;
	// register to reader list
	readerList[INDEX] = this;
	// prompt to user
	std::cout << "A reader is created successfully\n";
}	// close constructor


/*	destructor(void)
	- to deregister from reader list*/
LineNumber::~LineNumber(void) {
	readerList[INDEX] = NULL;
}	// close destructor


/*	go_to_line(int)
	- to update line and charPos
	- Input: the index of line want to go
	- Output:
		1. If lineAddress is not valid, raise warning
		2. If lineAddress is valid, update line and charPos*/
void LineNumber::go_to_line(int lineAddress)	{
	bool valid = true;	// a flag
	// validate lineAddress
	if (lineAddress >= FILE_SIZE) {
		// raise warning
		std::cout << lineAddress << " is greater than maximum line number: " 
					<< FILE_SIZE - 1 << "\n";
		// set flag to false
		valid = false;
	}	// close if
	// validate lineAddress
	if (lineAddress < 0) {
		// raise warning
		std::cout << lineAddress << " is not valid, must be non-negative\n";
		// set flag to false
		valid = false;
	}	// close if
	// if passed
	if (valid == true) {
		int startLine = 0;	// line to start reading
		int startCharPos = 0;	// start position char to read
		// find the smaller and nearest line index, which being read
		// 		by other instance
		const LineNumber* nearLine = LineNumber::find_nearest_line(lineAddress);
		// check if the nearLine is found
		if (nearLine != NULL) {
			startLine = nearLine->get_current_line();
			startCharPos = nearLine->get_char_pos();
		}	// close if 1
		// start reading
		for (int lineIndex = startLine; lineIndex < lineAddress; lineIndex ++ ) {
			// add number of characters of the reading line
			startCharPos += file[lineIndex];
		}	// close for
		// jump to next begin character of the address line
		startCharPos += 1;
		// update line and charPos
		line = lineAddress;
		charPos = startCharPos;
		// prompt done reading
		std::cout << "Reading line " << lineAddress << "\n";
	}	// close if
}	// close go_to_line


/*	find_nearest_line(int)
	- to find the instance that is reading the line
	that is the nearest and smaller than the line address
	- input: line address
	- output:
		1. NULL - if not found or the found instance is reading at begin of file(line 0)
		2. the const reference to the found instance */
const LineNumber* LineNumber::find_nearest_line(int lineAddress) const {
	// the max index found
	int maxIndex = 0;
	// initialize a variable to hold result
	LineNumber* found = NULL;
	// search in reader list 
	for (int i = 0; i < MAX_INSTANCE; i++) {
		// check if the current element is valid
		if (readerList[i] != NULL) {
			int eleLine = readerList[i]->get_current_line(); // current instance line
			// check if ele's line is NOT greater than line address
			if (eleLine <= lineAddress)
				// check if ele's line greater than maxIndex
				if (eleLine > maxIndex) {
					maxIndex = eleLine;
					found = readerList[i];
				}	// close if 2
				// close if 1
		}	// close if
	}	// close for
	return found;
}	// close find_nearest_line


/*	get_current_line(void)
	- to return the reading line 
	- input: none
	- output:
		1. -1 : if the instance has not read anything yet, and prompt to user
		2. return the reading line*/
int LineNumber::get_current_line(void) const {
	if (line == -1) 
		// promt to user
		std::cout << "The reader has not read anything yet\n";
	return line;
}	// close get_current_line


/*	get_char_pos(void)
	- to return position of current charater
	- input: none
	- output:
		1. -1 : if the reader has not read anything yet, and prompt to user
		2. long int: the position of character*/
long	 int LineNumber::get_char_pos(void) const {
	if (charPos == -1) 
		// promt to user
		std::cout << "The reader has not read anything yet\n";
	return charPos;
}	// close get_char_pos