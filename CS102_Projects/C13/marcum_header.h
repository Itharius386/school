//============================
//guard
#ifndef MARCUM_HEADER
#define MARCUM_HEADER
//============================
//dependency headers
#include <iostream>
#include <string>
#if defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__)
#include <windows.h>
#endif

void setcolor(int);
void d_in(double*, int);
void c_in(char*,char*,int);
void i_in(int*, int);
void s_i_in(int*, int*, int);
void display(std::string, std::string, int);
bool YesNo(std::string);


#endif
