#include <stdio.h>
#define PI 3.14159f


//	Name: Spherical
//  Purpose: Finds the volume of a sphere of a given radius
//  By: James Marcum


int main(void)

{
	int radius;
	float volume;

	printf("Please enter a radius: ");
	scanf("%d", &radius);

	volume = (4.0f / 3.0f) * PI * radius * radius * radius;
	
	printf("The volume of a sphere with radius %d is %.1f", radius, volume);
	
	return 0;
}

