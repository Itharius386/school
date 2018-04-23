#pragma once


#include <sstream>
using namespace std;

//==============================================================================
class Employee {
protected:
    string employee_name;
    int employee_number;
    string hire_date;
    static int empNumCount;
public:
    Employee(string name, int number, int year = 1900, int month = 1, int day = 1) {
        employee_name = name;
        employee_number = number;
        setHireDate(year,month,day);
        empNumCount++;
    }
    ~Employee() { empNumCount--; }
    string getName() { return employee_name; }
    int getNumber() { return employee_number; }
    string getHireDate() { return hire_date; }
    void setName(string name){ employee_name = name; }
    void setNumber(int num) {
        try
        if (num <= 999 && num >= 0)
            employee_number = num;
        else
            throw InvalidEmployeeNumber;
    }
    void setHireDate(int year, int month, int day){
        stringstream temp;
        temp << day << "/" << month << "/" << year;
        hire_date = temp.str();
    }
    static const int getEmployeeTotal();
};

int Employee::empNumCount = 0;
const int Employee::getEmployeeTotal() { return empNumCount; }

//Employee End
//==============================================================================


//==============================================================================
class ProductionWorker : public Employee {
private:
    //day == 1, night == 2
    int shift;
    double pay_rate;
public:
    ProductionWorker(int shift_time, double rate, string name, int number, \
        int year = 1900, int month = 1, int day = 1) : Employee(name, number, year, month, day) {
            shift = shift_time;
            pay_rate = rate;
    }
    void setRate(double rate) { pay_rate = rate; }
    void setShift(int shift_time) { shift = shift_time; }
    string getShift() {
        if (shift == 1)
            return "Day";
        else
            return "Night";
    }
    double getRate() { return pay_rate; }
};
//ProductionWorker End
//==============================================================================
