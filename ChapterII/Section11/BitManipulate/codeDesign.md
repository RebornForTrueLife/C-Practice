
# Code design

## Data
1. Input
2. Output
	- print out a 10x10 bitmapped square
3. Used data
	- [graphic] : 2 dimension array of bytes
	- [X_SIZE] : an integer which is the max size of horizontal direction of the graphic array
	- [Y_SIZE] : an integer, max size of vertical direction of the graphic array

## Code flow
1. Main
	> `Print` instruction for this program

	> `Draw` a square with size 10

	> `Print` the graphics array 

	> `Exit`

2. print the graphics array
- This function is to print the graphics array to terminal, with 'X 'value mean the bit set to 1 and '.' value mean the bit is set to 0

	> `For each` [line] in the vertical direction [Y_SIZE]:

		> `For each` [byte] in the horizontal direction: [X_SIZE] / 8:

			> `For each` [bit] in [byte] from 0x80 to 0x01
				<!-- get only current bit -->
				> `If` [graphics][byte][line] & [bit] != 0 		
				<!-- mean current bit is 1 -->
					> `Print` 'x' 

				> `Else`
				<!-- mean current bit is 0 -->
					> `Print` '-''
				<!-- close if -->
		> `Go to` nextline

3. set bit 
- This function is to set selected bit to 1

	> `Take` bit position: [x] [y]

	> `Calculate` [line] of the chosen bit = y

	> `Calculate` [byte] of the chosen bit = x / 8

	<!-- declare a byte with setted bit at the chosen bit position -->
	> `Declare` a [activeByte] = 0x80 >> (x % 8)

	> `Set` bit of [byte] by: [byte] | = [activeByte]

	> `Exit`

4. clear bit
- This function is to clear value of the selected bit, means set it to 0
	
	> `Take` bit position: [x] [y]

	> `Calculate` [line] of the chosen bit = y

	> `Calculate` [byte] of the chosen bit = x / 8

	<!-- declare a byte with setted bit at the chosen bit position -->
	> `Declare` a [activeByte] = 0x80 >> (x % 8)

	> `Assign` [activeByte] with one complement of it: `~ [activeByte]`

	> `Set` bit of [byte] by: [byte] & = [activeByte]

	> `Exit`	

5. test bit
- This function is return the reuslt TRUE or FALSE whether the selected bit is 1 or 0 respectively

	> `Take` bit position: [x] [y]

	> `Calculate` [line] of the chosen bit = y

	> `Calculate` [byte] of the chosen bit = x / 8

	<!-- declare a byte with setted bit at the chosen bit position -->
	> `Declare` a [activeByte] = 0x80 >> (x % 8)

	> `Assign` [activeByte]  & = [byte]

	> `If` the bit is not set: [activeByte] == 0

		> `return` FALSE

	<!-- Else the bit is set -->
	> `return` TRUE

6. draw rectangle
- This function is used to draw [width] x [height] bitmapped-rectangle in the grahics array
- Some used data:
	- CONST: START_X, START_Y: the start bit to draw in X and Y direction

	> `Take` [width], [height] of the square

	> `Check` if the square is fit in the graphics array:

		> `If` (START_X + [width] > X_SIZE ) `OR` (START_Y + [height] > Y_SIZE) 

			> `Raise` warning that the rectangle is not gfit in the graphics array

			> `EXIT`

	<!-- Go to all need active bit in the ractangle And set it to 1-->
	<!-- Draw 2 horizontal lines  -->
	> `Declare` [lineUp] = START_Y

	> `Declare` [lineDown] = START_Y + [height] - 1

	> `For each` [bit] in from START_X to (START_X + [width] -1):

		> `Set_bit` with [x] = [bit].x, [y] = [lineUp]

		> `Set_bit` with [x] = [bit].x, [y] = [lineDown]

	<!-- Draw 2 vertical line -->
	> `Declare` [verLeft] = START_X
	
	> `Declare` [verRight] = START_X + [width] - 1

	> `For each` [bit] from START_Y to START_Y + [height] - 1:

		> `Set_bit` with [x] = [verLeft], [y] = [bit].y
		
		> `Set_bit` with [x] = [verRight], [y] = [bit].y

	> `Exit`
