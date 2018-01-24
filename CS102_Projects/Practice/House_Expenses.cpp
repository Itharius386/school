//shows monthly and annual costs for given catagories of expenses

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//expense class - takes in type and amount/month
class Expense{
  private:
//total for month
    double total_mnth;
//name of expense
    string e_name;
  public:
      Expense(double amount, string name){total_mnth = amount; e_name = name;}
      ~Expense(){}

      double getMonth(){return total_mnth;}
      double getYear(){return total_mnth*12;}
      double getDay(){return total_mnth*12/365;}
      string getName(){return e_name;}
};


int main(){
  


  return 0;
}
