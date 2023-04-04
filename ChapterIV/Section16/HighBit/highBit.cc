/********************************************
 * highBit - copy a file to a new file after removing 
 * all character with high bit set
 * Uage: 
	- run object file, pass 2 string: [source file name]
	and [destination file name]
	- the program read the srcFile; remove char with high
	bit set; write data to desFile
	- the program will prompt if successfully copied
 ********************************************/

#include <iostream>
#include <fstream>


// FUNC DECLARE
/*	copy_modify(string, string)
	- to read the source file; remove all char with high
	bit set; write to destination file
	- input: source file name; destination file name
	- output: 3 cases
		1. Unable to open source file: raise warning
		2. DesFile already existed: raise warning
		3. else, prompt successfully copied*/
void copy_modify(const char* srcFile, const char* desFile);


// main
int main(int argc, char const *argv[]) {
	std::cout << "The program is used to read a file; remove "
		<< "all character with hight bit set; write to a new file\n\n";
	// check the number of arguments
	if (argc != 3) {
		std::cerr << "Need to give exactly 2 arguments: \n"
			<< "\t[source file name] [destination file name]\n"
			<< "\t[destination file]: must haven't existed\n\n";
		exit(8);
	}	// close if
	// copy file
	copy_modify(argv[1], argv[2]);
	return 0;
}	// end  main 


// IMPLEMENT

// copy modified data
void copy_modify(const char* srcFile, const char* desFile) {
	// check able to open srcFile
	std::ifstream inFile(srcFile, std::ifstream::in | std::ifstream::binary);
	if (inFile.is_open() == false) {
		std::cerr << "Unable to open source file: '" << srcFile << "'.\n";
		exit(-1);
	}	// close if
	// check if desFile exited
	std::ifstream checkOpen(desFile, std::ifstream::in);
	if (checkOpen.is_open()) {
		std::cerr << "The destination file already exited. Deny to overwrite!\n";
		exit(-1);
	}	// close if
	// Open destination file
	std::ofstream outFile(desFile, std::ofstream::out | std::ofstream::binary);
	// read each byte in srcFile
	char *buffer = new char[1];	// hold each byte
	while (true) {
		// terminate cond
		if (inFile.good() == false) 	// end of file
			break;
		// read 1 byte
		inFile.read(buffer, 1);
		// check if the byte does not set the high bit
		if ( (buffer[0] & 0x80) == 0 )
			// write byte to desFile
			outFile.write(buffer, 1);
	}	// close while
	// prompt to user
	std::clog << "Successfully copied file!\n";
}	// close copy_modify