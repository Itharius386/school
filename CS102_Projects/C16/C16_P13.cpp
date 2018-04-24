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

//==============================================================================
//structure to hold 1 year of weather data
struct annualWeather{
    int year;
    double total_annual_rain;
    double avg_annual_rain;
    double avg_annual_temp;
    double annual_h_temp;
    double annual_l_temp;
    int annual_h_month;
    int annual_l_month;
    weatherData monthlyData[12];
};//annualWeather
//initially did this project with an array of pointers to pointers of arrays
//but just making this structure, that held a year of data was much cleaner looking
//also holding the annual info which made it much nicer feeling

//prototypes
bool mainLoop(char *choice, const int data_entered);
string enumMonth(const int mth); //gets a string of the month
weatherData getWeatherData(const int mth = -1, const char t_type = 'F', const string r_type = "inches"); //'set' would be a better term I guess
void displayWeatherData(const weatherData output, const int mth); //displays a month of data
void setAnnualData(vector<annualWeather> &year_data); //sets the annual averages/his/lows
void displayAnnualData(const annualWeather yr_report); //displays a year of data
//end prototypes

//BEGIN MAIN
int main(){
time_t timer = time(NULL);
struct tm *year = localtime(&timer); //just used to get the current year - because being reusable.
int current_year = year->tm_year+1900, \
    year_num, year_total, \
    data_entered = 0;
    //year_num is current year we are itterating on, year_total is max years to itterate to
    //current_year is the actual current year
char temp_type = 'F', choice = '0', metric = 'n',year_change = 'n', \
     metric_c[] = {'y','n'}, year_c[] = {'y','n'};
string rain_type = "inches";

vector<annualWeather> report[100];

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
        cout << "How many years of data would you like to enter (Max 100): ";
        GetNumInRange(year_total,100);
        year_num = current_year-year_total;
        //sets year to the lowest (ex. 2018-2 = 2016) we are getting data for
        //report.annualWeather[year_total];
        //array of annualWeather = number of years we need

        for (int year=0; year<year_total; year++){
            (*report)[year].year = current_year - year - 1;
            //keep having to use 'current-i-1' math and it looks ugly
            //also use year so many times it looks like it's spelled wrong - critical feature
            cout << "Year " << current_year - year - 1<< endl;
            for (int month=JANUARY; month<=DECEMBER;month++){
                (*report)[year].monthlyData[month] = getWeatherData(month, temp_type, rain_type); //set monthly level data
                cout << endl;
                //displayWeatherData(report[year].monthlyData[month], month);
                //just for testing
            }
            setAnnualData((*report)[year]); //sets the annual level data
            year_num++; //will end on the current_year
        }
    } //end choice 'a'

    if (choice == 'b') {
        cout << "Would you like to use the metric system? (Does NOT convert) (y/n): ";
        c_in(&metric, metric_c, 2);
        cout << "Current year is " << current_year << ", would you like to change it? (y/n): ";
        c_in(&year_change, year_c, 2);
        if (metric == 'y'){
            temp_type = 'C';
            rain_type = "cm";
        }
        else {
            temp_type = 'F';
            rain_type = "inches";
        }
        if (year_change == 'y' && data_entered == 0){
            cout << "Enter new year: ";
            i_in(&current_year,1);
        }
        else if (data_entered == 1) {
            cout << "Cannot change year with prior data entered" << endl << "Enter to Return to Menu";
            getchar();
        }
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
        for (int i = 0; i < year_total; i++){
            displayAnnualData(report[i]);
        }
        cout << endl << "Press Enter to Return to Menu";
        getchar();
    } //end choice 'c'

    if (choice == 'd'){
        int selected = 0, \
            *select_from = new int [year_total];
        cout<< endl << "Years: "; //which years you can select
        for (int i = 0; i < year_total; i++){
            cout << current_year-i-1 << " ";
            select_from[i] = current_year-i-1;
        }
        cout<< endl << "What year would you like data for: ";
        s_i_in(&selected,select_from,year_total);
        selected = current_year - selected - 1;
        cout << endl << left << setw(10) << "Month" << setw(10) << "Rainfall" << setw(12) << "High Temp" << setw(12) << "Low Temp" << setw(15) << "Average Temp" << endl;
        for (int i = JANUARY; i <= DECEMBER; i++){
            displayWeatherData(report[selected].monthlyData[i], i);
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
    d_in(&input.rainfall,1); //get rainfall, positive only

    cout << "Enter max temperature("<< t_type <<"):     ";
    d_in(&input.h_temp); //get high temp
    while(input.h_temp < -100 || input.h_temp > 140){
        cout << "Temperature must be between -100 and 140 F, try again: ";
        d_in(&input.h_temp); //in range
    }

    cout << "Enter lowest temperature("<< t_type <<"):  ";
    d_in(&input.l_temp); //get low temp
    while(input.l_temp < -100 || input.l_temp > 140){
        cout << "Temperature must be between -100 and 140 F, try again: ";
        d_in(&input.l_temp); //in range
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

//takes in an annualWeather struct and sets the annual data based on the monthly data struct array
void setAnnualData(annualWeather &year_data){
    double sum_rain = 0, avg_rain = 0, \
        high_temp = -100, low_temp = 140, sum_temp = 0, avg_temp = 0;
    int low_month, high_month;
    weatherData *month_data = year_data.monthlyData; //typing year_data.monthlyData.xxxx is too much work when I index it through a pointer instead

    for (int month=JANUARY; month<=DECEMBER;month++){
        //sum data
        sum_rain += month_data[month].rainfall; //sums all rainfall to get annual average and total
        sum_temp += month_data[month].avg_temp; //sums avg temps to get annual avg

        if (month_data[month].h_temp > high_temp){//hi temp checks
            high_temp = month_data[month].h_temp; //annual high temp
            high_month = month; //annual high month
        }
        if (month_data[month].l_temp < low_temp){ //low temp checks
            low_temp = month_data[month].l_temp; //annual low temp
            low_month = month; //annual low month
        }
    }
    //average it out
    avg_rain = sum_rain/12;
    avg_temp = sum_temp/12;

    //just set it all in this block so it would be easy to find
    year_data.total_annual_rain = sum_rain;
    year_data.avg_annual_rain = avg_rain;
    year_data.avg_annual_temp = avg_temp;
    year_data.annual_h_temp = high_temp;
    year_data.annual_l_temp = low_temp;
    year_data.annual_h_month = high_month;
    year_data.annual_l_month = low_month;
} //setAnnualData

//displays a line of annual weather data for a given year
void displayAnnualData(const annualWeather yr_report){
    cout<< left << setw(6) << yr_report.year \
        << setw(10) << yr_report.total_annual_rain \
        << setw(10) << yr_report.avg_annual_rain \
        << setw(10) << enumMonth(yr_report.annual_h_month) \
        << setw(11) << yr_report.annual_h_temp \
        << setw(10) << enumMonth(yr_report.annual_l_month) \
        << setw(11) << yr_report.annual_l_temp << endl;
} //displayAnnualData
