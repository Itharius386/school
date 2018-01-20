#include <stdio.h>

//	Name: The ol'switcheroo v9001
//  Purpose: reverse the digits of a number with any number of digits
//  Author: James Marcum


int main(void)

{
//define number and reversed number
int num, rnum = 0;

//Ask user for a number to reverse
	printf("Enter an integer: \t\t");
	scanf("%d",&num);

//reverse num
	do {
//have the reversed number increment by 10
	rnum *= 10;
//add the next digit of num to the reverse
	rnum += num%10;
//divide num by 10 and repeat
	num /= 10;
	} while (num > 0);

//print reversed
	printf("The number in reverse is: \t%d",rnum);

return 0;
}

