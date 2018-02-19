/*
Circle class - 1 member of radius - private
public - functions - setRadius, getRadius, getArea, and getCircum
prompt for radius - print radius area and circumference
*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
using namespace std;

class Shape{
public:
    virtual double getArea() = 0;
};

class Circle : public Shape{
private:
    double const pi = 3.14159;
    double radius;
public:
    Circle(){radius = 1;}
    Circle(double r){radius = r;}
    void setRadius(double r){radius = r;}
    double getRadius(){return radius;}
    virtual double getArea(){return pi*pow(2,radius);}
};

int main(){
    int shape_loop=0;
    double temp_shape;
    vector<Shape> your_shapes;
    cout << "Number of shapes? ";
    cin >> shape_loop;

    while(shape_loop){
        cout << "Value for shape: ";
        cin >> temp_shape;
        your_shapes.push_back(Circle(temp_shape));
        shape_loop--;
    }
    return 0;
}
