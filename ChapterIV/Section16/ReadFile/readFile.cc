/********************************************
 * readFile - read a file and return number of line in it
 * Uage: 
	- run the object file, passed the  name of file
	in object_file dir
	- the program will read the file and return number of
	lines in the file
 ********************************************/

#include <iostream>
#include <fstream>


int main(int argc, char const *argv[]) {
	std::cout << "The program is used to read a file(name: argument passed) "
				<< "and print out the number of lines in the file\n";
	// check argument
	if (argc != 2) {
		// std::cout << argc << "\n";
		// argument does not match
		std::cerr << "The argument number is not match\n"
					<< "There is 1 arg: [file_name]\n";
		exit(8);					
	} 	// close if
	// open file
	std::ifstream openFile;
	openFile.open(argv[1], std::ifstream::in);
	if (!openFile.is_open()) {
		std::cerr << "Unable to open file: " << argv[1] << " for reading\n";
		exit(-1);
	}	// close if
	// reading each line
	int count = 0;	// number of lines
	char buffer[1000];	// buffer to read line
	while (openFile.good()) {
		openFile.getline(buffer, sizeof(buffer));
		count += 1;
	}	// close while
	// print the number of line
	std::cout << "Number of line in file: " << count << "\n";
	return 0;
}	// end  main 