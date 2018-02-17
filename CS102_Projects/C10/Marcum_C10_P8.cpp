/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                                         *
 *    Author: James Marcum                                                                 *
 *    Class:  CS102                                                                        *
 *                                                                                         *
 *    Function: Sum the digits of a String                                                 *
 *                                                                                         *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
//left it pretty simple this time
//fun with vectors of strings

//header
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include "marcum_header.h"
#include "marcum_header.cpp"
//namespace
using namespace std;

//prototype
bool isNum(string num_str);
int SumString(string num_str);

//BEGIN MAIN
int main(){
    vector<string> numbers;
	string num_str = "";
    int repeat;

    display("Digit Summ-oner v9.9","Sum all the digits all the time!",2);

    cout << "How many sets of numbers would you like to enter: ";
    i_in(&repeat,1);

    for (int i = 0; i < repeat; i++){
        do { //while the string isn't only numbers
            cout << "Enter a set of numbers without spaces: ";
            setcolor(14);
            getline(cin >> ws,num_str);
            setcolor();
        } while (!isNum(num_str));
		numbers.push_back(num_str);

    //for (int i = 0; i < repeat; i++)
        sort(numbers[i].begin(),numbers[i].end()); //smallest to largest order

        cout << "Your numbers sorted are: ";
    	setcolor(10);
    	cout << numbers[i] << endl;
        setcolor();
    	cout << "The smallest number entered is: ";
    	setcolor(10);
    	cout << numbers[i][0] << endl; //index 0 == smallest
        setcolor();
    	cout << "The largest number entered is:  ";
    	setcolor(10);
    	cout << numbers[i][numbers[i].length()-1] << endl; //index at length - 1 == largest
        setcolor();
    	cout << "The sum of your digits is:      ";
    	setcolor(10);
    	cout << SumString(numbers[i]) << endl << endl;
        setcolor();
    }

	return 0;
}
//END MAIN


//isNum
//Input a string
//Returns 1 if it contains only numbers
//Else returns 0
bool isNum(string num_str){
    for (int i = 0; i < num_str.length(); i++){ //for the length of the string
        if (!isdigit(num_str[i])){ //if any character is not a digit, return 0
            cout << "Please enter only numbers." << endl;
            return 0;}
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
