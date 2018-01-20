#include <stdio.h>

//	Name: Octalots are like ocelots
//  Purpose: Takes an integer and displays it as an octal
//  Author: James Marcum


int main(void)

{

// Number, original number saved, Digits 1-5
int num, num_o, dig1, dig2, dig3, dig4, dig5;

//Ask user for a number between 0 and 32767
	printf("Please enter a number between 0 and 32767: ");
	scanf("%d", &num);

//Save the number in num_o to confirm it converted to octal correctly	 
	num_o = num;
	
//calculate number in base 8
	dig1 = num % 8;
	num /= 8;
	dig2 = num % 8;
	num /= 8;
	dig3 = num % 8;
	num /= 8;
	dig4 = num % 8;
	num /= 8;
	dig5 = num % 8;
	num /= 8;
	               
	
//print the number as an octal
	printf("Your number as an octal is: %d%d%d%d%d\n\n", dig5, dig4, dig3, dig2, dig1);
	
//print directly as an octal
	printf("Here it is again, just so you don't forget: %.5o",num_o);


return 0;

}

/* Okay, so I realized my problem with this one was that I wanted to use a loop for the program because 
I couldn't figure out how to check the length of the octal without conditionals or looping 
but figured that wasn't what I was supposed to do. Then I realized that 32767 was just 77777 in octal and it was irrelevent*/

