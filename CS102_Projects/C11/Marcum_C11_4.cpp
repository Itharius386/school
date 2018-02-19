/*4. Weather Statistics
Write a program that uses a structure to store the following weather data for a particular
month:
Total Rainfall
High Temperature
Low Temperature
Average Temperature
The program should have an array of 12 structures to hold weather data for an
entire year. When the program runs, it should ask the user to enter data for each
month. (The average temperature should be calculated.) Once the data are entered
for all the months, the program should calculate and display the average monthly
rainfall, the total rainfall for the year, the highest and lowest temperatures for the
year (and the months they occurred in), and the average of all the monthly average
temperatures.
Input Validation: Only accept temperatures within the range between –100 and +140
degrees Fahrenheit.
5. Weather Statistics Modification
Modify the program that you wrote for Programming Challenge 4 so it defines an
enumerated data type with enumerators for the months ( JANUARY , FEBRUARY , etc.).
The program should use the enumerated type to step through the elements of the
array.*/

#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <algorithm>
#include "marcum_header.h"
#include "marcum_header.cpp"
//namespace
using namespace std;

enum MONTHS {JANUARY, FEBRUARY, MARCH, APRIL, JUNE, JULY, AUGUST, SEPTEMBER, \
             OCTOBER, NOVEMBER, DECEMBER};
struct weatherData{
    double rainfall;
    double h_temp;
    double l_temp;
    //calcs avg temp on demand
};

//Class
class Weather{
private:

    int year;
    int month;
    weatherData data;
public:
    Weather(){}
    Weather(double rf, double htemp, double ltemp){}
    void setDate(int yr, int mth){year = yr; month = mth;}
    void setRainfall(double rf){data.rainfall = rf;}
    void setHTemp(double htemp){data.h_temp = htemp;}
    void setLTemp(double ltemp){data.l_temp = ltemp;}
    int getMonth(){return month;}
    int getYear(){return year;}
    double getRainfall(){return data.rainfall;}
    double getHTemp(){return data.h_temp;}
    double getLTemp(){return data.l_temp;}
    double getAvgTemp(){return data.h_temp/data.l_temp;}
};

int main(){
int year_num;
//Weather *weather_report[12] = NULL;

cout << "Weather Report" << endl;

cout << "How many years of data would you like to enter: ";
i_in(&year_num,1);

map <int, Weather>  

for (int i=0; i<year_num; i++){
    for (int j=0; j<DECEMBER;j++){
        cout << "Enter value: ";

    }
}


return 0;
}
