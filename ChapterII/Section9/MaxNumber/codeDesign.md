
# Code design

## Data
1. Input 
	- [size] : the size of the array
	- [value] : a variable to hold values of array
2. Output
	- [maxValue] : max value of the array
3. used data
	- const MIN_FLOAT

## Code flow
1. Main
	> `Print` the instruction of the program

	> `Initialize` [maxValue] = MIN_FLOAT

	> `Ask` user to enter the size of the array

	> `For each` [value] in array:

		> `If` [maxValue] < [value]

			> [maxValue] = [value]

	> `Print` out the [maxValue]

	> `Exit` 