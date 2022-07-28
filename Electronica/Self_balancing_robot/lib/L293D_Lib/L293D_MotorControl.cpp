#include <L293D_MotorControl.h>

L293D_MotorControl::L293D_MotorControl(){

}

L293D_MotorControl::~L293D_MotorControl(){

}

void L293D_MotorControl::setup(const uint8_t pin_1, const uint8_t pin_2, const uint8_t pwm){
    _pin1 = pin_1;
    _pin2 = pin_2;
    _pwm = pwm;

    pinMode(_pin1, OUTPUT);
    pinMode(_pin2, OUTPUT);
    pinMode(_pwm, OUTPUT);
}

void L293D_MotorControl::rotate(uint8_t Vel, boolean dir){
    switch (dir)
    {
    case 0:
        digitalWrite(_pin1, LOW);
        digitalWrite(_pin2, HIGH);
        analogWrite(_pwm, Vel);
        break;
    case 1:
        digitalWrite(_pin2, LOW);
        digitalWrite(_pin1, HIGH);
        analogWrite(_pwm, Vel);
        break;
    
    default:
        break;
    }
}