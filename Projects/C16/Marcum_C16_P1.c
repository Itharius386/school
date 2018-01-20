#include <stdio.h>
#include <stdbool.h>

#define MAX_L 20 //Max length for names
#define MAX_S 20 //Max student count

//	Name: Gradebot v.ZZ
//  Purpose: receive student data, then calculate and present final grades for students
//  Author: James Marcum


//Function Prototypes

bool end(char check[]);
void print_student(int num);

//Structures

struct student{
	char f_name[MAX_L];
	char l_name[MAX_L];
	int id_num;
	float test1;
	float test2;
	float test3;
} students[MAX_S];

//MAIN BEGIN

int main(void)

{

int i=0, count = 0;

	//why are we here?
	printf("Please enter up to %d students: Name, ID, and 3 Test Grades\n"
			"We will then calculate their final grade for you\n\n", MAX_S);

	//loop to get info
	do	{
		//get name
		printf("Please enter a student name (ZZ to quit): ");
		scanf("%s", &students[i].f_name);
		//check for ZZ
		if (end(students[i].f_name))
			//exit loop
			break;
		
		//get last name if ZZ wasn't entered
		scanf(" %s", &students[i].l_name);
	
		//get id
		printf("Please enter student's ID number: ");
		scanf("%d", &students[i].id_num);
	
		//get test scores
		printf("Please enter student's three test scores: ");
		scanf("%f %f %f", &students[i].test1, &students[i].test2, &students[i].test3);
	
		//increase i
		i++;
		count++;
		
		printf("\n\n");
		}while(i < MAX_S);

	//print some info
	if (count != 0)
		printf("\n\n\nSTUDENT\t\t\t\tFINAL GRADE\n\n");
	
	//loop print students and grades
	for (i=0; i < count; i++)
		print_student(i);	 	 
		

return 0;
}


//MAIN END

//Functions Below

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *														 *
 *	end:	checks for 'ZZ' entered to end the loop		 *
 *			and student entry							 *
 *														 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

bool end(char check[])
{
int i;
char quit[] = "ZZ";

for (i=0; i < 3; i++){
	if (check[i] != quit[i])
		return 0;}
	
return 1;
}


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *														 *	 
 *	print_student:	prints the student's name and grade  *
 *														 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void print_student(int num)
{
int grade = 0;

	//print name: last, first
	printf("%s, ",students[num].l_name);
	printf("%s",students[num].f_name);
	
	//TAB
	printf("\t\t\t\t");
	
	//get grade
	grade  = (students[num].test1 + students[num].test2 + students[num].test3)/3;
	grade /= 10;
	
	//print grade
	switch(grade)
		{
		case 0:case 1:case 2:case 3:case 4:case 5: printf("F"); break; //0-59
		case 6: printf("D"); break; //60-69
		case 7: printf("C"); break; //70-79
		case 8: printf("B"); break; //80-89
		default: printf("A"); break; //90+
		}
		
	printf("\n");
}

