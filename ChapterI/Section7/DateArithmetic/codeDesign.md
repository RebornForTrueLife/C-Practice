
# Code design


## Data:

### Date: 

- **Concept**: A combination of day, month and year
	> Day and month are positive integers, year is an integer(can be negative)
	> There are valid range of day(depend on month), month[1-12]
- **Operation** that can be applied on a-date:
	> Comparison: Given a date [A] and a date [B]: [A] is greater than [B] if [A] happens after [B]; [A] is equal [B] if [A] is [B]; [A] is smaller than [B] if [A] happens before [B]
	> Addition: add a date [A] with a non-negative integer [d], return a date [B] that happens [d] days **after** date [A]
	> Subtraction: subtract a date [A] wiht a non-negative integer [d], return date [B] that happens [d] days **before** date [A]
	> Distance: Measure the distance between 2 dates [A] & [B], return the number of days between 2 day(including 2 dates), [B] need to greater than [A]
- **Represent date data**
	> An short-int array dimension 3: [day, month, year]
	> There are functions associated with date data:
		1. Validate: `Check` if a particular date is valid
		2. Compare: Input 2 date [A], [B] in order, return whether [A] greater or smaller than or equal to [B].
		3. Addition: `Input` a date, a non-negative integer, `Return` a date
		4. Substraction: `Input ` a date, a non-negative integer, `Return` a date
		5. MeasureDistance: 'Input' 2 dates, `Return` a number of days between 2 days, the smaller date need to be entered first.


## Main flow:

> `Inform` user about list of date's operations
> `Ask` user enter operation choice: an interger
> `Instruct` user with user's specific choice respectively
> `Operate` user's operation with input data from user
> `Print` out the result
> `Exit` program


## Funtions flow:

*#1 Do just 2 operation first: validation and comparison*

1. **Validate**
	> `Take` an short integer array dimension 3 [day, month, year]
	> `Check` if year is a leap year or normal year
		> `If` year is a normal year: mean number days in Feb is 28 days
		> `If` year is a leap year: number day in Feb is 29 days
	> `Check` if month is in valid range [1-12]
	> `Check` if day is in valid range - depend on month

2. **Comparison**
	> `Take` 2 dates, which are 2 short integer arrays with dimension 3: [A] and [B], containing 3 fields: [day, month, year]
	> `Validate` each date
		> `If` there is any date that is not valid, `Raise` warning and `Exit`program
	> `Compare` the years of 2 dates:
		> `If` they are equal, `Return` the comparison result
	> `Compare` the months of 2 dates:
		> `If` they are equal, `Return` the comparison result
	> `Compare` the day of 2 dates, `Return` the comparison result
	- To represent result: using an short integer:
		> 1: if [A] is greater
		> 0: for equal
		> -1: if [A] is smaller

3. **Instructor**
*This func will take the user choice, and for each choice, it will PRINT respective instruction and  CALL respective PROCEDURE for user's chosen operation*
	> `Take` an short-integer [choice]
	> With each valid choice:
		> `Print` corresponding instruction
		> `Call` corresponding procedure for chosen operation
	> `If` choice is not valid: `Raise` warning and `Exit` Program 

4. **OperationProcedure**
*Note: It's like an abstract method, each type of operation will have corresponding variation of this fucn*
	> `Ask` user to enter needed data
	> `Operate` on the input data
	> `Print` out the result
