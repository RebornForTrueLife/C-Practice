
# Code design


## Data

### Input
- An integer number: [number]

### Output
- Result of checking if [number] is a prime: true or false?


## Code flow

### Main
- > `Instruction` user about how to use the program
- > `Ask` user to enter the [number]
- > `Checking` if [number] is a prime
- > `Print` out the checked result

### Function flow
1. checkPrime:
- > `Take` an integer [number]
- > `Check` if it GREATER than 1
	- > if NOT: `Return` false
- > `From` [count] = 2 to SQRT([number]):
	- > `Check` if [number] is divisible by [count]
		- > `If` true, `Return` false
- > `Return` true

> *Note: the reason why only check to quare root of number is: if the number is a product of 2 smaller natural number, one of them has to be smaller than SQRT(number); Prove is explain below:*;
- Prove:
	- the smallest number that greater than sqrt of [number]: sqrt(numer) + 1; and it is obvious to see that power 2 of (sqrt(number) + 1) > number; So if [number] is a product of 2 smaller natural number, one of them has to be smaller than [number]