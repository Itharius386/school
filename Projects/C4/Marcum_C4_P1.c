#include <stdio.h>

//	Name: The ol' switcheroo 
//  Purpose: reverses the digits of a 2 digit number
//  Author: James Marcum


int main(void)

{

//Number, First Digit, Second Digit
int num, first_dig, sec_dig;


//Ask user for a two-digit number
	printf("Please enter a two-digit number: ");
	scanf("%d", &num);

//calculate first and second digit	  
	first_dig = num / 10;
	sec_dig = num % 10;

//print in reverse
	printf("%d in reverse is: %d%d\n", num, sec_dig, first_dig);
	
return 0;

}

