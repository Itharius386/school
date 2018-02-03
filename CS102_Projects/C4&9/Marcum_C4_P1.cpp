/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                                         *
 *    Author: James Marcum                                                                 *
 *    Class:  CS102                                                                        *
 *                                                                                         *
 *    Function: Min/Max + Extras - takes in some numbers and determines which is larger    *
 *                                                                                         *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

//header
#include <iostream>
#include <iomanip>
#include "marcum_header.h"
#include "marcum_header.cpp"

//namespace
using namespace std;

//prototype

//class for XY pair
class XYRelation{
    private:
        double x, y;
    public:
        XYRelation(double num1,double num2){x = num1; y = num2;} //construct the relationship
        double X(){return x;}//get x
        double Y(){return y;}//get y
        double Bigger(){ //get bigger
            if (x > y)
                return x;
            return y;}
        double Smaller(){ //get smaller
            if (x < y)
                return x;
            return y;}
        double Distance(){return Bigger() - Smaller();} //get Distance

};

//BEGIN MAIN
int main(){
    double number1, number2;
    display("Numerical Relationship Helper v0.2","Helping you understand the relationship between your numbers"); //display
    cout << "Enter the first number: ";//get the first number - allows negative
    d_in(&number1);
    cout << "Enter the second number: ";//get the second number - allows negative
    d_in(&number2);

    XYRelation pair(number1,number2); //Make the pair

    cout << fixed << setprecision(2); //limit to 2 decimal places for floats
    cout << pair.Bigger() << " is the larger number." << endl; //Bigger
    cout << pair.Smaller() << " is the smaller number." << endl; // Smaller
    cout << pair.Smaller() << " is " << pair.Distance() << " units away from " << pair.Bigger() << " on a number line." << endl; //Distance

    return 0;
}
//END MAIN
