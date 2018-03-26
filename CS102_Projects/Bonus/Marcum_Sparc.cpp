/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                         *
 * Author: James Marcum                                                    *
 * Class: CS 102                                                           *
 *                                                                         *
 * Function: SPARC v2.0 - We playing sparc all over again                  *
 *                                                                         *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
//I wish I had more time over the break to work on this, but I still like how this turned out

//all them headers
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <cstdlib>
#include "marcum_header.h"
#include "marcum_header.cpp"
#include "die.h"
//namespace
using namespace std;

//Prototypes
void dice_display(int value1, int value2);
int MainLoop();
bool Rollem(Die &die1, Die &die2, int winner1 = 6, int winner2 = 7, int loser1 = 2, int loser2 = 12, int sparc = 0);

//==============================================================================
//BEGIN MAIN
int main() {
    //seed with time
    srand(time(0));
    //the dice
    Die die1, die2;
    //other things
    int selection = -1;
    int w_count = 0, l_count = 0;

    while (selection = MainLoop()) {
        //1 - A: Play
        //2 - B: Results
        //0 - C: Exit
        if (selection == 1) {
            if (Rollem(die1, die2)) {
                cout << "You win!" << endl;
                w_count += 1;
            }
            else {
                cout << "You lost!" << endl;
                l_count += 1;
            }
            cout << "Press enter to return to the main menu";
            getchar();
        } //selection 1 - play
        if (selection == 2) {
            cout << endl << "You have won " << w_count << " times so far" << endl;
            cout << "You have lost " << l_count << " times so far"<< endl;
            cout << "Press enter to return to the main menu" << endl;
            getchar();
        } //selection 2 - results
    };
    return 0;
} //END MAIN
//==============================================================================

//==============================================================================
//displays a visual for the dice
//just looks like a lot of text, but it's almost all 'char()'
void dice_display(int value1, int value2){
    int display[] = {value1, value2};

    setcolor();
    cout<< "     ";
    setcolor(240);
    cout << char(201) << char(205)<< char(205)<< char(205)<< char(205)<< char(205)<< char(187);
    setcolor();
    cout << "     ";
    setcolor(240);
    cout << char(201) << char(205)<< char(205)<< char(205)<< char(205)<< char(205)<< char(187) <<  endl;
    setcolor();
    for (int i=0; i<2; i++){
        setcolor();
        cout << "     ";
        setcolor(240);
    	//switch based on dice value
    	switch(display[i]){
    	case(6): case(5): case(4): cout<<char(186)<<char(4)<<"   "<< char(4)<<char(186); break;
    	case(3): case(2): cout<<char(186)<<"    "<<char(4)<<char(186); break;
    	case(1): cout<<char(186)<<"     "<<char(186); break;
    	}
    }
    cout << endl;
    //next layer
    for (int i=0; i<2; i++){
        setcolor();
        cout << "     ";
        setcolor(240);
    	switch(display[i]){
            case(6): cout<<char(186)<<char(4)<<"   "<<char(4)<<char(186); break;
        	case(5): case(3): case(1): cout<<char(186)<<"  "<<char(4)<<"  "<<char(186); break;
        	case(4): case(2): cout<<char(186)<<"     "<<char(186); break;
        	}}
        cout << endl;
    //bottom layer
    for (int i=0; i<2; i++){
        setcolor();
        cout << "     ";
        setcolor(240);
    	switch(display[i]){
            case(6): case(5): case(4): cout<<char(186)<<char(4)<<"   "<< char(4)<<char(186); break;
        	case(3): case(2): cout<<char(186)<<char(4)<<"    "<<char(186); break;
        	case(1): cout<<char(186)<<"     "<<char(186); break;
        	}}
        cout << endl;
    //cap them off
    setcolor();
    cout<< "     ";
    setcolor(240);
    cout << char(200) << char(205)<< char(205)<< char(205)<< char(205)<< char(205)<< char(188);
    setcolor();
    cout << "     ";
    setcolor(240);
    cout << char(200) << char(205)<< char(205)<< char(205)<< char(205)<< char(205)<< char(188) <<  endl;
    setcolor();
}
//dice_display
//==============================================================================

//==============================================================================
//your everyday menu
int MainLoop() {
char option; //options[] = {'a','b','c'};
string options[] = {"Play Game","Results","Exit"};
system("CLS");
display("Let's play SPARC!", "Good Luck!!",240);
cout<< "On your first roll:" << endl << "You win if you roll a 6 or 7 but lose if you roll a 2 or 12" << endl
    <<"On future rolls:" << endl << "You win if you roll the same as your first roll, but lose on 6 or 7" << endl << endl;
option = Menu(options,3);
if (option == 'a')
    return 1;
if (option == 'b')
    return 2;
if (option == 'c')
    return 0;
}
//MainLoop
//==============================================================================

//==============================================================================
//rolls the dice and determines the win for Sparc
bool Rollem(Die &die1, Die &die2, int winner1, int winner2, int loser1, int loser2, int sparc){
    cout << "Press enter to roll the dice" << endl;
    getchar();
    die1.roll();
    die2.roll();
    dice_display(die1.getValue(),die2.getValue());
    if (die1.getValue() + die2.getValue() == winner1 || die1.getValue() + die2.getValue() == winner2)
        return 1;
        //win
    else if (die1.getValue() + die2.getValue() == loser1 || die1.getValue() + die2.getValue() == loser2)
        return 0;
        //lose
    else {
        if (sparc == 0){
            sparc = 1;
            loser1 = winner1;
            loser2 = winner2;
            winner1 = die1.getValue() + die2.getValue();
            winner2 = winner1;
            cout << "You got your Sparc!" << endl << "Your Sparc is " << winner1 << endl;
        }
    return Rollem(die1, die2, winner1, winner2, loser1, loser2, sparc);
    }
}
//Rollem
//==============================================================================
