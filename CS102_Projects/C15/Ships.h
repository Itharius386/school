#pragma once
#include "marcum_header.h"
#include "marcum_header.cpp"
#include <iostream>
#include <string>
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
    virtual void printShip() const {
        cout << "The ship is called ";
        setcolor(14);
        cout << "S.S. " << name;
        setcolor();
        cout << " and was built in ";
        setcolor(14);
        cout << year << endl;
        setcolor();
    }
};

class CruiseShip : public Ship {
private:
    int passengers;
public:
    CruiseShip(string nm, string yr, int pass) : Ship(nm, yr) { passengers = pass; }
    CruiseShip(string nm, int pass) : Ship(nm) { passengers = pass; }
    void setPass(int num) { passengers = num; }
    int getPass() { return passengers; }
    void printShip() const {
        cout << "The ship is called ";
        setcolor(14);
        cout << "S.S. " << name;
        setcolor();
        cout << " and can hold ";
        setcolor(14);
        cout << passengers;
        setcolor();
        cout << " passengers" << endl;
    }
};

class CargoShip : public Ship {
private:
    int cargo;
public:
    CargoShip(string nm, string yr, int num) : Ship(nm, yr) { cargo = num; }
    CargoShip(string nm, int num) : Ship(nm) { cargo = num; }
    void setCargo(int num) { cargo = num; }
    int getCargo() { return cargo; }
    void printShip() const {
        cout << "The ship is called ";
        setcolor(14);
        cout << "S.S. " << name;
        setcolor();
        cout << " and can hold ";
        setcolor(14);
        cout << cargo;
        setcolor();
        cout << " tonnes of cargo" << endl;
    }
};
