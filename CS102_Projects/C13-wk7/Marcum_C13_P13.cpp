/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                         *
 * Author: James Marcum                                                    *
 * Class: CS 102                                                           *
 *                                                                         *
 * Function: Coin Game - Flip coins, add the resulting heads to your pool  *
 *           Win if you get exactly the winning amount!                    *
 *                                                                         *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
//floating point maths required me to switch the coin class from double to int for
//the denomination to ensure proper checking against the total

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
void initDispCoin(const Coin &coin);
void dispCoin(const Coin &coin);

int winning_amount = 100;
//==============================================================================
//BEGIN MAIN
int main(){
    srand(time(0));
    //srand(123); //debug seed - will add to $1.00
    //srand(1234); //debug seed - will bust
    double temp; //needed for chaning the winning amount
    int loop, selection = -1;
    Coin quarter(25), dime(10), nickel(5);
    while (selection = mainLoop()){
        if (selection == 1){
            double sum = 0;
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
                cout << endl << fixed << showpoint << setprecision(2) <<"Total so far: $" << static_cast<double>(sum)/100 << endl;
                if (sum == winning_amount) {
                    cout << "You won!" << endl << "Press enter to return to menu";
                    getchar();
                    break;
                }
                else if (sum > winning_amount) {
                    cout << "You lost!" << endl << "Press enter to return to menu";
                    getchar();
                    break;
                }
                cout << "Press enter for next toss" << endl;
            } while (sum < winning_amount);
        } //selection 1
        if (selection == 2){
            string options[] = {"Change denominations", "Change winning threshold", "Return to Menu"};
            cout << endl;
            char option = Menu(options, 3);
            cout << endl;
            if (option == 'a'){
                char coin_selected, coins[] = {'a','b','c'};
                double denom;
                cout << "Which coin do you want to change:" << endl;
                cout << "A: The "<< quarter.getCoinDenom() << endl;
                cout << "B: The "<< dime.getCoinDenom() << endl;
                cout << "C: The "<< nickel.getCoinDenom() << endl;
                cout << "Selection an option: ";
                c_in(&coin_selected, coins, 3);
                cout << endl << "Value must be between 0.01 and 1.00" << endl;
                switch(coin_selected){
                    case('a'): {
                        cout << "Enter denomination for the selected " << quarter.getCoinDenom() << ": " ;
                        GetNumInRange(denom, 1.0,0.01);
                        quarter.setDenom(denom*100);
                        break;
                    }
                    case('b'): {
                        cout << "Enter denomination for the selected " << dime.getCoinDenom() << ": " ;
                        GetNumInRange(denom, 1.0,0.01);
                        dime.setDenom(denom*100);
                        break;
                    }
                    case('c'): {
                        cout << "Enter denomination for the selected " << nickel.getCoinDenom() << ": " ;
                        GetNumInRange(denom, 1.0,0.01);
                        nickel.setDenom(denom*100);
                        break;
                    }
                } //denom switch
            } //S2 OA
            if (option == 'b'){
                cout << "Enter a new winning threshold value (0.01 - 100.00): ";
                GetNumInRange(temp,100.0,0.01);
                winning_amount = temp * 100;
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
    display("Let's play a game!", "Flip the coins and add heads to your pool!",9);
    cout << fixed << showpoint << setprecision(2) << "You win if you get exactly $" << static_cast<double>(winning_amount)/100 << endl << endl;
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
