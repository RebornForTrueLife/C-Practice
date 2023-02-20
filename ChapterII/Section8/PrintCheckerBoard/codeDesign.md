
# Code design


## Data
### Input
> Size of checkboard: an integer; GREATER than 0; [size]

## Function flow
1. Main
- > `Print` out the info about this program
- > `Ask` user to enter [size]
- > `Operate` 'printCheckBoard' to print out the checkboard
- > `Exit`

2. Print checkboard
- > `Take` [size]
- > `Calculate` number of row: [numberRow] = 1 + 4 \* [size]
- > `For each` [row], `Check` if [row] divisible by 4:
	- > `If ` true:
		- > `Print` "+"
		- > `Print` "-----+" `For` [size]times
	- > `Else`:
		- > `Print` "|"
		- > `Print` [number_space_each_square_unit] and "|" `For` [size] times
	- > `Print` new line character
- > `Exit`