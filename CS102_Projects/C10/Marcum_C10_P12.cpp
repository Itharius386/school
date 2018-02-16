/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                                         *
 *    Author: James Marcum                                                                 *
 *    Class:  CS102                                                                        *
 *                                                                                         *
 *    Function: Verifies that a given password fits the minimum requirements               *
 *    Default: Length >=6, 1 Uppercase, 1 lowercase, 1 Digit                               *
 *                                                                                         *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

//headers
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include "marcum_header.h"
#include "marcum_header.cpp"
//namespace
using namespace std;

//Class
class Account{
    private:
        string username;
        string password;
    public:
        Account(){}
        Account(string user, string pass){username = user; password = pass;}
        void setUsername(string user){username = user;}
        void setPassword(string pass){password = pass;}
        string getUsername(){return username;}
        string getPassword(){return password;}
};

//prototype
bool PasswordCheck(string password);

//BEGIN MAIN
int main(){
    string password = "", username = "";
    int account = 0; //number of accounts to add
    fstream Vault;
    vector<Account> your_accounts;

    Vault.open("notpasswords.txt",ios::in|ios::app);

    display("Super Secure Secret Password Safe vSSSS+", "Keeping it secret, keeping it safe");

    cout << "How many accounts do you want to add to your safe: ";
    i_in(&account);

    for (int i = 0; i < account; i++){
        cout << "Enter your username: ";
        setcolor(14);
        getline(cin >> ws, username);
        setcolor();
        do {
            cout << "Enter a password:    ";
            setcolor(0); //not as good as echo off, but it's fine for this
            getline(cin >> ws, password);
            setcolor();
        } while(!PasswordCheck(password));
        Vault << username << " " << password << endl;
        cout << "Account Saved." << endl;
    }
    Vault.close();
    return 0;
}
//END MAIN

//PasswordCheck
//Takes in a String
//returns 0 if it does not meet requirements
//returns 1 otherwise
//defaults to length >= 6, at least 1 number, 1 lowercase, and 1 uppercase
bool PasswordCheck(string password){
    int dig_flag = 0, up_flag = 0, lower_flag = 0, len_flag = 0, ws_flag = 1;
    //flags for checking a digit, uppercase, lowercase, length, and whitespace

    if (password.length() >= 6) // length check
        len_flag = 1;
    for (int i = 0; i < password.length(); i++){//check for each flag type
        if (isdigit(password[i]))
            dig_flag = 1;
        if (islower(password[i]))
            lower_flag = 1;
        if (isupper(password[i]))
            up_flag = 1;
        if (password[i] == ' ')
            ws_flag = 0;
    }
    if (!dig_flag) //if they didn't do something right
        cout << "Password must contain a number." << endl;
    if (!up_flag)
        cout << "Password must contain at least 1 uppercase letter." << endl;
    if (!lower_flag)
        cout << "Password must contain at least 1 lowercase letter." << endl;
    if (!len_flag)
        cout << "Password too short. Must be at least 6 characters." << endl;
    if (!ws_flag)
        cout << "Password cannot contain spaces." << endl;
    if (!dig_flag || !up_flag || !lower_flag || !len_flag || !ws_flag)//if anything wrong, return 0 to redo
        return 0;
    return 1;
}
