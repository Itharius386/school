//============================
//guard
#ifndef MARCUM_HEADER
#define MARCUM_HEADER
//============================
//dependency headers
#include <iostream>

//functions prototypes here

//============================
//
//  d_in: Asks user for input, will prompt until a real number is entered and assigns it to argument1
//
//  Arg1: double  pointer of input will be assigned here
//  Arg2: int     1 for postives only, 0 for positive or negative (Deaults to 0)
//
//============================
void d_in(double*, int = 0);

//============================
//
//  c_in: Asks user for input, prompts user until a character within the array of arguement2 is entered, and assigns it to argument1
//
//  Arg1: char  pointer of input to be assigned
//  Arg2: char  Array with acceptable inputs
//  Arg3: int   Size of Array
//
//============================
void c_in(char*,char*,int);

//============================
//
//  i_in: Asks user for input, prompts for an integer and assigns to Arg1
//
//  Arg1: int   pointer of input to be assigned
//  Arg2: int   1 for postives only, 0 for positive or negative (Deaults to 0)
//
//============================
void i_in(int*, int = 0);

//============================
//
//  s_i_in: Asks user for input, prompts user until an integer within the array of arguement2 is entered, and assigns it to argument1
//
//  Arg1: int pointer of input to be assigned
//  Arg2: int Array with acceptable inputs
//  Arg3: int Size of Array
//
//============================
void s_i_in(int*, int*, int);
#endif
