
# Code design

## Data
1. ClassOne
	> private
		- File: a string
		- (static) count: the number of objects created

	> public
		- check_usage(void): check if any object is using the File

2. ClassTwo
	> private
		- File: a string
		- (static) count: the number of objects created

	> public
		- check_usage(void): check if any object is using the File


## Code flow

1. main
	> `Print` instruction of program

	> `Exit`

2. Class<One, Two>:: check_usage(void)
	> `Check` if [count] == 0:

		> `If` TRUE: return 0

		> `Else`: return 1

3. check(void)
	- to check if The [File] is used by either of 2 classes

	> `If` <ClassOne>::<check_uage>() == 1 `Or` <ClassTwo>::<check_uage>()

		> `return` 1

	> `return` 0