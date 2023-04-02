
# Code design

## Data
1. CheckBook
	- private member
		1. count: an integer : number of entries in the checkbook
		2. list: an int array: store entries; MAX_SIZE = 100
	- public member
		0. construction(): initialize [count]
		1. add_item(int entry): put input entry to [list]
		2. total(void): return the total number of entries stored


## Code flow

1. main
	> `Print` the services of CheckBook class

	> `Exit`

2. CheckBook: add_item
	- to put an entry to [list], increment [count]

	> `Take` [entry]

	> `Put` [entry] to the end of [list]

	> `Increment` [count] by 1

3. CheckBook: total
	- return value of [count]

	> `Return` [count]

4. CheckBook: construction
	
	> `Initialize` [count] = 0