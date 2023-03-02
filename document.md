
# List some library function that used in this learning C++ project


1. In `iostream` library
	- cout
	- cin

2. In `iomanip` library: input/output manipulation 
	- set fixed [number] of numbers in decimal part in a float
		```
		> std::cout << std::fixed;
		> std::cout << std::setprecision([number]);
		```

3. In `string` libarary
	- To input a string from any input stream, use command:
		> `std::getline ([source_iostream], [string_variable], [char_deliminate])`, char_delim default is '\n'

		> Eg: std::getline (std::cin, str)