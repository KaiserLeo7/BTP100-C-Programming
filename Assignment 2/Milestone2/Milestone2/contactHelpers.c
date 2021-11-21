/* -------------------------------------------
Name: Andriy Ostapovych
Student number: 143066181
Email: aostapovych@myseneca.ca
Section: BTP100SBB
Date: 11/13/2018
----------------------------------------------
Assignment: 2
ilestone:  2
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include "contactHelpers.h"

// This source file needs to "know about" the functions you prototyped
// in the contact helper header file.
// HINT: Put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
//       #include your contactHelpers header file on the next line:


//------------------------------------------------------
// Function Definitions
//------------------------------------------------------

// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 2 =======       |
// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        empty function definitions below and     |
// |        complete the definitions as per the      |
// |        Milestone-2 specifications               | 
// |                                                 |
// | - The clearKeyboard function is done for you    |
// +-------------------------------------------------+


// Clear the standard input buffer
void clearKeyboard(void)
{
	while (getchar() != '\n'); // empty execution code block on purpose
}

// pause function definition goes here:
void pause(void)
{
	printf("(Press Enter to Continue)");
	clearKeyboard();
	
}

// getInt function definition goes here:
int getInt(void)
{
	int value;
	char newLine = 'x';

	while (newLine != '\n'){
		
		scanf("%d%c", &value, &newLine);
		
		if(newLine != '\n'){
			clearKeyboard();
			printf("*** INVALID INTEGER *** <Please enter an integer>: ");
		}	
	

	}

	 return value;
 }

// getIntInRange function definition goes here:

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
// yes function definition goes here:

int yes(void)
{
	char Entry, NL;
	int yOrY = 0;
	
	do { 
		scanf(" %c%c", &Entry, &NL);
		if(NL != '\n'){

			clearKeyboard();
			printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");

		}
		else {
			if (Entry == 'y' || Entry == 'Y')
				yOrY = 1;
			}
	} while(NL != '\n');
	return yOrY; 
}
// menu function definition goes here:

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

selection = getIntInRange(0,6);
return selection;

}
// contactManagerSystem function definition goes here:
void contactManagerSystem(void)
{
	int selection = 0, yesOrNo = 2;

	while (yesOrNo != 1){
		selection = menu();

		switch (selection){
	
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

		if(yesOrNo == 1)
		printf("Contact Management System: terminated\n");
		break;
		if(yesOrNo == 0)
		break;

		}
	}
}
