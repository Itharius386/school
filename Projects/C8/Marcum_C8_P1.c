#include <stdio.h>
#include <stdbool.h>

//	Name: Repo-digit: The Digit Rock 0pera
//  Purpose: Show which digits are repeated if any
//  Author: James Marcum


int main(void)

{
//digit checker, this digit needs printed array, no repeated digit checker, i because i
int dig, p_num[10] = {0}, notevenone = 0, i = 0;
//let the number entered be super long (112233445566778899)
long long num;
//have we seen the digit before array
bool dig_seen[10] = {false};



//Let them know what we want and ask for a number
	printf("*---------------------------------------------*\nWe are going to check your number for repeating digits!\n*---------------------------------------------*\n");
	printf("Enter an integer to be checked: ");
	scanf("%lld", &num);



//loop through the number, digit by digit
	while (num > 0)
	{
		dig = num % 10;
//check if we have seen that digit before, if yes then note that we should print it later
		if (dig_seen[dig])
			++p_num[dig];
//but make sure we also note that we have now seen it	 
		dig_seen[dig] = true;
//on to the next digit
		num /= 10;
	}
	


//blank check
	for (i = 0; i < 10; i++)
	{
//adds 1 to notevenone for any repeated digit in the number
		notevenone += p_num[i];
	}


	
//and if it was still 0 after checking	  	  
	if (notevenone == 0)
//let them know that nothing was repeated
		printf("No digits were repeated\n");
	else 
	{
//loop through p_num and tell them what was repeated
		printf("Repeated digit (s): ");
		for (i = 0; i < 10; i++)
		{
			if (p_num[i] > 0)
				printf("\a%d ", i);
		}
	}


return 0;
}

