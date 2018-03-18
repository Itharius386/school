#include "marcum_header.h"

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
#if defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__)

void setcolor(int color){
    HANDLE screen;//make handle
    screen = GetStdHandle(STD_OUTPUT_HANDLE);//set the handle to the standard output
    SetConsoleTextAttribute(screen, color);//set the color
}
#else //if not windows
void setcolor(int color){
    return; //just returns
}
#endif


//============================
//  d_in: Asks user for input, will prompt until a real number is entered and assigns it to argument1
//
//  Arg1: double  pointer of input will be assigned here
//  Arg2: int     1 for postives only, 0 for positive or negative (Deaults to 0)
//============================
void d_in(double *input, int pos){
    setcolor(ICOLOR);
    std::cin >> *input;//get a input
    while (std::cin.fail()){//if not a double do it again
        setcolor();
        std::cout << "\aInvalid, try again: ";
        setcolor(ICOLOR);
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cin >> *input;
        }
    if (pos == 1){//if positives only
    while (*input < 0){//check if positive
        setcolor();
        std::cout << "\aPositive Values only: ";
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
    while (true){
        setcolor(ICOLOR);
        std::cin >> *input;//get that character
        *input = tolower(*input);
        for (int i=0;i<array_size;i++){ //check it against the acceptable inputs
            if (*input == tolower(check[i])){
                std::cin.clear();
                std::cin.ignore(256,'\n');
                setcolor();
                return; //if acceptable input break
            }
        }
        //because if you didn't it was wrong and you gotta do it again
        std::cin.clear();
        std::cin.ignore(256,'\n');
        setcolor();
        std::cout << "\aInvalid entry, try agian: ";
    }
}

//============================
//  i_in: Asks user for input, prompts for an integer and assigns to Arg1
//
//  Arg1: int   pointer of input to be assigned
//  Arg2: int   1 for postives only, 0 for positive or negative (Deaults to 0)
//============================
void i_in(int *input, int pos){
    setcolor(ICOLOR);
    std::cin >> *input;
    while (std::cin.fail()){ //if it wasn't an integer
        setcolor();
        std::cout << "\aInvalid, try again: ";
        std::cin.clear();
        std::cin.ignore(256,'\n');
        setcolor(ICOLOR);
        std::cin >> *input;} //get another input
    std::cin.clear();
    std::cin.ignore(256,'\n');
    if (pos == 1){ //if positives only
        while (*input < 0){//and not a positive
            setcolor();
            std::cout << "\aPositive Values only: ";
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
    while (true){
        setcolor(ICOLOR);
        std::cin >> *input;//get an int
        for (int i=0;i<array_size;i++){//check it against the acceptable inputs
            if (*input == check[i]){
                std::cin.clear();
                std::cin.ignore(256,'\n');
                setcolor();
                return;
            }
        }
        //because if you didn't it was wrong and you gotta do it again
        std::cin.clear();
        std::cin.ignore(256,'\n');
        setcolor();
        std::cout << "\aInvalid entry, try agian: ";
    }
}


//============================
//	display:  Provides basic display for a program, good for up to 2 lines
//			  Recommended both lines have same even or odd number of characters
//
//	Arg1:	  string  first line to be printed
//	Arg2:	  string  second line to be printed (defaults to blank, matches an even number of characters in Arg1)
//============================
void display(std::string line1, std::string line2, int color){
	int big_string; //determines which of the 2 lines is longer for width consideration
    int offset = 10; //white space from the edges of the display
	if (line1.length() > line2.length())
		big_string = line1.length();
	else
		big_string = line2.length();
    setcolor(color);
	std::cout << char(201); //print corner
	for (int i = 0; i < big_string + offset; i++)
		std::cout << char(205); //print width
	std::cout << char(187) << std::endl << char(186); //corner + side
	for (int i = 0; i < big_string + offset; i++)
		std::cout << " "; //blank row
	std::cout << char(186) << std::endl << char(186); // side and next line side
	for (int i = 0; i < (big_string - line1.length())/2 + 5; i++)
		std::cout << " ";//print some white space: see loop for math
	std::cout << line1;//print line1
	for (int i = 0; i < (big_string - line1.length())/2 + 5; i++)
		std::cout << " ";//the rest of the line
	std::cout << char(186) << std::endl << char(186); //side and next line side
	for (int i = 0; i < (big_string - line2.length())/2 + 5; i++)
		std::cout << " ";//same as before
	std::cout << line2;//print line2
	for (int i = 0; i < (big_string - line2.length())/2 + 5; i++)
		std::cout << " ";
	std::cout << char(186) << std::endl << char(186);
	for (int i = 0; i < big_string + offset; i++)
		std::cout << " ";//row of white
	std::cout << char(186) << std::endl << char(200);//cap the bottom left corner
	for (int i = 0; i < big_string + offset; i++)
		std::cout << char(205);//final width
	std::cout << char(188) << std::endl << std::endl;//last corner and endl twice
    setcolor();
}


//==============================================================================
//  YesNo:      gets a y/n from user and returns 1 or 0
//
//  phrase:     string to display to prompt user
//==============================================================================
bool YesNo(std::string phrase = " "){
    char choice = '0', choices[] = {'y','n'};
    if (phrase == " ")
        std::cout << "Would you like to go again? (y/n): ";
    else
        std::cout << phrase << " (y/n): ";
    c_in(&choice,choices,2);
    if (choice == 'y')
        return 1;
    else
        return 0;
}

//
//menu
//
char Menu(const std::string *options, const int max){
    char selection;
    char choices[26];
    for (int i = 0; i < 26; i++)
        choices[i] = ('A' + i); //put A-Z into the choices array
    std::cout<< "Options:" << std::endl;
    for (int i = 0; i < max; i++){ //display each option entered
        std::cout << choices[i] << ": " << options[i] << std::endl;
    }
    std::cout << "Select an option: ";
    c_in(&selection,choices,max); //get a choice from a-max
    return selection; //returns the letter choice (lower case)
}
