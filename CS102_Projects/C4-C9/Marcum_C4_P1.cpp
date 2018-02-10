/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                                         *
 *    Author: James Marcum                                                                 *
 *    Class:  CS102                                                                        *
 *                                                                                         *
 *    Function: Min/Max + Extras - takes in some numbers and determines which is larger    *
 *                                                                                         *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

//It's hard to figure out ways that 2 semi-random numbers would be related for no reason
//header
#include <iostream>
#include <iomanip>
#include <windows.h>
#include "marcum_header.h"
#include "marcum_header.cpp"

//namespace
using namespace std;

//prototype
unsigned long long fibber(int);

//class for XY pair
class XYRelation{
    private:
        double x, y;
    public:
        XYRelation(double num1,double num2){x = num1; y = num2;} //construct the relationship
        double getX(){return x;}//get x
        double getY(){return y;}//get y
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
    unsigned long long fibbed;
    display("Numerical Relationship Helper v0.2","Helping you understand the relationship between your numbers",11); //display
    cout << "Enter the first number: ";//get the first number - allows negative
    d_in(&number1);
    cout << "Enter the second number: ";//get the second number - allows negative
    d_in(&number2);

    XYRelation pair(number1,number2); //Make the pair
    cout << endl;
    if (pair.Distance() == 0){ //if same
        cout << "The numbers you entered are the same." << endl;
        cout << pair.Bigger() << " is the same as " << pair.Smaller();}
    else{
    cout << pair.Bigger() << " is the larger number." << endl; //Bigger
    cout << pair.Smaller() << " is the smaller number." << endl << endl; // Smaller
    cout << pair.Smaller() << " is " << pair.Distance() << " units away from " \
    << pair.Bigger() << " on a number line." << endl << endl;} //Distance
    //Why 1-93 inclusive? Because that's all my unsigned long long will hold
    //Also truncates for floats and goes with the floored int
    if (pair.getX() < 94 && pair.getX() > 0){
        fibbed = fibber(number1);
        cout << fibbed << " is #" << static_cast<int>(pair.getX()) << " in the fibonacci Sequence." << endl;}
    if (pair.getY() < 94 && pair.getY() > 0){
        fibbed = fibber(number2);
        cout << fibbed << " is #" << static_cast<int>(pair.getY()) << " in the fibonacci Sequence." << endl;}
    return 0;
}
//END MAIN

//did you know: unsigned long longs will only hold fibonacci numbers to 93?
//Also iterative instead of recursive, because fun
unsigned long long fibber(int number){
unsigned long long current = 1, previous = 0, next = 0;
int i = 2; //starts at 2 because 1 and 2 are 1
while (i <= number){//it mostly explains itself
    next = previous + current;
    previous = current;
    current = next;
    i++;}
    return current;
}
