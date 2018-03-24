#pragma once

#include <iostream>
#include <iomanip>
#include "marcum_header.h"
#include "marcum_header.cpp"

class Clock; //forward declaration

std::ostream &operator<< (std::ostream &, const Clock &obj);

class Clock{
private:
    int hours,\
        minutes,\
        seconds;
    void simplify_time();
public:
    Clock(){hours = 0; minutes = 0; seconds = 0;} //defaults to 0
    Clock(int hr, int min, int sec){
        hours = hr;
        minutes = min;
        seconds = sec;
        simplify_time();
    } //constructor
    //inline set/get
    void setHours(int hr) {hours = hr;}
    void setMinutes(int min) {minutes = min;}
    void setSeconds(int sec) {seconds = sec;}
    int getHours() {return hours;}
    int getMinutes() {return minutes;}
    int getSeconds() {return seconds;}
    //overload + - ++() ++(int) --() --(int) < >
    //see Clock.cpp
    Clock operator+(const Clock &right); //add
    Clock operator-(const Clock &right); //subtract
    bool operator>(const Clock &right); //greater than
    bool operator<(const Clock &right); //less than
    bool operator==(const Clock &right); //equal to
    Clock operator++(); //pre-increment
    Clock operator++(int); //post-increment
    Clock operator--(); //pre-decrement
    Clock operator--(int); //post decrement
    //friendly overloaded operator
    friend std::ostream &operator<< (std::ostream &, const Clock &obj);
};
