//**************************************************************//
//  Name    : Matriz_74HC595                                    //
//  Author  : Lautaro Beutel                                    //
//  Date    : 20, 05, 2022                                      //
//  Version : 1.0                                               //
//  Notes   : Este programa utiliza dos registros de            //
//          : desplazamiento para controlar una matriz led      //
//**************************************************************//
#include <Arduino.h>


#define A_SRL_DATA 4
#define A_SHIFT_CLOCK 2
#define A_LATCH_CLOCK 3

#define B_SRL_DATA 7
#define B_SHIFT_CLOCK 5
#define B_LATCH_CLOCK 6

void Escribir(int pin_data, int pin_clock, int pin_latch, byte DATA){       //Funcion para enviar info al 74hc595

  
  shiftOut(pin_data, pin_clock, LSBFIRST, DATA);

  digitalWrite(pin_latch, LOW);     //Latch para el registro de las salidas
  digitalWrite(pin_latch, HIGH);
  digitalWrite(pin_clock, LOW);
}

void LETRA_L(){

}

void setup() {
  pinMode(A_SRL_DATA, OUTPUT);      //declaracion de las salidas
  pinMode(A_SHIFT_CLOCK, OUTPUT);
  pinMode(A_LATCH_CLOCK, OUTPUT);
  
  pinMode(B_SRL_DATA, OUTPUT);      //declaracion de las salidas
  pinMode(B_SHIFT_CLOCK, OUTPUT);
  pinMode(B_LATCH_CLOCK, OUTPUT);
}

void loop() {
}