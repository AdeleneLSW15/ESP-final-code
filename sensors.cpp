/*
Test program to show sensor values on LCD screen
Note: Change pins to your microcontroller pins.
*/
#include "mbed.h"

class sensor{
private:
    AnalogIn inputs;
    DigitalOut darlington;
    double reading;
    int sLogic;
public:
    sensor(PinName inputPin,PinName darPin): inputs(inputPin), darlington(darPin) {sensor::clearReading();}
    double getReading(void){
        //reads the digital input pin and return
        
        reading = inputs.read();
        return reading;
    }
    void clearReading(){
        reading = 0;
        sLogic = 0;
    }
    void on(){
        darlington = 1;
    }
    void off(){
        darlington = 0;
        }
    void toggle(){
        if (darlington == 1){
            off();
        }
        else if (darlington == 0){
            on();
        }
        }
    int digitalize(){ //white is between 0.5 and 1.0 black is between 0 and 0.3
        if (getReading() > 0.5){
            sLogic = 1;
            return sLogic;
        
        }
        else {
            sLogic = 0;
            return sLogic;
        }
    }

};
