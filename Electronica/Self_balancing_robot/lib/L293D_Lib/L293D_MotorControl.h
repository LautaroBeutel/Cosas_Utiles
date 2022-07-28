//              >L293D_PINOUT<
//                  +----+
//         1,2 EN  1|    |16  VCC1
//             1A  2|    |15  4A
//             1Y  3|    |14  4Y
//            GND  4|    |13  GND
//            GND  5|    |12  GND
//             2Y  6|    |11  3Y
//             2A  7|    |10  3A
//           VCC2  8|    |9   3,4 EN
//                  +----+

#ifndef _L293D_MOTORCONTROL_H
#define _L293D_MOTORCONTROL_H

#include <Arduino.h>

class L293D_MotorControl{
    public:
        L293D_MotorControl(/* args */);
        ~L293D_MotorControl();
        void setup(const uint8_t pin_1,const uint8_t pin_2, const uint8_t pwm);
        void rotate(uint8_t Vel, boolean dir);
    private:
        uint8_t _pin1, _pin2, _pwm;
        /* data */
    protected:

};

#endif