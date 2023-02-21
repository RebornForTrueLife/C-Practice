
# Code design

## Data

### Input
- the greatest number in the table: a positive integer [size]

### Output
- print out the multiplication number

## Code flow
1. main
- > `Print` the instruction for the program
- > `Ask` user to enter [size]
- > `Operate` the procedure to print out the multiplication number
- > `Exit`

2. printMulTable
- > `Take` an int [size]
- > //`Print` the first row([row] = 0) of table by:
	- > `Print` [tab]
	- > `For each` [number] in [1..size]:
		- > `Print` [number]
		- > `Print` [tab]
	- > `Print` [new line]
- > `For each` [row] in table[1..size]:
	- > `Print` [row] & a 'tab'
	- > `For each` [number] in [1..size]:
		- > `Print` the multiplication between [row] and [number]
		- > `Print` [tab]
	- > `Print` [new line]
- > `Exit`