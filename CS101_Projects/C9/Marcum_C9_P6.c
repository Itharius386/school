#include <stdio.h>

//	Name: fun(ctions) with polynomials
//  Purpose: solve a given polynomial for x
//  Author: James Marcum


//Funcation prototypes

int com_poly(int x);

//BEGIN MAIN

int main(void)

{
// x here
int x;

//prompting
	printf("\nWe are going to solve 3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6\nfor a given value.\n\nEnter a value for x: ");
//scanning
	scanf("%d",&x);
//print-f-ing (and computing the answer I guess)
	printf("\n\nFor x = %d, the polynomial is equal to: %d",x,com_poly(x));
	
//fin?
return 0;
}

//END MAIN

//functions below

/* * * * * * * * * * * * * * * * * * * * * * *
 *											 *
 *	com_poly:	solves a polynomial for x	 *
 *											 *
 * * * * * * * * * * * * * * * * * * * * * * */

int com_poly(int x)
{
return ((3* (x* x* x* x* x)) + (2* (x* x* x* x)) - (5* (x* x* x)) - (x* x) + (7*x) - 6);
}

