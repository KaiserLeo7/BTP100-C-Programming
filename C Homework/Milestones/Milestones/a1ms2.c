/* -------------------------------------------
Name: Andriy Ostapovych
Student number: 143066181
Email: aostapovych@myseneca.ca
Section: BTP100SBB
Date: 10/25/2018

----------------------------------------------
Assignment: 1
Milestone:  2
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include "contacts.h"

int main(void)
{
	// Declare variables here:
	struct Name wholeName = { 0 };
	struct Address address = { 0 };
	struct Numbers numbers = { 0 };

	char option;
	// Display the title

	printf("Contact Management System\n");
	printf("-------------------------\n");

	// Contact Name Input:

	printf("Please enter the contact's first name: ");
	scanf("%30[^\n]", wholeName.firstName);

	printf("Do you want to enter a middle initial(s)? (y or n): ");
	scanf("%c\n", &option);


	if (option == 'y' || option == 'Y') {
		printf("Please enter the contact's middle initial(s): ");
		scanf("%6[^\n]", wholeName.middleInitial);
		renewOption();
	}

	printf("Please enter the contact's last name: ");
	scanf("%35[^\n]\n", wholeName.lastName);


	// Contact Address Input:

	printf("Please enter the contact's street number: ");
	scanf("%d", &address.streetNumber);

	printf("Please enter the contact's street name: ");
	scanf("%40[^\n]\n", address.street);

	printf("Do you want to enter an apartment number? (y or n): ");
	scanf("%c\n", &option);

	if (option == 'y' || option == 'Y') {
		printf("Please enter the contact's apartment number: ");
		scanf("%d", &address.apartmentNumber);
		renewOption();
	}

	printf("Please enter the contact's postal code: ");
	scanf("%7[^\n]\n", address.postalCode);

	printf("Please enter the contact's city: ");
	scanf("%40[^\n]\n", address.city);

	// Contact Numbers Input:

	printf("Do you want to enter a cell phone number? (y or n): ");
	scanf("%c\n", &option);

	if (option == 'y' || option == 'Y') {
		printf("Please enter the contact's cell phone number: ");
		scanf("%10s\n", numbers.cell);
		renewOption();
	}

	printf("Do you want to enter a home phone number? (y or n): ");
	scanf("%c\n", &option);

	if (option == 'y' || option == 'Y') {
		printf("Please enter the contact's home phone number: ");
		scanf("%10s\n", numbers.home);
		renewOption();
	}


	printf("Do you want to enter a business phone number? (y or n): ");
	scanf("%c\n", &option);

	if (option == 'y' || option == 'Y') {
		printf("Please enter the contact's business phone number: ");
		scanf("%10s\n", numbers.business);
		renewOption();
	}

	// Display Contact Summary Details

	printf("Contact Details\n");
	printf("---------------\n");
	
	printf("Name Details\n");
	printf("First name: ");
	printf("%s\n", wholeName.firstName);
	printf("Middle initial(s): ");
	printf("%s\n", wholeName.middleInitial);
	printf("Last name: ");
	printf("%s\n", wholeName.lastName);

	printf("Address Details\n");
	printf("Street number: ");
	printf("%d\n", address.streetNumber);
	printf("Street name: ");
	printf("%s\n", address.street);
	printf("Apartment: ");
	printf("%d\n", address.apartmentNumber);
	printf("Postal code: ");
	printf("%s\n", address.postalCode);
	printf("City: ");
	printf("%s\n", address.city);

	printf("Phone Numbers:\n");
	printf("Cell phone number: ");
	printf("%s\n", numbers.cell);
	printf("Home phone number: ");
	printf("%s\n", numbers.home);
	printf("Business phone number: ");
	printf("%s\n", numbers.business);


	// Display Completion Message

	printf("Structure test for Name, Address, and Numbers Done!");
	
	return 0;
}


renewOption() {

	char option = 0;

}
/*  SAMPLE OUTPUT:

	Contact Management System
	-------------------------
	Please enter the contact's first name: Tom
	Do you want to enter a middle initial(s)? (y or n): y
	Please enter the contact's middle initial(s): L. A.
	Please enter the contact's last name: Wong Song
	Please enter the contact's street number: 20
	Please enter the contact's street name: Keele Street
	Do you want to enter an apartment number? (y or n): y
	Please enter the contact's apartment number: 40
	Please enter the contact's postal code: A8A 4J4
	Please enter the contact's city: North York
	Do you want to enter a cell phone number? (y or n): Y
	Please enter the contact's cell phone number: 9051116666
	Do you want to enter a home phone number? (y or n): Y
	Please enter the contact's home phone number: 7052227777
	Do you want to enter a business phone number? (y or n): Y
	Please enter the contact's business phone number: 4163338888

	Contact Details
	---------------
	Name Details
	First name: Tom
	Middle initial(s): L. A.
	Last name: Wong Song

	Address Details
	Street number: 20
	Street name: Keele Street
	Apartment: 40
	Postal code: A8A 4J4
	City: North York

	Phone Numbers:
	Cell phone number: 9051116666
	Home phone number: 7052227777
	Business phone number: 4163338888

	Structure test for Name, Address, and Numbers Done!
*/