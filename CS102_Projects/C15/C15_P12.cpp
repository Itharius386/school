/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                             *
 * Author: James Marcum                                                        *
 * Class: CS 102                                                               *
 *                                                                             *
 * Function: Ships, Cargo Ships, and Cruise Ships - a registry basically       *
 *                                                                             *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
 //used a vector over an array, same end result though

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Ships.h"
#include "marcum_header.h"
#include "marcum_header.cpp"
using namespace std;

//prototypes
int mainLoop();
int numShips(string shiptype);
void DisplayShip(const Ship *ship);

//BEGIN MAIN
int main() {
    int selection = -1;
    vector<Ship*> registry;
    while (selection = mainLoop()) {
        /*
        1 Create Ship
        2 Create Cruise Ship
        3 Create Cargo Ship
        4 Display
        5 Exit
        */
        if (selection == 1) {
            string name, year;
            int loop = numShips("ship");
            for (int i = 0; i < loop; i++) {
                cout << endl << "Ship #" << i + 1 << endl;
                cout << "What is the name of the ship: ";
                setcolor(14);
                getline(cin, name);
                setcolor();
                cout << "What year was it built: ";
                setcolor(14);
                getline(cin, year);
                setcolor();
                registry.push_back(new Ship(name, year)); //adds the ship to registry
            }//loop
        } // selection 1
        if (selection == 2) {
            string name;
            int pass;
            int loop = numShips("cruise ship");
            for (int i = 0; i < loop; i++) {
                cout << endl << "Ship #" << i + 1 << endl;
                cout << "What is the name of the ship: ";
                setcolor(14);
                getline(cin, name);
                setcolor();
                cout << "How many passengers can it hold: ";
                GetNum(pass);
                registry.push_back(new CruiseShip(name, pass)); //adds the ship to registry
            }//loop
        } // selection 2
        if (selection == 3) {
            string name;
            int tonnes;
            int loop = numShips("cargo ship");
            for (int i = 0; i < loop; i++) {
                cout << endl << "Ship #" << i + 1 << endl;
                cout << "What is the name of the ship: ";
                setcolor(14);
                getline(cin, name);
                setcolor();
                cout << "How many tonnes of cargo can it hold: ";
                GetNum(tonnes);
                registry.push_back(new CargoShip(name, tonnes)); //adds the ship to registry
            }//loop
        } // selection 3
        if (selection == 4) {
            for_each(registry.begin(), registry.end(), DisplayShip);
            cout << endl << "Press Enter to return to Menu.";
            getchar();
        } // selection 4
    } //mainLoop

    return 0;
}//END MAIN

//==============================================================================
//BEGIN Functions

//main loop - main display and selection getter for loop
int mainLoop(){
    char option, options[] = {'a','b','c','d','e'};
    system("CLS");
    display("Ship Registry v2.0","Sail On!", 10);
    cout<< "Options:" << endl \
        << "A: Create Ship" << endl \
        << "B: Create Cruise Ship" << endl \
        << "C: Create Cargo Ship" << endl \
        << "D: Display Ships" << endl \
        << "E: Exit" << endl << endl;
    cout << "Select an Option from the list: ";
    c_in(&option,options,5);
    switch(option){
        case('a'): return 1;
        case('b'): return 2;
        case('c'): return 3;
        case('d'): return 4;
        case('e'): return 0;
    }
    return 0; //incase somehow breaks out of the loop
}//mainLoop

int numShips(string shiptype) {
    int loop;
    cout << "How many " << shiptype << "s do you want to make: ";
    GetNum(loop,1);
    return loop;
} //numShips

void DisplayShip(const Ship *ship) {
    ship->printShip();
}//DisplayShip
