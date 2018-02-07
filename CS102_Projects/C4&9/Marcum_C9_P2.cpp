/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                                         *
 *    Author: James Marcum                                                                 *
 *    Class:  CS102                                                                        *
 *                                                                                         *
 *    Function: Test Scores with Pointers & Sorting & Averages!                            *
 *                                                                                         *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

//similar to last week but I changed it to add the Test class, switched to pointer notation
//Also, Colors

//Headers
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include "marcum_header.h"
#include "marcum_header.cpp"
//Namespace
using namespace std;

//Prototypes

//Classes
class Test{
    friend double testavg(Test*,int); //needed to be friend with average to get access to grade variable
    friend bool compare(const Test &a, const Test &b); //needed for sorting
    private:
        double grade;
        string student_name;
    public:
        Test(){grade = 0; student_name = " ";}//default constructor
        Test(double num, string name = " "){grade = num; student_name = name;}//unused in this program
        double getGrade(){return grade;}//gets grade
        char getLetter(){//gets letter, also colored
            switch(static_cast<int>(grade)/10){
                case(0):case(1):case(2):case(3):case(4):case(5): setcolor(64); return 'F';
                case(6): setcolor(4); return 'D';
                case(7): setcolor(2); return 'C';
                case(8): setcolor(9); return 'B';
                default: setcolor(14); return 'A';}}
        string getStudent(){return student_name;}//gets student name
        void setGrade(double num){grade = num;}//set the grade
        void setStudent(string name){student_name = name;} //sets the name
};
//Test Average Prototype
double testavg(Test*, int);
//Basic Compare for sorting
bool compare(const Test &a, const Test &b);

//BEGIN MAIN
int main(){
int max_num = 5, i =0;
double average = 0, temp_test_num;
char named = 'n', named_check[]={'y','n'};//just needed for extras
string stu_name;
Test *test_score = NULL; //point to nothing with the main Test array pointer
//display
display("Welcome to the Grade'o'matic v9.86","We calculate your average so you don't have to!!",9);

//prompt to add student names
cout << "Would you like to add student names? (y/n): ";
c_in(&named,named_check,2); //okay so this still uses indexing, but it's only used for the extra name checking
//get number of test scores
cout << "How many test scores would you like to enter: ";
i_in(&max_num,1); //pointers inside
cout << endl;
//allocate enough mamory for array of max_num of Test objects
test_score = new Test[max_num];

//loop get test values
for (i=0; i < max_num; i++){
    if (named == 'y'){//if student name get
        cout << "Enter Student #" << i+1 <<"\'s Name: ";
        setcolor(15);
        getline(cin >> ws,stu_name);
        setcolor();
        (test_score + i)->setStudent(stu_name);}
    cout << "Enter value for test #" << i+1 << ": ";//get test score
    d_in(&temp_test_num,1);
    (test_score + i)->setGrade(temp_test_num);}// '->' to reference member without subscripting
	
sort(test_score,test_score + max_num, compare);//sort test scores

average = testavg(test_score,max_num);//calculate average

//table display
setcolor(10);
cout << endl << left << setw(6) << "Score" << setw(8) << "Grade";//column names
if (named == 'y')
    cout<< setw(26) << "Name";
cout << endl; // extra column name if students have names
setcolor(11);
for(int j=0;j<80;j++)
    cout << "_"; //line
cout << endl;


for(i=0; i < max_num; i++){//output scores loop
    setcolor(15);
    cout << setw(6) << (test_score+i)->getGrade(); //score
    cout << (test_score+i)->getLetter(); //letter grade
    setcolor();
    cout << setw(7) << " " <<setw(26) << (test_score+i)->getStudent() << endl; //get name if students have names
}
setcolor();
//tell average and grade average
cout << "\nThe average test score is ";
setcolor(15);
cout << fixed << setprecision(1) << average << endl;
setcolor();
cout << "The average letter grade is a(n) ";
setcolor(12);
//cast the average as an int and divide by 10 to get an int to give it a grade
//grade scale of 90+ A, 80-89 B, 70-79 C, 60-69 D, 0-59 F
switch(static_cast<int>(average/10)){
    case(0):case(1):case(2):case(3):case(4):case(5): setcolor(64); cout << 'F'; break;
    case(6): setcolor(4); cout << 'D'; break;
    case(7): setcolor(2); cout << 'C'; break;
    case(8): setcolor(9); cout << 'B'; break;
    default: setcolor(14); cout << 'A';}
setcolor();
cout << endl;

return 0;
}
//END MAIN

//Just your average function
double testavg(Test *scores, int max){
    double average = 0;
    for (int i = 0; i < max; i++)//loop sum grades
        average += (scores + i)->grade;
    average /= max;//divide by max
    return average;
}

//compare function for sorting the Test class
bool compare(const Test &a, const Test &b)
{
    return a.grade < b.grade;//flipping the '<' to '>' will change from ascending to descending
}

