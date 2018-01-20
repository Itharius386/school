#include <stdio.h>

//	Name: Coming to terms
//  Purpose: reduce a fraction to lowest terms
//  Author: James Marcum


int main(void)

{
//define numerator, demoninator, remainder, gcd, throwaway number 1
int numer, demon, rem, gcd, num1;

//Ask user for fraction
	printf("Enter a fraction: ");
	scanf("%d/%d", &numer,&demon);
	
//set gcd and num1 to the numerator and demoninator
	gcd = numer;
	num1 = demon;

//use gcd and num1 to calculate the GCD
	while (num1 != 0) {
			rem = gcd % num1;
			gcd = num1;
			num1 = rem;
		}

//divide numerator and denominator by GCD
	numer /= gcd;
	demon /= gcd;

//come to terms with your smaller fraction
//present it as a whole number if the demoninator is 1
	if (demon == 1)
		printf("Your fraction reduced to %d\nIt's a whole number now", numer);
	else
		printf("Your fraction reduced to %d/%d", numer, demon);


return 0;
}

