#include "marcum_header.h"

//Takes in double variable
//chceks if input is a double, otherwise prompts user until double is entered
void d_in(double *input){
    std::cin >> *input;
    while (std::cin.fail()){
        std::cout << "Invalid, try again: ";
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cin >> *input;
        }
}

//Takes in char variable, array of characters to check for, and max array array_size
//checks until a character within the array is entered and places it within 'input'
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
