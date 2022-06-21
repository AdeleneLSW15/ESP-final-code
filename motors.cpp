#include "mbed.h"

//Motors Class
class motor{
private:
    PwmOut pwmMotor;
    DigitalOut bipolar, direction;
public:
    motor(PinName pwmPin,PinName bipolarPin, PinName directionPin): pwmMotor(pwmPin), bipolar(bipolarPin), direction(directionPin)
    {
        pwmMotor.period_us(50); //set pwm frequency automatically!
        bipolar.write(0);
        motor::off();
    }
    void setDirection(int direct){
        direction = direct;   
    }
    void forward(float dutyCycle){
        setDirection(0);
        pwmMotor.write(1 - dutyCycle);
    }
    void backward(float dutyCycle){
        setDirection(1);
        pwmMotor.write(1 - dutyCycle);
    }
    void off(){
        setDirection(0);
        pwmMotor.write(1.00);
    }
};
//Kp1 = 0.056, kp2 = 0.057