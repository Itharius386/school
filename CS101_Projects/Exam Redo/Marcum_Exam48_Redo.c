#include <stdio.h>
#include <ctype.h>

//	Name: vowel counting
//  Purpose: Finds the number of vowels in a sentence
//  Author: James Marcum


//Function Prototypes



//MAIN BEGIN

int main(void)

{
int vowels[5]={0}, total = 0, i;
char input;

	printf("We will count the vowels in a sentence.\n\n");
	printf("Enter a sentence: ");
	
	while ((input = getchar()) != '\n'){
		if (isalpha(input))
			switch (toupper(input)){
				case 'A': vowels[0]++; break;
				case 'E': vowels[1]++; break;
				case 'I': vowels[2]++; break;
				case 'O': vowels[3]++; break;
				case 'U': vowels[4]++; break;
				}
		}
	printf("\nYou entered %d 'A's",vowels[0]);
	printf("\nYou entered %d 'E's",vowels[1]);
	printf("\nYou entered %d 'I's",vowels[2]);
	printf("\nYou entered %d 'O's",vowels[3]);
	printf("\nYou entered %d 'U's",vowels[4]);

	for (i=0;i<5;i++){
		total += vowels[i];
		}
	
	printf("\n\nTotal number of vowels enters was %d",total);

return 0;
}


//MAIN END

//Functions Below


