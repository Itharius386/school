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
using namespace std;
//functions prototypes here

#if defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__)
//============================
//
//  ohandle:    sets the standard output handle for a given handle
//
//  Arg1:       Input handle to be set - as pointer
//
//============================
void ohandle(HANDLE *screen);
#endif //only included if we have windows

//============================
//
//  setcolor:   sets the output color
//
//  Arg1:       color to set (Default to 7: White)
//
//  0=Black, 1=Blue, 2=Green, 3=Cyan, 4=Red, 5=Purple, 6=Yellow, 7=White
//  8-15=Bright of above
//	Then it cycles through background colors, 256 combinations total
//
//============================
void setcolor(int color=7);

//============================
//
//  setpos:        sets the position of the cursor
//
//  Arg1, Arg2:    x,y position to place the cursor at
//
//============================
void setpos(short col, short row);

//============================
//  d_in: Asks user for input, will prompt until a real number is entered and assigns it to argument1
//
//  Arg1: double  pointer of input will be assigned here
//  Arg2: int     1 for postives only, 0 for positive or negative (Deaults to 0)
//============================
void d_in(double*, int = 0);

//============================
//  c_in: Asks user for input, prompts user until a character within the array of arguement2 is entered, and assigns it to argument1
//
//  Arg1: char  pointer of input to be assigned
//  Arg2: char  Array with acceptable inputs
//  Arg3: int   Size of Array
//============================
void c_in(char*,char*,int);

//============================
//  i_in: Asks user for input, prompts for an integer and assigns to Arg1
//
//  Arg1: int   pointer of input to be assigned
//  Arg2: int   1 for postives only, 0 for positive or negative (Deaults to 0)
//============================
void i_in(int*, int = 0);

//============================
//  s_i_in: Asks user for input, prompts user until an integer within the array of arguement2 is entered, and assigns it to argument1
//
//  Arg1: int pointer of input to be assigned
//  Arg2: int Array with acceptable inputs
//  Arg3: int Size of Array
//============================
void s_i_in(int*, int*, int);

//============================
//	display:  Provides basic display for a program, good for up to 2 lines
//			  Recommended both lines have same even or odd number of characters
//
//	Arg1:	  string  first line to be printed
//	Arg2:	  string  second line to be printed (defaults to blank, matches an even number of characters in Arg1)
//  Arg3:     into    color of text
//============================
void display(string, string = "",int = 7);


#endif
