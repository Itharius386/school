
class Clock{
private:
    int hours,\
        minutes,\
        seconds;
    simplify_time();
public:
    Clock(){};
    Clock(hr,min,sec){
        hours = hr;
        minutes = min;
        seconds = sec;
    }
    void setHours(int hr) {hours = hr;}
    void setMinutes(int min) {minutes = min;}
    void setSeconds(int sec) {seconds = sec;}
    int getHours() {return hours;}
    int getMinutes() {return minutes;}
    int getSeconds() {return seconds;}
    //overload + - ++() ++(int) --() --(int) < >
    void operator+()
};
