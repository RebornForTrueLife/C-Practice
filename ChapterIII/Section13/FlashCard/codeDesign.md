
# Code design

## Data
0. Stack (of Card)
	- inteface:
		1. create empty stack 
		2. PUSH: push a [card] at the top of stack
		3. POP: return a [card] at the bottom of stack and remove it

1. Card
	- private
		1. [question] : a string
		2. [answer] : a string
	- inteface:
		1. constructor(string, string): 
			> create a new card with given question and answer
		2. get_question(void)
			> return the question
		3. get_anser(void)
			> return the answer
		4. check_answer(string)
			> given the user's answer, check if it is same as card's answer

2. FlashCard
	- private
		1. [stack] of cards
	- interface
		1. constructor(FILE)
			> read data in the FILE
			> create list of [card] from the FILE
			> PUSH all [card]s to [stack]
		2. move_card(Card)
			> to get the last [card] and put it in top of stack
		3. learn_card(void)
			- take the last card, and print the question to ask user
				> if stack is empty, promt to user and exit
			- get user's answer
			- compare user's answer to card's answer:
				- If true, remove the card
				- If false, move_card to the begin of stack
		4. is_done(void)
			- return TRUE if the stack is empty
			- else, return FALSE
