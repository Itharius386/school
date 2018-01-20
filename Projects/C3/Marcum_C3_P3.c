#include <stdio.h>

//	Name: IS BEN HERE TODAY 
//  Purpose: Takes an ISBN and seperates it into groups
//  Author: James Marcum


int main(void)

{
//define variables for each group of the ISBN
int prefix, group_id, pub_code, item_num, check_dig;


//Ask user for ISBN
	printf("Enter ISBN (###-#-###-#####-#): ");
	scanf("%d-%d-%d-%d-%d", &prefix, &group_id, &pub_code, &item_num, &check_dig);

//Print the number groups
	printf("GS1 prefix: %d\n", prefix);	   
	printf("Group identifier: %d\n", group_id);
	printf("Publisher code: %d\n", pub_code);
	printf("Item number: %d\n", item_num);
	printf("Check digit: %d\n", check_dig);
	
return 0;

}

