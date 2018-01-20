#include <stdio.h>


//	Name: schfifty-five v2.0
//  Purpose: Writes out a 2 digit number but with pointer-string arrays
//  Author: James Marcum


//MAIN BEGIN

int main(void)

{
//num, first and second digit
int num=1, dig1, dig2;
//ones array for 1-9
char *ones[] = {".", "one.","two.", "three", "four.", "five.", "six.", "seven.", "eight.", "nine."};
//tens for thefirst half of 20-99
char *tens[] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
//special array for 10-19
char *teens[] = {"ten.", "eleven.", "twelve.", "thirteen.","fourteen.", "fifteen.", 
				"sixteen.", "seventeen.", "eighteen.", "nineteen."};

	//why are we here
	printf("**********************************\n"
		   "Pick any number from 1 to 99!\n"
		   "We will print it out just for you!\n"
		   "**********************************\n\n");
	
	//get a 2 digit number from the user
	//repeat until it's a 2 digit number
	do{
		printf("Enter a two-digit number: ");
		scanf("%d", &num);
		} while (num < 1 || num > 99);

	//set digits
	dig1 = num % 10;
	dig2 = num / 10;
	
	//print first half of message
	printf("\nYour number is ");
	
	//check for digits 1-9
	if (dig2 == 0)
		printf("%s\n", ones[dig1]);
	//special 10-19 case
	else if (dig2 == 1)
		printf("%s\n", teens[dig1]);
	//cases 20-99
	else {
		printf("%s", tens[dig2-2]);
		//check to add the '-' since I added 1-9 coverage
		if (dig1 != 0)
			printf("-%s\n",ones[dig1]);
		else
			printf("%s\n",ones[dig1]);}

return 0;
}


//MAIN END


