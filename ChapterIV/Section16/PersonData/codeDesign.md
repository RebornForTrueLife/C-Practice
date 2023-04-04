
# Code design


## Data
1. class Person
	> private
		- [ID] 4 number characters, unique for each person
		- [name] string
		- [address] string
		- [phone] string
		- [email] string

	> public
		- constructor(string): create an object with given ID string
		- read_data(string): read information from given file, need to check the ID at the beginning of the file, only read when match with ID of object
		- print_info(void): print the information of the person, prompt warning if not contain information yet


## Code flow

1. main
	> `print` instruction

	> `print` class Person services

	> `Exit`


## Class Person
1. constructor(string)
	- initialize [ID]

	> `take` [ID]

	> `Check` [ID] is exactly 4 character string number

		> `Not`: raise warning


2. read_data(string)
	- read data from given formated file

	> `take` [fileName]

	> `Open` [fileName] --> [inFile]

	<!-- check ID -->
	> `read` first line, `Assign` 4 character to [fileID]

	> `Check if` [fileId] match with [ID]

		> `Not`: raise warning

	> `Declare` [count] = 0

	> `Declare` string [array]

	> `while` TRUE

		> `if` [inFile] reach END_OF_FILE

			> `GET OUT`

		> `If` [count] Greater or Equal to 4

			> `GET OUT`

		> `read` [line] of [inFile]

		> `put` [line] to [array]

		> `Increase` [count] by 1

	> `If` [count] is Not 4:

		> `raise` warning: file is not enough infomation

	> `Assign` [array] sequentially into [name], [address], [phone], [email]

3. print_info(void)
	- print info of person to screen

	> `check if` [name] is empty

		> `Yes`: prompt that data is empty

		> `return`

	> `print` [name] [address] [phone] [email] 