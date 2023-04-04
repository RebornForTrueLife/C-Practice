
# Personal data

***Data format for personal data***

*Preliminary Specification*


## Purpose
> to define a data format to store personal data and a program to read the formated file


## Description
1. Data format:
	```
	[ID]
	[infomation: name]
	[infomation: address]
	[infomation: phone number]
	[infomation: email address]
	```

2. The program define a class to represent personal data 
- The class Person:
	- which each object has a unique ID and corresponding file to store the infomation. The file has format defined above.
	- Personal infomation includes:
		0. object ID
		1. name
		2. address
		3. phone number
		4. email address
	- Services:
		1. read data from a corresponding ID file
		2. print out the person's information 