
# Code design

## Data
### Input
- number of parallel : a positive integer, [number]
- resistor value - hold all resistor in parallel in each iteration: a float, [value]

### Output
- total resistor - value of total resistor: a float: [total]

## Function flow
### main
- > `Print` out the introduce of the program
- > `Initialize` [total] = 0.0
- > `Ask` user to enter [number] of resistors
- > `Print` prompt to ask user enter the series of float [value]
- > `For each` [value] entered:
	- > `Add` to [total] with the expression: 1/[value];
- > `Assign` [total] with 1/[total]
- > `Print` out the [total]
- > `Exit`