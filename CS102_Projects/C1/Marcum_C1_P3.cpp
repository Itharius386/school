/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                                                 *
 *  Author: James Marcum                                                                           *
 *  Class: CS 102                                                                                  *
 *                                                                                                 *
 *  Function: Compute spheres based on given parameter                                             *
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
#include <vector>
//namespace
using namespace std;

const double PI = 3.14159;

//Sphere object class - based on radius
class Sphere
{
private:
    double radius;
    //#ifndef PI
    //#define PI 3.14159
    //#endif
public:
    //constructer prototype
    Sphere(double num, char type);
    //set functions
    void setRadius(double r){radius = r;}
    void setDiameter(double d){radius = d/2;}
    void setVolume(double v){radius = cbrt((v/PI)*(3/4.0));}
    void setArea(double a){radius = sqrt(a/(4*PI));}
    //get functions
    double getRadius(){return radius;}
    double getDiameter(){return radius*2;}
    double getVolume(){return (4/3.0) * PI * pow(radius,3);}
    double getArea(){return 4 * PI * pow(radius,2);}
};

//prototypes
void d_in(double*);
void c_in(char*,char*,int);
void display();

//BEGIN MAIN
int main()
{
//input, sphere type, loop char, and checks for sphere and loop
double inp;
char s_type, type_check[] = {'r','a','d','v'},
     repeat = 'y', repeat_check[] = {'y','n'};
vector <Sphere> spheres;

//start display
display();
//main loop for sphere calculation
while (repeat == 'y'){
  //prompt for sphere type
  cout << "\nHow would you like your sphere calculated? (r = radius, d = diameter, a = surface area, v = volume): ";
  c_in(&s_type,type_check,4);
  //prompt for value
  cout << "Enter a value for the ";
      switch (s_type){
      case('r'): cout << "radius: "; break;
      case('a'): cout << "area: "; break;
      case('v'): cout << "volume: "; break;
      case('d'): cout << "diameter: "; break;
    }
  d_in(&inp);
  //sphere object init
  spheres.push_back(Sphere (inp, s_type));
  //prompt for repeated operation
  cout << "Would you like to add another sphere? (y/n) ";
  c_in(&repeat, repeat_check,2);
}
cout << endl << endl;
cout.fill(' ');
cout << left << setw(15) << "Radius" << left << setw(15) << "Area" << left << setw(15) << "Diameter" << left << setw(15) << "Volume" << endl;
for (int j =0 ; j < spheres.size(); j++){
  cout << left << setw(15) << spheres[j].getRadius() << left << setw(15) << spheres[j].getArea() << left << setw(15) << spheres[j].getDiameter() << left << setw(15) << spheres[j].getVolume() << endl;}


return 0;
}

//END MAIN

//went and built a proper constructer
//constructer
Sphere::Sphere(double num, char type){
  if (num <=0){
    radius = 1;
    cout << "Invalid Entry, defaulted to radius of 1\n";}
  else{
  switch (type){
      case 'r':   radius = num; break;
      case 'd':   radius = num/2; break;
      case 'a':   radius = sqrt(num/(4*PI)); break;
      case 'v':   radius = cbrt((num/PI)*(3.0/4)); break;}}
}

//error checking input for doubles
void d_in(double *input){
    cin >> *input;
    while (cin.fail()){
        cout << "Invalid, try again: ";
        cin.clear();
        cin.ignore(256,'\n');
        cin >> *input;
        }
}

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

//starting display function
void display(){
  cout << endl << endl;
  cout << "#";
  cout.width(31) << cout.fill('-');
  cout << "#" <<endl;
  cout << "|" << "  Spheres\"R\"US Inc. Presents  " << "|" <<endl;
  cout << "|" << "       SPHERE CALC v.01       " << "|" <<endl;
  cout << "#" ;
  cout.width(31) << cout.fill('-') ;
  cout << "#" <<endl << endl;
}
