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
#include <sstream>
#include "marcum_header.h"
#include "marcum_header.cpp"
//Namespace
using namespace std;

//Prototypes

//class
//a movie has a title, and can reference the number of Tickets sold
//Also can be 3D for a theatre surcharge, and has a rating for analytic purpose
//it won't have an individual price/ticket, as that is set by the theatre/distributor
//but I let it calculate the revenue from price inputs
class Movie{
  private:
    string title;
    int a_ticket_sold, c_ticket_sold, is3D, rating;
  public:
    //constructor - with no arguements acts as a 'wizard' and walksthrough building the showing
    Movie(){
        int r_check[]={1,2,3,4,5}, d_check[] = {0,1};
        cout << "Enter the title: ";
        getline(cin >> ws,title);
        cout << "Enter # of Adult Tickets sold: ";
        i_in(&a_ticket_sold,1);
        cout << "Enter # of Child Tickets sold: ";
        i_in(&c_ticket_sold,1);
        cout << "Is it in 3D? (0 = No, 1 = Yes): ";
        s_i_in(&is3D,d_check,2);
        cout << "What is the the movie's rating? (1-5): ";
        s_i_in(&rating,r_check,5);}
    Movie(string name,int a_tic=0,int c_tic=0,int _3d=0,int rated=3)
      {title = name; a_ticket_sold = a_tic; c_ticket_sold = c_tic; is3D = _3d; rated = rating;}
    //what is better: having them take the input as an arguement or have them with 0 arguements and call for their own input with input checking built in to prevent user error?
    void setTitle(){
        cout << "Enter the title: ";
        getline(cin >> ws,title);}
    void setATicket(){
        cout << "Enter # of Adult Tickets sold: ";
        i_in(&a_ticket_sold,1);}
    void setCTicket(){
        cout << "Enter # of Child Tickets sold: ";
        i_in(&c_ticket_sold,1);}
    void set3D(){
        int check[] = {1,2};
        cout << "Is it in 3D? (0 = No, 1 = Yes): ";
        s_i_in(&is3D,check,2);}
    void setRating(){
        int check[]={1,2,3,4,5};
        cout << "What is the the movie's rating? (1-5): ";
        s_i_in(&rating,check,5);}
    //gets
    string getTitle(){return title;}
    int getATicket(){return a_ticket_sold;}
    int getCTicket(){return c_ticket_sold;}
    int get3D(){return is3D;}
    char show3D(){
        if (is3D == 1)
            return 'Y';
        return 'N';}
    int getRating(){return rating;}
    string showRating(){
        stringstream star;
        for (int i = 0; i < rating; i++)
            star << '*';
        return star.str();}
    double calcGross(double priceAdult, double priceChild, double surcharge3D){
        double total = 0;
        if (is3D)
            total += (a_ticket_sold + c_ticket_sold) * surcharge3D;
        total += a_ticket_sold * priceAdult + c_ticket_sold * priceChild;
        return total;
    }
};

//BEGIN MAIN
int main(){
//variable inits with default values
    double a_tic_cost = 10, c_tic_cost = 6, retained_percent = .2, surcharge3D = 3, \
        profit = 0, t_gross_profit = 0, retained_earn = 0, t_retained = 0;
    int num_rep,i;
    string title;
    vector<Movie> showing;
//loop checks
    char settings = 'a', yn_check[] = {'y', 'n'};

    display("Welcome to The Movie Money Generator","Get all the money you ever dreamed of!");
    cout << "Would you like to change the settings? (y/n): ";
    c_in(&settings,yn_check,2);
    if (settings == 'y') {
        cout << "#~~~~~~~~~~#~~~~~~~~~~*Settings*~~~~~~~~~~#~~~~~~~~~~#" << endl;
        cout << "Price of Adult Tickets (Default $10):     $";
        d_in(&a_tic_cost,1);
        cout << "Price of Child Tickets (Default $6):      $";
        d_in(&c_tic_cost,1);
        cout << "Surcharge for 3D (Default $3):            $";
        d_in(&surcharge3D,1);
        cout << "Percent of earnings retained (Default 20): ";
        d_in(&retained_percent,1);
        //0-100 check
        while (retained_percent < 0 || retained_percent > 100){
        cout << "Must be between 0-100: ";
        d_in(&retained_percent);}
        //divide entered number by 100 to get it as a percentage
        retained_percent /= 100;
        //again only a single chance to change settings per run of the programs
        system("CLS");
        display("Welcome to The Movie Money Generator","Get all the money you ever dreamed of!");}
    //number of movies to enter
    cout << "How many movies do you want to enter?: ";
    i_in(&num_rep,1);
    //main loop
    for (i = 0; i < num_rep; i++){
        //make that many movies
        showing.push_back(Movie());
        cout << endl;}
    system("CLS");
    display("Welcome to The Movie Money Generator","Get all the money you ever dreamed of!");
    //clear the screen, add the display, then display all the results
    cout << fixed  << setprecision(2);
    cout << setw(30) << " " << left << setw(8) << " Adult" << setw(8) << " Child" << setw(10) << "Gross" << setw(9) << "Retained" << setw(12) << " Paid to" << endl;
    cout << setw(21) << "Title" << setw(6) << "Rated" << setw(3) << "3D" << setw(8) << "Tickets" << setw(8) << "Tickets" << setw(10) << "Profit" << setw(10) << "Earning" << setw(12) << "Distributor" << endl;
    for (int j = 0; j < 80; j++)
        cout << "_";
    cout << endl;
    for (i = 0; i < num_rep; i++){
        profit = showing[i].calcGross(a_tic_cost,c_tic_cost,surcharge3D);
        retained_earn = profit * retained_percent;
        t_gross_profit += profit;
        t_retained += retained_earn;
        cout << setw(21) << showing[i].getTitle() << setw(6) << showing[i].showRating() << setw(3) << showing[i].show3D() << setw(8) << showing[i].getATicket() << setw(8) << showing[i].getCTicket() << "$" << setw(9) << profit << "$" << setw(9) << retained_earn << "$" << setw(11) << profit - retained_earn << endl;
    }
  return 0;
}
//END MAIN
