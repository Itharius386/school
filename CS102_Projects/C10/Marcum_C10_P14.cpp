/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                                         *
 *    Author: James Marcum                                                                 *
 *    Class:  CS102                                                                        *
 *                                                                                         *
 *    Function: Takes in a string of words without spaces, and produces a sentence         *
 *              I can't think of a easier way to explain it                                *
 *                                                                                         *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
//The most minimum

//header
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "marcum_header.h"
#include "marcum_header.cpp"
//namespace
using namespace std;

//prototypes
bool sentenceCheck(string sentence);
string sentenceConvert(string sentence);

//BEGIN MAIN
int main(){
    string WordsWordsWords, fixed_sentence;

    display("Sentence Fixer 1.01","Fixing your poorly written sentences since 2018",13);

    setcolor(2);
    cout << "Enter a sentence without spaces or punctuation, but capitalize each word." << endl \
    	 <<"Ex: TheQuickBrownFoxJumpedOverTheLazyDog" << endl << endl;
    setcolor();

    do {
		cout << "Enter a sentence: ";
        getline(cin >> ws, WordsWordsWords);
    } while(!sentenceCheck(WordsWordsWords));

    fixed_sentence = sentenceConvert(WordsWordsWords); //The fixer

    cout << endl << "We fixed your sentence:" << endl;
	cout << WordsWordsWords << endl;

    return 0;
}
//END MAIN

//sentenceCheck
//Takes in a string
//returns 1 if it's a sentence
//else returns 0
bool sentenceCheck(string sentence){
    int has_upper = 0;
    for (int i = 0; i < sentence.length(); i++){
        if (!isalpha(sentence[i])){ //is it not a letter?
            cout << "Invalid Sentence, please try again." << endl;
			return 0;
			}
        if (isupper(sentence[i]))
            has_upper = 1;
        }
    if (has_upper && isupper(sentence[0]))
        return 1;
    else{
        cout << "Please fix your capitalization." << endl;
        return 0;
    }
}

//sentenceConvert
//takes in a horrible sentence
//turns it into a real sentence
string sentenceConvert(string sentence){
	stringstream temp;
	temp << sentence[0]; //Put the first letter into the stream
    for (int i = 1; i < sentence.length(); i++){
        if (isupper(sentence[i])){
			//if we are at an uppercase
			temp << " ";
			//insert a space
            temp << char(tolower(sentence[i]));
			//and insert the lowercase of the next word
			}
        else
			//otherwise just insert the letter
		    temp << sentence[i];
		}
	temp << "."; //finish with a period
	return temp.str();
}
