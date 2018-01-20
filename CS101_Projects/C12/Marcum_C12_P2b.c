#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

//arbitrary max: 80-17
#define MAX 63

//	Name: Evil did I dwell, lewd I did live.
//  Purpose: Checks a message if it's a palindrome or not - Pointer Version
//  Author: James Marcum



//Function Prototypes
//these first one seems a little familiar, hmm...
int read_mess(char mess[], int num);
//bool palindrome_check_int(char mess[], int num);- Not included in this version
bool palindrome_check_point(char mess[], int num);


//MAIN BEGIN

int main(void)

{
//that good ol' message array all setup
char message[MAX];
//and it's length
int message_len = read_mess(message, MAX);

	//call palindrome_check_int and display result - NOT INCLUDED IN THIS VERSION
	/*
	if (palindrome_check_int(message,message_len))
		printf("\nIt's really a palindrome!\n");
	else
		printf("\nThat was NOT a palindrome!\n");
	*/

	//call palindrome_check_point and display result
	if (palindrome_check_point(message,message_len))
		printf("\nIt's really a palindrome!\n");
	else
		printf("\nThat was NOT a palindrome!\n");
		

return 0;
}


//MAIN END

//Functions Below


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *																   *
 *	read_mess	indexes a message into an array					   *
 *				returns the length of the message as an int		   *
 *   															   *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

//changed from C12_P1 to add the alpha check
int read_mess(char mess[], int num)
{
//need an i set to 0 and an input
int i=0;
char input;


	//Why are we here!	
	printf("**********************************************\n"
		   "*                                            *\n"
		   "*          Welcome to our gameshow!          *\n"
		   "*           Tonight we are playing           *\n"
		   "*            'Is It a Palindrome!'           *\n"
		   "*                                            *\n"
		   "**********************************************\n");
	//prompting
	printf("\n\nEnter a message: ");
	//as long as the input is not a new line, or longer than the max then
	//if it is anything between A-Z add it to the array (in caps) and increase i
	while ((input = getchar()) != '\n' && i < num)
		if (isalpha(input))
			{
			mess[i] = toupper(input);
			i++;
			}	 

//return length	   
return i;
}


//SPOILERS - THIS IS FOR THE ~OTHER~ PROJECT
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *																   *
 *	palindrome_check_int	  checks if you entered a palindrome   *
 *							  while using an array subscript       *
 * 	  	  	  	  	  	  	  	  	  	  	  	  	  	  	       *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
 
/*
bool palindrome_check_int(char mess[], int num)
{
//need an i, a start, and an end (which isn't null)
int i, begin = 0, end = num-1;

	//as long as the begining is less than the end
	//check if the letter at begin in the array is not the same as the one at the end
	//if not, stop and return false
	//else increase begin and decrease end by 1 and check again (technically increase/decrease before the return but close enough)
	while (begin < end)
	{
		if (mess[begin++] != mess[end--])
			return false;
	}

return true;
}
*/


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *																   *
 *	palindrome_check_point    checks if you entered a palindrome   *
 *							  while using a pointer		           *
 * 	  	  	  	  	  	  	  	  	  	  	  	  	  	  	       *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
 

bool palindrome_check_point(char mess[], int num)
{
//a begining and an ending pointer
//begin set to the location of the message array start
//end set to the location of the array end before the null
char *begin_point = mess, *end_point = mess + num - 1;
	
	//as long as begin_point is less than the end_point
	//check if they are not pointing to the same thing at different locations
	//if not, stop and return false
	//else increase begin_point and decrease end_point by 1 and check again
	while (begin_point < end_point)
		{
		if (*begin_point++ != *end_point--)
			return false;	 
		}
	
return true;
}


