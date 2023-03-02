
# Code design

## Data
1. Input
	- A string: [inputString]
2. Output
	- An integer: number of words in the [inputString]: [count]
3. Used
	- An array of exeption characters: apostrophe, hyphen: Excetion_Array = {\', \-} 
	- range of alphabetic characters:  65-90, 97-122
	- range of numberic characters: 48-57

## Code flow
1. main
	> `Print` out the instruction for user

	> `Ask` user to enter [inputString]

	> `Count` number of words([count]) in the [inputString]

	> `Print` the result 

2. count number of word
	- To count the number of words in a given string

	> `Take` a string [inputString]

	> `Initialize` an iterator of [inputString]: [it]

	> `Initialize` [countWord] = 0
	<!-- Read each char of the string -->
	> `While` [it] is Not the end of [inputString]:
		
		> `Assign` [currentChar] = value of [it]

		> `If` [currentChar] is a letter:
			<!-- wordReading is a variable to show that a word is being read -->
			> `Assign` [wordReading] = TRUE 

			> `Increment` [countWord] by 1
			<!-- Read one word -->	
			> `While` [wordReading] == TRUE:

				> `If` [currentChar] is Not a letter:

					> `Assign` [wordReading] = FALSE
					<!-- For special cases -->
					> `If` [currentChar] is in [Exception_Array]:

						> `Declare` [nextChar] = value of [it + 1]

						> `If` [nextChar] is Exist `And` [nextChar] is a letter:

							> `Assign` [wordReading] = TRUE

				> `If` [it] is not End_of_string:
					<!-- Move to next char -->
					> `Increment` [it] by 1

					> `Assign` [currentChar] = value of [it]
		> `If` [it] is End_of_string:

			> `break`
		<!-- Move to next char -->
		> `Increment` [it] by 1

3. check letter
	- *To check if a character is alphabet or is a number, if it is return true, else, return false* 

	> `Take` a character [c]

	> `If` c in range[65..90] or [97..122] or [48..57]:

		> `Return` TRUE

	> `Return` FALSE


## Debug:
- There are data bug in somewhere
	<!-- - Checking the checkLetter func  -->
	<!-- - Make a function: iterate each char of a given string and print out -->
	<!-- - Make a countWord for simpler word definition: just a segment of adjacent alphabet letter -->
	