
# Stack Lock

***Define Class with shared stack***

*Preliminary Specification*

## Purpose 
> Define a class that has a stack, each instance of the class can access the stack if no other instance access it. 

## Description
- Each instance can Lock and Unlock the stack.
- When an instance try to use the stack, it check if the stack is free, if so, it lock the stack until it done; and only the instance that lock the stack in the first place can unlock the stack.
- Class ShareStack:
	> Services:
		1. lock stack
		2. unlock stack(only the instance locked can do this)
		