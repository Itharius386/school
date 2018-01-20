/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                                                 *
 *  Author: James Marcum                                                                           *
 *  Class: CS 102                                                                                  *
 *  Time: 30 minutes                                                                               *
 *                                                                                                 *
 *  Function: Compute dollar amount with tax added                                                 *
 *                                                                                                 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

//included headers
#include <iostream>
#include <cmath>
#include <iomanip>
//namespace
using namespace std;

//input check prototype
double din_check(double *input);

//BEGIN MAIN

int main(){
    double cash = 0, tax_rate = .05;

//prompt for cash value
    cout << "Enter a cash value: ";
    din_check(&cash);
//prompt for tax rate
    cout << "Enter tax rate (5 for 5%): ";
    din_check(&tax_rate);
//check input for being entered as whole number
    if (tax_rate > 1)
        tax_rate /= 100;

//output value with tax
    cout << "Value with tax: $" <<  fixed << setprecision(2) << cash + cash * tax_rate;

    return 0;
}

//END MAIN


//input check function
double din_check(double *input){
    cin >> *input;
    while (cin.fail()){
        cout << "Invalid, try again" << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cin >> *input;
        }
    return *input;
}