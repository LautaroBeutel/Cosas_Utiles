#include <Arduino.h>
#include <L293D_MotorControl.h>

#define ADELANTE 1
#define    ATRAS 0

L293D_MotorControl MotorA;
L293D_MotorControl MotorB;

const uint8_t PIN_1A = 4;
const uint8_t PIN_2A = 5;
const uint8_t PIN_1B = 8;
const uint8_t PIN_2B = 7;

const uint8_t PWM_A = 3;
const uint8_t PWM_B = 6;

void setup() {
  MotorA.setup(PIN_1A, PIN_2A, PWM_A);
  MotorB.setup(PIN_1B, PIN_2B, PWM_B);

  MotorA.rotate(255, ATRAS);
  MotorB.rotate(127, ATRAS);
}

void loop() {
  // put your main code here, to run repeatedly:
}