
# Code design

## Data

### Input 
- an integer: [number] <= 100
- All cases input can be:
	- from 0 to 9: zero, one, two, three, four, five, six, seven, eight, nine
	- from 10 to 19: ten, eleven, twelve, thirteen, fourteen, fifteen, sixteen, seventeen, eighteen, nineteen
	- from 20 to 99: twenty, thirty, forty, fifty, sixty, seventy, eighty, ninety. Special case with 0 after
	- 100: one hundred

### Used data
- a constant string array of [zero .. nine] : ONE_WORD[10]
- a constant string array of [10..19]: TEEN_WORD[10]
- a constant string array of [20, 30...90]: TEN_WORD[8]
- a string for 100: HUNDRED = "one hundred"
- A global integer array to hold the return value of function: the size of array is the [number of digit in MAX_INT] + [1 number holding array size] = 10 + 1 =11: arrayReturn[11]
- size of arrayReturn = MAX_SIZE

### Output
- print out the word of each digit in [number]

## Code flow

1. main
	> `Print` the instruction of the program

	> `Ask` user to enter [number]

	> `Check` if [number] is a non-negative integer

		> If not, raise error and `Exit` program

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

	> `Initialize` [index] of the first digit of number in the [array]

	> `With each` cases:

		> `Case` 1: 

			> `Get` value in ONE_WORD array with index is the digit located in [index] of the [array]

			> `Assign` the value to [word]

		> `Case` 2: 

			> `Get` the [tensPlace] of the number = value of array at [index]

			> `Get` the [onesPlace] of the number = value of array at [index + 1]

			> `Check` if [tensPlace] == 1:

				> Is TRUE, [word] = value of arrayTEEN_WORD at index is [onesPlace]

				> IS FALSE: [word] = value of array TEN_WORD at index is ([tensPlace] - 2) *cuz array start from word of 20*

					> `If` [onesPlace] != 0 is TRUE:

						> `Add` value of array ONE_WORD at index: [onesPlace] to [word]

		> `Case` 3: 

			> `Assign` [word] with HUNDRED 
	
	> `Return` [word]