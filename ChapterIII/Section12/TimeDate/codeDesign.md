
# Code design

## Data
1. TimeDate
	- used to store time and date
	- Fields
		1. min : an integer, [1, 60]
		2. hour: an integer, [0, 23]
		3. day: an integer, [1, 31]
		4. month: an integer, [1, 12]
		5. year: an integer
	- Method:
		1. time_diff: to find difference timeDate1 and timeDate2 in minutes by take timeOF_timeDate1 - timeOf_timeDate2

## Code flow
1. main
	> `Print` the interface of TimeDate data type
	> `Exit`

2. time_diff
	> `Take` [timeDate1] [timeDate2]

	<!-- convert time to minutes -->
	> `Assign` [min1] with totol minutes of [timeDate1]

	> `Assign` [min2] with total minute of [timeDate2]

	> `Assign` [minDiff] with [min1] - [min2]

	> `return` [minDiff]