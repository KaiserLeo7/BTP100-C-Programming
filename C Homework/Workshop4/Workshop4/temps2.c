//--------------------------------------------------
// Name:   Andriy Ostapovych
// Student Number: 143066181
// Email:   aostapovych@myseneca.ca
// Section: B 
// Workshop: 4
//--------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS
#define MAX 10
#include <stdio.h>

int main(void)
{

	int userDays, highValues[MAX], lowValues[MAX], arrayValue, highestTemp = 0, lowestTemp = 0, lastDay, highestDay = 0, lowestDay = 0, highTempSum = 0, lowTempSum = 0;
	double totalSum, averageTemp;

	printf("---=== IPC Temperature Calculator V2.0 ===---");

	printf("\nPlease enter the number of days, between 3 and 10, inclusive: ");
	
	scanf("%d", &userDays);
	
	while (userDays < 3 || userDays > 10) {
		
		printf("\nInvalid entry, please enter a number between 3 and 10, inclusive: ");
		scanf("%d", &userDays);
		
	}

	printf("\n");

		for (arrayValue = 0; arrayValue < userDays; arrayValue++) {
				printf("Day %d - High: ", arrayValue + 1);
				scanf("%d", &highValues[arrayValue]);
				printf("Day %d - Low: ", arrayValue + 1);
				scanf("%d", &lowValues[arrayValue]);

		}

		printf("\nDay  Hi  Low\n");

		for (arrayValue = 0; arrayValue < userDays; arrayValue++) {
			printf("%d    %d    %d\n", arrayValue + 1, highValues[arrayValue], lowValues[arrayValue]);


			if (highValues[arrayValue] > highestTemp)
			{
				highestTemp = highValues[arrayValue];
				highestDay = arrayValue + 1;
			}

			if (lowValues[arrayValue] < lowestTemp)
			{
				lowestTemp = lowValues[arrayValue];
				lowestDay = arrayValue + 1;
			}
		}
		printf("\nThe highest temperature was %d, on day %d", highestTemp, highestDay);
		
		printf("\nThe lowest temperature was %d, on day %d\n", lowestTemp, lowestDay);

		printf("\nEnter a number between 1 and %d to see the average temperature for the entered number of days, enter a negative number to exit: ", userDays);
		scanf("%d", &lastDay);

		while (lastDay >= 0) {
			while (lastDay >= 1 && lastDay <= userDays)
			{
				for (arrayValue = 0; arrayValue < lastDay; arrayValue++)
				{
					highTempSum = highTempSum + highValues[arrayValue];
					lowTempSum = lowTempSum + lowValues[arrayValue];
				}

				totalSum = highTempSum + lowTempSum;
				averageTemp = (double)(totalSum / lastDay) / 2;
				printf("\nThe average temperature up to day %d is: %.2lf\n", lastDay, averageTemp);
				highTempSum = 0;	//highTempSum, lowTempSum, & totalSum reset
				lowTempSum = 0;
				totalSum = 0;

		
				printf("\nEnter a number between 1 and %d to see the average temperature for the entered number of days, enter a negative number to exit: ", userDays);
				scanf("%d", &lastDay);
			}
			while (lastDay > userDays || lastDay == 0 )
			{
				printf("\nInvalid entry, please enter a number between 1 and %d, inclusive: ", userDays);
				scanf("%d", &lastDay);
			}
				
		}
		printf("\nGoodbye!\n");
				return 0;


}
