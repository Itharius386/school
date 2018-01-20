#include <stdio.h>

//	Name: x to the power of...
//  Purpose: Solves a polynomial for a given value of x
//  Author: James Marcum


int main(void)

{
	int x, value;

	printf("Enter a value for x: ");
	scanf("%d", &x);
	
	value = (3 *x*x*x*x*x) + (2 *x*x*x*x) - (5 *x*x*x) - (x*x) + (7 *x) - 6;

	printf("The value of 3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6 where x equals %d is %d", x , value);

return 0;
}

