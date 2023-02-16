
# Code design


## Data:

### Date: 

- **Concept**: A combination of day, month and year
	> - Day and month are positive integers, year is an integer(can be negative)
	> - There are valid range of day(depend on month), month[1-12]
- **Operation** that can be applied on a-date:
	> - Comparison: Given a date [A] and a date [B]: [A] is greater than [B] if [A] happens after [B]; [A] is equal [B] if [A] is [B]; [A] is smaller than [B] if [A] happens before [B]
	> - Addition: add a date [A] with a non-negative integer [d], return a date [B] that happens [d] days **after** date [A]
	> - Subtraction: subtract a date [A] wiht a non-negative integer [d], return date [B] that happens [d] days **before** date [A]
	> - Distance: Measure the distance between 2 dates [A] & [B], return the number of days between 2 day(including 2 dates), [B] need to greater than [A]
- **Represent date data**
	> - An int array dimension 3: [day, month, year]
	> - There are functions associated with date data:
		1. Validate: `Check` if a particular date is valid
		2. Compare: Input 2 date [A], [B] in order, return whether [A] greater or smaller than or equal to [B].
		3. Addition: `Input` a date, a non-negative integer, `Return` a date
		4. Substraction: `Input ` a date, a non-negative integer, `Return` a date
		5. MeasureDistance: 'Input' 2 dates, `Return` a number of days between 2 days, the smaller date need to be entered first.
		6. toDayStamp: convert a [date] into an integer which represent [date] in the time line, base_date is 1/1/0, which has day stamp is 0.
		7. toDate: convert a day stamp(an integer) into a [date]


## Operations

### Operation declare
***Core blocks***
1. `Main`: where to implement interface to user
2. `Instructor`: to give instructions for user with a givenspecific user's choice and call the corresponding operation procedure
3. `OperationProcedure`: an abstract Procedure - which mean each Operation for Date data will have one Procedure respectively. This procedure is used to implement each operation: ASK user for date, CALCULATE result, PRINT the result
4. `measureDistance`: to perform counting number of days between t2 dates
5. `addSub`: to perform `add` a number of days to a date and `return` the result date(if number of days is a negative number, same meaning as subtraction)

***Support block***
1. `checkLeapYear`: to check if the given year is a leap year, `return` true if it is a leap year and vice versa.
2. `Validate`: to validate a given* date, if the date is invalid, `raise` error and `exit` program
3. `Compare`: to perform comparision between 2 dates(detail in date desciprtion)
4. `dayStamp`: to `convert` the given date into a number of days from base_date(1/1/0) to the given date. *Note: day stamp of  base_date is 1, 0 day_stamp is 1/1/0*
5. `toDate`: to `convert` a given dayStamp(a int) to corresponding date format(an array dimension 3 of int)

### Operation Flow
0. Main
	```
	> `Inform` user about list of date's operations
	> `Ask` user enter operation choice: an interger
	> `Instruct` user with user's specific choice respectively
	> `Operate` user's operation with input data from user
	> `Print` out the result
	> `Exit` program
	```

1. **Validate**
	```
	> `Take` an integer array dimension 3 [day, month, year]
	> `Check` if year is a leap year or normal year
		> `If` year is a normal year: mean number days in Feb is 28 days
		> `If` year is a leap year: number day in Feb is 29 days
	> `Check` if month is in valid range [1-12]
	> `Check` if day is in valid range - depend on month
	```
2. **Comparison**
	```
		> `Take` 2 dates, which are 2 integer arrays with dimension 3: [A] and [B], containing 3 fields: [day, month, year]
		> `Validate` each date
			> `If` there is any date that is not valid, `Raise` warning and `Exit`program
		> `Compare` the years of 2 dates:
			> `If` they are not equal, `Return` the comparison result
		> `Compare` the months of 2 dates:
			> `If` they are not equal, `Return` the comparison result
		> `Compare` the day of 2 dates, `Return` the comparison result
		- To represent result: using an integer:
			> 1: if [A] is greater
			> 0: for equal
			> -1: if [A] is smaller
	```
3. **Instructor**
*This func will take the user choice, and for each choice, it will PRINT respective instruction and  CALL respective PROCEDURE for user's chosen operation*
	```
	> `Take` an integer [choice]
	> With each valid choice:
		> `Print` corresponding instruction
		> `Call` corresponding procedure for chosen operation
	> `If` choice is not valid: `Raise` warning and `Exit` Program 
	```
4. **OperationProcedure**
*Note: It's like an abstract method, each type of operation will have corresponding variation of this fucn*
	```
	> `Ask` user to enter needed data
	> `Operate` on the input data
	> `Print` out the result
	```

5. **MeasureDistance**
	```
	> `Take` 2 dates: date [A] and date [B]
	> `Declare` an int: 'totalDay' to contain the number of days between 2 dates
	> `Check` if date[A] is greater than [B] by [compare func]
		> If [A] greater than [B]: `Raise` warning and `Exit` program
	> `Calculate` dayStamp of date A 
	> `Calculate` dayStamp of date B
	> [totalDay] = [dayStampB] - [dayStampA] + 1
	> `Return` totalDay
	```
6. **AddSubOperation**
	```
	> `Take` a date [A] and an integer number [d]
	> `Convert` date [A] to [daystamp]of [A]
	> `Add` [d] tp [daystamp], `Assign` result to [newDaystamp]
	> `Convert` [newDaystamp] to [date]
	> `Return` [date]
	```

### Support functions
1. **DayStamp**
	*Note: for dates that are before base_date, which are described: the day before base_date is 31/12/-1, which has day_stamp: -1. And the base_date is 1/1/0, which has day stamp 0* 
	```
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
	```
2. **toDate**
	```
	> `Take` an integer [dayStamp]
	> `Declare` [sign]: hold sign of day stamp(1 or-1)
	<!-- If` [dayStamp] is negative, mean the date is before base_date -->
	> [dayStamp] \*= sign 
	<!-- Find year -->
	> [min_year] = [dayStamp] modulo 366 	// the minimum number of years that date with dayStamp might fall to
	> `Increasing From` [year] = [min_year], `calculate` the day_stamp of the first_day of year `Until` [dayStamp] are SMALLER than day_stamp
	> `Decrease ` [year] by 1 to find the year of the date of [dayStamp]
	> `If` sign == -1
		> `Increase` year by 1 and change sign, cuz negative year start by -1
	> 
	<!-- Find month -->
	> `Check` if sign == 1
		> If `true`: `Calculate` number of days left from the begin day of [year] to the date of [dayStamp]: [left_day] = [dayStamp] - dayStamp(1/1/[year]) + 1 <!-- because  day stamp start by 0 -->
		> `Else`: [left_day] = - [dayStamp] + abs(1/1/ - [year]) + 1
	> `Define``totalDay `of [month]: total number days from 1/1 to the last day of [month] in the same year <!-- note: check leap year -->
	> `From` [month] = 1; `increasing`[month] by 1 `Until` totalDay([month]) GREATER or EQUAL than [left_day] <!-- equal because the special case in the last day of the year 31/12 -->
	<!-- Find day -->
	> [day] = [left_day] - totalDay([month - 1])
	> if [day] == 0 then it the day is last day of [month -1]: [day] = lastDayof [month - 1]; 
		> `Decrease` [month] by 1
	<!-- return result -->	
	> return [day] [month] [year]
	```
