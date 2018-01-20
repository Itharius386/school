#include <stdio.h>

//arbitrary max: 80-17
#define MAX 63

//	Name:noisreV retnioP - esreveR ni daeR t'naC T
//  Purpose: Reverses a sentence - Pointer Version
//  Author: James Marcum


//Function Prototypes

int read_mess(char mess[], int num);
void print_mess(char mess[], int num);
//void print_mess_reverse_int(char mess[],int num); - Not included in this version
void print_mess_reverse_point(char mess[],char *final_char);

//MAIN BEGIN

int main(void)

{
//start up message
char message[MAX] = {0};
//length check and set it to the value returned from read_mess
int message_len = read_mess(message, MAX); //call read_mess to get the message


	//call print_mess
	print_mess(message, message_len);
	//call print_mess_reverse_int - NOT INCLUDED
	//print_mess_reverse_int(message, message_len);
	//call print_mess_reverse_point
	print_mess_reverse_point(message, &message[message_len]);	 
		 
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
 
int read_mess(char mess[], int num)
{
//need an i and an input
int i;
char input;


	//Why are we here!
	printf("*****************************************************\n"
		   "*                                                   *\n"
		   "*   We are going to reverse your message today!     *\n"
		   "*    For the low price of 'running this program'    *\n"
		   "*     You too, can reverse a message today!         *\n"
		   "*                                                   *\n"
		   "*****************************************************");
	//prompting
	printf("\n\nEnter a message: ");
	//loop and place in array, just any garbage until you hit max or hit enter
	//cuts you off at the max
	for (i = 0;(input = getchar()) != '\n' && i < num; i++)
		mess[i] = input;	

//return length	   
return i;
}


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *																   *
 *	print_mess		prints a message from an array	  	  	       *
 *   															   *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
 
void print_mess(char mess[], int num)
{
//
char *c_point;

	//verify input was correct
	printf("\nYour message: ");
	//save location in memory of message array at mess[0]
	//check that it is less than memory location of message's total length
	//print what is in that memory location - loop
	//increment memory location by 1
	for (c_point = mess; c_point < mess + num; c_point++)
		printf("%c", *c_point);
	//line break
	printf("\n");

}

//SPOILERS - THIS IS FOR THE ~OTHER~ PROJECT
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *																   *
 *	print_mess_reverse_int	  prints a message from an array       *
 * 							  but in reverse					   *
 *							  and using an array subscript         *
 * 	  	  	  	  	  	  	  	  	  	  	  	  	  	  	       *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
 

/*void print_mess_reverse_int(char mess[],int num)
{
//why always an i
int i;

	//line that up with the printed one!
	printf("In reverse:   ");
	//start with the last character (not the null!)
	//check you aren't going beyond the start
	//print it
	//go backwards by 1
	for (i = num - 1; i >= 0; i--)
		printf("%c",mess[i]);
	//line break
	printf("\n");

}
*/

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *																   *
 *	print_mess_reverse_point  prints a message from an array       *
 * 							  but in reverse					   *
 *							  and using a pointer		           *
 * 	  	  	  	  	  	  	  	  	  	  	  	  	  	  	       *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
 
 
void print_mess_reverse_point(char mess[],char *final_char)
{
//Set point to the memory of the last character that wasn't null
char *c_point = final_char - 1;
	
	//lined up
	printf("In reverse:   ");
	//already set the point to the last letter
	//as long as it isn't going past the beginning
	//print the letter in the location
	//decrease the location by 1
	while(c_point >= &mess[0])
		printf("%c", *c_point--);
	printf("\n");
	
}


