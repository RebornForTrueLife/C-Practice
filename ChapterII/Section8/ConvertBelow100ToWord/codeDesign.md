
# Code design

## Data

### Input 
- an integer: [number]
- a constant string array of [zero .. nine] with element is the word of 
corresponding index: NUMBER_WORD[10]
- A global integer array to hold the return value of function: the size of array is the [number of digit in MAX_INT] + [1 number holding array size] = 10 + 1 =11: arrayReturn[11]
- size of arrayReturn = MAX_SIZE

### Output
- print out the word of each digit in [number]

## Code flow

1. main
	> `Print` the instruction of the program

	> `Ask` user to enter [number]

	> `convert` number to word 

	> `Print` out the result

2.  convertNumberToArray
- *convert an non-negative integer into an array with the size of number is allocated in index 0 of the array, and digits of number  will be held in the last elements of the array. For example: number 123 will be convert to`array = {[size] ... [1][2][3]}`*

	> `Take` a non-negative integer [number]

	> `Declare` [index] that initialized from last index of the [arrayReturn]

	> `while` there is still digit left in [number]:

		> `Take` last digit(modulo 10) of [number], `assign` to element in [index] location in the [arrayReturn]

		> `Decrement` [index] by 1

		> `Remove` last digit from [number]

	> `Assign` arrayReturn[0] by size of [number] = (MAX_SIZE - 1) - [index]

	> `Return` arrayReturn;

3. convertArrayToString
- *convert the array of number(with the size is in index 0) into a string of words*

	> `Take` an array in format of [arrayReturn]

	> `Declare` an empty string [word]

	> `Assign`[size] of number = arrayReturn[0]

	> `For each` [value] from last [size] elements of arrayReturn, in left to right order:

		> `Add` the element of NUMBER_WORD array, with index is [value], to  string [word]

	> `Return` [word]