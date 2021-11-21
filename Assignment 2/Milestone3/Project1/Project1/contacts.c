/* -------------------------------------------
Name: Andriy Ostapovych
Student number: 143066181
Email: aostapovych@myseneca.ca
Section: BTP100SBB
Date: 11/19/2018
----------------------------------------------
Assignment: 2
Milestone:  3
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// +-------------------------------------------------+
// | NOTE:  Include additional header files...       |
// +-------------------------------------------------+


#include "contacts.h"


#include "contactHelpers.h"


// +---------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-2   |
// |        function definitions below...              |
// |                                                   |
// | *** See hint regarding the getNumbers function    |
// +---------------------------------------------------+


// getName:


void getName(struct Name *Contact)

{
	// Contact Name Input:

	printf("Please enter the contact's first name: ");
	scanf(" %30[^\n]", Contact->firstName);
	clearKeyboard();

	printf("Do you want to enter a middle initial(s)? (y or n): ");

	if (yes())
	{
		printf("Please enter the contact's middle initial(s): ");
		scanf(" %6[^\n]", Contact->middleInitial);
		clearKeyboard();

	}

	printf("Please enter the contact's last name: ");
	scanf(" %35[^\n]", Contact->lastName);
	clearKeyboard();

}

// getAddress:

void getAddress(struct Address *Contact)

{

	// Contact Address Input:

	printf("Please enter the contact's street number: ");

	do {

		Contact->streetNumber = getInt();

		if (Contact->streetNumber < 0)

			printf("*** INVALID STREET NUMBER *** <must be a positive number>: ");

	} while (Contact->streetNumber < 0);

	printf("Please enter the contact's street name: ");
	scanf(" %40[^\n]", Contact->street);

	printf("Do you want to enter an apartment number? (y or n): ");

	if (yes())
	{
		printf("Please enter the contact's apartment number: ");

		do {

			Contact->apartmentNumber = getInt();

			if (Contact->apartmentNumber < 0)

				printf("*** INVALID APARTMENT NUMBER *** <must be a positive number>: ");

		} while (Contact->apartmentNumber < 0);

	}

	printf("Please enter the contact's postal code: ");
	scanf(" %7[^\n]", Contact->postalCode);
	clearKeyboard();

	printf("Please enter the contact's city: ");
	scanf(" %40[^\n]", Contact->city);
	clearKeyboard();

}

// getNumbers:
// HINT:  Update this function to use the new helper 
//        function "getTenDigitPhone" where applicable

void getNumbers(struct Numbers *Contact)

{
	char telNum[10];

	// Contact Numbers Input:

	printf("Please enter the contact's cell phone number: ");
	getTenDigitPhone(telNum);
	clearKeyboard();

	printf("Do you want to enter a home phone number? (y or n): ");

	if (yes()) {
		printf("Please enter the contact's home phone number: ");
		getTenDigitPhone(telNum);
		clearKeyboard();

	}

	printf("Do you want to enter a business phone number? (y or n): ");

	if (yes()) {
		printf("Please enter the contact's business phone number: ");
		getTenDigitPhone(telNum);
		clearKeyboard();

	}

}

// getContact

void getContact(struct Contact *Contact)

{
	getName(&Contact->name);
	getAddress(&Contact->address);
	getNumbers(&Contact->numbers);
}
