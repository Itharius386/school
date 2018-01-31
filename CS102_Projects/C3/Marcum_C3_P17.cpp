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

//headers
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <windows.h>
//namespace
using namespace std;
//prototypes
void d_in(double*);
void c_in(char*,char*,int);
void s_i_in(int*, int*, int);
int tutor(int);
void display();

//BEGIN MAIN
int main(){
  //init variables
  int difficulty = 1, dif_check[] = {1,2,3,4};
  char repeat = 'y', re_check[] = {'y', 'n', 'd'};

  //seed rng
  srand(unsigned(time(0)));

  //loop
  while (repeat == 'y'){
  //display
    //display();
  //run tutor
    tutor(difficulty);
  //check loop
    cout << "Would you like to go again? (y/n or d to change difficulty): ";
    c_in(&repeat, re_check, 3);
    if (repeat == 'y')
      system("CLS");
    //difficulty settings
    else if (repeat == 'd'){
      cout << "Choose a difficulty (1 = Easy, 2 = Medium, 3 = Hard, 4 = Lunatic): ";
      //quick force check that the number entered is 1-4
      s_i_in(&difficulty,dif_check,4);
      //set back to repeat so it continues to loop
      repeat = 'y';
      //clear the screen
      system("CLS");}
    }

  return 0;
}

//END MAIN

//TUTORING - input a difficulty level
//difficulty is exponential
int tutor(int dif){
  //init num1/2, answer, and operation identifier
  //operation is between 1-3, at 1:+, 2:+ -, 3:+ - *
  int num1, num2, ops = rand()%dif + 1, remain = 0;
  double ans = 0;
  //set numbers = to a random number with respect to a power of the difficulty
  //Had to static_cast (dif) to get it to compile in Quincy, had to use 10.0 instead of 10 because of overload ambiguity
  //static_cast on the result because of modulus only working with int values
  num1 = rand()%static_cast<int>(pow(10.0,static_cast<int>(dif))) + 1;
  //added in checks for lunatic difficulty to help prevent E powered answers
  //added for division to prevent constant 0 answers with everthing in Remainder
  if (ops == 3 && dif == 4)
    num2 = rand()%1000 + 1;
  else if (ops == 4)
    num2 = rand()%500 + 1;
  else
    num2 = rand()%static_cast<int>(pow(10.0,static_cast<int>(dif))) + 1;
  //output num1
  cout<< setw(12) << num1 << endl;
  //determine which operation will take place, priint it and calculate the answer
  switch(ops){
    case(1): cout << " +"; ans = num1 + num2; break;
    case(2): cout << " -"; ans = num1 - num2; break;
    case(3): cout << " *"; ans = num1 * num2; break;
    case(4): cout << " /"; ans = num1 / num2; remain = num1%num2; break;}
  //output num2
  cout<< setw(10) << num2 << endl;
  //line
  cout<< "____________";
  //wait for enter
  cin.get();
  //show answer
  cout<< setw(12) << setprecision(10) << ans;
  if (ops == 4)
    cout << " R " << remain;
  cout << endl;
  //return success
  return 1;
}


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

//specific integer input
void s_i_in(int *input, int check[], int array_size){
    int i, b_check=0, temp;
    while (true){
        cin >> temp;
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
