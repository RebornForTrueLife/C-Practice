
# Code design


## Data
1. Input
	- [array] : integer array
	- [size] : size of array

2. Output
	- set all elements in [array] to 0
	- prompt to user


## Code flow
1. main
	> `Print` the instruction of the program

	> `Ask` user to enter the [size] of array

	> `Ask` user to enter the elements of [array]

	> `Call` <set_zero>[array] to set its elements to 0

	> `Prompt` done zero out

	> `Exit`

2. set_zero
	- to set all elements in given array to 0 and its size

	> `take` [array], [size]

	> `Declare` [count] = 0

	> `while` TRUE:

		> `Assign` `*array` = 0

		> `Increase` [array] by 1

		> `Increase` [count] by 1

		> `If` [count] Greater or Equal to [size]

			> `GET OUT` 

	> `Prompt` to done zero out