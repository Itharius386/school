#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>

#define D_SIDE 6


//	Name: SPARC
//  Purpose: Play the dice game of champions!
//  Author: James Marcum


//Function Prototypes

void instruct();
bool roll(int *win1,int *win2,int *lose1,int *lose2,int *sparc);
void ddd(int dice1,int dice2);
void highscore(int win,int lose);


//MAIN BEGIN

int main(void)

{
//sparc, winning numbers, losing numbers, counters
int sparc, winner1 = 6, winner2 = 9, loser1 = 3, loser2 = 12, w_count = 0, l_count = 0;
//command check
char cmd;

	//seed the rand generator
	srand((unsigned) time(NULL));

	//main game loop
	do {
		//clears the screen each game, terrible system call
		system("cls||clear");
		
		//instructions
		instruct();
		
		//Tell round if round 2+ otherwise wish them luck!
		if (w_count + l_count == 0)
			printf("\n\n%c%c%cGood Luck!%c%c%c\n\n",177,177,176,176,177,178);
		else
			printf("\n\n    Round %d\n%c%c%cGood Luck!%c%c%c\n\n", w_count+l_count+1,176,177,178,178,177,176);
		
		//reset values, will calculate by # of sides to account for other die
		sparc = 0;
		winner1 = D_SIDE;
		winner2 = D_SIDE*1.5;
		loser1 = D_SIDE/2;
		loser2 = D_SIDE*2;
		
		//wait for first roll
		getchar();
		
		//roll it
		if (roll(&winner1,&winner2,&loser1,&loser2,&sparc)){
			//win
			printf("\nYou won!\n");
			w_count +=1;}
		else{
			//lose
			printf("\nYou lost!\n");
			l_count +=1;}
		
		//at win|lose ask to play again
		do{
			printf("\nDo you want to play again? (Y/N): ");
			cmd = getchar();
			getchar();
			} while (!(tolower(cmd) == 'y' || tolower(cmd) == 'n')); //this single line took hours to figure out and it's still not perfect I think
			
		} while (tolower(cmd) == 'y');

	//how did they do?
	highscore(w_count,l_count);
	
return 0;
}


//MAIN END

//Functions Below

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *																 *
 *	Instruct:	Tells the user how the game works				 *
 *																 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


