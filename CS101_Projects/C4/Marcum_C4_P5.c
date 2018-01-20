#include <stdio.h>

//	Name: UP-Code
//  Purpose: Finds the check digit of a UPC
//  Author: James Marcum


int main(void)

{
//Digits 1-11, First Sum, Second Sum, Check
int d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11, f_sum, s_sum, check_sum;

//Ask for UPC
	printf("Enter the first 11 digits of a UPC: ");
	scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d", &d1,&d2,&d3,&d4,&d5,&d6,&d7,&d8,&d9,&d10,&d11);

//calculate check sum
	f_sum = d1+d3+d5+d7+d9+d11;
	s_sum = d2+d4+d6+d8+d10;
	check_sum = 9-(((3*f_sum + s_sum)-1)%10);

//print check
	printf("The check digit is: %d\n", check_sum);

return 0;

}

