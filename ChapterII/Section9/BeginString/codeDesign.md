
# Code design

## Data
1. Input
	- 2 string: [stringA] [stringB]
2. Output
	- A statement that clarify if [stringA] begins [stringB]

## Code flow
1. Main
	> `Print` instruction of the program

	> `Ask` user to enter 2 strings

	> `Check` if [stringA] begins [stringB], `assign` result to [result]

	> `Print` out the [result] as a statement

2. Check begins
	- A function to check if first string begins second string:
	- So the conditions to check are:
		- 1st: The size of [stringA] must be smaller or equal to the size of [stringB]
		- 2nd: each character of [stringA] must be the same as each character of [stringB] at same index
		
	> `Take` 2 string [stringA] and [stringB]
	<!-- Compare size -->
	> `If` size of [stringA] GREATER than size of [stringB]:

		> `Return` FALSE
	<!-- Compare first part -->
	> `Find` the position of [stringA] in [stringB] if it exists by func `std::string::find`, `assign` return value to [pos] - (a std::size_t)

	> `If` [pos] != 0 

		> `Return` FALSE

	> `Return` TRUE
