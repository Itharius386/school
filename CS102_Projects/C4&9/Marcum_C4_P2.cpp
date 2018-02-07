/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                                         *
 *    Author: James Marcum                                                                 *
 *    Class:  CS102                                                                        *
 *                                                                                         *
 *    Function: Roman Numeral Convertion WITH INPUT VALIDATION! Subtractive Notation Used  *
 *                                                                                         *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

//getting into the high 1000's is hard because then they switch to a notation with lines above the letters
//so I stopped at 1000
//header
#include <iostream>
#include "marcum_header.h"
#include "marcum_header.cpp"
#include <string>
#include <sstream>

//namespace
using namespace std;

//prototype

//class
class Roman{
    private:
        int number;
        stringstream roman;
    public:
        Roman(){}
        Roman(int num){number = num;} //construct
        int getNum(){return number;} //get
        void setNum(int num){number = num;} //set
        string getRoman(){
            if (number == 1000){//if it's 1000 set as M and return
                roman << "M";
                return roman.str();}
            if (number / 100 != 0){//get the 100's place if needed
                switch(number/100){
                    case(1): roman << "C"; break;
                    case(2): roman << "CC"; break;
                    case(3): roman << "CCC"; break;
                    case(4): roman << "CD"; break;
                    case(5): roman << "D"; break;
                    case(6): roman << "DC"; break;
                    case(7): roman << "DCC"; break;
                    case(8): roman << "DCCC"; break;
                    case(9): roman << "CM"; break;}}
            if (number%100/10 != 0){//get 10's place if needed
                switch(number%100/10){
                    case(1): roman << "X"; break;
                    case(2): roman << "XX"; break;
                    case(3): roman << "XXX"; break;
                    case(4): roman << "XL"; break;
                    case(5): roman << "L"; break;
                    case(6): roman << "LX"; break;
                    case(7): roman << "LXX"; break;
                    case(8): roman << "LXXX"; break;
                    case(9): roman << "XC"; break;}}
            if (number%10 != 0)//get the one's place
                switch(number%10){ //that single switch the project wanted all along
                    case(1): roman << "I"; break;
                    case(2): roman << "II"; break;
                    case(3): roman << "III"; break;
                    case(4): roman << "IV"; break;
                    case(5): roman << "V"; break;
                    case(6): roman << "VI"; break;
                    case(7): roman << "VII"; break;
                    case(8): roman << "VIII"; break;
                    case(9): roman << "IX"; break;}
            return roman.str();}
};


//BEGIN MAIN
int main(){
    int number,loop=0,i=0;
    Roman *roman_ptr = NULL;

    display("Integer to Roman Numeral Convertion vIV","Keep it below 1,000 Edition",8); //display
    cout <<"How many integers do you want to convert: ";
    i_in(&loop,1);
    roman_ptr = new Roman[loop];
    do{
        cout << "Enter an integer between 1-1000 to convert: "; //prompt
        do{
            i_in(&number,1); // positives only
            if (number < 1 || number > 1000) //if not in range, prompt and loop
                cout << "\aNumber must be between 1-1000, try again: ";
        } while(number < 1 || number > 1000);
        (roman_ptr+i)->setNum(number);
        loop--;
        i++;
    }while(loop);

    for (loop = 0; loop < i; loop++){
    setcolor(14);
    cout << (roman_ptr+loop)->getNum();
    setcolor();
    cout << " is ";
    setcolor(12);
    cout << (roman_ptr+loop)->getRoman();
    setcolor();
    cout << " in Roman Numeral form." << endl;}
    return 0;
}
//END MAIN
