
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


## Operations

### Operation declare
***Core blocks***
1. `Main`: where to implement interface to user
2. `Instructor`: to give instructions for user with a givenspecific user's choice and call the corresponding operation procedure
3. `OperationProcedure`: an abstract Procedure - which mean each Operation for Date data will have one Procedure respectively. This procedure is used to implement each operation: ASK user for date, CALCULATE result, PRINT the result
4. `measureDistance`: to perform counting number of days between t2 dates
5. `add`: to perform `add` a number of days to a date and `return` the result date
5. `subtract`: to `subtract` a number of days to a date and `return` the result date

***Suport block***
1. `Validate`: to validate a given* date, if the date is invalid, `raise` error and `exit` program
2. `Compare`: to perform comparision between 2 dates(detail in date desciprtion)
3. `dayStamp`: to `convert` the given date into a number of days from base_date(1/1/0) to the given date. *Note: day stamp of  base_date is 1, 0 day_stamp is 1/1/0*

### Operation Flow
0. Main
	> `Inform` user about list of date's operations
	> `Ask` user enter operation choice: an interger
	> `Instruct` user with user's specific choice respectively
	> `Operate` user's operation with input data from user
	> `Print` out the result
	> `Exit` program

*#1 Do just 2 operation first: validation and instructor*
*#2 Code [comparison fucntion], [distance measure func]*

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
		> `If` they are not equal, `Return` the comparison result
	> `Compare` the months of 2 dates:
		> `If` they are not equal, `Return` the comparison result
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

5. **MeasureDistance**
	> `Take` 2 dates: date [A] and date [B]
	> `Declare` an int: 'totalDay' to contain the number of days between 2 dates
	> `Check` if date[A] is greater than [B] by [compare func]
		> If [A] greater than [B]: `Raise` warning and `Exit` program
	> `Calculate` dayStamp of date A 
	> `Calculate` dayStamp of date B
	> [totalDay] = [dayStampB] - [dayStampA] + 1
	> `Return` totalDay

6. **Addition operation**
	> `Take` a date [A] and a non-negative number [d]
	> ...

### Support functions
*Note: for dates that are before base_date, which are described: the day before base_date is 31/12/-1, which has day_stamp: -1. Then the corresponding date with absolute year of a date [day/month/negative_year] is [day/month/abs_year]. So day_stamp of the given date is calculated by: calculate the day_stamp of corresponding year(assign value to [dayStamp]), minus ([number of days of abs_year] -1 + [number of days of year 0 == 366]) to [dayStamp], and change sign of [dayStamp]* 

1. **DayStamp**
	> `Take` a date [A]
	> `Check` if [A] is valid
	> `Check` if year of [A] is negative
		> if true, var [sign] = -1, change year_[A]  to [its absolute value] -1
		> else, var [sign] = 1
	> `Count` number of days from base_date to the end_date of the year before year_[A], `Assign` result to [totalDay]
	> `Count` the day from the begin of year_[A] to the date A INCLUSIVELY and `Assign` result to [dayCurrentYear]
	> `If` date is before base_date: 
		> `subtract` [number days of year 0] from total year
		> [dayCurrentYear]  = [number of day in current year] - [dayCurrentYear]
	> [totalDay] += [dayCurrentYear]
	> `change sign` of [totalDay]
	> `Return` [totalDay]


## Continue: 
- coded DayStamp
- Next code: measure Distance
	
