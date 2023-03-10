
# Code design

## Data
1. Input
	- [c] : a character, which is to be checked
2. Output
	- print out the result if [c] is a digit, a hex-digit
3. Used info
	- a digit in range [0..9] ~ [48..57]
	- a hex digit in range [0..9] [A..F] [a..f]
		- [A-F] ~ [65..90]
		- [a..f] ~ [97..122]

## Code flow
1. Main
	> `Print` the instruction of the program

	> `Ask` user to enter [c]

	> `Check` if [c] is a digit, a hex-digit

	> `Print` out the result

2. Macros
	1. IS_DIGIT
		> parameter: c

		> code: `( ((c) >= 0) && ((c) <= 9) )`

	2. IS_HEX
		> parameter: c

		> code: `( ( ((c) >= 65) && ((c) <= 90) ) || ( ((c) >= 97) && ((c) <= 122) ) || IS_DIGIT(c) )`