
# Simple queue

***Define a simple queue class***

*Preliminary Specification*

## Purpose
> a queue class provide some services: put and get values

## Description
- Queue:
	- Put value into a stack
	- Get value from the stack in FIFO order

## Example
```
	queue = []
	queue.put(3) 	[3]
	queue.put(4) 	[3 4]
	queue.get() 	return 3; [4]
```