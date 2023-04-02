
# Code design


## Data
1. class Animal<Name> 
	> private
		- (static)[count] : number of animal are being treated

	> public
		- (Friend) get_total(void): 
			> return total number of animal of all kinds are being treated


## Code Flow

1. main
	> `Print` instruction of the program

	> `Declare`  some animal

	> `Call` <get_total> to get number of animals

	> `Print` the number of animals

	> `Exit`

2. get_total
	> `Initialize` [total] = 0

	> `For each` Animal<name>:

		> `Add` [count] of Animal<name> to [total]

	> `return` [total]

