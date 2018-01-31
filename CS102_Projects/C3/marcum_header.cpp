#include "marcum_header.h"
#include <iostream>
using namespace std;
//See header for notes on how each function works

void d_in(double *input, int pos){
  std::cin >> *input;
  while (std::cin.fail()){
    std::cout << "Invalid, try again: ";
    std::cin.clear();
    std::cin.ignore(256,'\n');
    std::cin >> *input;
    }
  if (pos == 1){
    while (*input < 0){
      cout << "Positive Values only: ";
      d_in(input);}}
}


void c_in(char *input, char check[], int array_size){
    int i, b_check=0;
    char temp;
    while (true){
        std::cin >> temp;
        temp = tolower(temp);
        for (i=0;i<array_size;i++){
          if (temp == check[i]){
            std::cin.clear();
            std::cin.ignore(256,'\n');
            b_check=1;
            break;}}
      if (b_check)
        break;
      else{
          std::cin.clear();
          std::cin.ignore(256,'\n');
          std::cout << "Invalid entry, try agian: ";}
    }
    *input = temp;
}


void i_in(int *input, int pos){
  cin >> *input;
  while (cin.fail()){
    cout << "Invalid, try again: ";
    cin.clear();
    cin.ignore(256,'\n');
    cin >> *input;
    }
  cin.clear();
  cin.ignore(256,'\n');
  if (pos == 1){
    while (*input < 0){
      cout << "Positive Values only: ";
      i_in(input);}}
}


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
