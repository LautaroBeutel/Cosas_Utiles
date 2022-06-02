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
byte FILA[] = {0x7f,0xbf,0xdf,0xef,0xf7,0xfb,0xfd,0xfe};

byte X_0[] = {0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0};
byte X_1[] = {0x0,0x0,0x0,0x18,0x18,0x0,0x0,0x0};
byte X_2[] = {0x0,0x0,0x0,0x66,0x66,0x0,0x0,0x0};
byte X_3[] = {0x0,0x18,0x18,0x0,0x0,0x66,0x66,0x0};
byte X_4[] = {0x0,0x66,0x66,0x0,0x0,0x66,0x66,0x0};
byte X_5[] = {0x0,0x66,0x66,0x18,0x18,0x66,0x66,0x0};
byte X_6[] = {0xdb,0xdb,0x0,0xdb,0xdb,0x0,0xdb,0xdb};

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
  int num = 0;

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

  pinMode(LED_BUILTIN, OUTPUT);

}

boolean bandera = 0;

unsigned long tiempo;
int intervalo = 100;

void loop() {
  if (millis() - tiempo > intervalo)
  {
    tiempo = millis();
    num = random(1, 6);
  }
  switch (num)
  {
  case 1: Imprimir(X_1, FILA);
    break;
  case 2: Imprimir(X_2, FILA);
    break;
  case 3: Imprimir(X_3, FILA);
    break;
  case 4: Imprimir(X_4, FILA);
    break;
  case 5: Imprimir(X_5, FILA);
    break;
  case 6: Imprimir(X_6, FILA);
    break;
  
  default:
    break;
  }
  
}