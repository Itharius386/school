#include <iostream>

using namespace std;

int main(){
    int *ptr = 0, max;
    cout <<"Make size of array? ";
    cin >> max;
    ptr = new int[max];

    for(int i =0;i<max;i++){
        cout << "Enter value: ";
        cin>>*(ptr+i);
    }
    for(int i = 0; i<max; i++){
        cout << "Value " << i+1 <<" is: " << *(ptr+i) << endl;
    }
    delete [] ptr;
    ptr = NULL;
    return 0;
}
