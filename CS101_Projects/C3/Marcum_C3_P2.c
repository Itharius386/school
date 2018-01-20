#include <stdio.h>

//	Name: Production List
//  Purpose: Enter item information and have the product listed by item, price, and date
//  Author: James Marcum


int main(void)

{
//define variables for the item, date, and price
int item_num, month, day, year;
float price;

//ask for item number
	printf("Enter item number: ");
	scanf("%d", &item_num);
//ask for price	   
	printf("Enter unit price: ");
	scanf("%f", &price);
//ask for purchase date	   
	printf("Enter purchase date (mm/dd/yyyy): ");
	scanf("%d/%d/%d", &month, &day, &year);

//print the table and collected item data
	printf("Item\t\tUnit\t\tPurchase\n\t\tPrice\t\tDate\n%d\t\t$%7.2f\t%.2d/%.2d/%.4d\n",item_num,price,month,day,year);

return 0;

}

