
# Flash card 

***Define a flash card class***

*Preliminary Specification*

## Purpose
> This program is used to define a Flash Card class to learn vocabulary

## Description
- There is 2 object: card and flash-card
	> a card contain a pair of question and answer

	> flash-card contain list of cards

- Card:
	> fields
		- question
		- answer
	> Services:
		0. create card: given a pair of question and answer
		1. get question
		2. get answer
		3.  check answer: check if an given answer is same as card's answer

- FlashCard
	> fields
		- stack of cards
	> Services
		0. create empty FlashCard
		1. learn last card
		2. is done: to check if there is any card in the stack, true if it is empty

