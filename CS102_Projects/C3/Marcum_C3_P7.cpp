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
#include <vector>
#include <windows.h>
#include "marcum_header.h"
#include "marcum_header.cpp"
//Namespace
using namespace std;

//Prototypes

//class
//a movie has a title, and can reference the number of Tickets sold
//Also can be 3D for a theatre surcharge, and has a rating for analytic purpose
//it won't have an individual price/ticket, as that is set by the theatre/distributor
class Movie{
  private:
    string title;
    int a_ticket_sold, c_ticket_sold, is3D, rating;
  public:
    //constructor
    Movie(string name,int a_tic=0, c_tic=0, _3d=0, rated=3)
      {title = name; a_ticket_sold = a_tic; c_ticket_sold = c_tic; is3D = _3d, rated = rating}
    //gets
    string getTitle(){return title;}
    int getATicket(){return a_ticket_sold;}
    int getCTicket(){return c_ticket_sold;}
    int get3D(){return is3D;}
    int getRating(){return rating;}
    //what is better: having them take the input as an arguement or have them with 0 arguements and call for their own input with input checking built in to prevent user error?
    void setTitle(string name){title = name;}
    void setATicket(int tic){a_ticket_sold = tic;}
    void setCTicket(int tic){c_ticket_sold = tic;}
    void set3D(int set){is3D = set;}
    void setRating(int set){rating = set;}
};


class Theatre{
  private:
    string theatre;
    vector<Movie> showings;
    double adult_tix_price, child_tix_price, charge_3D \
          retained_percent;
  public:
    Theatre(string name = "The Best Theatre You Never Saw", double ap = 10, double cp = 6, double D3 = 3){theatre = name; adult_tix_price = ap; child_tix_price = cp; charge_3D = D3;}
    void addShowing(string title){showings.push_back(Movie(title));}

}

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
  //Get their Theatre's name
  //getline(cin >>)
  //prompt for movie name or settings option
  cout << "Enter the name of a movie or enter 's' to change the settings: ";
  //cin >> ws fixes my cin to getline issue of \n being left in the stream if you go to settings, and gets rid of leading whitespace :D
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
