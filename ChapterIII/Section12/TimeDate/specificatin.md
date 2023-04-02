
# TimeDate

***A data structure to store time date***

*Preliminary Specification*

## Purpose
> provide a data structure to store time date and some operator on this data type


## Description

- TimeDate: used to store time and date
	> Fields:
		- min : minute
		- hour
		- day
		- month
		- year
	> Method:
		- time_diff: find difference between 2 times in minutes


## Example

```
	// format: {min, hour, day, month, year}
	timeDate1  = { 30, 8, 10, 1, 2000 } 
	timeDate1  = { 30, 10, 10, 1, 2023 } 
	// cal time_diff by take time1 - time2
	time_diff( timeDate1, timeDate2 ) = - 120 mins
```