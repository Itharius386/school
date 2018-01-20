#include <stdio.h>

//	Name: schfifty-five
//  Purpose: Writes out a two digit number
//  Author: James Marcum


int main(void)

{
//define number, digits 1-2
int num, dig1, dig2;

//Ask for a 2 digit number
	printf("Enter a two digit number: ");
	scanf("%d",&num);

//print half the message
	printf("You entered the number ");

//determine if the number is special
	if (num < 20)
		{
		switch (num)
			{
			case 10: printf("Ten."); break;
			case 11: printf("Eleven."); break;
			case 12: printf("Twelve."); break;
			case 13: printf("Thirteen."); break;
			case 14: printf("Fourteen."); break;
			case 15: printf("Fifteen."); break;
			case 16: printf("Sixteen."); break;
			case 17: printf("Seventeen."); break;
			case 18: printf("Eighteen."); break;
			case 19: printf("Nineteen."); break;
			}
		}
//if not special, seperate into digits and print them out
	else
		{
		dig1 = num/10;
		dig2 = num%10;
		
		switch (dig1)
			{
			case 2: printf("Twenty"); break;
			case 3: printf("Thirty"); break;
			case 4: printf("Fourty"); break;
			case 5: printf("Fifty"); break;
			case 6: printf("Sixty"); break;
			case 7: printf("Seventy"); break;
			case 8: printf("Eighty"); break;
			case 9: printf("Ninety"); break;
			}
		switch (dig2)
			{
			case 0: printf("."); break;
			case 1: printf("-one."); break;
			case 2: printf("-two."); break;
			case 3: printf("-three."); break;
			case 4: printf("-four."); break;
			case 5: printf("-five."); break;
			case 6: printf("-six."); break;
			case 7: printf("-seven."); break;
			case 8: printf("-eight."); break;
			case 9: printf("-nine."); break;
			}
		}
	if (num == 55)
		printf("\n\n\n\nThat's schfifty-five.\n\n\n\n");

//schfifty-five
return 0;
}

