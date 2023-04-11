
# Specification
> To count the number of bits in a character array using register variable


# Code design

## Data
1. input
	- [file] : name of file where the character array is stored

2. output 
	- the number of bits in the character array


## Flow
1. Main
	> `Print` instruction

	> `Get` [file] from argument list

	> `Get` a [string] from the file

	> `Count` number of bits in [string]

	> `print` result 


2. count_bit(char*)
	- take a string and count the number of bit in the string using register variable

	> `take` character array [string]

	> `Set` [startTime]

	> `initialize` [count] = 0

	> `while` TRUE

		> `if` [string][0] is '\0'

			> `Get out`

		<!-- 1 byte = 8 bits -->
		> `Add` 8 to [count]

		<!-- increase the pointer 1 character -->
		> [string] += 1	

	> `Set` [endtime]

	> `print` [executeTime] = [endtime] - [startTime]

	> `return` [count]