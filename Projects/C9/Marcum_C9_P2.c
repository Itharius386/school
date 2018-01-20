#include <stdio.h>

//	Name: Your uncle Sam called, he said you owed him some money V2 (Let's get functional!)
//  Purpose: determine taxes due based on income tax bracket but with a function
//  Author: James Marcum


/* * * * * * * * * * * *
 * Function prototypes *
 * * * * * * * * * * * */

float i_tax_you(float income);


// BEGIN MAIN

int main(void)

{
//define taxable income
float income;
char again;

printf("*****************************\n");
printf("    UNCLE SAM WANTS YOU!\n");
printf("     TO PAY SOME TAXES!\n");
printf("*****************************\n");

//just in case you want to do it more than once
do  {
//Ask for taxable income
	printf("Enter your taxable income: ");
	scanf("%f",&income);
	
//tax time
	printf("\nUncle Sam wants you to pay $%.2f in taxes!\n", i_tax_you(income));
	printf("More taxes to check? (Y/N)\a ");
	scanf(" %c", &again);
	} while (again == 'y' || again == 'Y');


return 0;
}

//END MAIN

//Funtions below:

/* * * * * * * * * * * * * * * * * * * * * * * * * * * **
 *	i_tax_you:	Calculates tax from a given income		*
 *														*
 *	Arguments:	income									*
 *														*
 * * * * * * * * * * * * * * * * * * * * * * * * * * * **/

float i_tax_you(float income)
{
//what we want (no we don't)
float tax_due;
	
//that code from last time, but instead of printing, just calculating	 
	if (income < 750)
		tax_due = (income)*0.01f;
	else if (income < 2250)
		tax_due = (income - 750)*0.02f + 7.50f;
	else if (income < 3750)
		tax_due = (income - 2250)*0.03f + 37.50f;
	else if (income < 5250)
		tax_due = (income - 3750)*0.04f + 82.50f;
	else if (income < 7000)
		tax_due = (income - 5250)*0.05f + 142.50f;
	else
		tax_due = (income - 7000)*0.06f + 230.00f;

//taxes go back	   
return tax_due;
}

