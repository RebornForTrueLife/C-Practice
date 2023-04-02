
# Code design


## Data

<!-- NOTE: for get_char_pos, initilize array of number characters at the index line -->
0. Used data
	- [file] : an integer array, each element hold the number of characters in corresponding line-which is the index.
		> this [file] will be created randomly
	- SIZE: the number of line(elements) in [file]


1. LineNumber
	> private
		- [file] : the shared file, each class has a single file
		- [line] int : current line number that the instance point to
		- [charPos] int : the position(in term of file) of first character at the current line
		- (static) [count] int : the number object that has been created, to index the new object
		- (const) INDEX : the ID of an object
		- (static) [readerList] : contain a list of instances that are still existing.
			> [readerList] is a map between: INDEX and corresponding object.
		- find_nearest_line(int): find the LineNumber instance which is reading nearest and smaller than the given lineAddress
	> public
		- constructor(void): to initalize INDEX, increase [count], register to [readerList]
		- destructor(void): to deregister from the [readerList]
		- go_to_line(int) : update [line], [charPos]
		- get_current_line(void): return [line]
		- get_char_pos(void): return [charPos]


## Code flow

1. main
	> `Print` the instruction of program

	> `Print` the services of LineNumber class

	> `Exit`

2. generate_file(int)
	- to generate an array of number of characters in the line(equal to index); given the number of line

	> `For each` [lineIndex]

		> `Assign` [array][lineIndex] = <random>[1..100]

	> return [array]


## Class LineNumber

### Initialize static
- `Initialize` [count] = 0
- `Initialize` [readerList] --> EMPTY

### Func members
1. constructor(void)
	- to initialize member variable
	> `Increase` [count] by 1

	> `Initialize` INDEX = [count]

	> `Initialize` [line] = -1

	> `Initialize` [charPos] = -1

	> `register` to [readerList]


2. destructor(void)
	- to deregister current instance from [readerList]

	> `Remove` element with id INDEX from the [readerList]

3. go_to_line(int)
	- to update [line] and [charPos]

	> `take` [lineAddress]

	<!-- check if the line address is valid -->
	> `Check` if [lineAddress] is smaller than <size_of>[file]

		> `If` Not: `raise` warning

		> `Exit`

	> `Call` <find_nearest_line>[lineAddress], `assign` LineNumber instance found to [nearLine]

	<!-- the line number start to read forward -->
	> `Declare` [startLine] = 0

	<!-- the char pos start to read forward -->
	> `Declare` [startCharPos] = 0

	> `If` [nearLine] is Not NULL:

		> `Assign` [startLine] = `Call` [nearLine]::<get_current_line>

		> `Assign` [startCharPos] = `Call` [nearLine]::<get_char_pos>

	> `For each` [lineIndex] from [startLine] to [lineAdress] - 1:

		> `Add` [startCharPos] with [file][lineIndex]

	> `Incease` [startCharPos] by 1 to point to first char of [lineAddress]

	> `Assign` [charPos] = [startCharPos]

	> `Assign` [line] = [lineAddress]

4. get_current_line(void)
	- to return the current line index

	<!-- `Check` if [line] has been assigned to valid index -->
	> `If` [line] Equal to -1:

		> `prompt` the instance has not read anything yet

	<!-- else -->
	> `return` [line]

5. get_char_pos(void)
	- to return the current char position
	<!-- check if the current char pos is valid -->
	> `If` [charPos] is -1:

		> `Prompt` the instance has not read anything yet

	<!-- else -->
	> `return` [charPos]

6. find_nearest_line(int)
	- to find the LineNumber instance which is reading the nearest and smaller than the given line address

	> `take` [lineAddress]

	> `Initialize` [maxIndex] = 0

	> `Initialize` [found] = NULL

	> `For each` [lineNumber] in [readerList]:

		> `if` the [lineNumber]::line Smaller or Equal to [lineAddress]

			> `If` the [lineNumber]::line Greater than [maxIndex]

				> `Assign` [maxIndex] = [lineNumber]::line

				> `Assign` [found] = [lineNumber]

	> `return` [found]

