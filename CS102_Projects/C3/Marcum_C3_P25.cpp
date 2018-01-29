/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                                         *
 *    Author: James Marcum                                                                 *
 *    Class:  CS102                                                                        *
 *                                                                                         *
 *    Function: Word Game                                                                  *
 *              Get inputs from the user and then tell them a little story                 *
 *                                                                                         *
 *                                                                                         *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

//header
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>
#include <windows.h>
#include <sstream>
//namespace
using namespace std;

//prototypes
void display();
void story_time(string);
void lambda_char(char c);

//BEGIN MAIN
int main(){
  //Would have done it as a vector of pairs but was too far beyond what was needed to accomplish the project
  //basic vector of strings is enough - needed it for shuffling
  //0 name, 1 city, 2 age, 3 college, 4 job, 5 pet, 6 petname
  vector<string> nouns(7)// = {"name","city","age","college","job","pet","petname"};
  //had to comment out the defaults and add '(7)' for initializing because quincy c++ std does not allow for '= {}' to initialize vectors
  
  //stringstream to put the entire story together as a single string
  stringstream story;

  //seed random gen
  srand(time(0));

  //display
  display();
  //big ol' getline for all the words
  cout << "Enter a name: ";
  getline(cin,nouns[0]);
  cout << "Enter a city: ";
  getline(cin,nouns[1]);
  cout << "Enter an age: ";
  getline(cin,nouns[2]);
  cout << "Enter a college: ";
  getline(cin,nouns[3]);
  cout << "Enter a profession: ";
  getline(cin,nouns[4]);
  cout << "Enter an animal: ";
  getline(cin,nouns[5]);
  cout << "Enter a petname: ";
  getline(cin,nouns[6]);
  //if the name was random, get another name and shuffle the vector
  if (nouns[0] == "random"){
    cout << "Enter another name: ";
    getline(cin,nouns[0]);
    random_shuffle(nouns.begin(),nouns.end());
  }
  //get some room
  cout << endl;

  //Tell a story - put it into the stream
  story<< "There once was a person named " << nouns[0] << " who lived in " << nouns[1] \
       << ". At the age of " << nouns[2] << ", " << nouns[0] << " went to college at " << nouns[3] \
       << ". " << endl << nouns[0] << " graduated and went to work as a(n) " << nouns[4] << ". Then, " << nouns[0] \
       << " adopted a(n) " << nouns[5] << " named " << nouns[6] << "." << endl << "They both lived happily ever after!\0";
  //Story time!
  story_time(story.str());

  return 0;
}
//END MAIN


//basic display
void display(){
  cout<< "#~~#~~#~~#~~#~~#~~#~~#~~#~~#~~#~~#~~#~~#~~#~~#~~#" << endl \
      << "|       Welcome to Story Time Adventures!       |" << endl \
      << "|        Follow the prompts for a story!        |" << endl \
      << "|         Enter 'random' for a surprise         |" << endl \
      << "#~~#~~#~~#~~#~~#~~#~~#~~#~~#~~#~~#~~#~~#~~#~~#~~#" << endl << endl;}


//Story Time Function
//make it print 1 letter at a time like someone is writing it out in front of you
//iterate over the string from begin to end, lambda expression to take each character and output it followed by pause
//It's important to put the stream into another string instead of converting it with story.str().begin() because it won't end
//just put it in a function to clean up main

void story_time(string story_str){
  for_each(story_str.begin(), story_str.end(),lambda_char);
}

//Lambda functions don't exist in Quincy's std C++ package. had to make it it's own function
//otherwise replace 'lambda_char' above with '[](char c){cout << c; Sleep(80);}' for the same effect without making a second named function call
void lambda_char(char c){
cout << c;
Sleep(80);}

