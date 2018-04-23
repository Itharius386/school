/*
Modify Programming Project #1 from Chapter 15 (Employee and Production Worker) so
that they throw exceptions whenever any of the following occurs:
The Employee Class should throw an exception named InvalidEmployeeNumber when it
receives an employee number less than 0 or greater than 999.
The ProductionWorker Class should throw and exception named InvalidShift when it
receives and invalid shift.
The ProductionWorker Class should throw and exception named InvalidPayRate when it
receives a negative number for the hourly pay rate.

Write a program that will prompt the user for this information.
*/
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                             *
 * Author: James Marcum                                                        *
 * Class: CS 102                                                               *
 *                                                                             *
 * Function: Employees - Helps keep track of your production workers           *
 *                                                                             *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <iostream>
#include <iomanip>
#include <map>
#include "marcum_header.h"
#include "marcum_header.cpp"
#include "Employee.h"

//namespace
using namespace std;

//Prototypes
int MainLoop();

int main() {
    int selection = -1;
    ProductionWorker my_only_employee(1,1,"Bill",1,1900,1,1);

    while(selection = MainLoop()){
        if (selection == 1) {
            string name;
            int number;
            int year;
            int month;
            int day;
            int shift;
            double rate;
            cout << endl << "What is the employee's name: ";
            setcolor(14);
            getline(cin, name);
            setcolor();
            cout << "What is the employee number: ";
            GetNum(number);
            cout << "Employment year: ";
            GetNum(year);
            cout << "Employment month: ";
            GetNumInRange(month,12,1);
            cout << "Employment day: ";
            GetNumInRange(day,31,1);
            cout << "Day(1) or Night(2) shift: ";
            GetNumInRange(shift,2,1);
            cout << "What is the pay rate: ";
            GetNum(rate);
            ProductionWorker temp(shift, rate, name, number, year, month, day);
            my_only_employee = temp;
        } //selection 1
        if (selection == 2) {
            setcolor(12);
            cout << endl << "Name      Number    Shift     Rate      Start-Date" << endl;
            setcolor(10);
            cout << left << setw(10) << my_only_employee.getName();
            cout << setw(10) << my_only_employee.getNumber();
            cout << setw(10) << my_only_employee.getShift();
            cout << fixed << setprecision(2) << setw(10) << my_only_employee.getRate();
            cout << setw(10) << my_only_employee.getHireDate();
            setcolor();
            getchar();
        } //selection 2
    }
    return 0;
}
//END MAIN


//==============================================================================
int MainLoop() {
char option; //options[] = {'a','b','c'};
string options[] = {"Create Production Worker","View Worker","Exit"};
system("CLS");
display("Worker Automation Station v1.01","You only get the one worker, though",10);
option = Menu(options,3);
if (option == 'a')
    return 1;
if (option == 'b')
    return 2;
if (option == 'c')
    return 0;
}
//MainLoop
//==============================================================================
