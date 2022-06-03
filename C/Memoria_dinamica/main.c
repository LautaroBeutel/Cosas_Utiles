//**************************************************************//
//  Name    : Memoria dinamica                                  //
//  Author  : Lautaro Beutel                                    //
//  Date    : 03/06/2022                                        //
//  Version : 1.0                                               //
//  Notes   : Programa ejemplo de memoria dinamica              //
//          :                                                   //
//****************************************************************


#include <stdio.h>
#include <stdlib.h>


int main(void){         //principio funcion main

    int n_1 = 20;
    int n_2 = 3;

    int *edad = malloc(sizeof(int));
    double *promedio = malloc(sizeof(double));
    int *cadena = malloc(n_1 * sizeof(char));
    float *lista = malloc(n_2 * sizeof(float));

    *edad = 15;
    *promedio = 17;

    for (int i = 0; i < n_1; i++){
        cadena[i] = i;
    }

    for (int i = 0; i < n_2; i++){
        lista[i] = i;
    }

    printf("Edad:\n\t%d\n", *edad);

    printf("Promedio:\n\t%f\n", *promedio);

    printf("\nCadena:\n\t");
    for (int i = 0; i < n_1; i++){
        printf("%c\t", cadena[i]);
    }

    printf("\nLista:\n\t");
    for (int i = 0; i < n_2; i++){
        printf("%f\t", lista[i]);
    }
    free(edad);
    free(promedio);
    free(lista);
    free(cadena);

    return 0;           //finalizacion exitosa del codigo
}//fin de de la funcion main