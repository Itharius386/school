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
#include "marcum_header.h"
#include "marcum_header.cpp"
//Namespace
using namespace std;

//Prototypes

//BEGIN MAIN
int main(){
//variable inits with default values
  double a_tic_cost = 10, c_tic_cost = 6, retained_percent = .2, \
         gross_profit = 0, retained_earn = 0;
  int a_tickets = 0, c_tickets = 0;
//loop checks
  char repeat = 'y', re_check[] = {'y', 'n'};
  string movie_name;
//main loop
while (repeat == 'y'){
  //display
  display("Welcome to The Movie Money Generator!","Get all the money you ever dreamed of!!");
  //prompt for movie name or settings option
  cout << "Enter the name of a movie or enter 's' to change the settings: ";
  getline(cin >> ws, movie_name);
  //if settings, change settngs (Limits options - Can't name a movie 's')
  if (movie_name == "s") {
    cout << "#~~~~~~~~~~#~~~~~~~~~~*Settings*~~~~~~~~~~#~~~~~~~~~~#" << endl;
    cout << "Price of Adult Tickets (Default $10):     $";
    d_in(&a_tic_cost,1);
    //positive check
    cout << "Price of Child Tickets (Default $6):      $";
    d_in(&c_tic_cost,1);
    cout << "Percent of earnings retained (Default 20): ";
    d_in(&retained_percent,1);
    //0-100 check
    while (retained_percent < 0 || retained_percent > 100){
      cout << "Must be between 0-100: ";
      d_in(&retained_percent);}
    //divide entered number by 100 to get it as a percentage
    retained_percent /= 100;}
  //else it's the movie title
  else{
    //get tickets sold
    cout << "Enter number of Adult Tickets sold: ";
    i_in(&a_tickets,1);
    cout << "Enter number of Child Tickets sold: ";
    i_in(&c_tickets,1);

    //calculate gross profit and retained earnings (The part you keep)
    gross_profit = (a_tickets * a_tic_cost + c_tickets * c_tic_cost);
    retained_earn = gross_profit * retained_percent;

    //show
    cout << endl << fixed  << setprecision(2) << setw(25) << left << "Movie Title:" << movie_name << endl \
         << setw(25) << "Adult Tickets Sold:" << a_tickets << endl \
         << setw(25) << "Child Tickets Sold:" << c_tickets << endl \
         << setw(25) << "Gross Box Office profit:" << "$" << gross_profit << endl \
         << setw(25) << "Net Retained Earnings:" << "$" << retained_earn << endl \
         << setw(25) << "Paid to Distributor:" << "$" << (gross_profit - retained_earn) << endl << endl;}
  //if they chose settings auto-loop to get movie title otherwise ask if they want to enter another
  if (movie_name != "s"){
    cout << "Would you like to enter another movie? (y/n): ";
    c_in(&repeat,re_check,2);}
    cin.clear();
  //clear the screen if they picked yes
  if (repeat == 'y')
    system("CLS");
  }
  return 0;
}
//END MAIN
