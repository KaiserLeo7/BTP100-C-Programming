/* -------------------------------------------
Name: Andriy Ostapovych
Student number: 143066181
Email: aostapovych@myseneca.ca
Section: BTP100SBB
Date: 11/25/2018
----------------------------------------------
Assignment: 2
Milestone:  4
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// +-------------------------------------------------+
// | NOTE:  Include additional header files...       |
// +-------------------------------------------------+


#include "contacts.h"


#include "contactHelpers.h"


// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        source code below...                     |
// +-------------------------------------------------+

// getName:


void getName(struct Name *contact)

{
	// Contact Name Input:

	printf("Please enter the contact's first name: ");
	scanf(" %30[^\n]", contact->firstName);
	clearKeyboard();

	printf("Do you want to enter a middle initial(s)? (y or n): ");

	if (yes())
	{
		printf("Please enter the contact's middle initial(s): ");
		scanf(" %6[^\n]", contact->middleInitial);
		clearKeyboard();

	}

	printf("Please enter the contact's last name: ");
	scanf(" %35[^\n]", contact->lastName);
	clearKeyboard();

}
// getAddress:

void getAddress(struct Address *contact)

{

	// Contact Address Input:

	printf("Please enter the contact's street number: ");

	do {

		contact->streetNumber = getInt();

		if (contact->streetNumber < 0)
		{
			printf("Please enter the contact's street number: ");
			contact->streetNumber = getInt();
		}
//	printf("*** INVALID STREET NUMBER *** <must be a positive number>: ");

	} while (contact->streetNumber < 0);

	printf("Please enter the contact's street name: ");
	scanf(" %40[^\n]", contact->street);

	printf("Do you want to enter an apartment number? (y or n): ");

	if (yes())
	{
		printf("Please enter the contact's apartment number: ");

		do {

			contact->apartmentNumber = getInt();

			if (contact->apartmentNumber < 0)
			{
				printf("Please enter the contact's apartment number: ");
				contact->apartmentNumber = getInt();
			}
//				printf("*** INVALID APARTMENT NUMBER *** <must be a positive number>: ");

		} while (contact->apartmentNumber < 0);

	}

	printf("Please enter the contact's postal code: ");
	scanf(" %7[^\n]", contact->postalCode);
	clearKeyboard();

	printf("Please enter the contact's city: ");
	scanf(" %40[^\n]", contact->city);
	clearKeyboard();

}


// getNumbers:


void getNumbers(struct Numbers *contact)

{

	// Contact Numbers Input:

	printf("Please enter the contact's cell phone number: ");
	getTenDigitPhone(contact->cell);
//	clearKeyboard();

	printf("Do you want to enter a home phone number? (y or n): ");

	if (yes())
	 {
		printf("Please enter the contact's home phone number: ");
		getTenDigitPhone(contact->home);
//		clearKeyboard();
  	 }

	printf("Do you want to enter a business phone number? (y or n): ");

	if (yes()) {
		printf("Please enter the contact's business phone number: ");
		getTenDigitPhone(contact->business);
//		clearKeyboard();

	}

}


// getContact:


void getContact(struct Contact *contact)

{
	getName(&contact->name);
	getAddress(&contact->address);
	getNumbers(&contact->numbers);
}
