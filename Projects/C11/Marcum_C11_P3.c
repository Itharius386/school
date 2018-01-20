#include <stdio.h>
#include <ctype.h>

//	Name: At my lowest... terms
//  Purpose: reduce a fraction to lowest terms - with functions and pointers
//  Author: James Marcum


//Function Prototypes

void reduce(int numerator, int denominator, int *reduced_numerator, int *reduced_denominator);

//MAIN BEGIN

int main(void)

{
//define numerator and demoninator, and reduced numerator and demoninator (yes, demon-inator, inates demons, fractionally)
int numer, demon, reduced_numer, reduced_demon;
//more fractions (maybe)
char again;

do  {
//Ask user for fraction
	printf("\nPlease enter a fraction to be reduced: ");
	scanf("%d/%d", &numer,&demon);
	
//Call reduce
reduce(numer,demon,&reduced_numer,&reduced_demon);


//come to terms with your smaller fraction
//present it as a whole number if the demoninator is 1
	if (reduced_demon == 1)
		printf("Your fraction reduced to %d\nIt's a whole number!", reduced_numer);
	else
		printf("Your fraction reduced to %d/%d", reduced_numer, reduced_demon);
		
	printf("\nAgain? (Y/N)\a ");
	scanf(" %c", &again);
	} while (again == 'y' || again == 'Y');


return 0;
}


//MAIN END

//Functions Below


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *														 *
 *	reduce:	reduces a fraction to it's lowest terms		 *
 *														 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void reduce(int numerator, int denominator, int *reduced_numerator, int *reduced_denominator)
{
//stay a deer, global cooldown, almost i
int remaindeer, gcd, num1;


	*reduced_numerator = numerator;
	*reduced_denominator = denominator;
	
//set gcd and num1 to the numerator and demoninator
	gcd = numerator;
	num1 = denominator;

//use gcd and num1 to calculate the GCD
	while (num1 != 0) {
			remaindeer = gcd % num1;
			gcd = num1;
			num1 = remaindeer;
		}

//divide numerator and denominator by GCD
	*reduced_numerator /= gcd;
	*reduced_denominator /= gcd;

}

