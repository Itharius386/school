/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                                                 *
 *  Name: Cash Counter                                                                             *
 *  Author: James Marcum                                                                           *
 *  Class: CS 102                                                                                  *
 *  Time: 2 hours - floating point math added 30 minutes                                           *
 *                                                                                                 *
 *  Function: Seperates a given dollar amount into currency of lowest terms                        *
 *                                                                                                 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

//headers
#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
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
        //removed getters/setters for now
        //display values
        void display(){
            //attempts to do this as a map failed when I realized that maps are sorted alphabetically for effecient sorting
            //map <string, int>::iterator loop;
            //for (loop = dollars.begin(); loop != dollars.end() ; loop++)
            //   cout << setw(15) << loop -> first << setw(10) << loop -> second << endl;
            //cout << endl;
            //for (loop = cents.begin(); loop != cents.end() ; loop++)
            //    cout << setw(15) << loop -> first << setw(10) <<loop -> second << endl;
            int i = 0;
            cout << endl << setw(14) << "Denomination" <<setw(10) << "Quantity" << endl;
            cout.fill('-');
            cout << "  " << setw(22) << '-' << endl;
            cout.fill(' ');
            for (;i < 6; i++){
                cout << setw(14) << d_list[i] << setw(10) << dollars[i] << endl;
            }
            cout << endl;
            if (t_cents > 0)
              {for (i=0; i < 4; i++){
                  cout << setw(14) << c_list[i] << setw(10) << cents[i] << endl;
              }}
            cout << endl;
        }
        //cash construct prototype
        Cash(double);
};

//prototype
//double input prototype
void din(string, double *);

//***BEGIN MAIN***//

int main(){
    //init the input and prompt string
    double money=0;
    string prompt = "Enter a monetary value here (we accept change) : ";
    cout << "WELCOME TO MONEY'MATIC\n\n";
    //get cash - error checking input
    din(prompt ,&money);
    //make it bills
    Cash bills(money);
    //show it off
    bills.display();
    //Main in 7 lines
    return 0;
}

//***END MAIN***//

//Cash constructor function
//from variable($ Value), constructs bill denominations at lowest terms
Cash::Cash(double total){
    cash = total;
    //truncate change for dollars
    t_dollar = floor(cash);
    //change is remaining amount
    //.05 for floating point corrections on conversion
    t_cents = ((cash - t_dollar) * 100) + .05;
    //for debugging
    //cout << t_dollar << endl << cash << endl << t_cents << endl <<  (cash - t_dollar) << endl;
    if (t_dollar > 0){
    dollars[0] = t_dollar / 100;
    dollars[1] = (t_dollar % 100) / 50;
    dollars[2] = (t_dollar % 50) / 20;
    dollars[3] = (t_dollar % 50 % 20) / 10;
    dollars[4] = (t_dollar % 10) / 5;
    dollars[5] = (t_dollar % 5);}
    if (t_cents > 0){
    cents[0] = t_cents / 25;
    cents[1] = (t_cents % 25) / 10;
    cents[2] = (t_cents % 25 % 10) / 5;
    cents[3] = (t_cents % 25 % 10 % 5);}
}

//receives a double as input
void din(string phrase, double *num){
  cout << phrase;
  cin >> *num;
  while (cin.fail()){
    cout << "Invalid entry, try again: ";
    cin.clear();
    cin.ignore(256,'\n');
    cin >> *num;
    }
  }
