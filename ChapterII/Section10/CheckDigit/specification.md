
# Check digit

***Check if a digit is a decimal digit, and extend to check if it is  a hex digit***

*Preliminary Specification*

## Purpose
> The program is used to check if a character is a digit, or a hex digit by writing macros

## Description
- There are 2 macros: is_digit and is_hex
	- is_digit: check if a character is a digit [0..9]
	- is_hex: check if a character is a hex digit [0..9] [A-F] [a-f]

## Example
```
	$ The program is used to check if a character is a digit or a hex digit
	$ Please enter a character: 9
	$ 9 is a digit
	$ Exit
```

```
	$ The program is used to check if a character is a digit or a hex digit
	$ Please enter a character: #
	$ # is NOT a digit
	$ Exit
```