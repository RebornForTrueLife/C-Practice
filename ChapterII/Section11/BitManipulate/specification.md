
# Bit manipulate

***create some function to manipulate bits***

*Preliminary Specification*

## Purpose
> The program is used to create some func to manipulate bits: clear_bit, test_bit, set_bit

## Desciption
- These functions are used in bitwise graphic to control each bit in a matrix of pixel: X_SIZE x Y_SIZE, represented by a 2 dimension array of bytes with size is: [X_SIZE/8, Y_SIZE]
	- a bit located in [x, y] : which is located in the [x%8] bit of element [x/8, y] in the bytes array
- What we can manipulate bits:
	1. set a bit with its bit location: [x, y]
	2. clear a bit with its location, mean set it to 0
	3. test a bit with a value(0 or 1) 
	4. a function to print the graph out to the terminal

## Example
```
	$ The program is used to manipulate each bit in a graphic array of 40x60
	$ The program can set, clear, test each bit
	$ And the demo is to draw a 10x10 square
	$ ... (a quare in terminal)
	$ EXIT
```