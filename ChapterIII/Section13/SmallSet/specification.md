
# Small Set

***Define a set for a small range of number***

*Preliminary Specification*

## Purpose
> Define a set that is used to hold the set of integer from 0 to 31. There are 2 services provided, set and clear element

## Description
- Set:
	- Services:
		0. Data: provide a way to hold set of integer in range [0..31]
		1. set : set an integer in the range, does nothing if it has been already set; raise warning the value is not valid
		2. clear: un-set an integer in the range, does nothing if it is not set; raise warning the integer is not valid.
		3. test: test an integer if it is set or not, raise warning if integer is not in the

	- Properties:
		1. [array] of int value, each value represents the state of corresponding index integer value. For example: array: {1, 0}, imply that the integer: 0 is set, due to the value in index 0 is TRUE, and for index 1, the integer 1 is not set.
		2. [size] : represent the range of integer set: [0 .. size - 1]
	

