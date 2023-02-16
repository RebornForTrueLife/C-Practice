
# Code design

## Date
- > transfer speed: which is 960 bytes / second in default
- > file_size: a float, take from user

## Main flow
- `Print` out the instruction to the user
- `Ask` user to enter a `float`, which is the [file size]
- `Calculate` the time needed to transfer the file
- `Print` out the result

## Functions flow
1. **calTimeTransfer**
	- > *The function to take a file size(float) and return transfer time(integer)*
	- `Take` a float - file size
	- `Convert` [file size] into an integer of byte unit
	- `Calculate` [time] by dividing [file size] with [transfer_speed]
	- `Return` [time]

2. **ConvertTime**
	- > *The function to convert time in second into [hour:min:second] format*
	- `Take` an integer which is [second]
	- `Calculate` [hour] by modulo [second] with 60\*60 == 3600
	- `Calculate` [timeLeft] when removing [hour]
	- `Calculate` [min] by modulo [timeLeft] with 60
	- `Return` the array [hour, min, timeLeft]