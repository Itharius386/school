#include <stdio.h>

//	Name: The ol' switcheroo v2.0
//  Purpose: reverses the digits of a 3 digit number
//  Author: James Marcum


int main(void)

{

//Number, First Digit, Second Digit, Third Digit
int num, first_dig, sec_dig, third_dig;


//Ask user for a three-digit number
	printf("Please enter a three-digit number: ");
	scanf("%d", &num);

//calculate first, second, and third digit	  
	first_dig = num / 100;
	sec_dig = (num / 10) % 10;
	third_dig = num % 10;

//print in reverse
	printf("%d in reverse is: %d%d%d\n", num, third_dig, sec_dig, first_dig);
	
return 0;

}

