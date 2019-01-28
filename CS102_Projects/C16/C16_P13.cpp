/*
Modify Programming Project #2 from Chapter 7 (#4 C11) (Rainfall statistics) to use a STL vector
instead of an array. Refer to the Tables if you wish to use any of the member functions.
*/

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                                         *
 *    Author: James Marcum                                                                 *
 *    Class:  CS102                                                                        *
 *                                                                                         *
 *    Function: Weather Reporting Station                                                  *
 *              Gets annual weather data and displays averages                             *
 *                                                                                         *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
 //I had to rewrite this whole thing to get it to work with vectors.

#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>
#include <vector>
#include "marcum_header.h"
#include "marcum_header.cpp"
//namespace
using namespace std;

//month enum
enum MONTHS {JANUARY, FEBRUARY, MARCH, APRIL, MAY, JUNE, \
             JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER};

//==============================================================================
//weather structure for 1 month of weather data
struct weatherData{
    double rainfall;
    double h_temp;
    double l_temp;
    double avg_temp;
};//weatherData

//prototypes
bool mainLoop(char *choice, const int data_entered);
string enumMonth(const int mth); //gets a string of the month
weatherData getWeatherData(const int mth = -1, const char t_type = 'F', const string r_type = "inches"); //'set' would be a better term I guess
void displayWeatherData(const weatherData output, const int mth); //displays a month of data
//end prototypes

//BEGIN MAIN
int main(){
char temp_type = 'F', choice = '0', metric = 'n',year_change = 'n', \
     metric_c[] = {'y','n'}, year_c[] = {'y','n'};
string rain_type = "inches";
int data_entered = 0;

int year;
double total_annual_rain;
double avg_annual_rain;
double avg_annual_temp;
double annual_h_temp;
double annual_l_temp;
int annual_h_month;
int annual_l_month;
vector<weatherData> monthlyData(12);

while (mainLoop(&choice, data_entered)){
    /*
    choices:
    A = Data entry
    B = Settings
    C = Annual display
    D = Months of year display
    E = exit
    */
    if (choice == 'a') {
        if (data_entered == 1){ //delete prior data
            cout << "Overwriting prior data..." << endl;
        }
        data_entered = 1; //data entry flag
        for (int month=JANUARY; month<=DECEMBER;month++){
            cout << endl;
            cout << enumMonth(month) << endl;

            cout << "Enter total rainfall("<<rain_type<<"): ";
            GetNum(monthlyData[month].rainfall,1); //get rainfall, positive only

            cout << "Enter max temperature("<< temp_type <<"):     ";
            GetNum(monthlyData[month].h_temp); //get high temp
            while(monthlyData[month].h_temp < -100 || monthlyData[month].h_temp > 140){
                cout << "Temperature must be between -100 and 140 F, try again: ";
                GetNum(monthlyData[month].h_temp); //in range
            }

            cout << "Enter lowest temperature("<< temp_type <<"):  ";
            GetNum(monthlyData[month].l_temp); //get low temp
            while(monthlyData[month].l_temp < -100 || monthlyData[month].l_temp > 140){
                cout << "Temperature must be between -100 and 140 F, try again: ";
                GetNum(monthlyData[month].l_temp); //in range
            }

            if (monthlyData[month].h_temp < monthlyData[month].l_temp){ //if the low is higher than the high
                cout << "High and Low reversed, fixed that for you." << endl;
                double temp = monthlyData[month].l_temp;
                monthlyData[month].l_temp = monthlyData[month].h_temp;
                monthlyData[month].h_temp = temp;
            } //not fixing this can cause issues when searching for the annual hi/low

            monthlyData[month].avg_temp = (monthlyData[month].h_temp+monthlyData[month].l_temp)/2; //calc average
        } // END LOOP
        double high_temp = -100, low_temp = 140, sum_temp = 0;
        for (int month=JANUARY; month<=DECEMBER;month++){
            //sum data
            total_annual_rain += monthlyData[month].rainfall; //sums all rainfall to get annual average and total
            sum_temp += monthlyData[month].avg_temp; //sums avg temps to get annual avg

            if (monthlyData[month].h_temp > high_temp){//hi temp checks
                annual_h_temp = monthlyData[month].h_temp; //annual high temp
                annual_h_month = month; //annual high month
            }
            if (monthlyData[month].l_temp < low_temp){ //low temp checks
                annual_l_temp = monthlyData[month].l_temp; //annual low temp
                annual_l_month = month; //annual low month
            }
        }
        //average it out
        avg_annual_rain = total_annual_rain/12;
        avg_annual_temp = sum_temp/12;
    } //end choice 'a'

    if (choice == 'b') {
        cout << "There doesn't seem to be anything here..." << endl;
        getchar();
    } //end choice 'b'

    if (choice == 'c'){
        cout << endl;
        setcolor(2);
        cout << left << setw(6) << " " << setw(10) << "Annual" << setw(10) << "Average" << setw(21) << "Annual" << setw(21) << "Annual" << endl;
        cout << left << setw(6) << "Year" << setw(10) << "Rainfall" << setw(10) << "Rainfall" << setw(21) << "High Temp" << setw(21) << "Low Temp" << endl;
        setcolor(11);
        for (int i = 0; i < 80; i++)
            cout << "_";
        setcolor();
        cout<< left << setw(6) << 1900 \
            << setw(10) << total_annual_rain \
            << setw(10) << avg_annual_rain \
            << setw(10) << enumMonth(annual_h_month) \
            << setw(11) << annual_h_temp \
            << setw(10) << enumMonth(annual_l_month) \
            << setw(11) << annual_l_temp << endl;
        cout << endl << "Press Enter to Return to Menu";
        getchar();
    } //end choice 'c'

    if (choice == 'd'){
        cout << endl << left << setw(10) << "Month" << setw(10) << "Rainfall" << setw(12) << "High Temp" << setw(12) << "Low Temp" << setw(15) << "Average Temp" << endl;
        for (int i = JANUARY; i <= DECEMBER; i++){
            displayWeatherData(monthlyData[i], i);
        }
        cout << endl << "Press Enter to Return to Menu";
        getchar();
    } //end choice 'd'

    if (choice == 'e'){
        return 0; //Does really run, but just there to show it exits the program
    } //end choice 'e'
}
return 0;
} //END MAIN

