#include <stdio.h>

//	Name: Your uncle Sam called, he said you owed him some money
//  Purpose: determine taxes due based on income tax bracket
//  Author: James Marcum


int main(void)

{
//define taxable income
float income;

//Ask for taxable income
	printf("Enter your taxable income: ");
	scanf("%f",&income);
	
//determine bracket and tax amount then print
if (income < 750)
	printf("You owe Uncle Sam $%.2f",(income)*0.01f);
else if (income < 2250)
	printf("You owe Uncle Sam $%.2f",(income - 750)*0.02f + 7.50f);
else if (income < 3750)
	printf("You owe Uncle Sam $%.2f",(income - 2250)*0.03f + 37.50f);
else if (income < 5250)
	printf("You owe Uncle Sam $%.2f",(income - 3750)*0.04f + 82.50f);
else if (income < 7000)
	printf("You owe Uncle Sam $%.2f",(income - 5250)*0.05f + 142.50f);
else
	printf("You owe Uncle Sam $%.2f",(income - 7000)*0.06f + 230.00f);

return 0;

}

