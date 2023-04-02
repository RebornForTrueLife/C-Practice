
# Code design


## Data
1. ShareStack
	> private
		- (static) [stack]: for simplicity, declare as a string
		- (static) [state]: bool value, TRUE means the stack is being used, vice versa
		- (static) [key]: to check when unlock, set to 0 when stack is free 
		- (static) [count]: the number of instance created (no decreasing even when any instance is destroyed)
		- (const) [index] : index of instance, to match with [key]

	> public
		- constructor(void): to initialize index of each instance
		- use_stack(void): access the stack, this should check the state of stack. If stack is locked, dont allow to access.
		- lock(void): lock the stack
		- unlock(void): unlock the stack if the stack is locked, also check if instance `call` is the one locked the stack, if not, Do not unlock.


## Code flow
1. main
	> `print` the services of the Class ShareStack

	> `Exit`


## Class ShareStack

0. Initialize static variable
	> `Assign` [stack] = "STACK"

	> `assign` [state] = FALSE

	> `Assign` [key] = 0

	> `Assign` [count] = 0

1. constructor(void)
	> `Increase` [count] by 1

	> `assign` [index] = [count]

2. use_stack(void)
	- to prompt to user that stack is ACCESS, or DENY
	> `Check` if [state] == TRUE

		> `If` so, `Print` ACCESS

		> `else`, `Print` DENY, other instance is using the stack

3. lock(void)
	- to lock the stack only if it is free

	<!-- Check if the stack is locked -->
	> `If` [state] is TRUE:

		> `Prompt` that The stack is being used

		> `Exit`

	> `Assign` [state] to TRUE

	> `Assign` [key] = [index]

	> `Prompt` the stack is locked

4. unlock(void)
	- to unlock the stack only if the stack is locked and the instance call this func is the one that locked the stack

	> `If` [state] is FALSE:

		> `Prompt` The stack is free to use

		> `Exit`

	> `If` [key] is different to [index]:

		> `Prompt` This instance is not the one locked the stack, Not allow to unlock stack now.

		> `Exit`

	> `Assign` [state] = FALSE

	> `Assign` [key] = 0

	


