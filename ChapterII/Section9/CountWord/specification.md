
# Count words

***Count number of words in a given string***

*Specification*

## Purpose:
> This program is used to count the number of words in a given string

## Description
- A word: is a set of adjacent letters which are in alphabet or are number
	> There is exception with character: ["  '  "]  like in  this word: "don't" 
	So this case is determined by checking the preceding letter and the following letter of the apostrophe, 
	if 2 letters are both in alphabet or are numbers: so that segment of letter is consider as a word
	> One exception with [" - "]: the same as apostrophe: eg: ice-scream, 343-343-434

## Example:

```
	$ This program is used to count the number of words in a given string
	$ Please enter the string: This afternoon is sunny and nice, I'm grateful for this
	$ The number of words is: 10
```