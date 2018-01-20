#include <stdio.h>

//	Name: Magic Four Square Thingy
//  Purpose: Takes numbers 1 through 16, place them in a grid, and determine the sums of rows, columns, and diagonals
//  Author: James Marcum


int main(void)

{

//define variables row sums, column sum, diagonal sums, and the numbers 1-16
int row_sum1, row_sum2, row_sum3, row_sum4, col_sum1, col_sum2, col_sum3, col_sum4, diag_sum1, diag_sum2, num1, num2, num3, num4, num5, num6, num7, num8, num9, num10, num11, num12, num13, num14, num15, num16;

//have user determine the order of numbers 1-16
	printf("Enter the numbers 1 through 16 in any order seperated by spaces:\n");
	scanf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",&num1 ,&num2 ,&num3 ,&num4 ,&num5 ,&num6 ,&num7 ,&num8 ,&num9 ,&num10 ,&num11 ,&num12 ,&num13 ,&num14 ,&num15 ,&num16);
	
//solve row sums: nums 1-4, 5-8, 9-12, 13-16
	row_sum1 = num1 + num2 + num3 + num4;
	row_sum2 = num5 + num6 + num7 + num8;
	row_sum3 = num9 + num10 + num11 + num12;
	row_sum4 = num13 + num14 + num15 + num16;

//solve column sums: nums 1,5,9,13 | 2,6,10,14 | 3,7,11,15 | 4,8,12,16
	col_sum1 = num1 + num5 + num9 + num13;
	col_sum2 = num2 + num6 + num10 + num14;
	col_sum3 = num3 + num7 + num11 + num15;
	col_sum4 = num4 + num8 + num12 + num16;

//solve diagonal sums: num 1,6,11,16 | 4,7,10,13
	diag_sum1 = num1 + num6 + num11 + num16;
	diag_sum2 = num4 + num7 + num10 + num13;
	
//print the 4 by 4 grid of numbers
	printf("\nThe numbers arranged in a grid:\n\t%2d %2d %2d %2d\n\t%2d %2d %2d %2d\n\t%2d %2d %2d %2d\n\t%2d %2d %2d %2d\n", num1, num2, num3, num4, num5, num6, num7, num8, num9, num10, num11, num12, num13, num14, num15, num16);

//print the sums
	printf("Row sums:\t %d %d %d %d\n", row_sum1, row_sum2, row_sum3, row_sum4);
	printf("Column sums:\t %d %d %d %d\n", col_sum1, col_sum2, col_sum3, col_sum4);
	printf("Diagonal sums:\t %d %d\n", diag_sum1, diag_sum2);

return 0;

}

