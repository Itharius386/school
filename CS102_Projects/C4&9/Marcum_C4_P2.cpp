/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                                         *
 *    Author: James Marcum                                                                 *
 *    Class:  CS102                                                                        *
 *                                                                                         *
 *    Function: Roman Numeral Convertion WITH INPUT VALIDATION! Subtractive Notation Used  *
 *                                                                                         *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

//header
#include <iostream>
#include <iomanip>
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
            if (number >= 1000){//if it's 1000 set as M and return
                switch(number/1000){
                    case(1): roman << "M"; break;
                    case(2): roman << "MM"; break;
                    case(3): roman << "MMM"; break;
                    case(4): roman << "MMMM"; break;}}
            if (number/100 != 0){//get the 100's place if needed
                switch(number/100%10){
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

    display("Integer to Roman Numeral Convertion vIV","Keep it below 5,000 Edition",8); //display

	cout <<"How many integers do you want to convert: ";//prompt
    i_in(&loop,1);
    roman_ptr = new Roman[loop];//it's them pointer things I've been hearing about

	do{
        cout << "Enter an integer between 1-4999 to convert: "; //prompt
        do{
            i_in(&number,1); // positives only
            if (number < 1 || number > 4999) //if not in range, prompt and loop
                cout << "\aNumber must be between 1-4999, try again: ";
        } while(number < 1 || number > 4999);
        (roman_ptr+i)->setNum(number);//set that array object to the number
        loop--;//decrement
        i++;//increment
    }while(loop);
	cout << endl;
    for (loop = 0; loop < i; loop++){//now in reverse
    setcolor(14);
    cout << setw(3) << (roman_ptr+loop)->getNum();
    setcolor();
    cout << " is ";
    setcolor(12);
    cout << (roman_ptr+loop)->getRoman();
    setcolor();
    cout << " in Roman Numeral form." << endl;}
    return 0;
}
//END MAIN
