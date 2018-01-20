#include <stdio.h>

//	Name: Valentines day makes a bad first date
//  Purpose: compares 2 dates and determines which came first
//  Author: James Marcum


int main(void)

{
//define month 1-2, day 1-2, year 1-2
int mnth1, mnth2, day1, day2, year1, year2;

//Ask them on a date ;)
	printf("Enter the first date (mm/dd/yyyy): ");
	scanf("%d/%d/%d",&mnth1,&day1,&year1);

//Ask them for a second date (too soon?)
	printf("Enter the second date (mm/dd/yyyy): ");
	scanf("%d/%d/%d",&mnth2,&day2,&year2);

//Which came first (chicken or the egg)
	if (year1 < year2)
		printf("\n%.2d/%.2d/%.2d came before %.2d/%.2d/%.2d",mnth1,day1,year1,mnth2,day2,year2);
	else if (mnth1 < mnth2 && year1 == year2)
		printf("\n%.2d/%.2d/%.2d came before %.2d/%.2d/%.2d",mnth1,day1,year1,mnth2,day2,year2);
	else if (day1 < day2 && mnth1 == mnth2 && year1 == year2)
		printf("\n%.2d/%.2d/%.2d came before %.2d/%.2d/%.2d",mnth1,day1,year1,mnth2,day2,year2);
	else if (day1 == day2 && mnth1 == mnth2 && year1 == year2)
		printf("\n%.2d/%.2d/%.2d and %.2d/%.2d/%.2d are the same date!!! Trickster!",mnth1,day1,year1,mnth2,day2,year2);
		//don't double book dates
	else
		printf("%.2d/%.2d/%.2d came before %.2d/%.2d/%.2d",mnth2,day2,year2,mnth1,day1,year1);


//No third date :(
return 0;

}

