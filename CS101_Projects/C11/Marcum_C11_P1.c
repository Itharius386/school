#include <stdio.h>

//	Name: Point Me to the Money ---> $$$$$
//  Purpose: Shows smallest number of bills by denomination - with a function and pointers
//  Author: James Marcum


//Function Prototypes

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones);

//MAIN BEGIN

int main(void)
{
//The money variables
int money, num20, num10, num5, num1;

//Left them know what's going on
	printf("$*$*$*$*$*$*$*$*$*$*$*\n");
	printf("$  CASH MONEY Y'ALL  *\n");
	printf("$*$*$*$*$*$*$*$*$*$*$*\n\n");
	printf("We are going to find the smallest number of bills needed for a given cash amount!\n\n");
//Prompt for money
	printf("Enter a dollar amount: ");
	scanf("%d", &money);

//call the function	   
	pay_amount(money,&num20,&num10,&num5,&num1);
	
//print the number of each bill
	printf("$20 Bills: %d\n", num20);
	printf("$10 Bills: %d\n", num10);
	printf(" $5 Bills: %d\n", num5);
	printf(" $1 Bills: %d\n", num1);

return 0;
}


//MAIN END

//Functions Below

/* * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *													   *
 *	pay_amount:		splits a dollar amount to		   *
 * 	   	   	   	    smallest number of bills needed    *
 *													   *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones)
{

//calculate and reduce
	*twenties = dollars / 20;
	*tens = (dollars - *twenties * 20) / 10;
	*fives = (dollars - (*twenties * 20 + *tens * 10)) / 5;
	*ones = (dollars - (*twenties * 20 + *tens * 10 + *fives * 5));

}

