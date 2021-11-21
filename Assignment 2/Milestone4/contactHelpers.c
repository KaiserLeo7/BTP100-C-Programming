/* -------------------------------------------
Name: Andriy Ostapovych
Student number: 143066181
Email: aostapovych@myseneca.ca
Section: BTP100SBB
Date: 11/19/2018
----------------------------------------------
Assignment: 2
Milestone:  4
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the SYSTEM string library functions.
// HINT: The library name is string.h.
//       #include the string.h header file on the next line:


#include <string.h>

// ----------------------------------------------------------
// Include your contactHelpers header file on the next line:

#include "contactHelpers.h"

// ----------------------------------------------------------
// define MAXCONTACTS for sizing contacts array (5):

#define MAXCONTACTS 5

struct Contact UserData[MAXCONTACTS] = { { { "Rick", {'\0'}, "Grimes" },
										{ 11, "Trailer Park", 0, "A7A 2J2", "King City" },
										{ "4161112222", "4162223333", "4163334444" } },
										{
										{ "Maggie", "R.", "Greene" },
										{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
										{ "9051112222", "9052223333", "9053334444" } },
										{
										{ "Morgan", "A.", "Jones" },
										{ 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
										{ "7051112222", "7052223333", "7053334444" } },
										{
										{ "Sasha", {'\0'}, "Williams" },
										{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
										{ "9052223333", "9052223333", "9054445555" } },
										{
										{ "", {'\0'}, "" },
										{ 0, "", 0, "", "" },
										{ "", "", "", } },
									};
//------------------------------------------------------
// Function Definitions
//------------------------------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        function definitions below...            |
// +-------------------------------------------------+

// clearKeyboard

void clearKeyboard(void)

{
	while (getchar() != '\n'); // empty execution code block on purpose
}


// pause:



void pause(void)

{
	printf("(Press Enter to Continue)");

	clearKeyboard();

}


// getInt:

int getInt(void)

{

	int value;

	char newLine = 'x';

	while (newLine != '\n') {

		scanf("%d%c", &value, &newLine);

		if (newLine != '\n') {

			clearKeyboard();

			printf("*** INVALID INTEGER *** <Please enter an integer>: ");

		}

	}
	return value;
}


// getIntInRange:


int getIntInRange(int lowerbound, int upperbound)

{
	int validInt, test = 0;

	while (test == 0)

	{
		validInt = getInt();

		if (validInt > upperbound || validInt < lowerbound)

			printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", lowerbound, upperbound);
		else
			test = 1;

	}
	return validInt;
}



// yes:




int yes(void)

{

	char Entry, NL;

	int yOrY = 0;

	do {

		scanf(" %c%c", &Entry, &NL);

		if (NL != '\n') {

			clearKeyboard();

			printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");

		}

		else {

			if (Entry == 'y' || Entry == 'Y')

				yOrY = 1;

		}

	} while (NL != '\n');

	return yOrY;

}



// menu:

int menu(void)

{
	int selection;

	printf("Contact Management System\n");
	printf("-------------------------\n");
	printf("1. Display contacts\n");
	printf("2. Add a contact\n");
	printf("3. Update a contact\n");
	printf("4. Delete a contact\n");
	printf("5. Search contacts by cell phone number\n");
	printf("6. Sort contacts by cell phone number\n");
	printf("0. Exit");
	printf("\n\n");
	printf("Select an option:> ");

	selection = getIntInRange(0, 6);
	printf("\n");
	return selection;

}

// contactManagerSystem:

void contactManagerSystem(void)

{
	int selection = 0, yesOrNo = 2;

	while (yesOrNo != 1) {

		selection = menu();

		switch (selection) {

		case 1:
			displayContacts(UserData, MAXCONTACTS);
			pause();
			printf("\n");
			break;


		case 2:
			addContact(UserData, MAXCONTACTS);

			pause();
			printf("\n");
			break;


		case 3:
			updateContact(UserData, MAXCONTACTS);
			pause();
			printf("\n");
			break;


		case 4:
			deleteContact(UserData, MAXCONTACTS);
			pause();
			printf("\n");
			break;


		case 5:
			searchContacts(UserData, MAXCONTACTS);
			pause();
			printf("\n");
			break;


		case 6:
			sortContact(UserData, MAXCONTACTS);
			pause();
			printf("\n");
			break;


		case 0:
			printf("Exit the program? (Y)es/(N)o: ");
			yesOrNo = yes();
			printf("\n");


			if (yesOrNo == 1)
				printf("Contact Management System: terminated\n");
			break;

			if (yesOrNo == 0)
				break;

		}
	}
}



// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        empty function definitions below...      |
// +-------------------------------------------------+

// getTenDigitPhone:

void getTenDigitPhone(char telNum[])

{
	int needInput = 1, i = 0, counter = 0;

	do {

		scanf("%10s", telNum);
//		clearKeyboard();
		
		
			for (i = 0; i <= 10; i++)
			{
				if (telNum[i] >= '0' && telNum[i] <= '9')
				{
					counter++;
					if (counter == 10)
					{
						needInput = 0;
					}
				}

			}
			clearKeyboard();
			if (needInput != 0)
			{
				
				printf("Enter a 10-digit phone number: ");

			}
		
	} while (needInput == 1);

}

// findContactIndex:

int findContactIndex(const struct Contact contacts[], int  size, const char cellNum[])

{
	int i = 0, match = -1;

	for (i = 0; i < size; i++ )
	{
		if (strcmp(contacts[i].numbers.cell, cellNum) == 0)
			match = i;
		
	}
		return match;
}

// displayContactHeader

void displayContactHeader(void)

{
//printf("\n");
printf("+-----------------------------------------------------------------------------+\n");
printf("|                              Contacts Listing                               |\n");
printf("+-----------------------------------------------------------------------------+\n");
           
}

// displayContactFooter

void displayContactFooter(int value)

{

printf("+-----------------------------------------------------------------------------+\n");
printf("Total contacts: %d\n\n", value);

}

// displayContact:

void displayContact(const struct Contact* contacts)
{

	if (contacts->name.middleInitial[0] != '\0')
		printf(" %s %s %s\n", contacts->name.firstName,
							  contacts->name.middleInitial, 
							  contacts->name.lastName);
	else
		printf(" %s %s\n", contacts->name.firstName, contacts->name.lastName);

	printf("    C: %-10s   H: %-10s   B: %-10s\n", contacts->numbers.cell,
													 contacts->numbers.home,
													 contacts->numbers.business);
	
	if (contacts->address.apartmentNumber > 0)
		printf("       %d %s, Apt# %d, %s, %s\n", contacts->address.streetNumber, 
												  contacts->address.street,
												  contacts->address.apartmentNumber, 
												  contacts->address.city,
												  contacts->address.postalCode);
	else
		printf("       %d %s, %s, %s\n", contacts->address.streetNumber, 
										 contacts->address.street,
										 contacts->address.city,
										 contacts->address.postalCode);

}

// displayContacts:

void displayContacts(const struct Contact contacts[], int size)
{
	int valid = 0, i;

	displayContactHeader();
	for(i = 0; i < size; i++ )
	{
		if ((strlen(contacts[i].numbers.cell)) > 0)
		{
			valid++;
			displayContact(&contacts[i]);
			
		}
	}
	displayContactFooter(valid);

}

// searchContacts:

void searchContacts(const struct Contact contacts[], int size)

{
	char telNum[11];

	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(telNum);
  	int index = findContactIndex(contacts, MAXCONTACTS, telNum);

	if(index != -1)
	{
		printf("\n");
		displayContact(&contacts[index]);
		printf("\n");
	}
	else
		printf("*** Contact NOT FOUND ***\n\n");

}

// addContact:

void addContact(struct Contact contacts[], int size)

{
	int i, check = -1;

	for (i = 0; i < size && check == -1; i++)
	{
		if (strlen(contacts[i].numbers.cell) == 0)
		{
			check = i;
			getContact(&contacts[i]);
			
			printf("--- New contact added! ---");
			printf("\n\n");

		}
	}	
	if (check == -1)
	{
		printf("*** ERROR: The contact list is full! ***");
		printf("\n\n");
	}
}

// updateContact:

void updateContact(struct Contact contacts[], int size)
{
	char telNum[11];
	struct Contact tempCont = { {{0}} };

	printf("Enter the cell number for the contact: ");

	getTenDigitPhone(telNum);
	int index = findContactIndex(contacts, size, telNum);
	
	if (index == -1)
	{
		printf("*** Contact NOT FOUND ***");
		printf("\n\n");
	}
	else
	{

		printf("\n");
		printf("Contact found:");
		printf("\n");
		displayContact(&contacts[index]);
		printf("\n");
		
		printf("Do you want to update the name? (y or n): ");
	

		if (yes()) 
		{
			contacts[index].name = tempCont.name;
			getName(&contacts[index].name);
		}
		printf("Do you want to update the address? (y or n): ");
		if (yes()) 
		{
			contacts[index].address = tempCont.address;
			getAddress(&contacts[index].address);
		}
		printf("Do you want to update the numbers? (y or n): ");
		if (yes()) 
		{
			contacts[index].numbers = tempCont.numbers;
			getNumbers(&contacts[index].numbers);
		}
		printf("--- Contact Updated! ---\n\n");
	}
	

}

// deleteContact:

void deleteContact(struct Contact contacts[], int size)
{
	char telNum[11];
	struct Contact temp = { {{0}} };
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(telNum);

	int index = findContactIndex(contacts, MAXCONTACTS, telNum);

	if (index == -1)
	{

		printf("*** Contact NOT FOUND ***");
	}
	else 
	{
		printf("\n");
		printf("Contact found:\n");
		displayContact(&contacts[index]);
		printf("\n");
		printf("CONFIRM: Delete this contact? (y or n): ");

		if (yes())
		{
			contacts[index].numbers = temp.numbers;
//		contacts[index].numbers.cell[0] = '\0';
			printf("--- Contact deleted! ---\n\n");
		}
		else
		{
			printf("\n");
		}
	}
}

// sortContacts:

void sortContact(struct Contact contacts[], int size)
{
	printf("<<< Feature to sort is unavailable >>>\n");

}

