//**************************************************************//
//  Name    : Matriz_74HC595                                    //
//  Author  : Lautaro Beutel                                    //
//  Date    : 20, 05, 2022                                      //
//  Version : 1.0                                               //
//  Notes   : Este programa utiliza dos registros de            //
//          : desplazamiento para controlar una matriz led      //
//**************************************************************//
#include <Arduino.h>

#define A_SRL_DATA_ 2
#define A_SHIFT_CLOCK 3
#define A_LATCH_CLOCK 4

#define B_SRL_DATA 5
#define B_SHIFT_CLOCK 6
#define B_LATCH_CLOCK 7



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