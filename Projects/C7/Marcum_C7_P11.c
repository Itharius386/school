#include <stdio.h>

//	Name: A rose by any other name
//  Purpose: Takes first and last name entered and displays it last name, first initial: Capulet, J.
//  Author: James Marcum


int main(void)

{
//First initial and last name characters
char first_initial, last_name;

//ask for a name
	printf("\nEnter a first and last name: ");
//steal the first initial
	scanf(" %c", &first_initial);
	
	
	
//ignore the rest of the first name
	while (getchar() != ' '){
	//I forgot to add these brackets for like 10 minutes and couldn't figure out why this wasn't working right
	}
	
	
	
//now steal the last name
	while ((last_name = getchar()) != '\n')
	{
//ignore the spaces	   	   
		if (last_name != ' ')
			printf("%c", last_name);
	}	
	
	
	
//finish it off with the ',' First initial, and the period
	printf(", %c.\n", first_initial);
	
	
return 0;
}

