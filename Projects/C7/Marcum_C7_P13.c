#include <stdio.h>

//	Name: Hemmingway doesn't use ten-dollar words
//  Purpose: Get average word length from a given sentence, includes punctuation as characters
//  Author: James Marcum


int main(void)

{
//character input, character count, word count
//word count = 1 because the last word won't be counted without a space and prevents Div0
char input;
int characters = 0, words = 1;

//Ask for a sentence
	printf("\nEnter a sentence: ");

//Get the sentence
	while ((input = getchar()) != '\n')
	{

		switch (input)
		{
//Words are seperated by spaces
//spamming spaces will mess up the program
			case ' ':
				words++;
				break;
			default:
//characters are everything else
				characters++;
				break;
		}
	
	}

//Tell them their total non-space characters
	printf("Total Characters: \t%d\n", characters);
//Total words
	printf("Total Words: \t\t%d\n", words);
//Get average word length from characters/words
	printf("Average word length: \t%.1f\n\n", (float) characters / words);

	
return 0;
}

