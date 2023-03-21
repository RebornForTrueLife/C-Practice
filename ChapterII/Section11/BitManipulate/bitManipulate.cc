/********************************************
 * bitManipulate - draw a square 10x10 into the terminal
 * Uage: 
	- run the object file
	- the program will print out the square in the terminal
 ********************************************/

#include <iostream>

#define CODING 	// meaning program is still being modifying
#undef CODING	// in implementing mode

// DATA DECLARE
// the horizontal size of the graphics
const int X_SIZE = 60;
// the vertical size of the graphics
const int Y_SIZE = 20;
// a graphics array 2 dimension
char graphics[X_SIZE / 8][Y_SIZE];
// the start position when draw a rectangle
const int START_X = 0;		// horizontal position
const int START_Y = 0;		// vertical position

// FUNCTION DECLARE
/*a function to print the graphics array to teh terminal
	- Input: NONE
	- Output: print to terminal*/
void print_graphics(void);

/*a function to set the input bit to 1
	- input: the position of bit: x and y
	- output: set the bit in given position to 1*/
void set_bit(const int x, const int y);

/*a function to clear the value of the given bit
	- input: the position of the bit: x and y
	- output: set the value of the given bit to 0*/
void clear_bit(const int x, const int y);

/* a function to check if the selected bit is set or not, 
	means its value is 1 or 0
	- input: position of the selected bit: x, y
	- output: a TRUE means it's set, 
	or FALSE means it's not set*/
bool test_bit(const int x, const int y);

/*a function to draw a rectangle with given width and height
which is start from fixed position: START_X and START_Y
	- input: the size of the rectangle: width and height
	- output: draw the rectangle on graphics array
	Note: just draw, not print out*/
void draw_rectangle(const int width, const int height);


// MAIN
int main(int argc, char const *argv[]) {
	int width; 	// width of the rectangle
	int height; 	// height of the rectangle
	// print the instruction of the program
	std::cout << "The program is used to draw a 10x10 squared on the terminal\n";
	// draw the square on the graphics array
	//  // set width and height to the square size
	width = 10;			
	height = 10;
	// The block code will not be compiled while coding
	#ifndef CODING
		draw_rectangle(width, height);
	#endif	// End of CODING
	// print out the gpaphics array
	print_graphics();
	return 0;
}	// end  main 


void print_graphics(void) {
	// travel through each line
	for (int line = 0; line < Y_SIZE; line ++ ) {
		// go through each byte in each line
		for (int byte = 0; byte < X_SIZE / 8; byte ++) {
			// go through 8 bit in the current byte
			for (int bit = 0x80; bit > 0; bit = (bit >> 1)) {
				// check if current bit is set
				if ((graphics[byte][line] & bit) != 0)  		// mean it's set
					std::cout << "X";
				else  	// mean it's NOT set
					std::cout << "_";
			}	// close for 2
		}	// close for 1
		std::cout << "\n";		// go to next line
	}	// close for
}	// end print_graphics


// function to set the selected bit
void set_bit(const int x, const int y) {
	int line = y;			// the line that bit is located
	int byte = x / 8;		// the byte that bit is located
	// the byte that set 1 bit in the given bit location
	int activeByte = 0x80 >> (x % 8);	
	// set the bit in the byte of the graphics array
	graphics[byte][line] |= activeByte;
}	// end set_bit


// function to clear the selected bit
void clear_bit(const int x, const int y) {
	int line = y;			// the line that bit is located
	int byte = x / 8;		// the byte that bit is located
	// a byte that set 1 bit in the given bit's location
	int activeByte = 0x80 >> (x % 8);
	// Take negative of activeByte
	activeByte = ~activeByte;
	// Do an AND to selected byte to set the selected bit to 0
	graphics[byte][line] &= activeByte;
}	// end clear_bit


// function to test if a bit is set
bool test_bit(const int x, const int y) {
	int line = y;			// the line that bit is located
	int byte = x / 8; 	// the byte that bit is located
	// a byte that set 1 bit in the given bit location in a byte
	int activeByte = 0x80 >> (x % 8);
	// check if the selected bit is set 
	//  // activeByte == 0 if the selected bit is not set
	activeByte &= graphics[byte][line];
	if (activeByte == 0)		// the bit is not set
		return false;
	// other case, the bit is set
	return true;
}	// end test_bit


// function to draw a rectangle
void draw_rectangle(const int width, const int height) {
	// check if the rectangle can be fit in the graphics array
	if ((START_X + width > X_SIZE) || (START_Y + height > Y_SIZE)) {
		// print warning 
		std::cout << "The rectangle is not fit in the graphics array\n";
		exit(0);		// exit the program
	}	// close if
	// Draw the rectangle by drawing 2 horizontal lines and 2 vertical line
	// // Draw 2 horizontal lines
	int lineUp = START_Y;						// upper line
	int lineDown = START_Y + height - 1;	// below line	
	int endX = START_X + width - 1;
	// 	go through each bit in 2 lines
	for (int bitX = START_X; bitX <= endX; bitX ++ ) {
		set_bit(bitX, lineUp); 		// set bit in upper line
		set_bit(bitX, lineDown);	// set bit in below line
	}	// close for
	// // Draw 2 vertical line
	int verLeft = START_X; 				// left vertical line
	int verRight = START_X + width - 1; 	// right vertical line
	int endY = START_Y + height - 1;
	// 	go through each bit in 2 lines
	for (int bitY = START_Y; bitY <= endY; bitY ++) {
		set_bit(verLeft, bitY); 		// set bit in left line
		set_bit(verRight, bitY); 		// set bit in right line
	}	// close for
}	// end draw_rectangle