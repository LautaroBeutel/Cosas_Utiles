//**************************************************************//
//  Name    : Archivos                                          //
//  Author  : Lautaro Beutel                                    //
//  Date    : xx, xx, xx                                        //
//  Version : 1.0                                               //
//  Notes   : Manipulacion de archivos                          //
//          :                                                   //
//****************************************************************


#include <stdio.h>
#include <stdint.h>

typedef struct{
    uint32_t tiempo;
    uint16_t valor;
    char tipo_sensor;
} sensores;




int main(void){         //principio funcion main

    sensores data[2], *ptdata_1, *ptdata_2;

    ptdata_1 = &data[0];
    ptdata_2 = &data[1];

    FILE *ptvar;

    ptvar = fopen("test.txt", "r");
    if(ptvar == NULL){
        printf("\nError 404 - test.txt does not exist\n"); 
        return 1;
    }

    

    fclose(ptvar);
    return 0;           //finalizacion exitosa del codigo
}//fin de de la funcion main