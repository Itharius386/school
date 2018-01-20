/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                                                 *
 *  Name: Cash Counter                                                                             *
 *  Author: James Marcum                                                                           *
 *  Class: CS 102                                                                                  *
 *  Time: 1.5 hours                                                                                   *
 *                                                                                                 *
 *  Function: Seperates a given dollar amount into currency of lowest terms                        *
 *                                                                                                 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

//headers
#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <map>
#include <list>
//namespace
using namespace std;

//class
class Cash{
    private:
        //dollar and cents array
        int dollars[6] = {0},
            cents[4] = {0};
        //total cash handler
        double cash=0;
        //total for dollar and total for cents
        int t_dollar=0, t_cents=0;
        //bill name array to match dollar and cents
        const string d_list[6] = {"Hundreds","Fifties","Twenties","Tens","Fives","Ones"}
               ,c_list[4] = {"Quaters", "Dimes" , "Nickles", "Pennies"};

    public:
        //getters
        double getCash()
        {return cash;}
        double getChange()
        {return static_cast<double>(t_cents)/100;}
        int getDollars()
        {return t_dollar;}

        //setter
        void setCash(double c)
        {cash = c;}

        //display
        void display(){
            //attempts to do this as a map failed when I realized that maps are sorted alphabetically for effecient sorting
            //map <string, int>::iterator loop;
            //for (loop = dollars.begin(); loop != dollars.end() ; loop++)
            //   cout << setw(15) << loop -> first << setw(10) << loop -> second << endl;
            //cout << endl;
            //for (loop = cents.begin(); loop != cents.end() ; loop++)
            //    cout << setw(15) << loop -> first << setw(10) <<loop -> second << endl; 
            int i = 0;
            for (;i < 6; i++){
                cout << setw(10) << d_list[i] << setw(10) << dollars[i] << endl;
            }
            cout << endl;
            for (i=0; i < 4; i++){
                cout << setw(10) << c_list[i] << setw(10) << cents[i] << endl;
            }
            cout << endl;
        }
        
        //cash construct prototype
        Cash(double);
};

//prototype

//***BEGIN MAIN***//

int main(){
    //init the input
    double money=0;
    //why we are here
    cout << "WELCOME TO MONEY'MATIC\n\nEnter a monetary value here (we accept change) : ";
    //get cash
    //din(&money);
    cin >> money;
    //make it bills
    Cash bills(money);
    //show it off
    bills.display();
    //Main is 6 lines with the return
    return 0;
}

//***END MAIN***//

//Cash constructor function
//from variable($ Value), constructs bill denominations at lowest terms
Cash::Cash(double total){
    cash = total;
    t_dollar = cash;
    t_cents = (cash - t_dollar) * 100;
    if (t_dollar > 0){
    dollars[0] = t_dollar / 100;
    dollars[1] = (t_dollar % 100) / 50;  
    dollars[2] = (t_dollar % 50) / 20;
    dollars[3] = (t_dollar % 20) / 10;
    dollars[4] = (t_dollar % 10) / 5;
    dollars[5] = (t_dollar % 5);}
    if (t_cents > 0){
    cents[0] = t_cents / 25;
    cents[1] = (t_cents % 25) / 10;
    cents[2] = (t_cents % 25 % 10) / 5;
    cents[3] = (t_cents % 5);}
}