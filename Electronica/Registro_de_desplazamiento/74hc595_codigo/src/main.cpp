//**************************************************************//
//  Name    : 74HC595_CODIGO                                    //
//  Author  : Lautaro Beutel                                    //
//  Date    : 18, 05, 2022                                      //
//  Version : 1.0                                               //
//  Notes   : Programa para desplegar un num del tipo byte      //
//          : en un registro de desplazamiento                  //
//**************************************************************//
#include <Arduino.h>

#define SRL_DATA 2          //Data Out PIN
#define SHIFT_CLOCK 3       //Register CLK PIN
#define LATCH_CLOCK 4       //Register ouput latch PIN

void Escribir(byte DATA){       //Funcion para enviar info al 74hc595

  
  shiftOut(SRL_DATA, SHIFT_CLOCK, LSBFIRST, DATA);

  digitalWrite(LATCH_CLOCK, LOW);     //Latch para el registro de las salidas
  digitalWrite(LATCH_CLOCK, HIGH);
  digitalWrite(LATCH_CLOCK, LOW);
}

void setup() {
  pinMode(SRL_DATA, OUTPUT);      //declaracion de las salidas
  pinMode(SHIFT_CLOCK, OUTPUT);
  pinMode(LATCH_CLOCK, OUTPUT);

  pinMode(LED_BUILTIN, OUTPUT);
  
}

void loop() {
  Escribir(B11011010);
 
}
