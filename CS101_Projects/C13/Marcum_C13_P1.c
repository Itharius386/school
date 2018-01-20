#include <stdio.h>
#include <ctype.h>
#include <string.h>

//max word length
#define MAX 20
//word length that stops program
#define STOP 4

//	Name: Ardvarks before Pangolins
//  Purpose: Determines which word comes first by dictionary order
//  Author: James Marcum


//Function Prototypes

int get_word(char word[]);
int compare(char word[],char word_s[],char word_s2[]);

//MAIN BEGIN

int main(void)

{
//word for length check, smallest and 2nd smallest words
/*	2nd smallest is intialized because having the first word be
  	both the first and second shortest word can cause issues */
char word[MAX+1], smallest_1st[MAX+1], smallest_2nd[MAX+1] = "zzzzz";


	//What's going on
	printf("*********************************************\n"
		   "*                                           *\n"
		   "*    Today we will find which word comes    *\n"
		   "*         earlier in the dictionary         *\n"
		   "*                                           *\n"
		   "*       Enter a 4 letter word to stop!      *\n"
		   "*                                           *\n"
		   "*            All lower case please          *\n"
		   "*                                           *\n"
		   "*********************************************\n");
	
	//get a starter word
	get_word(word);
	//copy it to smallest word
	strcpy(smallest_1st, word);
	//make sure it wasn't an accident
	if (strlen(word) == STOP)
		printf("\nYou just started\nAre you sure you want to stop?\nEnter it again to quit\n\n");
	
	//start the compare loop
	//just a 'while' made it auto quit with the initial word being 4 letters, do loop fixed it
	do
	{
		compare(word,smallest_1st,smallest_2nd);
	} while (strlen(word) != STOP);
	
	//result print	  
	printf("\nThe word that would come first is: %s",smallest_1st);
	printf("\nFollowed by: %s",smallest_2nd);

return 0;
}


//MAIN END

//Functions Below

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *																 *
 *	read_word	prompts the user and copies a word they input	 *
 *				returns the length of the string				 *
 *																 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

int get_word(char word[])
{

	//basic, easy, prompts and gets a string
	printf("Enter word: ");
	scanf("%20s", word);

//return length
return strlen(word);		
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *																 *
 *	compare		Calls read_word, compares string order with		 *
 *				prior smallest and 2nd smallest words   		 *
 *																 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

int compare(char word[],char word_s[],char word_s2[])
{

	//gets the word
	get_word(word);
	
	//stated that it should not include the 4 letter word, added the strlen check to make sure it would not include them
	if (strcmp(word, word_s) < 0 && strlen(word) != STOP){
		//copies the current shortest to second shortest
		strcpy(word_s2, word_s);
		//copies the current word to shortest
		strcpy(word_s, word);}
	else if (strcmp(word, word_s2) < 0 && strlen(word) != STOP)
		//copies to second shortest if it isn't shorter than the first but it shorter than the second
		strcpy(word_s2, word);

//return length
return strlen(word);
}

