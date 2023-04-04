
# Code design


## Data
1. input
	- argv[1] - [inFile]: input file containing integer list

2. output
	- 2 cases:
		1. raise warning if can not read the input file
		2. prompt to user if done write to a new file(show the des file name)


## Code flow
1. main
	> `Print` the instruction 

	> `validate` number of argument( Equal to 2 ):

		> `INVALID`: raise warning

	> `Call` <write_binary>[argv[1]] to read file and write new file in binary format

	> `Exit`

2. write_binary
	- to read the list of integer in a file; write the list in a new file(list.dat) in binary format

	> `take` [inFile]

	> `Check if` being able to open [inFile]

		> `NOT`: raise warning

	> `Open` [outFile] which is used to stored ninary data

	> `Read each` [number] in the [inFile]

		> `write` <binary>[number] into [outFile]

	> `Prompt` to [outFile]