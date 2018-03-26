#pragma once

class Die {
private:
    int value;
    int sides;
public:
    //construct the die and roll a random number
    Die(int s = 6) {
    sides = s;
    value = rand()%sides + 1;
    }
    //roll the die
    void roll() { value = rand()%sides + 1; }
    //get num sides
    int getSides() { return sides; }
    //get value of die
    int getValue() { return value; }
};
