#include "mbed.h"
#include "QEI.h"

//Encoder Class
class encoder{
private:
    QEI wheel;
    float pulse, prevPulse, encodeTicksPerSec, wheelSpeed;
    float sampleTime1, sampleTime2, sampleTime;
    int flag;
    Ticker time1, time2, ticksCalc;

public:
    encoder(PinName chanAPin, PinName chanBPin): wheel(chanAPin, chanBPin, NC, 512)
    {
        encoder::reset();
        sampleTime = 0.01;
        encoder::tickSpeed(sampleTime);
    }
    void reset(){
        pulse = 0;
        prevPulse = 0;
        encodeTicksPerSec = 0;
        wheel.reset();
    }
    /*
    pulse1 = wheel1.getPulses();
                pulse2 = wheel2.getPulses();
                prevPulse1 = pulse1;
                prevPulse2 = pulse2;
    */
    void calcSpeedWheel(){
        pulse = wheel.getPulses();
        encodeTicksPerSec = (pulse - prevPulse)/sampleTime;
        wheelSpeed = (encodeTicksPerSec * 2 * 3.1412159 * 0.00375 * 0.867)*100 / 512;
        prevPulse = pulse;
    }
    void tickSpeed(float tickTime){
        ticksCalc.attach(callback(this, &encoder::calcSpeedWheel), tickTime);
    }
    float getSpeed(){
        return wheelSpeed;
    }
}; 