/*
Circle class - 1 member of radius - private
public - functions - setRadius, getRadius, getArea, and getCircum
prompt for radius - print radius area and circumference
*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include "marcum_header.h"
#include "marcum_header.cpp"
//namespace
using namespace std;

//Base Shape Class
class Shape {
public:
    virtual double getArea()=0;
};

//Circle Class
class Circle : public Shape{
private:
    double const pi = 3.14159;
    double radius;
public:
    Circle(){radius = 1;}
    Circle(double r){radius = r;}
    void setRadius(double r){radius = r;}
    double getRadius(){return radius;}
    double getArea(){return (pi*radius*radius);}
};

int main(){
    int shape_loop=0;
    double temp_shape;
    vector<Circle> your_shapes;
    cout << "Number of shapes? ";
    cin >> shape_loop;
    for (int i=0;i<shape_loop;i++){
        cout << "Value for shape: ";
        cin >> temp_shape;
        your_shapes.push_back(Circle(temp_shape));
        cout << your_shapes[i].getArea() << endl;
    }
    return 0;
}
