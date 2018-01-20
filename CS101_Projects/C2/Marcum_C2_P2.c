#include <stdio.h>

int main(void)

{
	int x, answer;

	printf("Enter an integer for x: ");
	scanf("%d",&x);
	answer = (3 * x * x * x * x) - (2 * x * x * x) + (6 * x * x) - x - 25;

	printf("Solving 3x^4-2x^3+6x^2-x-25 = %d", answer);
	
	return 0;
}

