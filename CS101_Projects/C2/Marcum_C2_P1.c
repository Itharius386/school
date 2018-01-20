#include <stdio.h>

int main(void)

{
	int radius;
	float area;

	printf("Enter a radius: ");
	scanf("%d",&radius);
	area = 3.14f * radius * radius;

	printf("The area of a circle with radius %d is %.2f",radius,area);
}

