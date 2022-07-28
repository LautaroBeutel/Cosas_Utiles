//******************************************************************************//
//  Name    : Interfaz_graficaGTK                                               //
//  Author  : Lautaro Beutel                                                    //
//  Date    : 03/06/2022                                                        //
//  Version : 1.0                                                               //
//  Notes   : Implementacion de las herramientas de "The GTK Proyect"           //
//          : para la creacion de una interfaz grafica                          //
//******************************************************************************//


#include <stdio.h>
#include <conio.h>

int main(void){         //principio funcion main
    float a = 0.1;
    float b = 0.2;

    printf("%0.17f", a + b);
    getch();
    return 0;           //finalizacion exitosa del codigo
}//fin de de la funcion main