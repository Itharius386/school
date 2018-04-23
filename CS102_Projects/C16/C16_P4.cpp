/*
Write a function template that accepts an argument and returns its absolute value. The
absolute value of a number is its value with no sign. For example, the absolute value of -5 is 5
and the absolute value of 17.54 is 17.54. Test the template in a simple driver. For example,
prompt the user for an integer and call the function to return the absolute value and then print the
absolute value. Then prompt the user to enter a float and call the function to return the absolute
value and then print the absolute value.
*/
#include <iostream>
#include "marcum_header.h"
#include "marcum_header.cpp"
using namespace std;

template <class T>
T ABS_Val(T num) {
    if (num < 0)
        num *= -1;
    return num;
}

int main() {
    int int_num, loop = 1;
    double float_num;
    display("ABS TEST","", 10);
    cout << "How many integers would you like to enter: ";
    GetNum(loop,1);

    for (int i = 0; i < loop; i++) {
        cout << "Enter integer #" << i+1 << ": ";
        GetNum(int_num,0);
        cout << "The Absolute Value of integer #" << i+1 << " is ";
        setcolor(12);
        cout << ABS_Val(int_num) << endl << endl;
        setcolor();
    }

    cout << "How many floating point numbers would you like to enter: ";
    GetNum(loop,1);

    for (int i = 0; i < loop; i++) {
        cout << "Enter float #" << i+1 << ": ";
        GetNum(float_num,0);
        cout << "The Absolute Value of float #" << i+1 << " is ";
        setcolor(12);
        cout << ABS_Val(float_num) << endl << endl;
        setcolor();
    }

    return 0;
}
