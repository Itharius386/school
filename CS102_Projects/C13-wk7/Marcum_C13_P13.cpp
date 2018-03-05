/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                         *
 * Author: James Marcum                                                    *
 * Class: CS 102                                                           *
 *                                                                         *
 * Function: Coin Game                                                     *
 *                                                                         *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


//headers
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include "marcum_header.h"
#include "marcum_header.cpp"
#include "coin.h"
//namespace
using namespace std;

//prototypes
int mainLoop();
void initDispCoin(const Coin &coin);
void dispCoin(const Coin &coin);

double winning_amount = 1;
//==============================================================================
//BEGIN MAIN
int main(){
    srand(time(0));
    //srand(123); //debug seed - will add to $1.00
    //srand(1234); //debug seed - will bust

    int loop, selection = -1;
    Coin quarter(.25), dime(.10), nickel(.05);
    while (selection = mainLoop()){
        if (selection == 1){
            float sum = 0;
            initDispCoin(quarter);
            initDispCoin(dime);
            initDispCoin(nickel);
            cout << endl << "Press enter to toss the coins." << endl;
            do {
                getchar();
                quarter.toss();
                dime.toss();
                nickel.toss();
                dispCoin(quarter);
                dispCoin(dime);
                dispCoin(nickel);
                if (quarter.getSideUp() == "heads")
                    sum += quarter.getDenom();
                if (dime.getSideUp() == "heads")
                    sum += dime.getDenom();
                if (nickel.getSideUp() == "heads")
                    sum += nickel.getDenom();
                setcolor();
                cout << endl << fixed << showpoint << setprecision(2) <<"Total so far: $" << sum << endl;
                if (sum > winning_amount) {
                    cout << "You lost!" << endl << "Press enter to return to menu";
                    getchar();
                    break;
                }
                else if (sum == winning_amount) {
                    cout << "You won!" << endl << "Press enter to return to menu";
                    getchar();
                    break;
                }
                cout << "Press enter for next toss" << endl;
            } while (sum < 1);
        } //selection 1
        if (selection == 2){
            string options[] = {"Change denominations", "Change winning threshold", "Return to Menu"};
            char option = Menu(options, 3);
            if (option == 'a'){
                string coin_selected[3];
                cout << "Which coin do you want to change:" << endl;
                coin_selected[0] = "The "<< quarter.getCoinDenom();
                coin_selected[1] = "The "<< dime.getCoinDenom();
                coin_selected[2] = "The "<< nickel.getCoinDenom();
            } //S2 OA
            if (option == 'b'){

            } //S2 OB
            if (option == 'c'){
                continue;
            } //S2 OC
        } //selection 2
    }
    return 0;
}
//END MAIN
//==============================================================================

//mainLoop
int mainLoop(){
    char option; //options[] = {'a','b','c'};
    string options[] = {"Play Game","Settings","Exit"};
    system("CLS");
    display("Let's play a game! Flip the coins and add heads to your pool","",9);
    cout << fixed << setprecision(2) << "You win if you get exactly $" << winning_amount << endl;
    option = Menu(options,3);
    if (option == 'a')
        return 1;
    if (option == 'b')
        return 2;
    if (option == 'c')
        return 0;
}

//shows the initial side of the coin
void initDispCoin(const Coin &coin){
    cout << "The "<< coin.getCoinDenom() <<" is currently on ";
    cout << coin.getSideUp() << endl;
    setcolor();
}

//shows the coin after a toss
void dispCoin(const Coin &coin){
    cout << "The "<< coin.getCoinDenom() <<" landed on ";
    cout << coin.getSideUp() << endl;
    setcolor();
}
