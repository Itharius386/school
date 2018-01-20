#include <stdio.h>


//	Name: swap_em
//  Purpose: show a function that swaps some numbers
//  Author: James Marcum


//Function Prototypes

void swap_em(int *first_num, int *second_num);

//MAIN BEGIN

int main(void)

{
int num1, num2;

	printf("We are going to swap some numbers around!\n");
	printf("Enter the first number: ");
	scanf("%d",&num1);
	printf("Enter the second number: ");
	scanf("%d",&num2);
	
	swap_em(&num1,&num2);
	
	printf("We swapped 'em: %d %d", num1, num2);

return 0;
}


//MAIN END

//Functions Below

void swap_em(int *first_num, int *second_num)
{
int j;
	j=*second_num;
	*second_num = *first_num;
	*first_num=j;
}

