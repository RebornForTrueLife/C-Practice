
# Code design

## Data
1. Input
	- [inputString] : a string
2. Output
	- [inputString] : after replaced \- with \_

## Code Flow
1. Main
	> `Print` the instruction of the program

	> `Ask` user to enter the string

	> `Replace` the \- with \_ in the [inputString]

	> `Print` out the replaced string

	> `Exit`

2. replaceChar
- A function to replace \- with \_ in the given string

	> `Take` [inputString]

	> `For each` [char] in [inputString]:

		> `If` [char] == \-:

			> `Assign` [char] = \_

	> `Return` [inputString]