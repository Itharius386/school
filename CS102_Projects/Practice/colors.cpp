#include <iostream>
#include <windows.h>
#include "marcum_header.h"
#include "marcum_header.cpp"
using namespace std;

int main(){
    int i = 0;
    for ( ;i < 256;i++){
        setcolor(i);
        cout << "Test Sentence " << i << endl;}
    setcolor();
    return 0;
}
