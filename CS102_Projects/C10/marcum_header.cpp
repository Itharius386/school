#include "marcum_header.h"
using namespace std;
#ifndef ICOLOR
#define ICOLOR 14
#endif


//============================
//
//  ohandle:    sets the standard output handle for a given handle
//
//  Arg1:       Input handle to be set - as pointer
//
//============================
void ohandle(HANDLE *screen){
    *screen = GetStdHandle(STD_OUTPUT_HANDLE);//set the handle to the standard output
}

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
void setcolor(int color){
    HANDLE screen;//make handle
    ohandle(&screen);//set to standard output
    SetConsoleTextAttribute(screen, color);//set the color
}

//============================
//
//  setpos:        sets the position of the cursor
//
//  Arg1, Arg2:    x,y position to place the cursor at
//
//============================
void setpos(short col, short row){
    HANDLE screen;
    COORD position;
    ohandle(&screen);
    position.X = col;
    position.Y = row;
    SetConsoleCursorPosition(screen, position);
}


//============================
//  d_in: Asks user for input, will prompt until a real number is entered and assigns it to argument1
//
//  Arg1: double  pointer of input will be assigned here
//  Arg2: int     1 for postives only, 0 for positive or negative (Deaults to 0)
//============================
void d_in(double *input, int pos){
    setcolor(ICOLOR);
    cin >> *input;//get a input
    while (std::cin.fail()){//if not a double do it again
        setcolor();
        cout << "\aInvalid, try again: ";
        setcolor(ICOLOR);
        cin.clear();
        cin.ignore(256,'\n');
        cin >> *input;
        }
    if (pos == 1){//if positives only
    while (*input < 0){//check if positive
        setcolor();
        cout << "\aPositive Values only: ";
        setcolor(ICOLOR);
        d_in(input);}}//recall function until positive and valid
    setcolor();
}

//============================
//  c_in: Asks user for input, prompts user until a character within the array of arguement2 is entered, and assigns it to argument1
//
//  Arg1: char  pointer of input to be assigned
//  Arg2: char  Array with acceptable inputs
//  Arg3: int   Size of Array
//============================
void c_in(char *input, char check[], int array_size){
    int i, b_check=0;
    char temp; //temp isn't really needed but it felt safer to use it
    while (true){
        setcolor(ICOLOR);
        cin >> temp;//get that character
        temp = tolower(temp);
        for (i=0;i<array_size;i++){ //check it against the acceptable inputs
          if (temp == check[i]){
            cin.clear();
            cin.ignore(256,'\n');
            b_check=1;//if acceptable input break
            break;}}
      if (b_check)
        break;//break all the way out
      else{//because if you didn't it was wrong and you gotta do it again
          cin.clear();
          cin.ignore(256,'\n');
          setcolor();
          cout << "\aInvalid entry, try agian: ";}
    }
    *input = temp;//place temp into input
    setcolor();
}

//============================
//  i_in: Asks user for input, prompts for an integer and assigns to Arg1
//
//  Arg1: int   pointer of input to be assigned
//  Arg2: int   1 for postives only, 0 for positive or negative (Deaults to 0)
//============================
void i_in(int *input, int pos){
    setcolor(ICOLOR);
    cin >> *input;
    while (cin.fail()){ //if it wasn't an integer
        setcolor();
        cout << "\aInvalid, try again: ";
        cin.clear();
        cin.ignore(256,'\n');
        setcolor(ICOLOR);
        cin >> *input;} //get another input
    cin.clear();
    cin.ignore(256,'\n');
    if (pos == 1){ //if positives only
        while (*input < 0){//and not a positive
            setcolor();
            cout << "\aPositive Values only: ";
            setcolor(ICOLOR);
            i_in(input);}}//call the function until it is valid and positive
    setcolor();
}

//============================
//  s_i_in: Asks user for input, prompts user until an integer within the array of arguement2 is entered, and assigns it to argument1
//
//  Arg1: int pointer of input to be assigned
//  Arg2: int Array with acceptable inputs
//  Arg3: int Size of Array
//============================
void s_i_in(int *input, int check[], int array_size){
    int i, b_check=0, temp;//temp isn't really needed but it felt safer to use it
    while (true){
        setcolor(ICOLOR);
        cin >> temp;//get an int
        for (i=0;i<array_size;i++){//check it against the acceptable inputs
            if (temp == check[i]){
                cin.clear();
                cin.ignore(256,'\n');
                b_check=1;//if acceptable input break
                break;}}
        if (b_check)
            break;//break all the way out
        else{//because if you didn't it was wrong and you gotta do it again
            cin.clear();
            cin.ignore(256,'\n');
            setcolor();
            cout << "\aInvalid entry, try agian: ";}
    }
    *input = temp;//place temp into the input
    setcolor();
}


//============================
//	display:  Provides basic display for a program, good for up to 2 lines
//			  Recommended both lines have same even or odd number of characters
//
//	Arg1:	  string  first line to be printed
//	Arg2:	  string  second line to be printed (defaults to blank, matches an even number of characters in Arg1)
//============================
void display(string line1, string line2, int color){
	int b_string; //determines which of the 2 lines is longer for width consideration
	if (line1.length() > line2.length())
		b_string = line1.length();
	else
		b_string = line2.length();
    setcolor(color);
	cout << char(201); //print corner
	for (int i = 0; i < b_string + 10; i++)
		cout << char(205); //print width
	cout << char(187) << endl << char(186); //corner + side
	for (int i = 0; i < b_string + 10; i++)
		cout << " "; //blank row
	cout << char(186) << endl << char(186); // side and next line side
	for (int i = 0; i < (b_string - line1.length())/2 + 5; i++)
		cout << " ";//print some white space: see loop for math
	cout << line1;//print line1
	for (int i = 0; i < (b_string - line1.length())/2 + 5; i++)
		cout << " ";//the rest of the line
	cout << char(186) << endl << char(186); //side and next line side
	for (int i = 0; i < (b_string - line2.length())/2 + 5; i++)
		cout << " ";//same as before
	cout << line2;//print line2
	for (int i = 0; i < (b_string - line2.length())/2 + 5; i++)
		cout << " ";
	cout << char(186) << endl << char(186);
	for (int i = 0; i < b_string + 10; i++)
		cout << " ";//row of white
	cout << char(186) << endl << char(200);//cap the bottom left corner
	for (int i = 0; i < b_string + 10; i++)
		cout << char(205);//final width
	cout << char(188) << endl << endl;//last corner and endl twice
    setcolor();
}
