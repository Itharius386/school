/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                         *
 * Author: James Marcum                                                    *
 * Class: CS 102                                                           *
 *                                                                         *
 * Function: Coin Class Demo                                               *
 *           Shows how the given Coin class works                          *
 *                                                                         *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
//game from project #13 added as well

//headers
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <cstdlib>
#include "marcum_header.h"
#include "marcum_header.cpp"
#include "coin.h"
//namespace
using namespace std;

//prototypes
int mainLoop();
void initDispCoin(Coin coin);
void dispCoin(Coin coin);


//==============================================================================
//BEGIN MAIN
int main(){
    srand(time(0));
    //srand(123); //debug seed - will add to $1.00
    //srand(1234); //debug seed - will bust

    int loop, selection = -1;

    while (selection = mainLoop()){
        if (selection == 1){
            Coin acoin;
            int heads = 0, tails = 0;
            cout << endl;
            initDispCoin(acoin);
            cout << endl;
            setcolor();
            cout << "How many times to toss the coin: ";
            GetNum(loop, 1);
            cout << endl;
            for (int i = 0; i < loop; i++){
                acoin.toss();
                setcolor();
                dispCoin(acoin);
                if (acoin.getSideUp() == "heads")
                heads++;
                else
                tails++;
            }
            setcolor();
            cout << endl << "Total Heads: " << heads << endl << "Total Tails: " << tails << endl;
            getchar();
        } //selection 1

        if (selection == 2){
            display("#13 - You have a quarter, dime, and nickel.","Flip them and add heads to your pool. You win if you hit $1 exactly");
            Coin quarter(.25), dime(.10), nickel(.05);
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
                if (sum > 1) {
                    cout << "You lost!" << endl << "Press enter to return to menu";
                    getchar();
                    break;
                }
                else if (sum == 1) {
                    cout << "You won!" << endl << "Press enter to return to menu";
                    getchar();
                    break;
                }
                cout << "Press enter for next toss" << endl;
            } while (sum < 1);
        } //selection 2
    }
    return 0;
}
//END MAIN
//==============================================================================

//mainLoop
int mainLoop(){
    char option, options[] = {'a','b','c'};
    system("CLS");
    display("Coin Toss Simulator", "Toss all the coins, all the time.",9);
    cout<< "Options:" << endl \
        << "A: Toss a coin" << endl \
        << "B: Play game" << endl \
        << "C: Exit" << endl;
    cout << "Select an option: ";
    c_in(&option,options,3);
    if (option == 'a')
        return 1;
    if (option == 'b')
        return 2;
    if (option == 'c')
        return 0;
}

//shows the initial side of the coin
void initDispCoin(Coin coin){
    cout << "The "<< coin.getCoinDenom() <<" is currently on ";
    cout << coin.getSideUp() << endl;
    setcolor();
}

//shows the coin after a toss
void dispCoin(Coin coin){
    cout << "The "<< coin.getCoinDenom() <<" landed on ";
    cout << coin.getSideUp() << endl;
    setcolor();
}
