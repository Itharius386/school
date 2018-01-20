#include <stdio.h>

//	Name: Dolla Dolla Bills Y'all
//  Purpose: Shows smallest number of bills by denomination for a given cash value
//  Author: James Marcum


int main(void)

{
int money, num20, num10, num5, num1;

	printf("Enter a dollar amount: ");
	scanf("%d", &money);
	
	num20 = money / 20;
	num10 = (money - num20 * 20) / 10;
	num5 = (money - (num20 * 20 + num10 * 10)) / 5;
	num1 = (money - (num20 * 20 + num10 * 10 + num5 * 5));
	
	printf("$20 Bills: %d\n", num20);
	printf("$10 Bills: %d\n", num10);
	printf(" $5 Bills: %d\n", num5);
	printf(" $1 Bills: %d\n", num1);

return 0;
}

