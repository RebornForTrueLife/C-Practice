
# Code design

## Data
1. Input 
- [number] : the input number, an integer

2. Output
- [result] : an integer, which is the number that was shifted all set bit in the [number]

## Code flow
1. Main
	> `Print` out the program instruction

	> `Ask` user to enter the [number]

	> `Shift` all bits in [number] to the left end

	> `Print` [result] out

	> `Exit`

2. shift_bit
- A function to shift all bit in a given number to its left end
	> `Take` [number]

	> `Initialize` [result] with 0x0000

	> `Initialize` [pos] by 0, which is the current position bit of [result]

	> `For each` [bit] in [number]

		> `If` [bit] is set:

			> `Set` bit at [pos] of [result]

			> `Increment` [pos] by 1

	> `return` [result]

