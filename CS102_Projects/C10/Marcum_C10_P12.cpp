/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                                         *
 *    Author: James Marcum                                                                 *
 *    Class:  CS102                                                                        *
 *                                                                                         *
 *    Function: Verifies that a given password fits the minimum requirements               *
 *    Default: Length >=6, 1 Uppercase, 1 lowercase, 1 Digit                               *
 *                                                                                         *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
//oh and it saves your usernames and passwords for you
//busy week and this is the only one I had a chance to really work on
//file does not do well with outside edits
//unless they conform to the 'id username password' scheme with id incrementing properly

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

//really basic account holding class
//Class
class Account{
    private:
        int id;
        string username;
        string password;
    public:
        Account(){}
        Account(int acc_id, string user = "", string pass = "")
            {id = acc_id; username = user; password = pass;}
        void setUsername(string user){username = user;}
        void setPassword(string pass){password = pass;}
        void setID(int acc_id){id = acc_id;}
        string getUsername(){return username;}
        string getPassword(){return password;}
        int getID(){return id;}
};

//prototype
bool PasswordCheck(string password);
bool UsernameCheck(string username);
bool ExtentionCheck(string *file_name, string extension);


//BEGIN MAIN
int main(){
    string password = "", username = "", account_name = "notpasswords.pass";
    char yn_check[] = {'y','n'}, yesno;
    int account = 0, id = 0, save = 1; //number of accounts to add, and account id tracker
    fstream Vault; //filestream
    vector<Account> your_accounts;

    display("Super Secure Secret Password Safe vSSS+", "Keeping it secret, keeping it safe!",3);

    cout << "Please enter your vault name: "; //get the vault file name
    setcolor(14);
	getline(cin >> ws, account_name);
    setcolor();
    ExtentionCheck(&account_name, ".pass"); //if the user adds the patented .pass extension to the file

    Vault.open(account_name.c_str(),ios::in);
    if (!Vault.fail()){//if it didn't not open
        while(Vault >> id){ //load in the id, username, and passwords of your vault
            getline(Vault >> ws,username,' ');
            getline(Vault,password,'\n');
            //testing for read errors - just prints out what it read in
            //cout << id << " " << username << " " << password << endl;
            your_accounts.push_back(Account(id,username,password));
            id++; //Makes sure the id is always +1 of what was read in
            }
        setcolor(3);
        cout << "Vault Loaded" << endl; //Let them know it loaded correctly
        setcolor();
        Vault.close();
        Vault.open(account_name.c_str(),ios::out);
        //close and reopen to write in the file
    }
    else{
        cout << "That vault account doesn't exist, would you like to create it? (y/n): ";
        c_in(&yesno,yn_check,2);
        if (yesno == 'y') //open it in output mode to create and add to it
            Vault.open(account_name.c_str(),ios::out);
        else    //else don't save any data
            save = 0;}


    cout << endl << "How many accounts do you want to add to your safe: ";
    i_in(&account,1); //get account loop

    for (int i = 0; i < account; i++){
        do {
        cout << "Enter your username: ";
        setcolor(14);
        getline(cin >> ws, username);
        setcolor();
    } while(!UsernameCheck(username));
        do {
            cout << "Enter a password:    ";
            setcolor(0); //not as good as echo off, but it's fine for this
            getline(cin >> ws, password);
            setcolor();
        } while(!PasswordCheck(password));
        your_accounts.push_back(Account(id,username,password));
        cout << "Account Saved." << endl;
		id++;
    }
    if (save)
        for (int i = 0; i < id; i++){ //rewrite the accounts to the vault
            Vault << your_accounts[i].getID() << " " << your_accounts[i].getUsername() \
                  << " " << your_accounts[i].getPassword() << endl;
    }
    if (save)
        Vault.close();

    cout << "View your accounts? (y/n): ";
    yesno = ' '; //reset
    c_in(&yesno,yn_check,2);
    if (yesno == 'y'){
		setcolor(13);
        cout << endl << left << setw(4) << "ID" << setw(20) << "Account Name" << setw(20) << "Password" << endl;
		setcolor(11);
		for (int i = 0; i < 80; i++)
			cout << "_";
		setcolor();
		cout << endl;
        for (int i = 0; i < id; i++) //rewrite the accounts to the vault
            cout << setw(4) << your_accounts[i].getID() << setw(20) << your_accounts[i].getUsername() \
                 << setw(20) << your_accounts[i].getPassword() << endl;
    }
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

    //regular expressions do this better, but C++11
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
        //Have you ever seen a password that let's you have spaces? I haven't
        //And I needed it since I delimit by spaces within the file
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
    if (!dig_flag || !up_flag || !lower_flag || !len_flag || !ws_flag)
        return 0;
    return 1;
} //END PasswordCheck

//UsernameCheck
//Takes in username String
//returns 0 if it contains spaces
//else returns 1
//file doesn't parse usernames with spaces
bool UsernameCheck(string username){
int ws_flag = 1;
for (int i = 0; i < username.length(); i++){//check for ws
    if (username[i] == ' ')
        ws_flag = 0;
}
if (!ws_flag){
    cout << "Username cannot contain spaces." << endl;
    return 0;}
return 1;
} //END UsernameCheck


//ExtentionCheck
//takes in a file name string, and expected extension
//checks if file name has that extension, and adds it to it if it doesn't
bool ExtentionCheck(string *file_name, string extension){
	string::size_type extension_id = file_name->rfind('.'); //find last '.'
	string ext;
	if (extension_id != string::npos) { //if '.' existed in the filename
		ext = file_name->substr(file_name->find_last_of('.'));
		if (ext == extension)
			return 1;
        else { //just tack .pass to the end of it - good enough for now
               //terrible in the long run though
        		file_name->append(extension);
        		return 1;
			}
	}
	else { //no extension - tack it on
		file_name->append(extension);
		return 1;
	}
    return 0;
}
