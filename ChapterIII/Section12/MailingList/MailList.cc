/********************************************
 * MailList - provide a data sstructure of List of Mail
 * Uage: 
	- use the object file
 ********************************************/

#include <iostream>

// CONST
const int NAME_SIZE = 60;		// max size of name
const int ADDRESS_SIZE = 60;	// max size of address
const int MAX_SIZE = 50;		// max number of mail can be stored


// Data structure
/*	name: Mail
	fields:
		- name: name of receiver
		- address1 and address2: 2 addresses of mail
		- city: city of receiver
		- state: 2 letter abbreviation
		- zip: numberic zip code */
struct Mail {
	char name[NAME_SIZE];
	char address1[ADDRESS_SIZE];
	char address2[ADDRESS_SIZE];
	char city[NAME_SIZE];
	char state[3];
	long int zip;
};	// close Mail

/* MailList: list of mails */
struct MailList {
	Mail array[MAX_SIZE];
	int size = 0;		// number of current mails stored
};	// close MailList
