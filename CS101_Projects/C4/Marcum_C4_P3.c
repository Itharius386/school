#include <stdio.h>

//	Name: The ol' switcheroo 3 - "We are doing it different this time!"
//  Purpose: reverses the digits of a 3 digit number
//  Author: James Marcum


int main(void)

{

//Digits 1, 2, and 3
int dig1, dig2, dig3;

//Ask for a number
	printf("Please enter a three-digit number: ");
	scanf("%1d%1d%1d", &dig1,&dig2,&dig3);

//Print in reverse
	printf("The number in reverse is: %d%d%d",dig3,dig2,dig1);

return 0;

}

