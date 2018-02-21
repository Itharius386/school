/*
Circle class - 1 member of radius - private
public - functions - setRadius, getRadius, getArea, and getCircum
prompt for radius - print radius area and circumference
*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include "marcum_header.h"
#include "marcum_header.cpp"
//namespace
using namespace std;

//Parent Shape Class
class Shape {
public:
    virtual string getType() const = 0;
    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
}; //Shape


class Circle : public Shape{
    //friend bool comp(const Circle & a, const Circle & b);
private:
    double pi, \
        radius;

public:
    Circle() {radius = 1; pi = 3.14159;}
    Circle(double r) {radius = r; pi = 3.14159;}
    string getType() const {return "Circle";}
    void setRadius(double r) {radius = r;}
    void setArea(float a) {radius = sqrt(a/pi);}
    void setDiameter(float d) {radius = d/2;}
    void setCircum(float c) {radius = c/(2*pi);}
    double getRadius() const {return radius;}
    virtual double getArea() const {return (pi*radius*radius);}
    double getCircum() const {return 2*pi*radius;}
    double getPerimeter() const {return getCircum();} //circumference of a circle is it's perimeter
}; //Circle


class Rectangle : public Shape{
private:
    double length, \
            width;
public:
    Rectangle() {length = 1; width = 1;}
    Rectangle(double l, double w) {length = l; width = w;}
    string getType() {return "Rectangle";}
    void setLength(double l) {length = l;}
    void setWidth(double w) {width = w;}
    double getLength() const {return length;}
    double getWidth() const {return width;}
    double getArea() const {return length * width;}
    double getPerimeter() const {return length * 2 + width * 2;}
}; //Rectangle


class Triangle : public Shape{
private:
    double side1, side2, side3;
public:
    Triangle(double s1, double s2, double s3) {side1 = s1; side2 = s2; side3 = s3;}
    //Right Triagle init below
    Triangle(double leg1, double leg2) {side1 = leg1; side2 = leg2; side3 = sqrt((leg1*leg1)+(leg2*leg2));}
    string getType() const {return "Triangle";}
    void setSide1(double s) {side1 = s;}
    void setSide2(double s) {side2 = s;}
    void setSide3(double s) {side3 = s;}
    double getPerimeter() const {return (side1 + side2 + side3)/2;}
    double getArea() const {
        double p = getPerimeter();
        return sqrt(p*((p-side1)*(p-side2)*(p-side3)));}
        //area of a triangle given only sides = perimeter - each side * perimeter
    double getSide1() const {return side1;}
    double getSide2() const {return side2;}
    double getSide3() const {return side3;}
}; //Triangle

//bool comp(const Circle & a, const Circle & b) {return a.radius < b.radius;} //for sorting
//prototypes
int mainLoop();
int numberOfShapes();
int circleSetBy();
void printArea(const Shape &shape);
void printPerimeter(const Shape &shape);
void printType(const Shape &shape);

//BEGIN MAIN
int main(){
    int selection = 1;
	vector<Shape*> shapes;
    //the shape vector of champions
    while(selection = mainLoop()){
        /*
        1 = Circle
        2 = Rectangle
        3 = Triangle
        4 = Display
        5 = Exit
        */
        if (selection == 1){
            double circle_value;
            int setCircle = circleSetBy();
            /*
            1 = Radius
            2 = Diameter
            3 = Area
            4 = Circumference
            */
            int loop = numberOfShapes("Circle");
            for (int i = 0; i < loop; i++){
                if (setCircle = 1){
                    cout << endl << "Enter radius of circle: ";
                    d_in(&circle_value,1);
                    shapes.push_back(new Circle(circle_value));
                } //set by 1
                if (setCircle = 1){
                    cout << endl << "Enter Diameter of circle: ";
                    d_in(&circle_value,1);
                    shapes.push_back(new Circle(circle_value));
                } //set by 2
                if (setCircle = 1){
                    cout << endl << "Enter Area of circle: ";
                    d_in(&circle_value,1);
                    shapes.push_back(new Circle(circle_value));
                } //set by 3
                if (setCircle = 1){
                    cout << endl << "Enter Circumference of circle: ";
                    d_in(&circle_value,1);
                    shapes.push_back(new Circle(circle_value));
                } //set by 4
            } //loop of shape
        } //selection 1

    }//end mainLoop

    return 0;
} //END MAIN


//main loop - main display and selection getter for loop
int mainLoop(){
    char option, options[] = {'a','b','c','d','e'};
    system("CLS");
    display("Shape Calculator v9000","All Shapes, All the Time", 10);
    cout<< "Options:" << endl \
        << "A: Create Circles" << endl \
        << "B: Create Rectangles" << endl \
        << "C: Create Triagles" << endl \
        << "D: Display Shapes" << endl \
        << "E: Exit" << endl << endl;
    cout << "Select an Option from the list: ";
    c_in(&option,options,5);
    switch(option){
        case('a'): return 1;
        case('b'): return 2;
        case('c'): return 3;
        case('d'): return 4;
        case('e'): return 0;
    }
    return 0; //incase somehow breaks out of the loop
}//mainLoop

int numberOfShapes(string type){
    int loop;
    cout << "How many " << type << "s do you want to make: ";
    i_in(&loop,1);
    return loop;
}//numberOfShapes

//determines which parameter to use to set circle
int circleSetBy(){
    char option, options[] = {'a','b','c','d'};
    cout<< endl << "Set Circle by:" << endl \
        << "A: Radius" << endl \
        << "B: Diameter" << endl \
        << "C: Area" << endl \
        << "D: Circumference" << endl;
    cout<< "Create Circle Using: ";
    c_in(&option,options,4);
    switch(option){
        case('a'): return 1;
        case('b'): return 2;
        case('c'): return 3;
        case('d'): return 4;
    }
    return 0;
}//circleSetBy

//prints area of shape
void printArea(const Shape &shape){
    cout << shape.getArea();
}

//prints perimeter of shape
void printPerimeter(const Shape &shape){
    cout << shape.getPerimeter();
}

//prints type of shape
void printType(const Shape &shape){
    cout << shape.getType();
}
