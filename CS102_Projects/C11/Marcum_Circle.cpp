/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                         *
 * Author: James Marcum                                                    *
 * Class: CS 102                                                           *
 *                                                                         *
 * Function: Circles & other fun Shapes                                    *
 *           Get areas, sort things, fun for all Shapes                    *
 *                                                                         *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

//Did my best to make it flow and simple to follow
//won't run on Quincy unless you turn on RTTI
//but it worked fine with Code::Blocks automatically in testing

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <typeinfo>
#include <algorithm>
#include "marcum_header.h"
#include "marcum_header.cpp"
#include "Shapes.h"
//namespace
using namespace std;


//==========
//prototypes
int mainLoop();
int numberOfShapes(string type);
int circleSetBy();
int triSetBy();
int sortBy();
void printArea(const Shape &shape);
void printPerimeter(const Shape &shape);
void printType(const Shape *shape);
void displayShape(const Shape *shape);
bool compareType(const Shape *typeA, const Shape *typeB);
bool comp(const Shape *a, const Shape *b);

//==============================================================================
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
            double side1=0,side2=0,side3=0;
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
                    do {
                        cout << "Enter Side 1 of Triangle #" << i+1 << ": ";
                        d_in(&side1,1);
                        cout << "Enter Side 2 of Triangle #" << i+1 << ": ";
                        d_in(&side2,1);
                        cout << "Enter Side 3 of Triangle #" << i+1 << ": ";
                        d_in(&side3,1);
                        if (side1 + side2 < side3 || side1 + side3 < side2 || side2 + side3 < side1)
                            cout << "Invalid Triangle. Check length of sides." << endl;
                    } while (side1 + side2 < side3 || side1 + side3 < side2 || side2 + side3 < side1);
                    //triangle validation added
                    shapes.push_back(new Triangle(side1,side2,side3));
                } //set by 2
            } //loop of shape
        } //selection 3

        if (selection == 4){
            int sortType = sortBy();
            if (sortType == 1)
                sort(shapes.begin(), shapes.end(),compareType); //sorts by shape
            if (sortType == 2)
                sort(shapes.begin(), shapes.end(),comp); //sorts by area
            setcolor(2);
            cout<< left << endl \
                << setw(12) << "Shape" \
                << setw(10) << "Radius /" \
                << setw(10) << " " \
                << setw(15) << "Side 3 /" \
                << setw(10) << " " \
                << setw(15) << "Perimeter /";
            cout<< left << endl \
                << setw(12) << "Type" \
                << setw(10) << "Length" \
                << setw(10) << "Width" \
                << setw(15) << "Hypotenuse" \
                << setw(10) << "Area" \
                << setw(15) << "Circumference" << endl;

            setcolor(5);
            for (int i = 0; i < 80; i++)
                cout << "_";
            setcolor();
            for_each(shapes.begin(),shapes.end(), displayShape);
        getchar();
        } // selection 4

    }//end mainLoop

    return 0;
} //END MAIN
//==============================================================================

//==============================================================================
//BEGIN Functions

//main loop - main display and selection getter for loop
int mainLoop(){
    char option, options[] = {'a','b','c','d','e'};
    system("CLS");
    display("Shape Calculator v9000","All Shapes, All the Time", 10);
    cout<< "Options:" << endl \
        << "A: Create Circles" << endl \
        << "B: Create Rectangles" << endl \
        << "C: Create Triangles" << endl \
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
    char option, options[] = {'a','b'};
    cout<< endl << "Triangle type:" << endl \
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

int sortBy(){
    char option, options[] = {'a','b'};
    cout<< endl << "Sort Options:" << endl \
        << "A: Shape Type" << endl \
        << "B: Area" << endl;
    cout<< "Sort by: ";
    c_in(&option,options,2);
    switch(option){
        case('a'): return 1;
        case('b'): return 2;
    }
    return 0;
}//sortBy

//this set of print functions were mostly used for testing
//prints area of shape
void printArea(const Shape &shape){
    cout << shape.getArea();
}//printArea

//prints perimeter of shape
void printPerimeter(const Shape &shape){
    cout << shape.getPerimeter();
}//printPerimeter

//prints type of shape
void printType(const Shape *shape){
    cout << shape->getType() << endl;
}//printType

//displays the attributes of a given shape
void displayShape(const Shape *shape){
    //sets color by type
    if (shape->getType() == "Circle")
        setcolor(11);
    if (shape->getType() == "Rectangle")
        setcolor(13);
    if (shape->getType() == "Triangle")
        setcolor(12);

    cout << left << fixed << setprecision(2) \
    << setw(12) << shape->getType();
    cout << shape->getAttributes();
    cout << setw(10) << shape->getArea() \
    << setw(15) << shape->getPerimeter() << endl;
}

//compares type of shape for sorting purposes
//probably could have made it simpler, but it works
bool compareType(const Shape *typeA, const Shape *typeB){
    int A, B;

    if (typeid(*typeA) == typeid(Circle))
        A = 0;
    if (typeid(*typeB) == typeid(Circle))
        B = 0;

    if (typeid(*typeA) == typeid(mRectangle))
        A = 1;
    if (typeid(*typeB) == typeid(mRectangle))
        B = 1;

    if (typeid(*typeA) == typeid(Triangle))
        A = 2;
    if (typeid(*typeB) == typeid(Triangle))
        B = 2;

    if (A == B) //if same type sort by area
        return comp(typeA, typeB);

    return A < B;
} //compareType

//compares a given shape by area
bool comp(const Shape *a, const Shape *b){
    double A = a->getArea(), B = b->getArea();
    return A < B;
} //comp

//END Functions
//==============================================================================
