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
#define A_SHIFT_CLOCK 3
#define A_LATCH_CLOCK 2

#define B_SRL_DATA 7
#define B_SHIFT_CLOCK 5
#define B_LATCH_CLOCK 6

int intervalo = 1000;
unsigned int tiempo_1 = 0;

void Escribir(int pin_data, int pin_clock, int pin_latch, byte DATA){       //Funcion para enviar info al 74hc595

  
  shiftOut(pin_data, pin_clock, LSBFIRST, DATA);

  digitalWrite(pin_latch, LOW);     //Latch para el registro de las salidas
  digitalWrite(pin_latch, HIGH);
  digitalWrite(pin_clock, LOW);
}

void LETRA_L(){
  Escribir(A_SRL_DATA, A_SHIFT_CLOCK, A_LATCH_CLOCK, B11111111);
  Escribir(B_SRL_DATA, B_SHIFT_CLOCK, B_LATCH_CLOCK, B11111110);

  Escribir(A_SRL_DATA, A_SHIFT_CLOCK, A_LATCH_CLOCK, B11111111);
  Escribir(B_SRL_DATA, B_SHIFT_CLOCK, B_LATCH_CLOCK, B11111101);

  Escribir(A_SRL_DATA, A_SHIFT_CLOCK, A_LATCH_CLOCK, B11111111);
  Escribir(B_SRL_DATA, B_SHIFT_CLOCK, B_LATCH_CLOCK, B11111011);


  Escribir(A_SRL_DATA, A_SHIFT_CLOCK, A_LATCH_CLOCK, B11111111);
  Escribir(B_SRL_DATA, B_SHIFT_CLOCK, B_LATCH_CLOCK, B11110111);


  Escribir(A_SRL_DATA, A_SHIFT_CLOCK, A_LATCH_CLOCK, B11111111);
  Escribir(B_SRL_DATA, B_SHIFT_CLOCK, B_LATCH_CLOCK, B11101111);


  Escribir(A_SRL_DATA, A_SHIFT_CLOCK, A_LATCH_CLOCK, B11111111);
  Escribir(B_SRL_DATA, B_SHIFT_CLOCK, B_LATCH_CLOCK, B11011111);

  Escribir(A_SRL_DATA, A_SHIFT_CLOCK, A_LATCH_CLOCK, B11111111);
  Escribir(B_SRL_DATA, B_SHIFT_CLOCK, B_LATCH_CLOCK, B10111111);


  Escribir(A_SRL_DATA, A_SHIFT_CLOCK, A_LATCH_CLOCK, B11111111);
  Escribir(B_SRL_DATA, B_SHIFT_CLOCK, B_LATCH_CLOCK, B01111111);
}

void setup() {
  pinMode(A_SRL_DATA, OUTPUT);      //declaracion de las salidas
  pinMode(A_SHIFT_CLOCK, OUTPUT);
  pinMode(A_LATCH_CLOCK, OUTPUT);
  
  pinMode(B_SRL_DATA, OUTPUT);      //declaracion de las salidas
  pinMode(B_SHIFT_CLOCK, OUTPUT);
  pinMode(B_LATCH_CLOCK, OUTPUT);

  /* Escribir(A_SRL_DATA, A_SHIFT_CLOCK, A_LATCH_CLOCK, 0xFF);
  Escribir(B_SRL_DATA, B_SHIFT_CLOCK, B_LATCH_CLOCK, 0x00); */

}

void loop() {
  LETRA_L();
}