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

// This source file needs to "know about" the SYSTEM string library functions.
// HINT: The library name is string.h.
//       #include the string.h header file on the next line:

#include <string.h>

// ----------------------------------------------------------
// Include your contactHelpers header file on the next line:

#include "ContactHelpers.h"

//------------------------------------------------------
// Function Definitions
//------------------------------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-2 |
// |        function definitions below...            |
// +-------------------------------------------------+

// clearKeyboard:

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
			printf("\n<<< Feature 1 is unavailable >>>\n\n");
			pause();
			printf("\n");
			break;

		case 2:
			printf("\n<<< Feature 2 is unavailable >>>\n\n");
			pause();
			printf("\n");
			break;

		case 3:
			printf("\n<<< Feature 3 is unavailable >>>\n\n");
			pause();
			printf("\n");
			break;

		case 4:
			printf("\n<<< Feature 4 is unavailable >>>\n\n");
			pause();
			printf("\n");
			break;

		case 5:
			printf("\n<<< Feature 5 is unavailable >>>\n\n");
			pause();
			printf("\n");
			break;

		case 6:
			printf("\n<<< Feature 6 is unavailable >>>\n\n");
			pause();
			printf("\n");
			break;

		case 0:
			printf("\nExit the program? (Y)es/(N)o: ");

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
// | ====== Assignment 2 | Milestone 3 =======       |
// +-------------------------------------------------+
// | Put empty function definitions below...         |
// +-------------------------------------------------+

// Generic function to get a ten-digit phone number (ensures 10-digit chars entered)
// ---------------------------------------------------------------------------------
// NOTE: Modify this function to validate only numeric character digits are entered
// ---------------------------------------------------------------------------------
void getTenDigitPhone(char telNum[])
{
	int needInput = 1, i = 0, counter = 0, flag = 1;

	while (needInput == 1) {
		scanf("%10s", telNum);
		clearKeyboard();

		if (strlen(telNum) == 10)
		{
			for (i = 0; i < 10 && flag == 1; i++)
			{
				if (telNum[i] >= '0' && telNum[i] <= '9')
				{
					counter++;
					if (counter == 10)
						needInput = 0;
				}
				else
					flag = 0;
			}
		}
		else
			printf("Enter a 10-digit phone number: ");
	}
}

// (String Length Function: validate entry of 10 characters)
		
// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{
	return -1;
}


// displayContactHeader
// Put empty function definition below:

void displayContactHeader(void);

// displayContactFooter
// Put empty function definition below:

void displayContactFooter(int);

// displayContact:
// Put empty function definition below:

void displayContact(const struct Contact*);


// displayContacts:
// Put empty function definition below:

void displayContacts(const struct Contact[], int);


// searchContacts:
// Put empty function definition below:


void searchContacts(const struct Contact[], int);

// addContact:
// Put empty function definition below:


void addContact(struct Contact[], int);

// updateContact:
// Put empty function definition below:

void updateContact(struct Contact[], int);

// deleteContact:
// Put empty function definition below:

void deleteContact(struct Contact[], int);

// sortContacts:
// Put empty function definition below:

void sortContact(struct Contact[], int);