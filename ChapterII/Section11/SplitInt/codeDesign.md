
# Code design

## Data
1. Input
	- [number] - long int 
2. Output
	- print 8 4-bit values that are splitted from [number]

3. Used data
	- [array] - an int array - size of 8, which holds 8 4-bit values

## Code flow
1. Main
	> `Print` the instruction of the program

	> `Ask` user to enter an integer

	> `Split` [number] into 4-bits values and `Put` in [array]

	> `Print` [array] out 

	> `Exit`

2. split_int
	- this function is used to split an long integer into 8 4-bit values, and store them into array

	> `Take` an long int

	<!-- pb: position of current bit -->
	> `Initialize` [pb] = 0;

	<!-- read each 4-bit chunk in the integer -->
	> `For each` [chunk] in the integer = bits from [pb] to [pb] + 3

		> `Check` if [bit-0] == 1:

			> `If` true, [byteHolder] = - 0x1

			> `Else`, [byteHolder] = 0x0
		<!-- read 3 bits left -->
		> `From` [bit-1]  to [bit-3]:

			> `Set` [bit-i] to [bit- (i + 4)] of [byteHolder]

		> `Push`  [byteHolder] ino [array]

	> `Return` array