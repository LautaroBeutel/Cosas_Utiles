//**************************************************************//
//  Name    : xxxxxxxxxxxx, xxxxxxxxxxx                         //
//  Author  : Lautaro Beutel                                    //
//  Date    : xx, xx, xx                                        //
//  Version : 1.0                                               //
//  Notes   : Descripcion programa                              //
//          :                                                   //
//****************************************************************


#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "rs232.h"

#ifdef _WIN32
    #include<windows.h>
#else
    #include <unistd.h>
#endif

int main(void){         //principio funcion main
    int i=0, 
        cport_nr = 7,
        console_speed = 9600;

    char mode[] = {'8', 'N', '1', 0};

    char str[] = {'a', 's', 'd'};

    if(RS232_OpenComport(cport_nr, console_speed, mode, 0)){
        printf("can not open comport\n");

        return 0;
    }

    while (1)
    {
        RS232_SendByte(cport_nr, str[i]);
        printf("sent: %c\n", str[i]);

        Sleep(1000);
        i++;
        i %= 3;
    }
    

    return 0;           //finalizacion exitosa del codigo
}//fin de de la funcion main





