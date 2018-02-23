//============================
//guard
#ifndef SHAPES_HEADER
#define SHAPES_HEADER
//============================
//just left this one with all inline declarations because they are mostly single line functions

#include <iomanip>
#include <string>
#include <sstream>
#include <cmath>

//Parent Shape Class
class Shape {
public:
    virtual string getType() const = 0;
    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual string getAttributes() const = 0;
}; //Shape


class Circle : public Shape{
private:
    double pi, \
        radius;

public:
    Circle() {radius = 1; pi = 3.14159;}
    Circle(double r) {radius = r; pi = 3.14159;}
    string getType() const {return "Circle";}
    string getAttributes() const {
        stringstream ss;
        ss << fixed << setprecision(2) << left << setw(10) << radius << setw(25) << " ";
        return ss.str();
    }
    void setRadius(double r) {radius = r;}
    void setArea(float a) {radius = sqrt(a/pi);}
    void setDiameter(float d) {radius = d/2;}
    void setCircum(float c) {radius = c/(2*pi);}
    double getRadius() const {return radius;}
    double getArea() const {return (pi*radius*radius);}
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
    string getAttributes() const {
        stringstream ss;
        ss << fixed << setprecision(2) << left << setw(10) << length << setw(10) << width << setw(15) << " ";
        return ss.str();
    }
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
    //Right triangle init below
    Triangle(double leg1, double leg2) {side1 = leg1; side2 = leg2; side3 = sqrt((leg1*leg1)+(leg2*leg2));}
    string getType() const {return "Triangle";}
    string getAttributes() const {
        stringstream ss;
        ss << fixed << setprecision(2) << left << setw(10) << side1 << setw(10) << side2 << setw(15) << side3;
        return ss.str();
    }
    void setSide1(double s) {side1 = s;}
    void setSide2(double s) {side2 = s;}
    void setSide3(double s) {side3 = s;}
    double getPerimeter() const {return (side1 + side2 + side3);}
    double getArea() const {
        double p = getPerimeter()/2;
        return sqrt(p*((p-side1)*(p-side2)*(p-side3)));}
        //area of a triangle given only sides = perimeter - each side * perimeter
    double getSide1() const {return side1;}
    double getSide2() const {return side2;}
    double getSide3() const {return side3;}
}; //Triangle

#endif
