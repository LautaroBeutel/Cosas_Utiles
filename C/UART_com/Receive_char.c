//**************************************************************//
//  Name    : xxxxxxxxxxxx, xxxxxxxxxxx                         //
//  Author  : Lautaro Beutel                                    //
//  Date    : xx, xx, xx                                        //
//  Version : 1.0                                               //
//  Notes   : Descripcion programa                              //
//          :                                                   //
//****************************************************************

#include <stdlib.h>
#include <stdio.h>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include "rs232.h"


int main() {
    int i=0, n,
        /*cport_nr=0,       [> COM1 on winchot <]*/
        cport_nr = 7,       /* /dev/ttyUSB0 */
        console_speed = 9600;       /* 9600 baud */

    char buff[4095];
    char mode[] = {'8', 'N', '1', 0};
        
    if (RS232_OpenComport(cport_nr, console_speed, mode, 0))
    {
        printf("Can not open the comport\n");
    }
    
    while(1) {
        n = RS232_PollComport(cport_nr, buff, 4096);

        if (n > 0)
        {   
            buff[n] = 0;   /* always put a "null" at the end of a string! */

            for(i=0; i < n; i++)
            {
                if(buff[i] < 32)  /* replace unreadable control-codes by dots */
                {
                buff[i] = '.';
                }
            }

            printf("received %i bytes: %s\n", n, (char *)buff);
            Sleep(1000);
        }
        
    }

    return(0);
    }