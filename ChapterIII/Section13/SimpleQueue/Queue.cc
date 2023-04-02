/********************************************
 * Queue - define class Queue to store integer values
 * Uage: 
	- Queue has 2 services:
	1. put value into queue
	2. get a value in queue in FIFO order
 ********************************************/

#include <iostream>

// MODE
#define CODING		// coding mode
// #undef CODING

// CONST
const int MAX_SIZE = 100;	// size of queue

// CLASS
class Queue {
private:
	// an array to hold values of queue
	int queue[MAX_SIZE];

	// the number of values in queue
	int count;

	// the start index of first value in queue
	int start;

	// func to get actual index by the queue-index
	int get_index(int queueIndex);

public:
	// constructor
	Queue();

	// ~Queue();	// destructor: default

	// put new value into queue
	void put(int value);

	// get the first value of the queue
	int get(void);
};	// close Queue


// main
int main(int argc, char const *argv[]) {
	// print serives of the Queue class
	std::cout << "The program is used to define Queue class, to store int values\n";
	std::cout << "Queue provides 2 services:\n";
	std::cout << "\t1. Put value into queue\n";
	std::cout << "\t2. Get first value in queue in FIFO order\n";
	// coding mode
	#ifdef CODING
		Queue queue;
		// get value when there queue is empty
		queue.get();
		// put value
		queue.put(100);
		queue.put(1340);
		// get value
		std::cout << "The first value of queue: " << queue.get() << "\n";
	#endif	// CODING
	return 0;
}	// end  main 


// IMPLEMENT

/*	Queue: constructor
	- initialize count and start*/
Queue::Queue(void) {
	count = 0;
	start = 0;
}	// close constructor


/*	Queue: get_index
	- get the actual index in array by the index of 
	the queue
	- input: queue index
	- output: actual index in array*/
int Queue::get_index(int queueIndex) {
	// index in the array
	int arrayIndex = start + queueIndex;
	// check if array index >= MAX_SIZE of array
	if (arrayIndex >= MAX_SIZE)
		// the index back to begin of array as a circle
		arrayIndex %= MAX_SIZE;
	return arrayIndex;
}	// close get_index


/*	Queue: put
	- to put new value in queue
	- input: value
	- output: 
		- if queue is NOT full, put value at the end of queue
		- if queue is full, raise wawrning*/
void Queue::put(int value) {
	// check if queue is full
	if (count >= MAX_SIZE) {
		// raise warning
		std::cout << "The queue is already full\n";
	} else {	// queue is Not full
		// get actual index for new value at the end of queue
		int arrayIndex = get_index(count);
		// put value into queue
		queue[arrayIndex] = value;
		// increment count
		count += 1;
		// inform user that value is put
		std::cout << "The value is put to queue!\n";
	}	// close if
}	// close put


/*	Queue: get
	- to get first value of the queue if there queue 
	is not empty, and remove it from the queue
	- input: none
	- output: 
		- if queue is Not empty: return first value
		- if queue is empty: raise warning*/
int Queue::get(void) {
	// check if queue is empty
	if (count == 0) 
		// raise warning
		std::cout << "The queue is empty\n";
	else {	// the queue is Not empty
		// get first value
		int value = queue[start];
		// remove it by increase start index
		start = get_index(start + 1);
		// return value
		return value;
	}	// close if
}	// close get