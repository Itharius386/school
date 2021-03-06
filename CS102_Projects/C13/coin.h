//============================
//guard
#pragma once
#ifndef COIN_HEADER
#define COIN_HEADER

//Coin class
//uses rand%1000 instead of 2 because of randomization issues that crop up with
//rand%2 only really checking a single bit of data.
//==============================================================================
#ifndef COIN_COLOR_H
#define COIN_COLOR_H 12
#endif
#ifndef COIN_COLOR_T
#define COIN_COLOR_T 10
#endif
//colors for headers and tails
#include <string>

class Coin{
private:
    float denomination;
    std::string sideUp;
public:
    Coin(float denom = 0){
        denomination = denom;
        int r = rand()%1000;
        if (r < 500)
            sideUp = "heads";
        else
            sideUp = "tails";
    }
    void toss(){
        int r = rand()%1000;
        if (r < 500)
            sideUp = "heads";
        else
            sideUp = "tails";
    }
    std::string getSideUp(){
        if (sideUp == "heads")
            setcolor(COIN_COLOR_H);
        else
            setcolor(COIN_COLOR_T);
        return sideUp;
    }
    void setDenom(float denom){ //sets numeric value of denomination
        denomination = denom;
    }
    float getDenom(){ return denomination; } //returns the value of the denomination
    std::string getCoinDenom(){ //returns the name of the denomination set
        switch (static_cast<int>(denomination*100)) {
            case 100: return "dollar coin";
            case 50: return "half-dollar coin";
            case 25: return "quarter";
            case 10: return "dime";
            case 5: return "nickel";
            case 1: return "penny";
            default: return "coin";
        }
    }
}; //Coin
//==============================================================================
#endif
