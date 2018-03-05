//============================
//guard
#pragma once
#ifndef FLOATING_ARRAY_HEADER
#define FLOATING_ARRAY_HEADER

//FloatingArray Class
//Using the smallest and largest and just checking when an element is added
//is better for the scope of the program, rather than checking every element
//everytime the getSmallest or getLargest is called.
class FloatingArray{
private:
    int array_size;
    double *number_array, \
    smallest, largest;

public:
    FloatingArray(int as){
        array_size = as;
        number_array = new double[as] { 0 };
        smallest = 0;
        largest = 0;
    }
    FloatingArray(int as, double size){
        array_size = as;
        number_array = new double[as];
        for (int i = 0; i < as; i++)
            number_array[i] = size;
        smallest = size;
        largest = size;
    }
    ~FloatingArray(){ //frees up the memory
        number_array = NULL;
        delete number_array;
        //cout << "Array deleted"; //test for when class goes out of scope
    }
    void setElement(int index, double num){
        number_array[index] = num;
        if (num > largest)
            largest = num;
        else if (num < smallest)
            smallest = num;
    }
    double getElement(int index){
        return number_array[index];
    }
    double getAverage(){
        double avg = 0;
        for (int i = 0; i < array_size; i++){
            avg += number_array[i];
        }
        avg /= array_size;
        return avg;
    }
    double getLargest(){
        return largest;
    }
    double getSmallest(){
        return smallest;
    }
    int getArraySize(){
        return array_size;
    }
};

#endif
