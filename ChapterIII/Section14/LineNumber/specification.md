
# LineNumber

***Define a class to manage reading file by line***

*Preliminary Specification*


## Purpose
> Define a class to manage reading a file by line

## Description
- Class LineNumber is defined for single file
- Many LineNumber instances can be used to read the file at a time. So the LineNumber class will keep track on list of LineNumber instances
- When a instance attempt to go to a [lineA], it will search on the list of current LIneNumber's instances to find the instance which is at the nearest smaller [lineB] to the [lineA]. 
	- In order to go to [lineA], the instance will read character by character from [lineB] to the begin character of [lineA].
	- and also, the [char_pos] of this instance will be updated ([char_pos] is the position of first character of a line)
- Class LineNumber provide 3 services:
	1. goto_line: go to a specific line
	2. get the current line number
	3. get character position: return the position of first character in the file of the current line.
