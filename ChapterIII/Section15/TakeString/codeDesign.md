
# Code design


## Data
1. input
	- program argument: argv[1]

## Code flow
1. main
	> `Print` the instruction of the program

	> `assign` [ptr] = `Call` <get_char_ptr>[argv[1]]

	> `Print` [ptr]

	> `Exit`

2. get_char_ptr(char*)
	- to return the pointer of the first nonwhite charater in the given string

	> `take` [string]

	> `while` TRUE:

		> `If` [string] is END_OF_STRING

			> `Prompt` there is no nonwhite char in this string

			> `return` NULL

		> `If` [string] is Not SPACE_CHAR

			> `return` [string]

		> `Increase` [string] by 1
