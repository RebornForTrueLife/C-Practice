
# Code design

## Data
1. Parity
	- Private members:
		1. count: an integer: the number of items in its storage
	- Public members
		1. put(int): put a integer into storage
		2. test(void): check if count is even or odd

## Code flow
1. main
	> `Print` the services of Parity class

	> `Exit`

2. Parity:: construction
	> `Initial` [count] = 0

3. Parity:: put
	- increase the count of number of items

	> `Take` [item]

	> `Increment` [count] by 1

4. Parity:: test
	- check if [count] is even or odd, if [count] is even return TRUE, vice versa

	> `If` [count] is even:

		> `Return` TRUE

	> `Return` FALSE

