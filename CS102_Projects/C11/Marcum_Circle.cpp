/*
Circle class - 1 member of radius - private
public - functions - setRadius, getRadius, getArea, and getCircum
prompt for radius - print radius area and circumference
*/
//Did my best to make it flow and simple to follow

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include "marcum_header.h"
#include "marcum_header.cpp"
//#include "Shapes.h"
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


class mRectangle : public Shape{
private:
    double length, \
            width;
public:
    mRectangle() {length = 1; width = 1;}
    mRectangle(double l, double w) {length = l; width = w;}
    string getType() const {return "Rectangle";}
    void setLength(double l) {length = l;}
    void setWidth(double w) {width = w;}
    double getLength() const {return length;}
    double getWidth() const {return width;}
    double getArea() const {return length * width;}
    double getPerimeter() const {return length * 2 + width * 2;}
}; //mRectangle
//Had to make it mRectangle over Rectangle because it wouldn't compile as Rectangle


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
int numberOfShapes(string type);
int circleSetBy();
int triSetBy();
void sortShape(Shape &shape);
void printArea(const Shape &shape);
void printPerimeter(const Shape &shape);
void printType(const Shape *shape);

//BEGIN MAIN
int main(){
    int selection = 1;
	vector<Shape*> shapes;
    //the shape vector of champions

    //main loop start
    //gets a selection
    while(selection = mainLoop()){
        /*
        1 = Circle
        2 = Rectangle
        3 = Triangle
        4 = Display
        0 = Exit
        */
        if (selection == 1){ //if circle
            double circle_value;
            double pi = 3.14159;
            int setCircle = circleSetBy(); //get set circle by
            /*
            1 = Radius
            2 = Diameter
            3 = Area
            4 = Circumference
            */
            int loop = numberOfShapes("Circle"); //num circles
            for (int i = 0; i < loop; i++){
                cout << endl;
                if (setCircle == 1){ //if Radius
                    cout << "Enter radius of circle #" << i+1 << ": ";
                    d_in(&circle_value,1); //get a radius
                    shapes.push_back(new Circle(circle_value)); //make a circle of radius
                } //set by 1
                if (setCircle == 2){
                    cout << "Enter Diameter of circle #" << i+1 << ": ";
                    d_in(&circle_value,1);
                    circle_value /=2;
                    shapes.push_back(new Circle(circle_value));
                } //set by 2
                if (setCircle == 3){
                    cout << "Enter Area of circle #" << i+1 << ": ";
                    d_in(&circle_value,1);
                    circle_value = sqrt(circle_value/pi);
                    shapes.push_back(new Circle(circle_value));
                } //set by 3
                if (setCircle == 4){
                    cout << "Enter Circumference of circle #" << i+1 << ": ";
                    d_in(&circle_value,1);
                    circle_value =  circle_value/(2*pi);
                    shapes.push_back(new Circle(circle_value));
                } //set by 4
            } //loop of shape
        } //selection 1

        if (selection == 2){
            double rec_len, rec_width;
            int loop = numberOfShapes("Rectangle");
            for (int i = 0; i < loop; i++){
                cout << "Enter Length of Rectangle #" << i+1 << ": ";
                d_in(&rec_len,1);
                cout << "Enter Width of Rectangle #" << i+1 << ": ";
                d_in(&rec_width,1);
                cout << endl;
                shapes.push_back(new mRectangle(rec_len, rec_width));
            }//loop of shape
        } //selection 2

        if (selection == 3) {
            double side1,side2,side3;
            int setTri = triSetBy();
            /*
            1 = Right triangle (2 side)
            2 = Other (3 side)
            */
            int loop = numberOfShapes("Triangle");
            for (int i = 0; i < loop; i++){
                cout << endl;
                if (setTri == 1){
                    cout << "Enter Side 1 of Triangle #" << i+1 << ": ";
                    d_in(&side1,1);
                    cout << "Enter Side 2 of Triangle #" << i+1 << ": ";
                    d_in(&side2,1);
                    shapes.push_back(new Triangle(side1,side2));
                } //set by 1
                if (setTri == 2){
                    cout << "Enter Side 1 of Triangle #" << i+1 << ": ";
                    d_in(&side1,1);
                    cout << "Enter Side 2 of Triangle #" << i+1 << ": ";
                    d_in(&side2,1);
                    cout << "Enter Side 3 of Triangle #" << i+1 << ": ";
                    d_in(&side3,1);
                    shapes.push_back(new Triangle(side1,side2,side3));
                } //set by 2
            } //loop of shape
        } //selection 3

        if (selection == 4){
            for_each(shapes.begin(),shapes.end(), printType);
        getchar();
        } // selection 4

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

int triSetBy(){
    char option, options[] = {'a','b','c','d'};
    cout<< endl << "Triagle type:" << endl \
        << "A: Right Triangle (Set with length of non-hypo sides)" << endl \
        << "B: Other Triangle (Sets by length of 3 sides)" << endl;
    cout<< "Create Triangle Using: ";
    c_in(&option,options,2);
    switch(option){
        case('a'): return 1;
        case('b'): return 2;
    }
    return 0;
}//triSetBy

void sortShape(Shape &shape){


} //sortShape

//prints area of shape
void printArea(const Shape &shape){
    cout << shape.getArea();
}

//prints perimeter of shape
void printPerimeter(const Shape &shape){
    cout << shape.getPerimeter();
}

//prints type of shape
void printType(const Shape *shape){
    cout << shape->getType() << endl;
}
