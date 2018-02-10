#include <iostream>
using namespace std;
unsigned long long fib(unsigned long long n);
int main(){

    unsigned long long n=0;

    for (int i = 0; i < 94; i++){
        if (i > 0){
            n = fib(i);
            cout << i << "     " << n << endl;}}
    return 0;
}
//unisnged long long can only do Fib to 93
unsigned long long fib(unsigned long long n){
  unsigned long long current = 1;
  unsigned long long next = 0;
  unsigned long long previous = 0;
  unsigned long long i = 2;
  while (i <= n){
    next = previous + current;
    previous = current;
    current = next;
    i++;}
  return current;
}
