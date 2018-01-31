/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                                         *
 *    Author: James Marcum                                                                 *
 *    Class:  CS102                                                                        *
 *                                                                                         *
 *    Function: Word Game                                                                  *
 *              Get inputs from the user and then tells them a little story                *
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
#include "marcum_header.h"
#include "marcum_header.cpp"
//namespace
using namespace std;

//Class
//technically not all nouns but close enough
class Nouns{
  private:
    //id and name of noun variables
    string name_id, name;
  public:
    //constructor
    Nouns(string id_, string str = ""){name_id = id_; name = str;}
    //get the name or id
    string getName(){return name;}
    string getId(){return name_id;}
    //set name or id, with input for the name from user
    void setName(){
      cout << "Enter a(n) "<< name_id<<": ";
      getline(cin,name);}
    void setId(string str){name_id = str;}
};

//prototypes
void char_per_tick(char);
void string_reader(string);

//BEGIN MAIN
int main(){
  //0 name, 1 city, 2 age, 3 college, 4 job, 5 pet, 6 petname by default
  vector<Nouns> nouns; //={"name","city","age","college","job","pet","petname"};
  //had to comment out the defaults for initializing because quincy c++ std does not allow for easy initialization of vectors
  //init of vector with Nouns objects with Ids - because quincy makes me have to do it the ugly way
  nouns.push_back(Nouns("name"));
  nouns.push_back(Nouns("city"));
  nouns.push_back(Nouns("age"));
  nouns.push_back(Nouns("college"));
  nouns.push_back(Nouns("job"));
  nouns.push_back(Nouns("pet"));
  nouns.push_back(Nouns("petname"));
  //stringstream to put the entire story together as a single string
  stringstream story;
  char settings = 'n', rand_set = 'n', yes_check[] = {'y','n'}, stor_type = 'b', hor_check[] = {'b','h'};
  //seed random gen
  srand(time(0));

  //display
  display("Welcome to Story Time Adventures!","Follow the prompts for a story!");
  cout << "Would you like to check the settings? (y/n): ";
  c_in(&settings,yes_check,2);
  if (settings == 'y'){
    cout<< "#=============#Settings#=============#" << endl \
        << "Randomize the story? (y/n): ";
    c_in(&rand_set,yes_check,2);
    cout<< "Basic or Horror? (b/h): ";
    c_in(&stor_type, hor_check,2);
    //Yes, I know this means you can only change the settings once per run, but it's how I want it.
    system("CLS");
    display("Welcome to Story Time Adventures!","Follow the prompts for a story!");

  }
  //big ol' set block for names
  for (int i = 0; i < 7; i++)
    nouns[i].setName();
  //if the users name was random, get another name and shuffle the vector
  if (rand_set == 'y'){
    random_shuffle(nouns.begin(),nouns.end());
  }
  //get some room
  cout << endl;

  //Tell a story - put it into the stream
  if (stor_type == 'b'){
    story<< "There once was a person named " << nouns[0].getName() << " who lived in " << nouns[1].getName() \
         << ". At the age of " << nouns[2].getName() << ", " << nouns[0].getName() << " went to college at " << nouns[3].getName() \
         << ". " << nouns[0].getName() << " graduated and went to work as a(n) " << nouns[4].getName() << ". Then, " << nouns[0].getName() \
         << " adopted a(n) " << nouns[5].getName() << " named " << nouns[6].getName() << ". They both lived happily ever after!";}
  else { //okay less a horror and more just silly
    story<< "Once upon a time, a stranger named " << nouns[0].getName() << " appeared in the quiet city of " << nouns[1].getName() \
         << ". The gentle folk  of the town were mere " << nouns[4].getName() << "s who only wanted to live their lives in peace. " \
         << nouns[0].getName() << " would not have that, though. With " << nouns[6].getName() << " the mighty war" << nouns[5].getName() << ", " \
         << nouns[0].getName() << " rode into town and took claim of the land, slaying any of the 'peaceful' townsfolk who dared try to stop them. " \
         << nouns[0].getName() << " then renamed the town " << nouns[3].getName() << " after the great and mighty empire from where they hailed. For " << nouns[2].getName() \
         << " years it remained within the power of " << nouns[3].getName() << ", and then the fire nation attacked...";}

  //Story time!
  string_reader(story.str());
  cout << endl;

  return 0;
}
//END MAIN


//Lambda functions don't exist in Quincy's std C++ package (min of C++11). had to make it it's own function
//otherwise replace 'char_per_tick' in string_reader with '[](char c){cout << c; Sleep(80);}' for the same effect without having to make a second named function call
void char_per_tick(char c){
cout << c;
Sleep(80);}

//Story Time Function - String reader
//make it print 1 letter at a time like someone is writing it out in front of you
//iterate over the string from begin to end, lambda expression to take each character and output it followed by pause
//It's important to put the stream into another string instead of converting it with story.str().begin() because it won't end even with a \0
//just put it in a function to clean up main
void string_reader(string str){
  //inits looping ints
  int i,j;
  //loops over the string at console length (~80)
  //adds new line characters to increase readability automatically
  for (i = 1; i < str.length()/80 + 1; i++){
  for (j=i*80; j > 0; j--){
    if (isspace(str[j])){
      str[j] = '\n';
      break;}}
  }
  //actual itteration over the string to print it
  //see above for the function call on the print
  for_each(str.begin(), str.end(),char_per_tick);
}
