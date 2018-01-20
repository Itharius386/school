#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

//	Name: Functional anagrams
//  Purpose: anagram checking but with functions
//  Author: James Marcum

//  some bits copy-pasted from my C8-P16

/* * * * * * * * * * * *
 * Function prototypes *
 * * * * * * * * * * * */

void read_word(int counts[26]);
bool equal_array(int counts1[26], int counts2[26]);


//MAIN HERE

int main(void)

{
//some arrays
int counts1[26] = {0}, counts2[26] = {0};

//What are we doing here!?
printf("Anagram checker!\n\n");

//call read word twice
	read_word(counts1);
	read_word(counts2);

//check for anagram-ization
	if (equal_array(counts1, counts2))
		printf("\a\nThese words are truly anagrams!\n");
	else
		printf("\a\nThese are not anagrams...\n");
		

return 0;
}

//MAIN END

//Funtions below:

/* * * * * * * * * * * * * * * * * * * * * * * * * * * **
 *														*
 *	read_word:	Reads a word into an array to count		*
 *				the total instances of each letter		*
 *														*
 * * * * * * * * * * * * * * * * * * * * * * * * * * * **/


void read_word(int counts[26])
{
//input the output to output the input
char input;

//prompt user
	printf("Enter a word: ");

//check that word!
	while((input = getchar()) !='\n')
	{
//is it alpha? Cause it better be.
		if (isalpha(input))
//better make sure it's an upper and then increment the array
			counts[toupper(input) - 65]++;
	}
} 

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *																 *
 *	equal_array:	Checks if the arrays have the same values	 *
 *																 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

bool equal_array(int counts1[26], int counts2[26])
{
//always need an 'i'
int i;
//bool check
bool equals = true;

//loop compare
for (i=0 ; i<26; i++)
	{
	if (counts1[i] != counts2[i])
		{
		equals = false;
		break;
		}
	}

//were they the same?!
return equals;
} 

