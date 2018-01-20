#include <stdio.h>

//	Name: Beep
//  Purpose: Finds largest number in a series
//  Author: James Marcum


int main(void)

{
//define number and largest number
float num = 0, lnum = 0;

//loop and ask the user to enter numbers until they enter 0 or a negative number
	do {
	printf("\aEnter a number: ");
	scanf("%f", &num);
//check if the number entered is greater than the largest number entered so far
	if (num > lnum)
		lnum = num;
	} while (num >0 );

//print largest number once the user ends the loop
	printf("Largest number entered was %.02f", lnum);

return 0;
}

