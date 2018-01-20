#include <stdio.h>
#include <ctype.h>

//	Name: Ay! Dey said I owe you.
//  Purpose: Count the vowels in a sentence
//  Author: James Marcum


int main(void)

{
//Counter as an integer set to 0 and input as a character
int counter = 0;
char input;

//Tell them we are counting vowels and let them know they need to enter a sentence to be counted
	printf("*******************************\nWe are gonna count some vowels!\n*******************************\n\n");
	printf("Enter a (good) sentence: ");

//Count the vowels
	while((input = getchar()) !='\n')
	{
		switch(toupper(input))
		{
		case 'A':case 'E':case 'I':case 'O':case 'U':
			counter++;
			break;
		}
	}

//judge them for their arrogance	
	if (counter < 5)
		printf("\nDo you know what a sentence is?\nWhatever you typed only had %d vowels", counter);
	else if (counter < 10)
		printf("\nThat's a sentence alright.\nA whole %d vowels.", counter);
	else
		printf("\nNice!\nYour sentence had %d vowels!\nGood job!", counter);

return 0;
}

