//============================
//guard
#ifndef SHAPES_HEADER
#define SHAPES_HEADER
//============================

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

#endif
