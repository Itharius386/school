/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                                         *
 *    Author: James Marcum                                                                 *
 *    Class:  CS102                                                                        *
 *                                                                                         *
 *    Function:   Box office calculator                                                    *
 *                Gives box office profit from tickets sold                                *
 *                and how much is paid back to the distributor                             *
 *                                                                                         *
 *    Default:    Adult: $10 | Child: $6 | Retained: 20%                                   *
 *                                                                                         *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

//Headers
#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>
//Namespace
using namespace std;

//Prototypes
void i_in(int*);
void c_in(char*, char*, int);
void d_in(double*);

//BEGIN MAIN
int main(){
//variable inits
  double a_tic_cost = 10, c_tic_cost = 6, retained_percent = .2, \
         gross_profit = 0, retained_earn = 0;
  int a_tickets = 0, c_tickets = 0;
  char repeat = 'y', re_check[] = {'y', 'n'};
  string movie_name;
//main loop
while (repeat == 'y'){
  //display
  cout << "#~@~#~@~#~@~#~@~#~@~#~@~#~@~#~@~#~@~#~@~#~@~#~@~#~@~#~@~#~@~#~@~#~@~#" << endl \
       << "|                                                                   |" << endl \
       << "|               Welcome to The Movie Money Generator!               |" << endl \
       << "|              Get all the money you ever dreamed of!!              |" << endl \
       << "|                                                                   |" << endl \
       << "#~@~#~@~#~@~#~@~#~@~#~@~#~@~#~@~#~@~#~@~#~@~#~@~#~@~#~@~#~@~#~@~#~@~#" << endl << endl;
  //prompt for movie name or settings option
  cout << "Enter the name of a movie or enter 's' to change the settings: ";
  getline(cin >> ws, movie_name);
  //if settings (Can't name a movie 's' unfortunately)
  if (movie_name == "s") {
    cout << "#~~~~~~~~~~#~~~~~~~~~~*Settings*~~~~~~~~~~#~~~~~~~~~~#" << endl;
    cout << "Price of Adult Tickets (Default $10):     $";
    d_in(&a_tic_cost);
    cout << "Price of Child Tickets (Default $6):      $";
    d_in(&c_tic_cost);
    cout << "Percent of earnings retained (Default 20): ";
    d_in(&retained_percent);
    //divide entered number by 100 to get it as a percentage
    retained_percent /= 100;}
  //else it's the movie title
  else{
    //get tickets sold
    cout << "Enter number of Adult Tickets sold: ";
    i_in(&a_tickets);
    cout << "Enter number of Child Tickets sold: ";
    i_in(&c_tickets);
    //calculate gross profit and retained earnings (The part you keep)
    gross_profit = (a_tickets * a_tic_cost + c_tickets * c_tic_cost);
    retained_earn = gross_profit * retained_percent;
    cout << endl << fixed  << setprecision(2) << setw(25) << left << "Movie Title:" << movie_name << endl \
         << setw(25) << "Adult Tickets Sold:" << a_tickets << endl \
         << setw(25) << "Child Tickets Sold:" << c_tickets << endl \
         << setw(25) << "Gross Box Office profit:" << "$" << gross_profit << endl \
         << setw(25) << "Net Retained Earnings:" << "$" << retained_earn << endl \
         << setw(25) << "Paid to Distributor:" << "$" << (gross_profit - retained_earn) << endl << endl;}
  //if they chose settings auto-loop to get movie title
  if (movie_name != "s"){
    cout << "Would you like to enter another movie?(y/n): ";
    c_in(&repeat,re_check,2);}
    cin.clear();
  //clear the screen
    system("CLS");
  }
  return 0;
}
//END MAIN


//Loops to get an integer, if a float is entered it will truncate and clear the stream
void i_in(int *input){
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

//Loops until a double/float is input
void d_in(double *input){
    cin >> *input;
    while (cin.fail()){
        cout << "Invalid, try again: " << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cin >> *input;
        }
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
