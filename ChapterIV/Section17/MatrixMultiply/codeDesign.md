
# Code design


## Data
1. Input
	- [file] : name of files, where to get the data
	- [matrixA], [matrixB]: 2 2-dimension arrays
	- [resutl] : 2-dimension array, which hold the result of multiplication

2. Output
	- compute the multiplication of [matrixA] [matrixB] 
	and write result to [result]


## Code flow
1. read_file(string)
	- a function to read a file and gets 2 matrices
	> `take` [file]

	> `read` [size] from file

	> `read` [matrixA]

	> `read` [matrixB]

	> `prompt` to user


2. multiply_matrix(array[][], array[][])
	- to multiply 2 square matrices and return the result
	> `take` [matrixA] [matrixB]

	> `allocate` [result] with same size as [matrixA]

	> `for each` [pos] in [matrixA]:

		> `calculate` element in [pos] in [result] = [element A] * [element B]

	> return [result]



