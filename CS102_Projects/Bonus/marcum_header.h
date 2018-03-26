//============================
//guard
#pragma once
//============================
#ifndef ICOLOR
#define ICOLOR 14 //default input color
#endif
//dependency headers
#include <iostream>
#include <string>
#if defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__)
#include <windows.h>
#endif

void setcolor(int = 7);
void d_in(double*, int = 0);
void c_in(char*,char*,int);
void i_in(int*, int = 0);
void s_i_in(int*, int*, int);
void display(std::string, std::string = " ", int = 7);
bool YesNo(std::string);
char Menu(const std::string *options, const int max);

//==============================================================================
//  GetNum: gets a number from the user
//
//  num: number goes here
//  Positive: whether or not the number must be positive (default can be negative)
//
//==============================================================================
template <class T>
void GetNum(T &num, int positive = 0){
    setcolor(ICOLOR);
    std::cin >> num;
    while (std::cin.fail()){ //if it wasn't a number
        setcolor();
        std::cout << "\aInvalid, try again: ";
        std::cin.clear();
        std::cin.ignore(256,'\n');
        setcolor(ICOLOR);
        std::cin >> num;
    } //get another number
    std::cin.clear();
    std::cin.ignore(256,'\n');
    if (positive == 1){ //if positives only
        while (num < 0){//and not a positive
            setcolor();
            std::cout << "\aPositive Values only: ";
            setcolor(ICOLOR);
            GetNum(num,1);
        }
    }//call the function until it is valid and positive
    setcolor();
}

//==============================================================================
//  GetNumInRange:  Gets a number from the user within a range
//
//  num: number goes here
//  max: max number to take in, inclusive
//  min: min number to take in, inclusive, 0 default
//
//==============================================================================


template <class T>
void GetNumInRange(T &num, T max, T min = 0){
    do {
        GetNum(num);
        if (num > max || num < min)
            std::cout << "Value out of range, try again: ";
    } while (num > max || num < min);
}
