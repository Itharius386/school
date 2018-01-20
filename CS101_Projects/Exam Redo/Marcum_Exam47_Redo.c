#include <stdio.h>
#define MAX 10

//	Name: add_subtract
//  Purpose: Run a function that finds the difference between the odd and even numbers entered
//			 (by order entered, not if the number was odd or even)
//  Author: James Marcum


//Function Prototypes

int add_subtract(int a[], int count);

//MAIN BEGIN

int main(void)

{
int nums[MAX], i;

	printf("Enter %d numbers seperated by spaces: ",MAX);
	for (i=0;i<MAX;i++){
		scanf("%d",&nums[i]);
		}
	printf("The difference of the sums of odds and evens is %d", add_subtract(nums,i));

return 0;
}


//MAIN END

//Functions Below

int add_subtract(int a[], int count)
{
int num1 = 0, num2 = 0, i = 0;

	for (i=0;i<count;i++)
		{
		if (i==0 || i%2==0)
			num1 += a[i];
		else
			num2 += a[i];
		}

	return num1-num2;
}

