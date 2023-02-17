
# Code design

## Data

### Input
- a positive integer: number of float in the series: [size]
- a float: which will hold the values of each float: [value]

### Output
- 2 integer: [posCount] and [negCount] which count the number of positive and negative floats respectively

## Code flow
1. Main
- > `Initialize` [posCount] and [negCount] by 0
- > `Give` instruction to user about this program
- > `Ask` user to enter number of float in the series
- > `Print` promt to tell user to enter the series of float numbers
- > `With` each [value] entered:
	- > `Check` if [value] > 0: `increment` [posCount]  by 1 AND `continue`
	- > `Check` if [value] < 0: `increment` [negCount]  by 1
- > `Print` out the number of positive values: [posCount] 
and number of negative values: [negCount]
