
# Code design


## Data
1. input
	- 2 arguments: [srcFile], [desFile] : string, file names

2. output
	> Cases
		1. Unable to open [srcFile]: raise warning
		2. [desFile] already existed: raise warning
		3. else, read [srcFile]; modified data; write to [desFile]


## Code flow
1. main
	> `take` 2 arguments: [srcFile] [desFile]

	> `print` instruction

	> `Check` number of arguments == 3

		> `Not`: raise warning

	> `Call` <copy_modify>[srcFile] [desFile]

	> `Exit`

2. copy_modify
	- take 2 string [srcFile] [desFile]; read [srcFile]; remove all byte with high bit set; write modified data to [desFile]

	> `take` [srcFile] [desFile]

	> `Check if` being able to open [srcFile]

		> `Not`: raise warning

	> `Check if` [desFile] already existed

		> `Yes`: raise warning

	> `Read each` [byte] in [srcFile]

		> `Check if` [byte] set the high bit

			> `Not`: `write` [byte] to [desFile]

	> `Prompt` to user