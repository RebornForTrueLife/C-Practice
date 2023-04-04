
# Code design


# Data 
1. input
	- 2 arguments string: [srcFile] [desFile]
	- NUMBER_SPACE: number of spaces to replace a tab

2. output
	-  cases:
		- unable to open [srcFile]: raise warning
		- [des_file] already existed: raise warning
		- else: read data from [srcFile], replace tab with multi space, write modified data to [desFile]


# Code flow
1. main	
	> `Take` 2 arguments [srcFile] [desFile]

	> `print` instruction

	> `Check` if successful get 2 arguments

		> `If` NOT: raise warning

	> `Call` <copy_modify>[srcFile] [desFile]

	> `Exit`

2. copy_modify
	> `take` [srcFile] [desFile]

	<!-- validate files -->
	> `Check` if [srcFile] is able to open

		> `If` NOT: raise warning

	> `Check` if [desFile] does not exist

		> `If` NOT: raise warning

	<!-- read file -->
	> `Read each` [line] of source file

		> `Assign` [modLine] = `Call` <replace_tab>[line]

		> `Write` [modLine] + '\n' to dest file

	<!-- prompt successfully copy -->
	> `Prompt` to user

3. replace_tab
	- given a string, replace tab with NUMBER_SPACE of space character, return replaced string

	> `take` [string]

	<!-- check each char in string -->
	> `while` TRUE

		> `Assign` [pos] = first index of '\t' in [string]

		<!-- check when there is no tab in string -->
		> `If` [pos] is -1

			> `GET OUT`

		<!-- using member func of string class -->
		<!-- which is replace at [pos] 1 char with Number_space [newChar], which is a space -->
		> `Call` [string]::<replace>[pos] [1] [NUMBER_SPACE] [' ']

		> `return` [string]