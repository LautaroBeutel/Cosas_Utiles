//**************************************************************//
//  Name    : Actividad 10.6                                    //
//  Author  : Lautaro Beutel                                    //
//  Date    : 03/06/2021                                        //
//  Version : 1.0                                               //
//  Notes   : Resolucion de la actividad 10.1                   //
//          : Modificar el programa del ejemplo 10.1            //
//****************************************************************

//#define ACTIVIDAD_A
//A-Usar datos en coma flotante en vez de enteros. Asignar valor inicial 0.3 a "u"

//define ACTIVIDAD_B
//A-Usar datos en doble precicion en vez de enteros. Asignar valor inicial 0.3 x 10^45 a "u"

//#define ACTIVIDAD_C
//A-Usar caracteres en vez de enteros. Asignar valor de "C" a "u"

/*        CODIGO DEL EJEMPLO:
 *  #include <stdio.h>
 *  
 *  void main(){
 *      int u = 3;
 *      int v;
 *      int *pu;
 *      int *pv;
 *
 *      pu = &u ;
 *      v = *pu;
 * 
 *      pv = &v;
 *
 *      printf("\nu=%d\t&u=%X\tpu=%X\t*pu=%d", u, &u, pu, *pu);
 *      printf("\n\nv=%d\t&v=%X\tpv=%X\t*pv=%d", v, &v, pv, *pv);
 *  }
 */

#include <stdio.h>
#if defined(ACTIVIDAD_B)
    #include <math.h>
#endif


int main(void){         //principio funcion main
#if defined(ACTIVIDAD_A)
    float u = 0.3;
    float v;

    float *pu;
    float *pv;
    
    pu = &u;
    v = *pu;
    pv = &v;
    
    printf("\n***************************************************");
    printf("\n\nu=%f\t&u=%p.\tpu=%p.\t*pu=%f", u, &u, pu, *pu);
    printf("\nv=%f\t&v=%p.\tpv=%p.\t*pv=%f\n", v, &v, pv, *pv);
    printf("\n***************************************************");

#endif

#if defined(ACTIVIDAD_B)
    double u = 0.3;
    double v;

    double *pu;
    double *pv;
    
    pu = &u;
    v = *pu;
    pv = &v;
    
    printf("\nu=%d\t&u=%p.\tpu=%p.\t*pu=%d", u, &u, pu, *pu);
    printf("\n\nv=%d\t&v=%p.\tpv=%p.\t*pv=%d", v, &v, pv, *pv);
#endif

#if defined(ACTIVIDAD_C)
    char u = 67;
    char v;

    char *pu;
    char *pv;
    
    pu = &u;
    v = *pu;
    pv = &v;
    
    printf("\nu=%c\t&u=%p.\tpu=%p.\t*pu=%c", u, &u, pu, *pu);
    printf("\n\nv=%c\t&v=%p.\tpv=%p.\t*pv=%c", v, &v, pv, *pv);
#endif
    return 0;           //finalizacion exitosa del codigo
}//fin de de la funcion main