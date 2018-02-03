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
        string roman;
    public:
        Roman(int num){number = num;} //construct
        int getNum(){return number;} //get
        void setNum(int num){number = num;} //set
        string getRoman(){
            if (number <= 10)
                switch(number){ //that switch the project wanted all along
                    case(1): roman = "I"; break;
                    case(2): roman = "II"; break;
                    case(3): roman = "III"; break;
                    case(4): roman = "IV"; break;
                    case(5): roman = "V"; break;
                    case(6): roman = "VI"; break;
                    case(7): roman = "VII"; break;
                    case(8): roman = "VIII"; break;
                    case(9): roman = "IX"; break;
                    case(10): roman = "X"; break;}
            return roman;}
};

//BEGIN MAIN
int main(){
    int number=0; //number to be converted
    display("Integer to Roman Numeral Convertion vII","Keep it below 3,000"); //display
    cout << "Enter an integer to convert: "; //prompt
    do{
        i_in(&number,1); // positives only
        if (number < 1 || number > 3000) //if not in range, prompt and loop
            cout << "Number must be between 1-3000, try again: ";
    } while(number < 1 || number > 3000);
    Roman mynum(number);
    cout << "Your number is " << mynum.getRoman() << " in Roman Numeral form.";

    return 0;
}
//END MAIN
