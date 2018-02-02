/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                                         *
 *    Author: James Marcum                                                                 *
 *    Class:  CS102                                                                        *
 *                                                                                         *
 *    Function: Property Taxes - Find out how much you owe in property taxes now!          *
 *              Just input current assessed value of the property                          *
 *                                                                                         *
 *    Default:  60% of actual value = Assessed value, Pay $0.75 per $100 assessed          *
 *                                                                                         *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

//headers
#include <iostream>
#include <iomanip>
#include <cmath>
#include <windows.h>
#include "marcum_header.h"
#include "marcum_header.cpp"
//namespace
using namespace std;

//prototypes
void display_settings(double*, double*);

//BEGIN MAIN
int main(){
  //init variables
  double  property_value, \
  assessed_value, assessed_rate = .6, \
  tax_rate = .75, tax_owed = 0;
  char repeat = 'y', re_check[] = {'y','n','s'};

  //enter main loop
  while (repeat == 'y'){
    //display banner
    display("Welcome to TAX SIM v1.3","We solve all property tax needs in one place!");
    //get property value
    cout << left << setw(35) << endl << "Enter the Actual Property Value:" << "$";
    d_in(&property_value,1);
    //calculate assessed = 60% actual
    assessed_value = (property_value * assessed_rate);
    //taxes = .75 for every 100
    tax_owed = assessed_value / 100.0 * tax_rate;
    //output values
    cout << fixed << setprecision(2) << setw(35) << "Assessed Value of Property: " << "$" << assessed_value << endl \
         << setw(35) << "Total Taxes Owed:" << "$" << tax_owed << endl;
    //loop?
    cout << "\nDo you have more property to assess? (y/n or 's' for settings): ";
    c_in(&repeat,re_check,3);
    if (repeat == 'y')
      system("CLS");
    if (repeat == 's'){
      display_settings(&assessed_rate,&tax_rate);
      repeat = 'y';
      system("CLS");
      }
  }
  //exit loop if 'n'

  return 0;
}
//END MAIN

//Displays settings, takes in assessed rate and taxed rate to be altered
void display_settings(double*assess,double*rate){
  cout << "$------------#---------Settings---------#------------$" << endl;
  cout << "Enter the assessed rate percentage (default 60): ";
  d_in(assess);
  *assess /= 100;
  cout << "Enter the tax rate per $100 (default 0.75): ";
  d_in(rate);
}
