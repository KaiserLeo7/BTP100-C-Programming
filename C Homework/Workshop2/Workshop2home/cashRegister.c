/*
	 Name:      <Andriy Ostapovych>
	 Student#:  <143066181>
	 Section:   <B>
*/

#define _CRT_SECURE_NO_WARNINGS
# include <stdio.h>


double paid, changeAfterLoon, changeAfterQuarters, changeAfterDimes, changeAfterNickels, changeAfterPennies, GST;
int paidLoonies, paidQuarters, paidDimes, paidNickels, paidPennies;

int main()

{
	printf("Please enter the amount to be paid: $");
	scanf("%lf", &paid);

	GST = paid * .13 + .005;
	paid = GST + paid;
	paidLoonies = paid;
	changeAfterLoon = paid - paidLoonies;
	paidQuarters = (changeAfterLoon * 100) / 25;
	changeAfterQuarters = ((int)(changeAfterLoon * 100)) % 25;
	paidDimes = changeAfterQuarters / 10;
	changeAfterDimes = ((int)(changeAfterQuarters)) % 10;
	paidNickels = changeAfterDimes / 5;
	changeAfterNickels = ((int)(changeAfterDimes)) % 5;
	paidPennies = changeAfterNickels / 1;
	changeAfterPennies = ((int)(changeAfterNickels)) % 1;



	printf("GST: %.2lf\n", GST);
	printf("Balance owing: $%.2lf\n", paid);
	printf("Loonies required: %d,", paidLoonies);
	printf(" balance owing $%.2lf\n", changeAfterLoon);
	printf("Quarters required: %d,", paidQuarters);
	printf(" balance owing $%.2lf\n", (float)changeAfterQuarters / 100);
	printf("Dimes required: %d,", paidDimes);
	printf(" balance owing $%.2lf\n", (float)changeAfterDimes / 100);
	printf("Nickels required: %d,", paidNickels);
	printf(" balance owing $%.2lf\n", (float)changeAfterNickels / 100);
	printf("Pennies required: %d,", paidPennies);
	printf(" balance owing $%.2lf\n", (float)changeAfterPennies / 100);


	return 0;
}