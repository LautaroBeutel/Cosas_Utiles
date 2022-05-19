//**************************************************************//
//  Name    : 74HC595_CODIGO                                    //
//  Author  : Lautaro Beutel                                    //
//  Date    : 18, 05, 2020                                      //
//  Version : 1.0                                               //
//  Notes   : Programa para desplegar un num del tipo byte      //
//          : en un registro de desplazamiento                  //
//****************************************************************
#include <Arduino.h>

#define SRL_DATA 2
#define SHIFT_CLOCK 3
#define LATCH_CLOCK 4

void Escribir(byte DATA){
  shiftOut(SRL_DATA, SHIFT_CLOCK, LSBFIRST, DATA);
  digitalWrite(LATCH_CLOCK, LOW);
  digitalWrite(LATCH_CLOCK, HIGH);
  digitalWrite(LATCH_CLOCK, LOW);
}

void setup() {
  pinMode(SRL_DATA, OUTPUT);
  pinMode(SHIFT_CLOCK, OUTPUT);
  pinMode(LATCH_CLOCK, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  
}

void loop() {
  Escribir(B11011010);
 
}
