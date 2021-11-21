/*
Name:  Andriy Ostapovych
Student number: 143066181
Email: aostapovych@myseneca.ca
Workshop: 5
Section: BTP100SBB
Date: 10/6/2018
*/

#define _CRT_SECURE_NO_WARNINGS
#define SIZE 4
#include <stdio.h>	

struct Employee {

	int idNumber, age;
	double salary;

};

int main(void)
{


	struct Employee emp[SIZE] = { {0} };
	int i = 0, option = 0, validEmp = 0, done = 0, idAttempt;

	printf("---=== EMPLOYEE DATA ===---\n\n");

	do {
		// Print the option list

		printf("1. Display Employee Information\n");
		printf("2. Add Employee\n");
		printf("3. Update Employee Salary\n");
		printf("4. Remove Employee\n");
		printf("0. Exit\n\n");
		printf("Please select from the above options: ");

		// Capture input to option variable

		scanf("%d", &option);
		printf("\n");

		switch (option) {

		case 0:	// Exit the program

			printf("Exiting Employee Data Program. Good Bye!!!\n");

			break;

		case 1: // Display Employee Data

			printf("EMP ID  EMP AGE EMP SALARY\n");
			printf("======  ======= ==========\n");

			for(i = 0; i < SIZE; i++){

				if (emp[i].idNumber > 0){

					printf("%6d%9d%11.2lf\n", emp[i].idNumber, emp[i].age, emp[i].salary);
					
				}
			}

			printf("\n");

			break;

		case 2:	// Adding Employee

			printf("Adding Employee\n");
			printf("===============\n");

			if (validEmp >= SIZE)
			{

				printf("ERROR!!! Maximum Number of Employees Reached\n\n");
				break;
			}
			else
			{
				for (i = 0; i < SIZE; i++) {

					if (emp[i].idNumber == 0) {

						printf("Enter Employee ID: ");
						scanf("%d", &emp[i].idNumber);

						printf("Enter Employee Age: ");
						scanf("%d", &emp[i].age);

						printf("Enter Employee Salary: ");
						scanf("%lf", &emp[i].salary);

						validEmp++;

						printf("\n");

						break;
					}
				}
			}
			break;

		case 3:// Update Employee Salary
				
			printf("Update Employee Salary\n");
			printf("======================\n");
			done = 0;
			do {
				printf("Enter Employee ID: ");
				scanf("%d", &idAttempt);
				
				for (i = 0; i < SIZE && done == 0; i++) {

					if (idAttempt == emp[i].idNumber) {
						done = 1;
						printf("The current salary is %.2lf\n", emp[i].salary);
						printf("Enter Employee New Salary: ");
						scanf("%lf", &emp[i].salary);

						printf("\n");

						
					}
				}
				if(done == 0)
				printf("*** ERROR: Employee ID not found! ***\n");

			} while (idAttempt != emp[i].idNumber && done == 0);

			break;

		case 4:// Remove Employee

			printf("Remove Employee\n");
			printf("===============\n");

			done = 0;

			do {
				printf("Enter Employee ID: ");
				scanf("%d", &idAttempt);
				
				for (i = 0; i < SIZE && done == 0; i++) {

					if (idAttempt == emp[i].idNumber) {

						done = 1;

						printf("Employee %d will be removed\n\n", emp[i].idNumber);

						emp[i].idNumber = 0;		//
						emp[i].age = 0;				//reset the Employee Slot
						emp[i].salary = 0;			//
						
						validEmp--;

		
					}
					
				}
				if(done == 0)
				printf("*** ERROR: Employee ID not found! ***\n");

			} while (idAttempt != emp[i].idNumber && done == 0);


			break;

		case '\n':
			break;

		default:
			printf("ERROR: Incorrect Option: Try Again\n\n");
		}

	} while (option != 0);


	return 0;
}

