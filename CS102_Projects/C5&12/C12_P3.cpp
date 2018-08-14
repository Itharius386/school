/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                                         *
 *    Author: James Marcum                                                                 *
 *    Class:  CS102                                                                        *
 *                                                                                         *
 *    Function: Tell a joke, Tell a punchline                                              *
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
fstream joke, punchline;
string input, file = "joke.txt", file2 = "punchline.txt";
char yn = 'z', check[] = {'y','n'};

joke.open(file.c_str(), ios::in);
if (joke.fail()) {
    cout << "File Not Found" << endl << "Would you like to enter a file name? (y/n): ";
    c_in(&yn,check,2);
    if (yn == 'y') {
        int attempt = 3;
        do{
            cout << endl << "Enter name of file to be opened (include .txt): ";
            getline(cin, file);
            joke.open(file.c_str(),ios::in);
            if (joke.fail()) {
                attempt--;
                cout << "File Not Found - Try again. " << attempt << " attempts remaining" << endl;
            }
        if (attempt == 0)
            break;
        } while(joke.fail());
    }
    else if (yn == 'n' || joke.fail()) {
        cout << "Exiting Program";
        return 0;
    }
}

while (joke) {
    getline(joke, input);
    cout << input << endl;
}

punchline.open(file2.c_str(), ios::in | ios::ate);
if (punchline.fail()) {
    cout << "File Not Found" << endl << "Would you like to enter a file name? (y/n): ";
    c_in(&yn,check,2);
    if (yn == 'y') {
        int attempt = 3;
        do{
            cout << endl << "Enter name of file to be opened (include .txt): ";
            getline(cin, file);
            punchline.open(file.c_str(),ios::in | ios::ate);
            if (punchline.fail()) {
                attempt--;
                cout << "File Not Found - Try again. " << attempt << " attempts remaining" << endl;
            }
        if (attempt == 0)
            break;
        } while(punchline.fail());
    }
    else if (yn == 'n' || punchline.fail()) {
        cout << "Exiting Program";
        return 0;
    }
}
char ch = 'z';
while (punchline && ch != '\n') {
    for(long i = 1; i < 10000; i++) {
        punchline.seekg(-i,ios::end);
        punchline.get(ch);
        if (ch == '\n')
            break;
    }
}
    getline(punchline, input);
    cout << input << endl << endl;


return 0;
}
