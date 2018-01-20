#include <stdio.h>

//	Name: knot in my neighborhood
//  Purpose: Describe the situation based on a given wind speed
//  Author: James Marcum


int main(void)

{
//define knot
float knot;

//ask for wind speed in knots
	printf("Enter the wind speed in knots: ");
	scanf("%f",&knot);
	
//determine description and print
if (knot < 1)
	printf("The Calmest day you'll ever have\n");
else if (knot < 4)
	printf("Light Airy day, have fun!\n");
else if (knot < 28)
	printf("Got a Breeze going on. Go fly a kite!\n");
else if (knot < 48)
	printf("Gale force winds, be careful out there kids!\n");
else if (knot <= 63)
	printf("A Storm is afoot, watch out!\n");
else 
	printf("Hurricane force winds. Batten down the hatches!\n");

return 0;

}

