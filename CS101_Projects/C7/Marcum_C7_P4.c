#include <stdio.h>
#include <ctype.h>


//	Name: Collectin dem digits
//  Purpose: Takes a phonenumber and converts letters in the number to the appropriate numbers
//  Author: James Marcum


int main(void)

{
//That's the 'digits' character
char digits;

//Ask user for a phone number
	printf("Enter a phone number: ");

//Take in the digits entered
	while ((digits = getchar()) != '\n')
		{
//Make sure it's uppercase (don't trust when the question says I can assume)
		switch (toupper(digits))
			{
			case 'A': case 'B': case 'C':
					printf("\a2");
					break;
			case 'D': case 'E': case 'F':
					printf("\a3");
					break;
			case 'G': case 'H': case 'I':
					printf("\a4");
					break;
			case 'J': case 'K': case 'L':
					printf("\a5");
					break;
			case 'M': case 'N': case 'O':
					printf("\a6");
					break;
			case 'P': case 'R': case 'S':
					printf("\a7");
					break;
			case 'T': case 'U': case 'V':
					printf("\a8");
					break;
			case 'W': case 'X': case 'Y':
					printf("\a9");
					break;
			default:
					putchar(digits);
			}
		}
//Oh and you can count the beeps to the number of letters changed

return 0;
}

