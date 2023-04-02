
# Code design

## Data
1. Queue
	- private member
		1. queue: an int array, MAX_SIZE = 100
		2. count: an int, the number of values in the queue
		3. start: an int, the start index of the queue in the array
		4. get_index(int): get the index of a value of the queue in the array, by passing value's queue-index
	- public member
		1. put(int): put a value at the end of the queue 
		2. get(): return the first value of the queue, and remove it from the queue.

## Code flow
1. main
	> `Print` the services of the Queue class

	> `Exit`

2. QUEUE class
	0. constuctor
		- initialize value in class

		> `initialize` [count] = 0

		> `initialize` [start] = 0
		
	1. get_index(int)
		- there are 2 kind of index: queue-index and its actual index in the array. Queue data is stored in actual array.
		- this func is used to get the actual array-index of a value by its queue-index

		> `Take` [queue-index]

		> `Assign` [array-index] = [start] + [queue-index]

		> `If` [array-index] Greater or Equal MAX_SIZE:
			<!-- mean the value is stored back to the begin of array -->
			> `Assign` [array-index] = [array-index] modulo (MAX_SIZE)

		> `return` [array-index]

	2. put(int)
		- to put a new value into the queue

		<!-- check if queue is full or not -->

		> `if` [count] >= MAX_SIZE

			> `print` warning that queue is full

			> `Exit`

		> `take` [value]

		> `assign` [array-index] = `call` <get_index>:[count]

		> `assign` [queue][array-index]= [value]

		> `increment`  [count] by 1

	3. get(void)
		- to return the first value of queue and remove it from the queue

		<!-- check if there is value in queue or not -->
		> `if` [count] == 0

			> `print` warning that queue is empty

			> `exit`

		> `assign` [value] = [queue][start]

		<!-- removing by just increase the start index of the queue -->
		> `assign` [start] = `call` <get_index>:([start] + 1)

		> `return` [value]

