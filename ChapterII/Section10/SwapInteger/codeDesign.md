
# Code design

## Data
1. Input
	- [int1] : an integer
	- [int2] : an integer
2. Output
	- Swapping value of [int1] and [int2]
	- Print out the result

## Code flow
1. Main
	> `Print` the program instruction

	> `Ask` user to enter 2 integers

	> `Swap` [int1] and [int2]

	> `Print` the result of [int1] and [int2]

	> `Exit`

2. Macro
- SWAP_INT
	> parameters: a, b

	> code: 

		> `1`: a = a + b: 	( (a) = ( (a) + (b) ) )

		> `2`: b = a - b: 	( (b) = ( (a) - (b) ) )

		> `3`: a = a - b: 	( (a) = ( (a) - (b) ) )

		> `{ 	( (a) = ( (a) + (b) ) );\
				( (b) = ( (a) - (b) ) ); \
				( (a) = ( (a) - (b) ) ); \
			}`