#include <iostream>
#include <windows.h>
#include <iomanip>
#include "marcum_header.h"
#include "marcum_header.cpp"
using namespace std;

int main(){
    int i = 0;
    for ( ;i < 256;i++){
        setcolor(i);
        cout << setw(70)<< left << "Test Sentence Code " << i << endl;}
    setcolor();
    return 0;
}
