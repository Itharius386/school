/*Password Verifier
Imagine you are developing a software package that requires users to enter their own
passwords. Your software requires that users’ passwords meet the following criteria:
• The password should be at least six characters long.
• The password should contain at least one uppercase and at least one lowercase letter.
• The password should have at least one digit.
Write a program that asks for a password and then verifies that it meets the stated
criteria. If it doesn’t, the program should display a message telling the user why.*/

//headers
#include <iostream>
#include <iomanip>
#include <string>

//namespace
using namespace std;

//prototype
bool PasswordCheck(string password);

//BEGIN MAIN
int main(){
    string password = "";
    do {
        cout << "Enter a password: ";
        getline(cin, password);
    } while(!PasswordCheck(password));
    cout << "Password Saved.";
    return 0;
}
//END MAIN

bool PasswordCheck(string password){
    int dig_flag = 0, up_flag = 0, lower_flag = 0; //flags for checking a digit, uppercase, and lowercase

    if (password.length() < 6){ // if password too short
        cout << "Password too short. Must be at least 6 characters." << endl;
        return 0;
    }
    for (int i = 0; i < password.length(); i++){//check for each flag type
        if (isdigit(password[i]))
            dig_flag = 1;
        if (islower(password[i]))
            lower_flag = 1;
        if (isupper(password[i]))
            up_flag = 1;
    }
    if (!dig_flag) //if they didn't do something right
        cout << "Password must contain a number." << endl;
    if (!up_flag)
        cout << "Password must contain at least 1 uppercase letter." << endl;
    if (!lower_flag)
        cout << "Password must contain at least 1 lowercase letter." << endl;
    if (!dig_flag || !up_flag || !lower_flag)//if anything wrong, return 0 to redo
        return 0;
    return 1;
}
