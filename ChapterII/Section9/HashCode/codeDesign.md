
# Code design

## Data
1. Input
	- [inputString] : the string to be hashed
2. Output
	- [hashCode] : the hash code of string

## Code flow
1. Main
	> `Print` the instruction of the program

	> `Ask` user to enter the input string

	> `Compute` the hash code of the string and `Assign` to [hashCode]

	> `Print` out the result

	> `Exit`

2. computeHash
- A function to take a string and return it hash code

	> `Take` [inputString]

	> `Initialize` [hashCode] = 0

	> `For each` [char] in the [inptString]:

		> `Add` value of [char] to [hashCode]

	> `Return` [hashCode]