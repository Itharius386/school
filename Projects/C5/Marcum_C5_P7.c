#include <stdio.h>

//	Name: Little b, big B
//  Purpose: determines the largest and smallest intergers in a set of 4
//  Author: James Marcum


int main(void)

{
//define integers 1-4, largest number, smallest number
int num1,num2,num3,num4, min12, min34, max12, max34, min, max;

//ask for a set of 4 integers
	printf("Enter four integers (seperate with spaces): ");
	scanf("%d %d %d %d",&num1,&num2,&num3,&num4);

//determine min and max groups
	//1
	if (num1 < num2)
		{
		min12 = num1;
		max12 = num2;
		}
	else
		{
		min12 = num2;
		max12 = num1;
		}
	//2
	if (num3 < num4)
		{
		min34 = num3;
		max34 = num4;
		}
	else
		{
		min34 = num4;
		max34 = num3;
		}

//determine min and max from the groups
	//3
	if (min12 < min34)
		min = min12;
	else
		min = min34;
	
	//4
	if (max12 > max34)
		max = max12;
	else
		max = max34;

//print the max and min
	printf("largest number is... %d\n",max);
	printf("Smallest Number is... %d", min);

//fin in four
return 0;

}

