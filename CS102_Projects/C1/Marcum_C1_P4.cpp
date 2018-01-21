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
#include <map>
//namespace
using namespace std;

//input check prototype
void d_in(double *input);

//BEGIN MAIN
int main(){
    int repeat = 0, i = 0;
    double cash = 0, tax_rate = .05;
    map<double,double> total_cash;
//display
  cout << "#======================================================#" << endl << "|      Welcome to Uncle Sam's Tax Rate Calculator      |" << endl << "#======================================================#\n\n";
  //prompt for tax rate
      cout << "Enter tax rate (5 for 5%): ";
      d_in(&tax_rate);
  //check input if it was entered as whole number
  //makes program not work for tax rates above 100% (if entered as decimal) and below 1%, but you have other concerns at those extremes
      if (tax_rate > 1)
          tax_rate /= 100;
  cout << "How many values would you like to enter: ";
  cin >> repeat;
//loop get values
for (;i < repeat;i++){
//prompt for cash value
    cout << "Enter a cash value: ";
    d_in(&cash);
    total_cash[cash] = (cash + cash * tax_rate);
  }
//output value with tax
    cout << setw(15) << "cash value" << setw(15) << "with tax" << endl;
    map<double,double>:: iterator loop;
    for (loop = total_cash.begin(); loop != total_cash.end(); loop++){
    cout << setw(15) << fixed << setprecision(2) << loop->first << setw(15 )<< loop->second << endl;}
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
