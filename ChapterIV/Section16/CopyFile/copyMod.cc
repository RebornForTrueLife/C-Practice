/********************************************
 * copyMod - copy a file to a new file after replace 
 * tab with multiple spaces
 * Uage: 
	- run object file, passed 2 arguments: (1)source file 
	and (2) destination file name
	- the program will copy modified data of file source
	and to destination file
 ********************************************/

#include <iostream>
#include <string>
#include <fstream>


// CONST
const int NUMBER_SPACE = 4;		// number of space to replace tab
const int SIZE_LINE = 100;		// max number char in a line

// FUNC DECLARE
/*	copy_modify(string, string)
	- read src file, replace every tab with multiple spaces, and 
	write modified data to desFile
	- input: source file and destination file name
	- output: 3 cases
		1. souce file is unable to open: raise warning
		2. destination file already existed: raise warning
		3. else, prompt successfully copied*/
void copy_modify(const std::string srcFile, const std::string desFile);

/*	replace_tab(string, int)
	- to replace every tab in the string with number of 
	spaces
	- input: string, and number of spaces to replace
	- output: a string after being replaced */
std::string replace_tab(std::string str, const int amount);


// // // main
int main(int argc, char const *argv[]) {
	std::cout << "The program is used to copy a file to a new file "
		<< "after replacing tab with multi spaces\n\n";
	// check enough argument passed
	if (argc < 3) {
		std::cerr << "The program need 2 passed arguemnt: [source file] "
			<< "and [destination file]\n";
		exit(8);
	}	// close if
	// copy file
	std::string srcFile = argv[1];
	std::string desFile = argv[2];
	copy_modify(srcFile, desFile);
	return 0;
}	// end  main 


// FUNC DEFINE

// copy file
void copy_modify(const std::string srcFile, const std::string desFile) {
	// open source file
	std::ifstream inFile(srcFile, std::ios::in);
		// check opening source file
	if (inFile.is_open() == false) {
		std::cerr << "Unable to open source file: '" << srcFile << "'. \n";
		exit(-1);
	}	// close if
	// open des file
		// check if desFile is exist 
	std::ifstream existFile(desFile);
	if (existFile.is_open()) {		// mean des file exist
		std::cerr << "The destination file already existed, deny to overwrite file\n";
		exit(-1);
	}	// close if
	std::ofstream outFile(desFile, std::ios::out);
		// check creating des file
	if (outFile.is_open() == false) {
		std::cerr << "Unable to create NEW destication file: '" << desFile << "'.\n";
		exit(-1);
	}	// close if
	// Read each line of source file
	char line[SIZE_LINE];	// a string to hold a read line
	std::string modLine;		// string to hold modified line
	while (true) {
		// terminate cond
		if (inFile.good() == false)
			break;
		// read line
		inFile.getline(line, sizeof(line));
		// replace tab with spaces
		modLine = replace_tab(line, NUMBER_SPACE);
		// write modified line to file
		outFile << modLine << '\n';
	}	// close while
	// close all file
	inFile.close();
	outFile.close();
	// prompt to user
	std::clog << "Copied successfully!\n";
}	// close copy_modify


// replacing tab with multi spaces
std::string replace_tab(std::string str, const int amount) {
	// loop until there is no tab in the input string
	while (true) {
		// find tab index in string
		std::size_t pos = str.find('\t');
		// terminate cond
		if (pos == std::string::npos)
			break;
		// replace tab with number of spaces
		str.replace(pos, 1, amount, ' ');
	}	// close while
	return str;
}	// close replace_tab