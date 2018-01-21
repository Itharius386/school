/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                                                 *
 *  Author: James Marcum                                                                           *
 *  Class: CS 102                                                                                  *
 *                                                                                                 *
 *  Function: Compute dollar amount with tax added                                                 *
 *                                                                                                 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

//keeping things simple

//included headers
#include <iostream>
#include <cmath>
#include <iomanip>
//namespace
using namespace std;

//input check prototype
void d_in(double *input);

//BEGIN MAIN
int main(){
    double cash = 0, tax_rate = .05;
//display
  cout << "#======================================================#" << endl << "|      Welcome to Uncle Sam's Tax Rate Calculator      |" << endl << "#======================================================#\n\n";
//prompt for cash value
    cout << "Enter a cash value: ";
    d_in(&cash);
//prompt for tax rate
    cout << "Enter tax rate (5 for 5%): ";
    d_in(&tax_rate);
//check input if it was entered as whole number
//makes program not work for tax rates above 100% and below 1%, but you have other concerns at those extremes
    if (tax_rate > 1)
        tax_rate /= 100;
//output value with tax
    cout << "Value with tax: $" <<  fixed << setprecision(2) << cash + cash * tax_rate;
    return 0;
}
//END MAIN

//input check function
void d_in(double *input){
    cin >> *input;
    while (cin.fail()){
        cout << "Invalid, try again" << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cin >> *input;
        }
}
