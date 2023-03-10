
# Code design

## Data
1. Input 
	- a value 
2. Output
	- a promt that state if the value is divisible by 10 or not

## Code flow

1. Main
	> `Print` the instruction of the program

	> `Ask` user to enter the value

	> `Use` macro to check if the value is divisible by 10

	> `Print` the result

2. Marco
	`#define DIV10(number) 	( ((number) % 10 == 0) )`