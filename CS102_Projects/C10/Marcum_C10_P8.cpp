/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                                         *
 *    Author: James Marcum                                                                 *
 *    Class:  CS102                                                                        *
 *                                                                                         *
 *    Function: Sum the digits of a String                                                 *
 *                                                                                         *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

//header
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include "marcum_header.h"
#include "marcum_header.cpp"
//namespace
using namespace std;

//prototype
bool isNum(string num_str);
int SumString(string num_str);


//BEGIN MAIN
int main(){
    string numbers = " ";

    display("Digit Summ-oner v9.9","Sum all the digits all the time!",10);

    do { //while the string isn't only numbers
        cout << "Enter a set of numbers without spaces: ";
        setcolor(14);
        getline(cin >> ws,numbers);
        setcolor();
    } while (isNum(numbers));

    sort(numbers.begin(),numbers.end()); //smallest to largest order

    cout << endl << "Your numbers sorted are: ";
	setcolor(11);
	cout << numbers << endl << endl;
    setcolor();
	cout << "The smallest number entered is: ";
	setcolor(11);
	cout << numbers[0] << endl; //index 0 == smallest
    setcolor();
	cout << "The largest number entered is: ";
	setcolor(11);
	cout << numbers[numbers.length()-1] << endl; //index at length - 1 == largest
    setcolor();
	cout << endl << "The sum of your digits is: ";
	setcolor(11);
	cout << SumString(numbers) << endl;
    setcolor();
	return 0;
}
//END MAIN


//isNum
//Input a string
//Returns 1 if it contains only numbers
//Else returns 0
bool isNum(string num_str){
    for (int i = 0; i < num_str.length(); i++){ //for the length of the string
        if (!isdigit(num_str[i])) //if any character is not a digit, return 0
            cout << "Please enter only numbers." << endl;
            return 0;
    }
    return 1; //else it is all digits
} //isNum END


//SumString
//Input a string of numbers
//returns the sum of the digits as an int
int SumString(string num_str){
    int sum = 0;
    for (int i = 0; i < num_str.length(); i++)
        sum += (num_str[i] - '0'); //sum each 'character'
    return sum;
} //SumString END
