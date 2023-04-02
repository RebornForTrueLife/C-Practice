
# File busy signal

***Check if a file, which is shared, is being used***

*Preliminary Specification*

## Purpose
> There are 2 classes share the same file, the program is used to track if the file is used by either of these 2 classes

## Description
1. There are 2 classes: ClassOne an ClassTwo
- Focus on this aspect of 2 classes:
	- a shared file: FILE
	- a static function to check if FILE is used in the class
		> by checking if there is any object created

		> by create a static count

2. The program will detect if there is an use FILE by either of 2 classes
	
