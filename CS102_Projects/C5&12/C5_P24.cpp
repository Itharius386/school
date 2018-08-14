/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                                         *
 *    Author: James Marcum                                                                 *
 *    Class:  CS102                                                                        *
 *                                                                                         *
 *    Function: Reads in the numbers of a file and produces the sum, count, and Average    *
 *                                                                                         *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "marcum_header.h"
#include "marcum_header.cpp"
using namespace std;

int main() {
fstream num_file;
string file = "Random.txt";
double sum = 0, average = 0, input;
int count = 0;
char yn = 'z', check[] = {'y','n'};

num_file.open(file.c_str(),ios::in);
if (num_file.fail()) {
    cout << "File Not Found" << endl << "Would you like to enter a file name? (y/n): ";
    c_in(&yn,check,2);
    if (yn == 'y') {
        int attempt = 3;
        do{
            cout << endl << "Enter name of file to be opened (include .txt): ";
            getline(cin, file);
            num_file.open(file.c_str(),ios::in);
            if (num_file.fail()) {
                attempt--;
                cout << "File Not Found - Try again. " << attempt << " attempts remaining" << endl;
            }
        if (attempt == 0)
            break;
        } while(num_file.fail());
    }
    else if (yn == 'n' || num_file.fail()) {
        cout << "Exiting Program";
        return 0;
    }
}
    while(num_file >> input){
        sum += input;
        count++;
    }
    num_file.close();
    average = sum / count;
    cout << "Sum of numbers in file: " << sum << endl;
    cout << "Average of numbers in file: " << average << endl;
    cout << "Count of numbers in file: " << count << endl;

return 0;
}
