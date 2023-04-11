
# Specification
> creating a similar function to memcpy of string library


# Code design

1. memcpy_
	- copy an character array from begin pointer for a given size of byte to another character pointer
	- input
		1. [des], [src] : character pointer
		2. [size] : number of bytes

	> `take` [des] [src] [size]

	> `allocate` memory for [des] with length = [size]

	> `For each` [character] from [src] to length of [size]:

		> `assign` [character] to current character of [des]

		> `increase` [des] by 1

		> `increase` [src] by 1

	> `return` [des]