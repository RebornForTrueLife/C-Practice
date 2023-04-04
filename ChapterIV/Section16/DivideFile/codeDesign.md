
# Code design


## Data 
1. input
	- argv[1] -> [inFile]: name of file containing a list of integers
	- [divisible.out], [notDivisible.out] : name of 2 output files

2. output
	- 2 cases
		1. unable to read [inFile]	
			> raise warning
		2. else, write numbers divisible by 3 in [divisible.out] and other numbers to [notDivisible.out]


## Code flow
1. main
	> `take` [inFile]

	> `print` the instruction

	> `Call` <divide_file>[inFile]

	> `Exit`

2. divide_file
	- open [inFile], read list of integers; find all numbers divisible by 3, write them into [divisible.out], other numbers write to [notDivisible.out]

	> `take` [inFile]

	> `Check` if being able to open [inFile]

		> `Not`: raise warning

	> `Read each` [number] in [inFile]:

		> `Check if` [number] is divisible by 3:

			> `Yes`: `write` [number] to [divisible.out]

			> `NO`: `write` [number] to [notDivisible.out]

	> `Prompt` to user
