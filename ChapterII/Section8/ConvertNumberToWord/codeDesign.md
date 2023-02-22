
# Code design

## Data

### Input 
- an integer: [number]
- a constant string array of [zero .. nine] with element is the word of 
corresponding index

### Output
- print out the word of each digit in [number]

## Code flow

1. main
	> `Print` the instruction of the program

	> `Ask` user to enter [number]

	> `convert` number to word 

	> `Print` out the result

2.  convertNumberToArray
- *convert an non-negative integer into an array with the size of number is allocated 
in index 0 of the array*

3. convertArrayToString
- *convert the array of number(with the size is in index 0) into a string of words*
