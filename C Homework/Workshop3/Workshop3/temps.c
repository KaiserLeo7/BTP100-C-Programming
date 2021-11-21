/*
	 Name:      <Andriy Ostapovych>
	 Student#:  <143066181>
	 Section:   <B>
*/

# include <stdio.h>

#define NUMS 4


int i, day = 1, loop, temps, highTemp, lowTemp, totalHighTemp, totalLowTemp, totalTemp, highestTemp, lowestTemp, highestTempDay, lowestTempDay;
double meanTemp;
int main (void)
{



	printf("---=== IPC Temperature Analyzer ===---");

	for (i = 0; i < NUMS; ++i)
	{
		while (loop < NUMS)
		{
		printf("\nEnter the high value for day %d: ", day);
		scanf("%d", &highTemp);
		printf("\nEnter the low value for day %d: ", day);
		scanf("%d", &lowTemp);
			if ((highTemp <= 40) && (lowTemp >= -40) && (highTemp > lowTemp)) //as long as all 3 conditions are true 
			{
				totalHighTemp = totalHighTemp + highTemp;						//saving high
				totalLowTemp = totalLowTemp + lowTemp;							//saving low
																			
				if(highTemp > highestTemp)
				{
					highestTemp = highTemp;
					highestTempDay = day;
				}
				if (lowTemp < lowestTemp)
				{
					lowestTemp = lowTemp;
					lowestTempDay = day;
				}
				loop++;															
				day++;
				//printf("%d", highestTemp );
				//printf("%d", lowestTemp);
			}
			else
			{
				printf("\nIncorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n");
				
			}
			
		}
		
	}
		
		printf("\nThe average (mean) temperature was: %.2lf\n",(float)((totalHighTemp + totalLowTemp)/NUMS)/2);
		printf("The highest temperature was %d, ", highestTemp); printf("on day %d\n", highestTempDay);
		printf("The lowest temperature was %d, ", lowestTemp); printf("on day %d\n", lowestTempDay);
	return 0;
}