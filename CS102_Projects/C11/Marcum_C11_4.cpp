/*4. Weather Statistics
Once the data are entered for all the months, the program should calculate and display the average monthly
rainfall, the total rainfall for the year, the highest and lowest temperatures for the
year (and the months they occurred in), and the average of all the monthly average
temperatures.
Input Validation: Only accept temperatures within the range between –100 and +140
degrees Fahrenheit.
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <time.h>
#include <algorithm>
#include "marcum_header.h"
#include "marcum_header.cpp"
//namespace
using namespace std;

//month enum
enum MONTHS {JANUARY, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST, SEPTEMBER, \
             OCTOBER, NOVEMBER, DECEMBER};
//just used for fun

//==============================================================================
//weather structure
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
    weatherData monthlyData[12];
};//annualWeather
//initially did this project with an array of pointers to pointers of arrays
//but just making a structure that held the years data was much cleaner

//prototype
string enumMonth(const int mth); //gets a string of the month
weatherData getWeatherData(const int mth, const char t_type = 'F'); //'set' would be a better term
void displayWeatherData(const weatherData output, const int mth, const int year);

//BEGIN MAIN
int main(){
time_t timer = time(NULL);
struct tm *year = localtime(&timer); //just used to get the year
int current_year = year->tm_year+1900, \
    mnths = 12, year_num, year_total; //year_num is year we are itterating on, year total is max years to itterate to
double rain, hi_temp, lo_temp;
char temp_type = 'F';

display("Weather Report");
cout << "How many years of data would you like to enter: ";
i_in(&year_total,1);
year_num = current_year-year_total;
//sets year to the lowest (ex. 2018-2 = 2016) we are getting data for
annualWeather *report = new annualWeather[year_total];
//array of annualWeather points for the number of years we need

for (int year=0; year<year_num; year++){
    report[year].year = year_num;
    cout << "Year " << current_year << endl;
    for (int month=JANUARY; month<=DECEMBER;month++){
        report[year].monthlyData[month] = getWeatherData(month, temp_type);
        displayWeatherData(report[year].monthlyData[month], month, year);
    }
    year_num++; //will end on the current_year
}


return 0;
} //END MAIN

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
    }
}//enumMonth

//gets a weatherData structure
weatherData getWeatherData(const int mth, const char t_type){
    weatherData input;

    cout << "Enter total rainfall(inches) for " << enumMonth(mth) << ": ";
    d_in(&input.rainfall,1); //get rainfall

    cout << "Enter max temperature("<< t_type <<") for " << enumMonth(mth) << ": ";
    d_in(&input.h_temp); //get high temp
    while(input.h_temp < -100 || input.h_temp > 140){
        cout << "Temperature must be between -100 and 140 F, try again: ";
        d_in(&input.h_temp);} //in range

    cout << "Enter lowest temperature("<< t_type <<") for " << enumMonth(mth) << ": ";
    d_in(&input.l_temp); //get low temp
    while(input.l_temp < -100 || input.l_temp > 140){
        cout << "Temperature must be between -100 and 140 F, try again: ";
        d_in(&input.l_temp);} //in range

    if (input.h_temp < input.l_temp){ //if the low is higher than the high
        cout << "High and Low reversed, fixed that for you." << endl;
        double temp = input.l_temp;
        input.l_temp = input.h_temp;
        input.h_temp = temp;
    }

    input.avg_temp = (input.h_temp+input.l_temp)/2; //calc average

    return input; //return the structure
} //getWeatherData

//displays a line of weather data
void displayWeatherData(const weatherData output, const int mth, const int year){
    cout << left << fixed << setprecision(2) << setw(6) << year \
    << setw(10) << enumMonth(mth) \
    << setw(7) << output.rainfall \
    << setw(7) << output.h_temp \
    << setw(7) << output.l_temp \
    << setw(7) << output.avg_temp << endl;
} //displayWeatherData
