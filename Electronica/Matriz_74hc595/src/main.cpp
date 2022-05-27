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

#define INICIO_DELAY 1000
#define SALTO_DELAY 5

//*********************************************** Mapas de bits para los caracteres ******************************************************//
byte FILA[] = {B11111110, B11111101, B11111011, B11110111, B11101111, B11011111, B10111111, B01111111};
byte X[] = {B10000001, B01000010, B00100100, B00011000, B00011000, B00100100, B01000010, B10000001};

byte Corazon_datos[] = {
  B00000000,
  B01100110,
  B11111111,
  B11111111,
  B01111110,
  B00111100,
  B00011000,
  B00000000
};

byte Mensaje_datos[] = {
  B00000000,
  B00000000,
  B01010100,
  B01110100,
  B01010100,
  B00000000,
  B00000100,
  B00000000
};
//****************************************************************************************************************************************//

void Escribir(int pin_data, int pin_clock, int pin_latch, byte DATA){       //Funcion para enviar info al 74hc595

  
  shiftOut(pin_data, pin_clock, MSBFIRST, DATA);

  digitalWrite(pin_latch, LOW);     //Latch para el registro de las salidas
  digitalWrite(pin_latch, HIGH);
  digitalWrite(pin_clock, LOW);
}

void Imprimir(byte Dato[], byte fila[]){      //funcion que usar Escribir() para imprimir un caracter a la matriz
  for (int8_t i = 0; i <= 7 ; i++)
  {
    Escribir(A_SRL_DATA, A_SHIFT_CLOCK, A_LATCH_CLOCK, 0x00);
    Escribir(B_SRL_DATA, B_SHIFT_CLOCK, B_LATCH_CLOCK, 0xFF);
    Escribir(A_SRL_DATA, A_SHIFT_CLOCK, A_LATCH_CLOCK, Dato[i]);
    Escribir(B_SRL_DATA, B_SHIFT_CLOCK, B_LATCH_CLOCK, fila[i]);
    //delay(SALTO_DELAY);
  }
}

void setup() {
  pinMode(A_SRL_DATA, OUTPUT);      //declaracion de las salidas
  pinMode(A_SHIFT_CLOCK, OUTPUT);
  pinMode(A_LATCH_CLOCK, OUTPUT);
  
  pinMode(B_SRL_DATA, OUTPUT);      //declaracion de las salidas
  pinMode(B_SHIFT_CLOCK, OUTPUT);
  pinMode(B_LATCH_CLOCK, OUTPUT);

  Escribir(A_SRL_DATA, A_SHIFT_CLOCK, A_LATCH_CLOCK, 0xFF);
  Escribir(B_SRL_DATA, B_SHIFT_CLOCK, B_LATCH_CLOCK, 0x00);
  delay(INICIO_DELAY);

}

void loop() {
  Imprimir(X, FILA);
}