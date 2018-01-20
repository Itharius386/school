#include <stdio.h>
#include <stdlib.h>
//I guess I shouldn't know about that library yet, but I needed absolute value for negative integers

//	Name: Numbers in numbers
//  Purpose: Determine the number of digits in a number (limitations apply)
//  Author: James Marcum


int main(void)

{
//define num
int num, dig=0;

//ask for a number (limit 4 digits)
	printf("Enter a number between -9999 and 9999: ");
	scanf("%d", &num);

//determine digits and print
	if (abs(num) > 9999)
		printf("\n%d has too many digits, ain't nobody got time for that.",num);
	else if (abs(num) > 999)
		printf("\nPretty sure %d has 4 digits",num);
	else if (abs(num) > 99)
		printf("\n%d definitely has 3 digits... I think",num);
	else if (abs(num) > 9)
		printf("\n%d has 2 digits, probably...",num);
	else
		printf("\n%d has a single digit, I am sure of it.",num);

//loop without digit limits if previous checks failed	 
	if (abs(num) > 9999)
		{
		do { 
			num /= 10;
			dig++;
			} while (abs(num) > 0);
		//print from loop
		printf("\n\n\nOkay, if you really have to know, it has %d digits\n", dig);
		}

return 0;

}

