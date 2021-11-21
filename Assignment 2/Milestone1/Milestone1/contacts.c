/* -------------------------------------------
Name: Andriy Ostapovych
Student number: 143066181
Email: aostapovych@myseneca.ca
Section: BTP100SBB
Date: 11/12/18
----------------------------------------------
Assignment: 2
Milestone:  1
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:

#include "contacts.h"

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-1 Milestone-4 |
// |        function definitions below...            |
// +-------------------------------------------------+

// getName:

void getName(struct Name *Contact)

{
	char option;

	// Contact Name Input:

	printf("Please enter the contact's first name: ");
	scanf(" %30[^\n]", Contact->firstName);

	printf("Do you want to enter a middle initial(s)? (y or n): ");
	scanf(" %c", &option);


	if (option == 'y' || option == 'Y') {
		printf("Please enter the contact's middle initial(s): ");
		scanf(" %6[^\n]", Contact->middleInitial);

	}

	printf("Please enter the contact's last name: ");
	scanf(" %35[^\n]", Contact->lastName);


}


// getAddress:

void getAddress(struct Address *Contact)

{

	char option;

	// Contact Address Input:

	printf("Please enter the contact's street number: ");
	scanf(" %d", &Contact->streetNumber);

	printf("Please enter the contact's street name: ");
	scanf(" %40[^\n]", Contact->street);

	printf("Do you want to enter an apartment number? (y or n): ");
	scanf(" %c", &option);

	if (option == 'y' || option == 'Y') {
		printf("Please enter the contact's apartment number: ");
		scanf(" %d", &Contact->apartmentNumber);

	}

	printf("Please enter the contact's postal code: ");
	scanf(" %7[^\n]", Contact->postalCode);

	printf("Please enter the contact's city: ");
	scanf(" %40[^\n]", Contact->city);

}

// getNumbers:

void getNumbers(struct Numbers *Contact)

{
	char option;

	// Contact Numbers Input:

	printf("Do you want to enter a cell phone number? (y or n): ");
	scanf(" %c", &option);

	if (option == 'y' || option == 'Y') {
		printf("Please enter the contact's cell phone number: ");
		scanf(" %10s", Contact->cell);

	}

	printf("Do you want to enter a home phone number? (y or n): ");
	scanf(" %c", &option);

	if (option == 'y' || option == 'Y') {
		printf("Please enter the contact's home phone number: ");
		scanf(" %10s", Contact->home);

	}


	printf("Do you want to enter a business phone number? (y or n): ");
	scanf(" %c", &option);

	if (option == 'y' || option == 'Y') {
		printf("Please enter the contact's business phone number: ");
		scanf(" %10s", Contact->business);

	}

}

// +-------------------------------------------+
// | ====== Assignment 2 | Milestone 1 ======= |
// +-------------------------------------------+

// getContact:
// Define Empty function definition below:

void getContact(struct Contact* contact) 

{


}