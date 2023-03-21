
# Code design

## Data
1. Input
	- [number] : an integer
2. Output
	- [count] : an integer, which is the number of set bit in [number]

## Code flow
1. Main
	> `Print` the instruction of the program

	> `Ask` user  to enter [number]

	> `Count` the number of set bit in the given integer

	> `Print` out the result

	> `Exit`

2. count_set_bit
	- A function to count the number of set bit in the given integer

	> `Take` an integer [number]

	> `Initialize` [count] = 0

	> `For each` set [bit] from 0x8000 to 0x0001

		<!-- `Check` if the bit at [bit] position of [number] is set -->
		> `Check` if [number] & [bit] != 0:

			> `Increment` [count] by 1

	> `return` [count]
