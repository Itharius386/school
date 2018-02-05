/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                                         *
 *    Author: James Marcum                                                                 *
 *    Class:  CS102                                                                        *
 *                                                                                         *
 *    Function: Test Scores with Pointers & Sorting & Averages!                            *
 *                                                                                         *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

//Headers
#include <iostream>
#include <iomanip>
#include <string>
#include "marcum_header.h"
#include "marcum_header.cpp"
//Namespace
using namespace std;

//Prototypes
void mysort(double array, int max);

//Classes
class Test{
    friend double testavg(Test*,int);
    private:
        double grade;
        string student_name;
    public:
        Test(){grade = 0; student_name = " ";}
        Test(double num, string name = " "){grade = num; student_name = name;}
        double getGrade(){return grade;}
        char getLetter(){
            switch(static_cast<int>(grade)){
                case(0):case(1):case(2):case(3):case(4):case(5):return 'F';
                case(6): return 'D';
                case(7): return 'C';
                case(8): return 'B';
                default: return 'A';}}
        string getStudent(){return student_name;}
        void setGrade(double num){grade = num;}
        void setStudent(string name){student_name = name;}
};
//Test Average Prototype
double testavg(Test*, int);

//BEGIN MAIN
int main(){
int max_num = 5, i =0;
double average = 0, temp_test_num;
Test *test_score = NULL; //point to nothing

display("Welcome to the Grade'o'matic 789.6","We calculate your average so you don't have to!!");

//get number of test scores to be entered
cout << "How many test scores would you like to enter: ";
i_in(&max_num,1); //hey look pointers inside
cout << endl;
//allocate enough mamory for array of max_num of Test objects
test_score = new Test[max_num];

//loop get test values
for (i=0; i < max_num; i++){
    cout << "Enter value for test #" << i+1 << ": ";
    d_in(&temp_test_num,1);//pointer without subscripting, also the function doesn't use any subscripting either
    (test_score + i)->setGrade(temp_test_num);}// '->' to reference member without subscripting

//calculate average
average = testavg(test_score,max_num);

//tell average and grade average
cout << "\nThe average test score is " << fixed << setprecision(1) << average << endl;
cout << "The letter grade on average is a(n) ";
//cast the average as an int and divide by 10 to get an int to give it a grade
//grade scale of 90+ A, 80-89 B, 70-79 C, 60-69 D, 0-59 F
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

void mysort(double array, int max){

}

double testavg(Test *scores, int max){
    double average = 0;
    for (int i = 0; i < max; i++)
        average += (scores + i)->grade;
    average /= max;
    return average;
}
