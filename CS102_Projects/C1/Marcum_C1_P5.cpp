/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * b bh * * * * * * * * * * * * * * *
 *                                                                                                 *
 *  Name: Poly Solver                                                                              *
 *  Author: James Marcum                                                                           *
 *  Class: CS 102                                                                                  *
 *                                                                                                 *
 *  Function: Solve polynomials                                                                    *
 *                                                                                                 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

// **warning** did not do much checking for user input errors

//headers
#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
//namespace
using namespace std;

//class
class PolySolve{
    private:
        //degree of polynomial, max degree
        int degree;
        //coeffient array
        double coeff[64];
    public:
        //set total degree of polynomial
        void setDegree(int poly_power)
        {degree = poly_power;}
        //set coefficent at given power of x
        void set1Coeff(double value, int x)
        {coeff[x] = value;}

        //returns f(x) as a string
        string getFunction(){
        stringstream ss;
        int i=0;
        ss << "f(x) = ";
        for (i=degree;i>=0;i--){
                if (coeff[i] > 1 || coeff[i] < 0 || (i == 0 && coeff[i] != 0))
                    {ss << coeff[i];}
                if (i != 0 && coeff[i] != 0)
                    {ss << 'x';
                    if (i>1)
                        ss << '^' << i;
                    if ( i > 0)
                        ss << " + ";}
        }
        string f_x = ss.str();
        return f_x;}

        //returns degree of polynomial
        int getDegree()
        {return degree;}
        //return coefficent at given power
        double getCoeff( int power)
        {return coeff[power];}

        //solve Polynomial for x
        double Solve(double x){
            int i;
            double result = 0;
            for (i = degree; i > 0 ; i--){
                result += (pow(x,i) * coeff[i]);}
                result += coeff[0];
            return result;}
};

//prototypes
void c_in(char*,char*,int);
void d_in(double*);

//BEGIN MAIN
int main(){
    int poly_degree = 1, i = 0;
    double coeffient = 0, x=0;
    char input, in_check[] = {'t','s'};
    PolySolve test, user;

    cout << "\nWelcome to POLY SOLVER 9000!";
    cout << "\n\nYou can run our test function by entering 't' now or enter 's' to solve your own polynomial: ";

    while (true){
        c_in(&input,in_check,2);
        //if test function
        if (tolower(input) == 't'){
        //test polynomial (the textbook's given equation)
        //not a good way to do this I think
            test.setDegree(5);
            test.set1Coeff(3,5);
            test.set1Coeff(2,4);
            test.set1Coeff(-5,3);
            test.set1Coeff(-1,2);
            test.set1Coeff(7,1);
            test.set1Coeff(-6,0);
        //show function
            cout << test.getFunction();
            cout << endl << "Enter a value for x: ";
            d_in(&x);
            cout << "f(" << x << ") = " << test.Solve(x);
            break;}
        //else set your own
        else {
            cout << "\nWhat is the degree of your polynomial? ";
            cin >> poly_degree;
            user.setDegree(poly_degree);
            for (i = poly_degree; i >= 0; i--){
                cout << "What is the coefficent of x^" << i <<": ";
                cin >> coeffient;
                user.set1Coeff(coeffient,i);}
            cout << "\nYour function is:\n";
            cout << user.getFunction();
            cout << "\n\nEnter a value for x: ";
            d_in(&x);
            cout << "f(" << x << ") = " << user.Solve(x);
            break;}}
    return 0;
}
//END main

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

void d_in(double *input){
    cin >> *input;
    while (cin.fail()){
        cout << "Invalid, try again: ";
        cin.clear();
        cin.ignore(256,'\n');
        cin >> *input;
        }
}