void instruct()
{
	//how to play
	printf("#--------------------------------------------------------------------#\n"
		   "|                                                                    |\n"
		   "|                         Welcome to SPARC!                          |\n"
		   "|                    The dice game of champions!                     |\n"
		   "|                                                                    |\n"
		   "|                            Roll two dice                           |\n"
		   "|             On your first roll you win if you roll a 6 or 9        |\n"
		   "|                    But if it's a 3 or 12, you lose!                |\n"
		   "|                                                                    |\n"
		   "|                Any other number will be your Sparc                 |\n"
		   "|  Now you lose on a 6 or 9, but win if you roll your Sparc again!   |\n"
		   "|                      Press ENTER twice to start!                   |\n"
		   "|                                                                    |\n"
		   "#--------------------------------------------------------------------#\n");
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *																 *
 *	Roll:	Main function of the game. 'rolls' 2 dice   		 *
 *			checks the values versus win|loss values and if		 *
 *			needed calls itself again.							 *
 *			Returns 1 on win, 0 on loss							 *
 *																 * 
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

bool roll(int *win1,int *win2,int *lose1,int *lose2,int *sparc)
{
//die 1 and 2, set to a random number based on number of sides
int die1= rand() % D_SIDE + 1, die2= rand() % D_SIDE + 1;
	
	//wait until the player rolls the dice
	getchar();
	
	//double check that we are using 6 sided dice before trying to display them
	if (D_SIDE == 6)
		ddd(die1, die2);
	else
		//else just tell them
		printf("You rolled %d and %d for a total of %d\n",die1, die2, die1+die2);
	
	//how did they do?
	if (die1+die2 == *win1 || die1+die2 == *win2)
		//returns a win
		return 1;
	else if (die1+die2 == *lose1 || die1+die2 == *lose2)
		//returns a loss
		return 0;
	else {
		//makes sure we haven't sparc'd yet
		if (*sparc == 0)
			{
			//make sure we don't do this on the next loop
			*sparc = 1;
			//what happened
			printf("\nYou got a Sparc!\n\nYour Sparc is %d\n\nPress enter to roll again!\n",die1+die2);
			//6's and 9's are now losses
			*lose1 = *win1;
			*lose2 = *win2;
			//wins are now the sparc value
			*win1 = die1+die2;
			*win2 = *win1;
			}
		//keeps going deeper until a win or loss is found and returns that value
		return roll(win1,win2,lose1,lose2,sparc);
		}
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *																 *
 *	ddd:	The Digital Dice Display - gives a visual			 *
 *			of the dice rolled by the player					 *
 *																 * 
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */ 
 
//digital dice display
void ddd(int dice1,int dice2)
{
//i, display array (cleaner than)
int i=0, display[] = {dice1, dice2};

//will require access to extended ASCII codes, should work fine on windows

//top of dice
printf("     %c%c%c%c%c%c%c     %c%c%c%c%c%c%c\n",201,205,205,205,205,205,187,201,205,205,205,205,205,187);
//first layer of dice
//loop for both dice
for (i=0; i<2; i++){
	//switch based on dice value
	switch(display[i]){
	case(6): case(5): case(4): printf("     %c%c   %c%c",186,4,4,186);break;
	case(3): case(2): printf("     %c    %c%c",186,4,186);break;
	case(1): printf("     %c     %c",186,186);break;
	}}
printf("\n");
//next layer
for (i=0; i<2; i++){
	switch(display[i]){
	case(6):printf("     %c%c   %c%c",186,4,4,186);break;
	case(5): case(3): case(1): printf("     %c  %c  %c",186,4,186);break;
	case(4): case(2): printf("     %c     %c",186,186);break;
	}}
printf("\n");
//bottom layer
for (i=0; i<2; i++){
	switch(display[i]){
	case(6): case(5): case(4): printf("     %c%c   %c%c",186,4,4,186);break;
	case(3): case(2): printf("     %c%c    %c",186,4,186);break;
	case(1): printf("     %c     %c",186,186);break;
	}}
//cap them off	  
printf("\n     %c%c%c%c%c%c%c     %c%c%c%c%c%c%c\n",200,205,205,205,205,205,188,200,205,205,205,205,205,188);

}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *	   	   	   	   	   	   	   	   	   	   	   	   	   	   	     *
 *	highscore:	gets the highscore from highscore.txt			 *
 *				creates the file if needed, then compares		 *
 *				this sessions scores to the current highscores	 *
 *				highscore = highest wins & win/loss ratio > 1	 *
 *																 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void highscore(int win,int lose)
{
  
	//Hi, chapter 22
	//some parts are probably excessive and messy, but it works!
	
	FILE *score_file;
    //current highscores
	int high_w = 0, high_l = 0;
	
	
	printf("\nYou got %d wins and %d losses\nWith a win/loss ratio of %.1f\n", win, lose, lose == 0 ? win : win/(float)lose);
	//open file in read only
    score_file = fopen("highscore.txt", "r");
    //did the file exist?
	if (score_file == NULL)
    	{
		//if no, create it and write the current scores to it
		score_file = fopen("highscore.txt", "w");
		fprintf(score_file,"%d\n%d\n", win,lose);
		printf("\a\n\nYou got the highscore!\nAlso that was the first score...\nSo you got it by default\n");
    	//close and return
		fclose(score_file);
		return;
		}
    
	//read wins and losses into variables
    fscanf(score_file,"%d", &high_w);
	fscanf(score_file,"%d", &high_l);
	
	/*did you score higher? highscore needs more wins than old highscore and a positive ratio
	positive ratio prevents terrible losing streaks from getting highscore for just having bulk wins
	win count prevents low quantity play such as 2 win 1 loss streak from being the highscore against something like 3 win 2 loss*/
	if (win >= high_w && (win/(float)lose >= 1 || win/(float)lose >= high_w/(float)high_l))
		{
		//let them know, close the file and open it in write mode, write the scores over the old scores
		printf("\a\n\nYou got the new highscore!");
		fclose(score_file);
		score_file = fopen("highscore.txt", "w");
		fprintf(score_file,"%d\n%d\n", win,lose);
		fclose(score_file);
		printf ("\nThe old highscore is %d wins, %d losses\nfor a win/loss ratio of %.1f", high_w, high_l, high_l == 0 ? high_w : high_w/(float) high_l);
		}
	//if not print current highscores and close
	else{
		printf ("\nThe current highscore is %d wins, %d losses\nwith a win/loss ratio of %.1f\nBetter luck next time!\n", high_w, high_l, high_l == 0 ? high_w : high_w/(float) high_l);
		fclose(score_file);}

}

