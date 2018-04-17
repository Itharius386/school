/*
Design a Ship class that has the following members:
• A member variable for the name of the ship (a string)
• A member variable for the year that the ship was built (a string)
• A constructor and appropriate accessors and mutators
• A virtual print function that displays the ship’s name and the year it was built.
Design a CruiseShip class that is derived from the Ship class. The CruiseShip class
should have the following members:
• A member variable for the maximum number of passengers (an int )
• A constructor and appropriate accessors and mutators
• A print function that overrides the print function in the base class. The CruiseShip
class’s print function should display only the ship’s name and the maximum number
of passengers.
Design a CargoShip class that is derived from the Ship class. The CargoShip class
should have the following members:
• A member variable for the cargo capacity in tonnage (an int ).
• A constructor and appropriate accessors and mutators.
• A print function that overrides the print function in the base class. The CargoShip
class’s print function should display only the ship’s name and the ship’s cargo capacity.
Demonstrate the classes in a program that has an array of Ship pointers. The array
elements should be initialized with the addresses of dynamically allocated Ship ,
CruiseShip , and CargoShip objects. (See Program 15-14 , lines 17 through 22, for an
example of how to do this.) The program should then step through the array, calling
each object’s print function.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Ship {
protected:
    string name;
    string year;
public:
    Ship() {
        name = " ";
        year = "1900";
    }
    Ship(string nm, string yr = "1900") {
        name = nm;
        year = yr;
    }
    void setName(string nm) { name = nm; }
    void setYear(string yr) { year = yr; }
    string getName() { return name; }
    string getYear() { return year; }
    virtual void printShip() { cout << "The ship is called S.S. " << name << " and was built in " << year << endl; }
};

class CruiseShip : public Ship {
private:
    int passengers;
public:
    CruiseShip(string nm, string yr, int pass) : Ship(nm, yr) { passengers = pass; }
    CruiseShip(string nm, int pass) : Ship(nm) { passengers = pass; }
    void setPass(int num) { passengers = num; }
    int getPass() { return passengers; }
    void printShip() { cout << "The ship is called S.S. " << name << " and can hold " << passengers << " passengers" << endl;}
};

class CargoShip : public Ship {
private:
    int cargo;
public:
    CargoShip(string nm, string yr, int num) : Ship(nm, yr) { cargo = num; }
    CargoShip(string nm, int num) : Ship(nm) { cargo = num; }
    void setCargo(int num) { cargo = num; }
    int getCargo() { return cargo; }
    void printShip() { cout << "The ship is called S.S. " << name << " and can hold " << cargo << " tonnes of cargo" << endl; }
};


int main() {
    vector<Ship*> registry;

    return 0;
}
