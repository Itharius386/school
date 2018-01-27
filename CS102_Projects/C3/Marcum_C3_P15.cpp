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
//namespace
using namespace std;

//prototypes
void d_in(double*);
void display();
void c_in(char*,char*,int);

//BEGIN MAIN
int main(){
  //init variables
  double  property_value = 10000, \
  assessed_value, assessed_rate = .6, \
  tax_rate = .75, tax_owed = 0;
  char repeat = 'y', re_check[] = {'y','n'};
  //display banner
  display();
  //enter main loop
  while (repeat == 'y'){
  //get property value
  cout << left << setw(35) << "\n Enter the Actual Property Value:" << "$";
  d_in(&property_value);
  //calculate
  assessed_value = (property_value * assessed_rate);
  tax_owed = assessed_value / 100.0 * tax_rate;
  //output values
  cout << fixed << setprecision(2) << setw(35) << " Assessed Value of Property: " << "$" << assessed_value << endl \
       << setw(35) << " Total Taxes Owed:" << "$" << tax_owed << endl;
  //loop?
  cout << "\n Would you like more taxes? (y/n): ";
  c_in(&repeat,re_check,2);
  }
  //exit loop

  return 0;
}
//END MAIN


//Loops to get an integer, if a float is entered it will truncate and clear the stream
void d_in(double *input){
  cin >> *input;
  while (cin.fail()){
    cout << "Invalid, try again: ";
    cin.clear();
    cin.ignore(256,'\n');
    cin >> *input;
    }
  cin.clear();
  cin.ignore(256,'\n');
}

//Loops until a character that is within the given array is input
void c_in(char *input, char check[], int array_size){
    int i, b_check=0;
    char temp;
    while (true){
        cin >> temp;
        temp = tolower(temp);
        for (i=0;i<array_size;i++){
          if (temp == check[i]){
            cin.clear();
            cin.ignore(256,'\n');
            b_check=1;
            break;}}
      if (b_check)
        break;
      else{
          cin.clear();
          cin.ignore(256,'\n');
          cout << "Invalid entry, try agian: ";}
    }
    *input = temp;
}

void display(){
  cout << "#----------------------------------------------------#" << endl \
       << "|              Welcome to TAX SIM v1.02              |" << endl \
       << "|    We solve all property tax needs in one place!   |" << endl \
       << "#----------------------------------------------------#" << endl;

}
