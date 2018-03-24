#pragma once
#include "Clock.h"

void Clock::simplify_time(){
    if (hours < 0 || minutes < 0 || seconds < 0) {
        if (seconds < 0){
            minutes -= ((abs(seconds)/60) + 1);
            seconds = 60 - (abs(seconds) % 60);
        }
        if (minutes < 0){
            hours -= ((abs(minutes)/60) + 1);
            minutes = 60 - (abs(minutes) % 60);
        }
        if (hours < 0){
            hours = 12 - (abs(hours) % 12);
        }
    }
    if (seconds > 60){
        minutes += (seconds/60);
        seconds = seconds%60;
    }
    if (minutes > 60){
        hours += (minutes/60);
        minutes = minutes%60;
    }
    if (hours > 12){
        hours = hours % 12;
    }
}   //simplifies the time

Clock Clock::operator+(const Clock &right){
    Clock temp;
    temp.hours = hours + right.hours;
    temp.minutes = minutes + right.minutes;
    temp.seconds = seconds + right.seconds;
    temp.simplify_time();
    return temp;
} //add hours/minutes/seconds - simplify

Clock Clock::operator-(const Clock &right){
    Clock temp;
    temp.hours = hours - right.hours;
    temp.minutes = minutes - right.minutes;
    temp.seconds = seconds - right.seconds;
    temp.simplify_time();
    return temp;
} //subtract 'above'

bool Clock::operator>(const Clock &right){
    if (hours > right.hours)
        return true;
    else if (hours == right.hours && minutes > right.minutes)
        return true;
    else if (hours == right.hours && minutes == right.minutes && seconds > right.seconds)
        return true;
    else
        return false;
} //greater than

bool Clock::operator<(const Clock &right){
    if (hours < right.hours)
        return true;
    else if (hours == right.hours && minutes < right.minutes)
        return true;
    else if (hours == right.hours && minutes == right.minutes && seconds < right.seconds)
        return true;
    else
        return false;
} //less than

Clock Clock::operator++(){
    ++hours;
    simplify_time();
    return *this;
} //pre-increment by hour

Clock Clock::operator++(int){
    Clock temp(hours, minutes, seconds);
    hours++;
    simplify_time();
    return temp;
} //post-increment by hour

Clock Clock::operator--(){
    --hours;
    simplify_time();
    return *this;
} //pre-decrement by hour

Clock Clock::operator--(int){
    Clock temp(hours, minutes, seconds);
    hours--;
    simplify_time();
    return temp;
} //post decrement by hour

std::ostream &operator<< (std::ostream &strm, const Clock &obj){
    strm << obj.hours << ":";
    if (obj.minutes < 10)
        strm << "0";
    strm << obj.minutes << ".";
    if (obj.seconds < 10)
        strm << "0";
    strm << obj.seconds;

    if (obj.hours < 0)
        strm << std::endl << "#StudentsAgainstTimeTravel :(";
    return strm;
}
