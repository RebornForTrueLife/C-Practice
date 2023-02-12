
# Date arithmetic

***Simple date arithmetic operations***

*Preliminary Specification*

Warning: This is a preliminary specification. Any resemblance to any software living or dead is purely coincidental


## Purpose of program: perform some simple arithmetic operation on date data
Program provides some operations on date to users. User then can choose operation from keyboard. After getting the choice from user, program will give specific instruction for corresponding operation to users. 

List of operations can be performed:

	[1] Count number of days between 2 dates
	[2] Print the date after [number] days of a given date
	[3] Print the date before [number] days of a given date

## Instructions for each operation:

### Concepts denotation:

***Comparison***
- A date [A] is consider as greater than another date [B] when [A] happens aftef [B]
- A date [A] is consider as equal to a date [B] when [A] is [B]

1. **Count number of days between 2 dates**
	> User will enter 2 dates, which are start-date and end-date
	> Program will print out number of day between 2 dates
	> Raise Warning: when start-date greater then end-date

2. **Print the date after [number] days of a given date**
	> User will enter the start-date and a non-negative integer [number]
	> Program will print the date after [number] days from the given date
	> Warning: when [number] is not a non-negative integer

3. **Print the date before [number] days of a given date**
	> User will enter the end-date and a non-negative integer [number]
	> Program will print the date before [number] days from the given date
	> Warning: when [number] is not a non-negative integer

*Note: program will raise warning when the date is not **VALID** in all cases*


## Example:

1. Operation 1:
	> $ ...
	> $ A simple date arithmetic operation
	> $ All operations are listed below:
	> $ 	[1] Count number of days between 2 dates
	> $ 	[2] Print the date after [number] days of a given date
	> $		[3] Print the date before [number] days of a given date
	> $ Please enter your choice: 1
	> $ Program will count number of days between 2 dates
	> $ A valid date format is: [20 10 2023]. Please enter:
	> $ Start-date: 6 1 2020
	> $ End-date: 8 3 2020
	> $ From 6/1/2020 To 8/3/2020, there are: 62 days
	> $ Exit...

2. Warning example:
	> $ ...
	> $ Please enter your choice: 2
	> $ Program will Print-out the-date after a-number-of-day from a-given-day
	> $ A valid date format is: [20 10 2023]. Please enter:
	> $ Start-date: 40 1 2020
	> $ WARNING: The date is not valid, program will shut-down, have a nice day!

	> $ ...
	> $ Please enter your choice: 2
	> $ Program will Print-out the-date after a-number-of-day from a-given-day
	> $ A valid date format is: [20 10 2023]. And the number of day is a non-negative integer. Please enter:
	> $ Start-date: 10 1 2020
	> $ Number of days: -10
	> $ WARNING: the day have to be a non-negative integer, program will exit, have a nice day!


