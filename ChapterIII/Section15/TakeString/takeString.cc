/********************************************
 * takeString - define a function to return the pointer
 * of the first nonwhite string in the given string
 * Uage: 
	- run the object file, passed with a string
	- the program will print out the first nonwhite character in the given string
 ********************************************/

#include <iostream>
#include <iomanip>


// FUNC DECLARE
// to get pointer of the first nonwhite character in the given string
char const *get_char_ptr(char const *string);


// main
int main(int argc, char const *argv[]) {
	std::cout << "The program is used to return " 
				<< "the first nonwhite char in the program arg[1]\n";
	// check if the argv[1] is passed
	if (argc < 2) {
		std::cout << "No string argument passed!\n";
		return -1;
	}	// close if
	// declare a pointer to the first char
	char const *ptr = get_char_ptr(argv[1]);
	// print out the pointer
	std::cout << std::hex;		// print hex number
	std::cout << "The address of first nonwhite char is: " << ptr[0] << "\n";
	std::cout << std::dec;
	return 0;
}	// end  main 


// FUNC DEFINE
char const *get_char_ptr(char const *string) {
	// read each char in string
	while (true) {
		// check if reaching the end of string
		if (*string == '\0') {
			std::cout << "There is no nonwhite char in the given string\n";
			return NULL;
		}	// close if
		// check if the current char is nonwhite char
		if (*string != ' ') 
			return string;
		// iterating string
		string += 1;
	}	// close while
}	// close get_char_ptr