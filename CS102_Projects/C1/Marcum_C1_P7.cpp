/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                                                 *
 *  Name: Cash Counter                                                                             *
 *  Author: James Marcum                                                                           *
 *  Class: CS 102                                                                                  *
 *                                                                                                 *
 *  Function: Seperates a given dollar amount into currency of lowest terms                        *
 *                                                                                                 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

//headers
#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
//so you can't initialize an array within a class unless you are in C++11 or higher, but vectors work allegedly
#include <vector>
//namespace
using namespace std;

//classes
//This is overkill for the scope of the program, but it seemed like fun
class Cash{
    private:
        //dollar and cents container
        vector<int> dollars, cents;
        //total cash handler
        double cash;
        //total for dollar and total for cents
        int t_dollar, t_cents;
        //bill name vector to match dollar and cents
        static string d_list[], c_list[];

    public:
        //display values
        void display(){
            cout << endl << setw(14) << "Denomination" <<setw(10) << "Quantity" << endl;
            cout.fill('-');
            cout << "  " << setw(22) << '-' << endl;
            cout.fill(' ');
            if (t_dollar > 0){
              for (int i = 0; i < dollars.size(); i++){
                  cout << setw(14) << d_list[i] << setw(10) << dollars[i] << endl;}}
            cout << endl;
            if (t_cents > 0){
              for (int i = 0; i < cents.size(); i ++){
                  cout << setw(14) << c_list[i] << setw(10) << cents[i] << endl;
              }}
            cout << endl;
        }
        //cash construct prototype
        Cash(double);
};

string Cash::d_list[] = {"Hundreds","Fifties","Twenties","Tens","Fives","Ones"}
       ,Cash::c_list[] = {"Quaters", "Dimes" , "Nickles", "Pennies"};

//prototype
void d_in(string, double *);

//***BEGIN MAIN***//
int main(){
    //init the input and prompt string
    double money=0;
    string prompt = "Enter a monetary value here (we accept change): ";
    cout << "WELCOME TO MONEY'MATIC\n\n";
    //get cash
    d_in(prompt ,&money);
    //make it bills
    Cash bills(money);
    //show it off
    bills.display();
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
		dollars.push_back(t_dollar / 100);
		dollars.push_back((t_dollar % 100) / 50);
		dollars.push_back((t_dollar % 50) / 20);
		dollars.push_back((t_dollar % 50 % 20) / 10);
		dollars.push_back((t_dollar % 10) / 5);
		dollars.push_back((t_dollar % 5));}
    if (t_cents > 0){
		cents.push_back(t_cents / 25);
		cents.push_back((t_cents % 25) / 10);
		cents.push_back((t_cents % 25 % 10) / 5);
		cents.push_back((t_cents % 25 % 10 % 5));}
}

//receives a double as input
void d_in(string phrase, double *num){
  cout << phrase;
  cin >> *num;
  while (cin.fail()){
    cout << "Invalid entry, try again: ";
    cin.clear();
    cin.ignore(256,'\n');
    cin >> *num;
    }
  }
