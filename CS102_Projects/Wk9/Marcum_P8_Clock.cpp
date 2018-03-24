/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                             *
 * Author: James Marcum                                                        *
 * Class: CS 102                                                               *
 *                                                                             *
 * Function: Clock - show the use of a 'Clock' class with overloaded operators *
 *                                                                             *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

 //careful overview of the example program showed a 12-hour base clock system
 //this was the basis for calculations
 //overloaded the '<<' because it makes this so much easier to read
 //kept it simple for spring break

//headers
#include <iostream>
#include <iomanip>
#include "marcum_header.h"
#include "marcum_header.cpp"
#include "Clock.h"
#include "Clock.cpp"
//namespace
using namespace std;


//BEGIN MAIN
int main(){
    int hr, min, sec;
    display("Hello and welcome to \"Clock\"!","We are going to do some time math!!");

    //time 1
    cout << "Enter the hours of Time #1: ";
    GetNum(hr);
    cout << "Enter the minutes of Time #1: ";
    GetNum(min);
    cout << "Enter the seconds of Time #1: ";
    GetNum(sec);
    Clock time1(hr, min, sec);
    cout << endl << "Time #1 is " << time1 << endl << endl;

    //time 2
    cout << "Enter the hours of Time #2: ";
    GetNum(hr);
    cout << "Enter the minutes of Time #2: ";
    GetNum(min);
    cout << "Enter the seconds of Time #2: ";
    GetNum(sec);
    Clock time2(hr, min, sec);
    cout << endl << "Time #2 is " << time2 << endl << endl;

    // '+' use
    Clock temp;
    temp = time1 + time2;
    cout << "Now we add them: " << temp << endl << endl;

    // '-' use
    temp = time1 - time2;
    cout << "Then we subtract them: " << temp << endl << endl;

    // '++' post use
    cout << "Time #1 post-incremented and added to Time #2 is " << time1++ + time2 << endl;
    cout << "Time #1 is now " << time1 << endl << endl;

    // '++' pre use
    cout << "Time #1 pre-incremented and added to Time #2 is " << ++time1 + time2 << endl;
    cout << "Time #1 is now " << time1 << endl << endl;

    // '--' post use
    cout << "Time #2 post-decremented and added to Time #1 is " << time1 + time2-- << endl;
    cout << "Time #2 is now " << time2 << endl << endl;

    // '--' pre use
    cout << "Time #2 pre-decremented and added to Time #1 is " << time1 + --time2 << endl;
    cout << "Time #2 is now " << time2 << endl << endl;

    // '>' use
    cout << "Is Time #1 > Time#2? ";
    if (time1 > time2)
        cout << "True" << endl << endl;
    else
        cout << "False" << endl << endl;

    // '<' use
    cout << "Is Time #1 < Time#2? ";
    if (time1 < time2)
        cout << "True" << endl << endl;
    else
        cout << "False" << endl << endl;

return 0;
}//END MAIN
