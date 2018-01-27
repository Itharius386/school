/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                                         *
 *    Author: James Marcum                                                                 *
 *    Class:  CS102                                                                        *
 *                                                                                         *
 *    Function:   Test Average                                                             *
 *                Calculate test average for a given number of scores                      *
 *                                                                                         *
 *                                                                                         *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

//Headers
#include <iostream>
#include <iomanip>
#include <string>
//Namespace
using namespace std;

//Prototypes
void i_in(int*);
void d_in(double*);

//BEGIN MAIN
int main(){
  int max_num = 5, i =0;
  double average = 0, *test_score = new double[max_num]; //dynamically allocated array

  cout << "#=====================================================================================#" << endl \
       << "|Welcome to the Grade'o'matic 9000.1 - We calculate your average so you don't have to!|" << endl \
       << "#=====================================================================================#" << endl << endl;

  //get number of test scores to be entered and allocate memory for it
  cout << "How many test scores would you like to enter: ";
  i_in(&max_num);
  cout << endl;
  //Not sure if this causes a memory leak with the prior declaration
  test_score = new double[max_num];

  //loop get test values
  for (i=0; i < max_num; i++){
    cout << "Enter value for test #" << i+1 << ": ";
    d_in(&test_score[i]);
  }

  //calculate average
  for (i=0; i < max_num; i++){
    average += test_score[i];
  }
  average /= max_num;

  //tell average and grade average
  cout << "\nThe average test score is " << fixed << setprecision(1) << average << endl;
  cout << "The letter grade of the average is a(n) ";
  switch(static_cast<int>(average/10)){
    case(0):case(1):case(2):case(3):case(4):case(5):cout << 'F';break;
    case(6): cout << 'D'; break;
    case(7): cout << 'C'; break;
    case(8): cout << 'B'; break;
    default: cout << 'A';
  }
  cout << endl;

  return 0;
}

//END MAIN

//Gets an integer, if a float is entered it will truncate and clear the stream
void i_in(int *input){
  cin >> *input;
  while (cin.fail()){
    cout << "Invalid, try again: ";
    cin.clear();
    cin.ignore(256,'\n');
    cin >> *input;
    }
  cin.clear();
  cin.ignore(256,'\n');
}

//Prompts until a double is entered
void d_in(double *input){
  cin >> *input;
  while (cin.fail()){
    cout << "Invalid, try again: ";
    cin.clear();
    cin.ignore(256,'\n');
    cin >> *input;
    }
  cin.clear();
  cin.ignore(256,'\n');
}
