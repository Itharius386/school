#include <stdio.h>

//	Name: What is the date anyway?
//  Purpose: restates the entered date in a different format.
//  Author: James Marcum


int main(void)

{

//define variables for date
int month, day, year;

//ask user for a date
	printf("Please enter a date (mm/dd/yyyy): ");
	scanf("%d/%d/%d", &month, &day, &year);

//print and format the date	   
	printf("You entered the date %.4d%.2d%.2d",year,month,day);
	
return 0;

}

