/*Sum of Digits in a String
Write a program that asks the user to enter a series of single digit numbers with nothing
separating them. Read the input as a C-string or a string object. The program should
display the sum of all the single-digit numbers in the string. For example, if the user
enters 2514, the program should display 12, which is the sum of 2, 5, 1, and 4. The
program should also display the highest and lowest digits in the string.*/

/**/

//header
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
//namespace
using namespace std;

//prototype
bool isNum(string num_str);
int SumString(string num_str);

//BEGIN MAIN
int main(){
    string numbers = " ";

    while (!isNum(numbers)) { //while the string isn't only numbers
        cout << "Enter a set of numbers without spaces: ";
        getline(cin,numbers);
    }
    sort(numbers.begin(),numbers.end()); //smallest to largest order

    cout << "Your numbers sorted are: " << numbers << endl;
    cout << "The smallest number entered is: " << numbers[0] << endl; //index 0 == smallest
    cout << "The largest number entered is: " << numbers[numbers.length()-1] << endl; //index at length - 1 == largest
    cout << "The sum of your digits is: " << SumString(numbers) << endl;
    return 0;
}
//END MAIN

//isNum
//takes in a string and checks if it contains only numbers
bool isNum(string num_str){
    for (int i = 0; i < num_str.length(); i++){ //for the length of the string
        if (!isdigit(num_str[i])) //if any character is not a digit, return 0
            return 0;
    }
    return 1; //else it is all digits
}

//takes in a string of digits and sums the digits
int SumString(string num_str){
    int sum = 0;
    for (int i = 0; i < num_str.length(); i++)
        sum += (num_str[i] - '0'); //sum each 'character'
    return sum;
}
