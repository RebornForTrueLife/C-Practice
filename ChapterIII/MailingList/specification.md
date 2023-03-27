
# Mailing List

***Design data structure for mailing list***

*Preliminary Specification*


## Purpose
> A program to provide a data structure for mailing list

## Description
- a mail: which is contain these infomation:
	1. name: last name and first name
	2. address1: 2 addresses
	3. address2: 
	4. city: name of city
	5. state: 2 char abbreviation
	6. zip: numberic zip code
- a mailing list: which is an list of mails

## Example:
```
	- a mail: [mailOwn]
		- name: nguyen minh
		- address1: 183 linhnam
		- address2: 123 trancao
		- city: hanoi
		- state: vn
		- zip: 10000
	- a mailing list: 
	[hanoiList] = { [mail1], [mail2], [mailOwn] }
	[hanoiList] is a mailing list which contains 3 mails
```