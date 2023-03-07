
# Code design

## Data
1. Input 
	- [number] - an integer; the number to be found in the array
	- [array] - an integer array
	- [size] - an integer; length of the array: should be in range of short_int = 32767
2. Output
	- [count] - an integer: the number of times [number] appears in [array]
3. Used data
	- MAX_SIZE = SHORT_MAX_INT = 32767

## Code flow
1. Main
	> `Print` the instruction of the program

	> `Ask` user to enter [size]

	> `Ask` user to enter [array]

	> `Ask` user to enter [number]

	> `Count` number of times [number] appears in [array], `Assign` result to [count]

	> `Print` result

	> `Exit`

2. Count occur
- *A function to count the number of time a given number appears in the given array with the given length. It's recursive function*
	- Divide the problem by: we only check 1 element at each `call`, from last to begin element; 
		- if the current element [i] Equal to the number then Increment return value by 1 and added with the return value of sub_Array, which is array[0..i-1]
	- End point: [size] == 0, return 0, cuz the array already done checking
	
	> `Take` [number], [array], [size]

	> `If` [size] == 0:

		> `Return` 0

	> `Else`:

		> `If` [number] == array[size-1]

			> `return` 1 + `Call`([number], [array], [size] - 1)

		> `Else` 

			> `return` `Call`([number], [array], [size] - 1)