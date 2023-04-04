/********************************************
 * Person - the program define a class Person to read 
 * data from file and store personal data
 * Uage: 
	- run object file
	- the program will print out the services of Person class
 ********************************************/

#include <iostream>
#include <fstream>
#include <string>


// MODE
#define CODING		// coding mode
// #undef	CODING		// turn off


// CONST
const int NUMBER_FIELD = 4; 	// number of info fields
const int STRING_SIZE = 100;	// size of an info field
const int ID_SIZE = 4;			// number of char in ID


// CLASS DECLARE
class Person {
private:
	std::string ID;	// unique id of an instance
	std::string name;	// person name
	std::string address;	// person home address
	std::string phone;	// person's phone number
	std::string email;	// mail address

public:
	// constructor: initialize ID
	Person(std::string id);

	// destructor
	// ~Person();	// default

	// read data from formated file
	void read_data(std::string fileName);

	// print person information
	void print_info(void);
};	// close Person


int main(int argc, char const *argv[]) {
	std::cout << "The program is used to define class Person\n";
	std::cout << "Person class provide 2 services:\n";
	std::cout << "\t1. Read data from formated file\n";
	std::cout << "\t2. Print the person's information\n";
	// coding mode
	#ifdef CODING
		Person p("1234");
		p.read_data("data.in");
		p.print_info();
	#endif	// CODING
	return 0;
}	// end  main 


// PERSON:: FUNC DEFINE
/*	constructor(string) */
Person::Person(std::string id) {
	// check if id is exactly 4 characters
	if (id.length() != 4) {
		std::cerr << "The given Id must be a 4-character-number string\n";
		exit(8);
	}	// close if
	ID = id;
	std::clog << "Successfully created an instance Person id: " << id << "\n";
}	// close constructor


/*	read_data(string)
	- to read person information from formated file; the format
	of the file is described in specification file.
	- input: data file name
	- output: 2 case
		1. if unable to open file: raise warning
		2. if file is not right format: raise warning
		3. else, promt successfully read*/
void Person::read_data(std::string fileName) {
	// check if being able to open file
	std::ifstream inFile(fileName);
	if (inFile.is_open() == false) {
		std::cerr << "Unable to open file: '" << fileName << "'.\n";
		return;
	}	// close if
	// check ID of file
	char fileId[ID_SIZE + 1];
	inFile.getline(fileId, ID_SIZE + 1);
	if (ID.compare(fileId) != 0) {
		std::cerr << "The file's id does not match the person's id\n";
		std::cerr << "### " << ID << " : " << fileId << "\n";
		return;
	}	// close if
	// read next NUMBER_FIELD lines of the file
	int count = 0; 	// number of fields read
	std::string array[NUMBER_FIELD];
	while (true) {
		// terminate conditions
		if (inFile.good() == false)	// end of file
			break;
		if (count >= NUMBER_FIELD)	// only read NUMBER_FIELD line
			break;
		// read line
		char line[STRING_SIZE + 1];
		inFile.getline(line, STRING_SIZE + 1);
		// put value to array
		array[count].assign(line);
		// increase count
		count += 1;
	}	// close while
	// check if read enough fields
	if (count != 4) {
		std::cerr << "The file does not contain enough data\n";
		std::cerr << "\tNumber of fields: " << NUMBER_FIELD << "\n";
		return;
	}	// close if
	// assign info to fields
	name = array[0];
	address = array[1];
	phone = array[2];
	email = array[3];
	// prompt 
	std::clog << "Successfully read data\n";
}	// close read_data


/*	print_info(void)
	- to print all personal data, raise warning if the 
	data is empty*/
void Person::print_info(void) {
	// print name
	if (name.empty())
		std::cout << "Name:\tMISSING\n";
	else
		std::cout << "Name:\t" << name << "\n";
	// print address
	if (address.empty())
		std::cout << "Address:\tMISSING\n";
	else
		std::cout << "Address:\t" << address << "\n";
	// print phone
	if (phone.empty())
		std::cout << "Phone:\tMISSING\n";
	else
		std::cout << "Phone:\t" << phone << "\n";
	// print email
	if (email.empty())
		std::cout << "Email:\tMISSING\n";
	else
		std::cout << "Email:\t" << email << "\n";
}	// close print_info