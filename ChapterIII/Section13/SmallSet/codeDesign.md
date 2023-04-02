
# Code design

## Data
1. Set
	> private:
		- [array] : an int array, represent state of an integer, which is equal to the index. 1 means set, 0 means not set
		- [size] : range of array: [0 .. size - 1]
		- check(int): check if an integer is in range
	
	> public:
		- constructor(): intialize [array] with all 0
		- set(int): set value of corresonding index to TRUE; raise warning if integer is not in the 
		- clear(int): set value of corresponding index to FALSE; ignore if the integer is not valid
		- test(int): test state of an integer; raise warning if the integer is not in the range

## Code flow
0. main
	> `Print` the services of Set class

	> `Exit`

1. Set:: constructor(void)
	> `Set` all value of [array] to 0

2. Set:: check(int)
	> `Take` [number]

	> `If` [number] is in range[0 .. [size] - 1]

		> `Return` TRUE

	> `return` FALSE

3. Set:: set(int)
	> `take` [number]

	> `If` [number] is Not valid:

		> `raise` warning

		> `exit`

	> `Assign` [array][number] = 1

	> `Prompt` to user that it is set

4. Set:: clear(int)
	> `take` [number]

	> `If` [number] is Not valid:

		> `raise` warning

		> `exit`

	> `Assign` [array][number] = 0

	> `Prompt` to user that it is clear

4. Set:: test(int)
	> `take` [number]

	> `If` [number] is Not valid:

		> `raise` warning

		> `exit`

	> `return` [array][number]