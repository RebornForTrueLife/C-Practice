
# Code design

## Data
### Input 
- number of floats: an integer: [number]
- value of each float: a float: [value]

### Output
- average value: a float: average

## Function flow
1. Main
- > `Print` out the instruction of the program
- > `Initialize` [average] = 0.0
- > `Ask` user to enter [number] of float
- > `Print` prompt to ask user enter the series of float [value]
- > `For each` [value] entered:
	- > `Add` to [average] with the expression: [value];
- > `Divide` [average] by [number] of floats
- > `Print` out the [average]
- > `Exit`