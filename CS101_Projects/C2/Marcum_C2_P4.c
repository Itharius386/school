#include <stdio.h>

//	Name: Taxation represented
//  Purpose: Adds 5% tax to a given cash value
//  Author: James Marcum


int main(void)

{
	float cash, plustax;
	
	printf("Enter an amount of money: ");
	scanf("%f", &cash);
	
	plustax = (cash * 1.05f);
	
	printf("With tax added: %.02f", plustax);
	
	return 0;
}

