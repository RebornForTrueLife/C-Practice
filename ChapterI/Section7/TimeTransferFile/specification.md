
# Time transfer file

***How long it takes to transfer a file given the file's size***

*Specification*


## Purpose: 

> This program is used to calcualte the time in seconds to transfer a file, given the size of that files and the transfer data speed

### Input

1. Transfer data speed
	- Default: 960 characters/second
2. File size: in MB(megabyte): is a float number
	- Data size conversion: 1MB = 1024 KB = 1024 ^ 2 B =  1024 ^3 \* 8 bits
	- 1 character needs 8 bits (1 byte) to be represented

### Output
> - Print out the time in [hour:minute:second] needed to transfer the files


## Example:

```
> $ This program will calculate the approximate time to transfer a file given the file's size
> $ The default speed is: 960 <characters>/<second></second>
> $ Enter the file size(in MB):  10
> $ The time needed for 10MB is in [hour : min : sec ]:   3 : 2 : 2
```

