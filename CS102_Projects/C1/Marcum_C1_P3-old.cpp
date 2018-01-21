/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                                                 *
 *  Author: James Marcum                                                                           *
 *  Class: CS 102                                                                                  *
 *  Time: 2 Hours                                                                                  *
 *                                                                                                 *
 *  Function: Compute sphere data based on given parameter                                         *
 *                                                                                                 *
 *  diameter    =   2* radius                                                                      *
 *  volume      =   4/3 * PI * radius^3                                                            *
 *  area        =   4 * PI * radius^2                                                              *
 *                                                                                                 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

//included headers
#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
//standard namespace
using namespace std;


//Sphere object class
class Sphere
{
private:
    double radius = -1;
    double PI = 3.14159;
public:

    Sphere(double, char);
    //setter functions
    void setRadius(double r)
    {radius = r;}
    void setDiameter(double d)
    {radius = d/2;}
    void setVolume(double v)
    {radius = cbrt((v/PI)*(3/4.0));}
    void setArea(double a)
    {radius = sqrt(a/(4*PI));}

    //get functions
    double getRadius()
    {return radius;}
    double getDiameter()
    {return radius*2;}
    double getVolume()
    {return (4/3.0) * PI * pow(radius,3);}
    double getArea()
    {return 4 * PI * pow(radius,2);}
};

//input check
double in_check(double *input){
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
    //input
    double inp;
    //sphere type
    char s_type, repeat = 'y';

//display
    cout << endl << endl;
    cout << "#";
    cout.width(31) << cout.fill('-');
    cout << "#" <<endl;
    cout << "|" << "  Spheres\"R\"US Inc. Presents  " << "|" <<endl;
    cout << "|" << "       SPHERE CALC v.01       " << "|" <<endl;
    cout << "#" ;
    cout.width(31) << cout.fill('-') ;
    cout << "#" <<endl << endl << endl;

//main loop for sphere calculation
while (repeat == 'y'){

//prompt for sphere information
    cout << "How would you like your sphere calculated? (r = radius, d = diameter, a = surface area, v = volume)\n";
    while (true){
        cin >> s_type;
        s_type = tolower(s_type);
        if (s_type == 'r' ||s_type == 'd' ||s_type == 'a' ||s_type == 'v' ){
            cin.clear();
            cin.ignore(256,'\n');
            break;}
        else{
            cin.clear();
            cin.ignore(256,'\n');
            cout << "Invalid entry, try agian.\n";}
    }

Sphere sphere1(1,s_type);

//output as chart
    cout << endl << endl;
    cout.fill(' ');
    cout << left << setw(15) << "Radius" << left << setw(15) << "Area" << left << setw(15) << "Diameter" << left << setw(15) << "Volume" << endl;
    cout << left << setw(15) << sphere1.getRadius() << left << setw(15) << sphere1.getArea() << left << setw(15) << sphere1.getDiameter() << left << setw(15) << sphere1.getVolume() << endl;

//record largest sphere entered so far
//    if (l_sphere.getRadius() < sphere1.getRadius())
  //      l_sphere.setRadius(sphere1.getRadius());

//prompt for repeated operation
    cout << "\n\nWould you like to calculate another sphere? (y/n) ";
    while (true){
        cin >> repeat;
        repeat = tolower(repeat);
        if (repeat == 'y' || repeat == 'n'){
            cin.clear();
            cin.ignore(256,'\n');
            break;}
        else{
            cin.clear();
            cin.ignore(256,'\n');
            cout << "Invalid entry, try again\n";}
    }
}

//at end of loop out put chart with largest sphere entered
//cout << "\nLargest sphere enter:" << endl;
//    cout << left << setw(15) << "Radius" << left << setw(15) << "Area" << left << setw(15) << "Diameter" << left << setw(15) << "Volume" << endl;
//    cout << left << setw(15) << l_sphere.getRadius() << left << setw(15) << l_sphere.getArea() << left << setw(15) << l_sphere.getDiameter() << left << setw(15) << l_sphere.getVolume() << endl;

return 0;
}

//END MAIN


//constructer
Sphere::Sphere(double num, char type){
  switch (type)
  {
      case 'r':   cout << "What is the radius of the sphere? ";
                  in_check(&num);
                  radius = num;
                  break;
      case 'd':   cout << "What is the diameter of sphere? ";
                  in_check(&num);
                  radius = num/2;
                  break;
      case 'a':   cout << "What is the area of sphere? ";
                  in_check(&num);
                  radius = sqrt(num/(4*PI));
                  break;
      case 'v':   cout << "What is the volume of sphere? ";
                  in_check(&num);
                  radius = cbrt((num/PI)*(3.0/4));
                  break;
}}
