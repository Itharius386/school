#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

//	Name: 'Ars Magna' - 1545 published work known as 'The Rules of Algebra' (and an anagram of 'Anagrams')
//  Purpose: Test if 2 words are anagrams
//  Author: James Marcum


int main(void)

{
//word array, i because i
int word[26] = {0}, i = 0;
//letters am i rite?
char input;
//is it an anagram?
bool ana = true;


//What are we doing here!?
printf("Anagram checker!\n\n");
//Ask for the word!
printf("Enter the first word: ");

//check that word!
	while((input = getchar()) !='\n')
	{
//is it alpha? Cause it better be.
		if (isalpha(input))
/*better make sure it's an upper and then increment the array
Also uppercase alpha characters are between 65-90 in ASCII as integers (Facts!)*/
			word[toupper(input) - 65]++;
	}

//get another word
printf("Enter the second word: ");
	while((input = getchar()) !='\n')
	{
		if (isalpha(input))
//repeat, but subtract!
			word[toupper(input) - 65]--;
	}

//loop it one more time!
	for (i=0; i<26; i++)
		{
//if it ain't 0 it ain't an anagram!
		if (word[i] != 0){
			ana = false;
			break;}
		}

//So what is it?!?!
if (ana == true)
printf("\a\nThese words are truly anagrams!\n");
else
printf("\a\nThese are not anagrams...\n");


return 0;
}

