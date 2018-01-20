#include <stdio.h>

//	Name: Too many dates to count
//  Purpose: determine which date came first
//  Author: James Marcum


int main(void)

{
//define date and earliest date
int mon, day, year, emon =13, eday =32, eyear =9999;

//Tell user
	printf("Determines earliest date (mm/dd/yyyy)\nEnter 0/0/0 when done\n");
	
//loop for dates until 0/0/0
	do {
	//ask for date
		printf("Enter a date: ");
		scanf("%d/%d/%d", &mon,&day,&year);

	//check for 0/0/0
		if (mon !=0 && day !=0 && year !=0)
		
		//check year
			if (year < eyear)
				{
				eyear = year;
				emon = mon;
				eday = day;
				}
		//if year same check month	  
			else if (year == eyear && mon < emon)
				{
				emon = mon;
				eday = day;
				}
		//if year and month same check day
			else if (year == eyear && mon == emon && day < eday && day !=0)
				eday = day;
		} while (mon != 0 && day != 0 && year != 0);

//print earliest date
	printf("\nThe earliest date entered was %.2d/%.2d/%.4d", emon,eday,eyear);


return 0;
}

