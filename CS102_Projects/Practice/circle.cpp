/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * 
 * Author: James Marcum                                                    *
 * Class: CS 102                                                           *
 *                                                                         *
 * Function: Do circle math for a given number of circles                  *
 *                                                                         *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;

//Circle class
class Circle
{   
    //give access to radius
    friend bool comp(const Circle & a, const Circle & b);

    private:
    float radius = -1;
    //pi = 3.14159
    float PI = 3.14159;
    
    //setters - all convert to radius
    public:
    void setRadius(float r)
    {radius = r;}
    void setArea(float a)
    {radius = sqrt(a/PI);}
    void setDiameter(float d)
    {radius = d/2;}
    void setCircum(float c)
    {radius = c/(2*PI);}

    //calculate for returns - all convert from radius
    float calcArea()
    {return pow(radius,2)*PI;}
    float calcDiameter()
    {return radius*2;}
    float calcCircum()
    {return 2*PI*radius;}
    float getRadius()
    {return radius;}
};

//compare function
bool comp(const Circle & a, const Circle & b)
{
    return a.radius < b.radius;
}

//input check
float in_check(float *input){
    cin >> *input;
    while (cin.fail()){
        cout << "Invalid, try again" << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cin >> *input;
        }
    return *input;
}

//BEGIN MAIN

int main()
{
int size=1, i;
float inp;
char circle_type = 'z', cirsort = 'x';

//get number of circles to calculate
cout << "How many circles do you want to calculate? ";
cin >> size;

//From what information are we calculating
cout << "What would you like to calculate them from? (r = radius, d = diameter, a = area, c = circumference)";
//loop for valid input
while (true){
    //cin >> use_facet<ctype<char>>(loc).tolower(circle_type);
    cin >> circle_type;
    circle_type = tolower(circle_type);
    if (circle_type == 'r' ||circle_type == 'd' ||circle_type == 'a' ||circle_type == 'c' )
        break;
    else
        cout << "Invalid entry, try agian.\n";
}

//init circles based on input amount
Circle circles[size];

//loop get criteria for calculation for each circle instance
for (i = 0 ; i < size ; i++)
    {
    switch (circle_type){
        case 'r':   cout << "What is the radius of circle number " << i+1 << "? ";
                    in_check(&inp);
                    circles[i].setRadius(inp);
                    break;
        case 'd':   cout << "What is the diameter of circle number " << i+1 << "? ";
                    in_check(&inp);
                    circles[i].setDiameter(inp);
                    break;
        case 'a':   cout << "What is the area of circle number " << i+1 << "? ";
                    in_check(&inp);
                    circles[i].setArea(inp);
                    break;
        case 'c':   cout << "What is the circumference of circle number " << i+1 << "? ";
                    in_check(&inp);
                    circles[i].setCircum(inp);
                    break;
        }
    }

//Ask to sort
cout << "Would you like your circles sorted by size?(y/n) ";
while (true){
    cin >> cirsort;
    cirsort = tolower(cirsort);
    if (cirsort == 'y' || cirsort == 'n')  
        break;
    else
        cout << "Invalid";
}
if (cirsort = 'y')
//sort by size of radius test
    sort(circles, circles + size, comp);

//don't do this, can't sort class
//sort(circles, circles + size);

//Produce chart of circle data
cout << endl << endl;
cout << left << setw(15) << "Circle" << left << setw(15) << "Radius" << left << setw(15) << "Area" << left << setw(15) << "Diameter" << left << setw(15) << "Circumference" << endl;
for (i = 0 ; i < size ; i++)
    cout << left << setw(15) << i+1 << left << setw(15) << circles[i].getRadius() << left << setw(15) << circles[i].calcArea() << left << setw(15) << circles[i].calcDiameter() << left << setw(15) << circles[i].calcCircum() << endl;

//fin
return 0;
}

//END MAIN