//it's the main loop
bool mainLoop(char *choice, const int data_entered){
system("CLS");
display("Weather Reporting Station","For Your Unbiased Weather Reporting Needs",2);

if (data_entered != 0) { //first cycle choice == '0'
    char choices[] = {'a', 'b', 'c', 'd', 'e'};
    cout<< "Options:" << endl \
        << "A: Enter Weather Data - Will Overwrite" << endl \
        << "B: Check Settings" << endl \
        << "C: Display Annual Data" << endl \
        << "D: Display Monthly Data for Year" << endl \
        << "E: Quit" << endl;
    cout<< endl << "Select Option: ";
    c_in(choice, choices, 5);
    if (*choice == 'e')
        return 0;
    }
else {
    char choices[] = {'a', 'b', 'c'};
    cout<< "Options:" << endl \
        << "A: Enter Weather Data" << endl \
        << "B: Check Settings" << endl \
        << "C: Quit" << endl;
    cout<< endl << "Select Option: ";
    c_in(choice, choices, 3);
    if (*choice == 'c'){
        *choice = 'e';
        return 0;
    }
}
    return 1;
}//mainLoop


//returns the month based on a given value from 0-11
string enumMonth(const int mth){
    switch(mth){
        case(JANUARY):return "January";
        case(FEBRUARY):return "February";
        case(MARCH):return "March";
        case(APRIL):return "April";
        case(MAY):return "May";
        case(JUNE):return "June";
        case(JULY):return "July";
        case(AUGUST):return "August";
        case(SEPTEMBER):return "September";
        case(OCTOBER):return "October";
        case(NOVEMBER):return "November";
        case(DECEMBER):return "December";
        default: return "today*"; //this should never come up, but is relevent for getWeatherData without initialization
    }
}//enumMonth

//makes a weatherData structure and returns it
//month and t_type are only neeed cosmetically
weatherData getWeatherData(const int mth, const char t_type, const string r_type){
    weatherData input;

    cout << enumMonth(mth) << endl;

    cout << "Enter total rainfall("<<r_type<<"): ";
    GetNum(input.rainfall,1); //get rainfall, positive only

    cout << "Enter max temperature("<< t_type <<"):     ";
    GetNum(input.h_temp); //get high temp
    while(input.h_temp < -100 || input.h_temp > 140){
        cout << "Temperature must be between -100 and 140 F, try again: ";
        GetNum(input.h_temp); //in range
    }

    cout << "Enter lowest temperature("<< t_type <<"):  ";
    GetNum(input.l_temp); //get low temp
    while(input.l_temp < -100 || input.l_temp > 140){
        cout << "Temperature must be between -100 and 140 F, try again: ";
        GetNum(input.l_temp); //in range
    }

    if (input.h_temp < input.l_temp){ //if the low is higher than the high
        cout << "High and Low reversed, fixed that for you." << endl;
        double temp = input.l_temp;
        input.l_temp = input.h_temp;
        input.h_temp = temp;
    } //not fixing this can cause issues when searching for the annual hi/low

    input.avg_temp = (input.h_temp+input.l_temp)/2; //calc average

    return input; //return the structure
} //getWeatherData

//displays a line of weather data
void displayWeatherData(const weatherData output, const int mth){
    cout << left << fixed << setprecision(2) \
    << setw(10) << enumMonth(mth) \
    << setw(10) << output.rainfall \
    << setw(12) << output.h_temp \
    << setw(12) << output.l_temp \
    << setw(15) << output.avg_temp << endl;
} //displayWeatherData
