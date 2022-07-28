
/**************************************************

file: demo_tx.c
purpose: simple demo that transmits characters to
the serial port and print them on the screen,
exit the program by pressing Ctrl-C

compile with the command: gcc demo_tx.c rs232.c -Wall -Wextra -o2 -o test_tx

**************************************************/

#include <stdlib.h>
#include <stdio.h>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include "rs232.h"



int main() {
  int i=0,
      /*cport_nr=0,       [> COM1 on winchot <]*/
      cport_nr=7,       /* /dev/ttyUSB0 */
      bdrate=9600;       /* 9600 baud */

  char mode[]={'8', 'N', '1', 0};

  char str[] = {'a', 's', 'd'};

  if(RS232_OpenComport(cport_nr, bdrate, mode, 0)) {
    printf("Can not open comport\n");

    return(0);
  }

  while(1) {
    RS232_SendByte(cport_nr, str[i]);

    printf("sent: %c\n", str[i]);

#ifdef _WIN32
    Sleep(50);
#else
    usleep(1000000);  /* sleep for 1 Second */
#endif

    i++;

    i %= 3;
  }

  return(0);
}

