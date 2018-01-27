/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                                         *
 *    Author: James Marcum                                                                 *
 *    Class:  CS102                                                                        *
 *                                                                                         *
 *    Function:   Math tutor program.                                                      *
 *                Generates random numbers and operations for the user to solve            *
 *                                                                                         *
 *                                                                                         *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <windows.h>

using namespace std;

void d_in(double*);
void c_in(char*,char*,int);

//BEGIN MAIN

int main(){
  int num1, num2, answer, difficulty = 0;
  char repeat = 'y', re_check[] = {'y', 'n'};

  srand(unsigned(time(0)));

  while (repeat == 'y'){
    num1 = rand()%10 + 1;
    num2 = rand()%10 + 1;

    cout << " " << num1;

    cout << "Would you like to go again? (y/n): ";
    c_in(&repeat, re_check, 2);
  }

  return 0;
}

//END MAIN


//error checking input for doubles
void d_in(double *input){
    cin >> *input;
    while (cin.fail()){
        cout << "Invalid, try again: ";
        cin.clear();
        cin.ignore(256,'\n');
        cin >> *input;
        }
}

//error check and input check characters, pass in array with characters to check input against + array size
void c_in(char *input, char check[], int array_size){
    int i, b_check=0;
    char temp;
    while (true){
        cin >> temp;
        temp = tolower(temp);
        for (i=0;i<array_size;i++){
          if (temp == check[i]){
            cin.clear();
            cin.ignore(256,'\n');
            b_check=1;
            break;}}
      if (b_check)
        break;
      else{
          cin.clear();
          cin.ignore(256,'\n');
          cout << "Invalid entry, try agian: ";}
    }
    *input = temp;
}
