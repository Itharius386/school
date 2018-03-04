/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                         *
 * Author: James Marcum                                                    *
 * Class: CS 102                                                           *
 *                                                                         *
 * Function: Floating Point Array Class Demo                               *
 *           Shows how the given FloatingArray class works                 *
 *                                                                         *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <iostream>
#include <iomanip>
#include "marcum_header.h"
#include "marcum_header.cpp"
#include "floating_array.h"
//namespace
using namespace std;

//prototypes
int mainLoop();

int main(){
    int asize, index, loop, selection = -1;
    double element, default_size;

    display("Number Entry Simulator v1.0","Enter Numbers, Get the Same Numbers Out",6);

    cout << "How many elements would you like to store in your array: ";
    GetNum(asize,1);
    cout << "Default value for the array: ";
    GetNum(default_size);
    FloatingArray your_array(asize, default_size);

    while (selection = mainLoop()){
        /*
        1: SET Value(s)
        2: GET Value(s)
        3: get average Data
        4: exit
        */
        if (selection == 1){
            cout << endl << "How many indices would you like to set: ";
            GetNum(loop,1);
            cout << "index '0' is the first index" << endl;
            for (int i = 0; i < loop; i++){
                cout << endl << "Enter index to set: ";
                GetNumInRange(index, asize-1);
                cout << "Enter value for index #" << index << ": ";
                GetNum(element);
                your_array.setElement(index, element);
            }
        } //selection 1
        if (selection == 2){
            char option, options[] = {'a','b'};
            cout<< endl << "Options:" << endl \
                << "A: Get all elements" << endl \
                << "B: View individual element" << endl \
                << "Select an Option: ";
            c_in(&option,options,2);
            cout << endl;
            if (option == 'a'){
                for(int i = 0; i < asize; i++)
                    cout << "Value at index #" << i << " is " << your_array.getElement(i) << endl;
                getchar();
            } //s2 opt A
            if (option == 'b'){
                cout << "How many values do you want to check: ";
                GetNum(loop,1);
                for (int i = 0; i < loop; i++){
                    cout << endl << "Which index do you want the value of: ";
                    GetNumInRange(index,asize-1);
                    cout << "Value at index " << index << " is " << your_array.getElement(index) << endl;
                } //s2 opt B
                getchar();
            }
        } //selection 2
        if (selection == 3){
            cout<< endl << "Highest Value: " << your_array.getLargest() << endl \
                << "Lowest Value: " << your_array.getSmallest() << endl \
                << "Average Value: " << your_array.getAverage() << endl;
            getchar();
        } //selection 3
    } //mainLoop

    return 0;
}

int mainLoop(){
    char option, options[] = {'a','b','c','d'};
    system("CLS");
    display("Number Entry Simulator v1.0","Enter Numbers, Get the Same Numbers Out",6);
    cout<< "Options:" << endl \
        << "A: Set Values" << endl \
        << "B: Get Values" << endl \
        << "C: Get Value Data" << endl \
        << "D: Exit" << endl;
    cout << "Select an Option: ";
    c_in(&option,options,4);
    if (option == 'a')
        return 1;
    if (option == 'b')
        return 2;
    if (option == 'c')
        return 3;
    if (option == 'd')
        return 0;
}
