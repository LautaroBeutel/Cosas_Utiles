//**************************************************************//
//  Name    : xxxxxxxxxxxx, xxxxxxxxxxx                         //
//  Author  : Lautaro Beutel                                    //
//  Date    : xx, xx, xx                                        //
//  Version : 1.0                                               //
//  Notes   : Descripcion programa                              //
//          :                                                   //
//****************************************************************


#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define X_MIN 1
#define X_MAX 118
#define Y_MIN 0
#define Y_MAX 29

void go(int x, int y);
void Frame();
void Menu_principal();

int main(void){         //principio funcion main
    Frame();
    Menu_principal();
    PlaySound("C:\\Users\\lauta\\Trabajos\\Varios\\Codigo_Util\\C\\Menu\\Miranda - Don (La guitarra del Lolo) 8Bits Cover.wav", NULL, SND_ASYNC);
    go(10, 10);
    system("pause");
    return 0;
}

void Menu_principal(){
    go((X_MAX / 2) - 5, Y_MIN + 1);
    printf("MENU PRINCIPAL");
    go(X_MIN + 1, Y_MAX - 2);
    printf("LAUTARO BEUTEL");
}

void Frame(){
    go(X_MIN, Y_MIN);
    printf("%c", 201);

    go(X_MAX, Y_MIN);
    printf("%c", 187);

    go(X_MIN, Y_MAX);
    printf("%c", 200);

    go(X_MAX, Y_MAX);
    printf("%c", 188);

    for(int i = X_MIN + 1; i < X_MAX; i++){
        go(i, Y_MIN);
        printf("%c", 205);
        go(i, Y_MIN + 2);
        printf("%c", 205);
        go(i, Y_MAX - 3);
        printf("%c", 205);
        go(i, Y_MAX);
        printf("%c", 205);
    }

    for(int i = Y_MIN + 1; i < Y_MAX; i++){

        if ((i == (Y_MIN + 2))
                || (i == (Y_MAX - 3))){
            go(X_MIN, i);
            printf("%c", 204);
            go(X_MAX, i);
            printf("%c", 185);
        }
        else{
            go(X_MIN, i);
            printf("%c", 186);
            go(X_MAX, i);
            printf("%c", 186);
        }
        
        
    }
}

void go(int x, int y) {
	// Obtener handle de la consola
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	// Establecer posición del nuevo cursor
	COORD pos;
	pos.X = x;
	pos.Y = y;
	// Colocar el cursor en el nuevo sitio
	SetConsoleCursorPosition(hConsole, pos);
}