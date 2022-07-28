//**************************************************************//
//  Name    : xxxxxxxxxxxx, xxxxxxxxxxx                         //
//  Author  : Lautaro Beutel                                    //
//  Date    : xx, xx, xx                                        //
//  Version : 1.0                                               //
//  Notes   : Descripcion programa                              //
//          :                                                   //
//****************************************************************

#include <stdio.h>
#include <math.h>

#define Modulo(x, y) sqrt((x)*(x) + y*y)



int main(void){         //principio funcion main
    float x, y;
    x = 2;
    y = 3;
    float m = Modulo(2+2, y);
    printf("%f", m);


    return 0;           //finalizacion exitosa del codigo
}//fin de de la funcion main