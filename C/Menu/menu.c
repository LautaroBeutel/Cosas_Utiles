#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

void HideCursor();              // El cursor está oculto
void gotoxy(int x, int y);      // Posicionamiento del cursor

typedef struct snake
{
    int x;
    int y;
    struct snake* next;
}snake;

#define WIDTH 100           // Ancho de la ventana de la consola
#define HEIGHT 30           // Altura de la ventana de la consola
#define SNAKEN 4            // La longitud inicial de la serpiente
#define LIFE 3              // Número inicial de vidas
#define SPEED 200           // Velocidad del juego, tiempo de reposo en bucle
#define U 1                 // Usa macros para reemplazar la dirección de acción de la serpiente que necesita ser reemplazada por números
#define D 2                 // El significado del nombre macro es la primera letra de las palabras en inglés en cada dirección
#define L 3                 // El estado de la serpiente, U: Arriba; D: Abajo; L: Izquierda, R: Derecha
#define R 4                 


void dtxxcsh()              // Mapa de salida
{

    for (int i = 1; i < WIDTH-1; i++)        // Salida de las paredes superior e inferior
    {
        gotoxy(i, 26);
        printf("-");
        gotoxy(i, 0);
        printf("-");
    }
    for (int i = 0; i < HEIGHT-3; i++)    // Salida de las paredes izquierda y derecha
    {
        gotoxy(0, i);
        printf("|");
        gotoxy(99, i);
        printf("|");
    }
    gotoxy(24, 28);
    printf("Puntuación: 0 Vida:% d Tiempo: 0",LIFE);   
    // xy 30,28 valor de puntuación disponible 14 espacios
}


int foodx, foody;           // Coordenadas de ubicación de alimentos

void sjcsswhs()             // Genera comida aleatoriamente
{
    srand(time(NULL));      

    foodx = rand() % (WIDTH - 4) + 2;       // Usa la macro para calcular el valor máximo del número aleatorio, necesitas agregar paréntesis

    while (foodx % 2)                       // Si la coordenada x de la comida no es pareja, obtén otra coordenada x
    {
        foodx = rand() % (WIDTH - 4) + 2;   //ancho
    }

    foody = rand() % (HEIGHT - 7) + 3;      //altura

    gotoxy(foodx, foody);
    printf("★");
}

snake* head;			    // Puntero de cabeza de serpiente

void cshs()                 // Inicializa la posición de la serpiente
{   
    snake *tail;            // Puntero de cola de serpiente
    int i;

    tail = (snake*)malloc(sizeof(snake));
    tail->next = NULL;
    tail->x = HEIGHT-6;
    tail->y = 8;

    // La longitud inicial de la serpiente es 5 SERPIENTE
    for (i = 1; i <= SNAKEN; i++)               // Crea una lista vinculada al final de la serpiente
    {
        head = (snake*)malloc(sizeof(snake));
        head->next = tail;

        head->x = 24 + i * 2;                   // head-> x debe ser un número par, que corresponde a un número par de coordenadas de alimentos
        head->y = 8;
        tail = head;                            // En este momento, el puntero de la cola de la serpiente apunta a la cabeza de la serpiente
    }

    while (tail)
    {
        gotoxy(tail->x, tail->y);
        printf("■");
        tail = tail->next;
    }
}

int status = R;	        // Estado de avance de serpiente

snake* p = NULL;        // Puntero de trabajo
snake* nexthead;        // La próxima cabeza de serpiente
int score = 0;          //Puntaje

void snakemove()	    // La serpiente avanza, U arriba, D abajo, L izquierda, R derecha
{
    nexthead = (snake*)malloc(sizeof(snake));

    if (status == U)
    {
        nexthead->y = head->y - 1;  // Determine la siguiente coordenada x, y de la nueva cabeza de serpiente
        nexthead->x = head->x;
    }
    if (status == D)                //debajo
    {
        nexthead->y = head->y + 1;
        nexthead->x = head->x;
    }
    if (status == L)                //izquierda
    {
        nexthead->x = head->x - 2;
        nexthead->y = head->y;
    }
    if (status == R)                //derecho
    {
        nexthead->x = head->x + 2;
        nexthead->y = head->y;
    }
    nexthead->next = head;
    head = nexthead;
    p = head;

    if (p->x == foodx && p->y == foody) // Determinar si la posición de la cabeza de serpiente coincide con la posición de la comida
    {
        while (p)                       // Nodo final de salida
        {
            gotoxy(p->x, p->y);
            if (p == head)
                printf("●");
            else
                printf("■");
            p = p->next;                // Debido a que cada movimiento crea un nuevo nodo principal y luego elimina un nodo final,
        }                               // Entonces, para agregar una sección de cuerpo, simplemente no suelte el nodo final en este bucle y genere el nodo final una vez.
        
        // sjcsswhs (); // Al encontrar comida, se producirá otra comida

        score++;
        gotoxy(32, 28);
        printf("%d", score);
    }
    else
    {
        while (p->next->next)           // No da salida al nodo final
        {
            gotoxy(p->x, p->y);
            if (p == head)
                printf("●");
            else
                printf("■");
            p = p->next;
        }

        gotoxy(p->next->x, p->next->y);
        printf("  ");
        free(p->next);
        p->next = NULL;
    }

    p = head;
    while (p)                       // Si las coordenadas de la comida se actualizan en la serpiente, se generará otra comida *
    {
        if (p->x == foodx && p->y == foody)
            sjcsswhs();
        p = p->next;
    }
}

void czfxhs()                   // Función de dirección de operación, recibe la entrada de teclas del teclado y controla la dirección de la serpiente
{
    char ch = _getch();
    switch (ch)
    {
        case 'w': 
            if(status != D)
                status = U; break;
        case 's': 
            if (status != U)
                status = D; break;
        case 'a': 
            if (status != R)
                status = L; break;
        case 'd': 
            if (status != L)
                status = R; break;
        case ' ': 
            _getch(); break;        // Espacio pausa
    }
}

int yxjstjjsmz_1()                  // Condición de caída de vida 1 muerdete
{
    snake* self = head->next;       // yo es un nodo en la serpiente
    while (self)
    {
        if (self->x == head->x && self->y == head->y) // Compara los miembros de cabeza y yo, la cabeza de serpiente siempre ha existido, y aquí está el cuerpo de serpiente
        {
            return 1;
        }
        self = self->next;
    }
    return 0;
}

int yxjstjjsmz_2()                  // La condición de caída de vida 2 golpea la pared
{
    if (head->x <= 1 || head->x >= 98 || head->y <= 0 || head->y >= 26)
        return 1;
    
    return 0;
}

int i = LIFE - 1;                   // La variable almacena el número de vidas

void qcsytmslbhs()                  // Limpia y libera los rastros que dejó la última serpiente, actualiza la información de vida
{
    p = head;
    int _x_ = p->x;                 // Se usa para guardar la posición de la cabeza de serpiente de la serpiente muerta, se usa para dar salida a la pared caída por la cabeza de serpiente
    int _y_ = p->y;
    while (head)
    {
        gotoxy(head->x, head->y);
        printf("  ");
        head = head->next;
        free(p);
        p = head;
    }
    gotoxy(52, 28);                 // Actualizar la información de vida
    printf("%d", i);

    if (_y_ == 0 || _y_ == HEIGHT - 4)      // Se usa para generar la posición de la cabeza de la serpiente después de que la serpiente muere y se despeja la pared reemplazada por la cabeza de la serpiente
    {
        gotoxy(_x_, _y_);
        printf("--");
    }
    else if (_x_ == WIDTH - 2)
    {
        gotoxy(_x_+1, _y_);
        printf("|");
    }
    else if(_x_ == 0)
    {
        gotoxy(_x_, _y_);
        printf("|");
    }
}

void sbjsjmhs()                     // No se pudo finalizar la interfaz
{
    p = head;                       // Liberar memoria
    while (head)
    {
        head = head->next;
        free(p);
        p = head;
    }

    system("cls");
    gotoxy(45, 12);
    printf("¡juego terminado!");
    gotoxy(44, 14);
    printf("Puntuación final:% d", score);
    gotoxy(0,28);
}

int updatetime()                        // Obtener la hora actual de la computadora una vez
{
    int now;
    SYSTEMTIME system_time;             
    GetLocalTime(&system_time);
    now = system_time.wMinute * 60 + system_time.wSecond;   
    return now;
}

int time_1/* = updatetime() */;                  // Ahorra tiempo cuando el juego acaba de comenzar

void gametime()                             // Escrito en cada bucle
{
	time_1 = updatetime();
    int time_2 = updatetime() - time_1;     // Actualiza la hora después de que comenzó el juego, resta la hora que acaba de comenzar de la hora actual
    gotoxy(72, 28);
    printf("%d s", time_2);
}

int main()//Función principal
{
    system("mode con cols=100 lines=30");   // Establecer el tamaño de la consola
    system("título Juego de serpientes");             // Establecer título
    HideCursor();                           // Ocultar el cursor

    sjcsswhs();                             // Inicializar un alimento aleatorio
    dtxxcsh();                              // Inicializar mapa, información

    for (; i >= 0; i--)                         //vida
    {
        cshs();                                 // Inicializa la posición de la serpiente
        status = R;                             // Inicializar la dirección del movimiento

        while (1)
        {
            snakemove();                        // Animación de acción de serpiente, la dirección está controlada por la variable de control

            if (_kbhit())
            {
                czfxhs();                       // Recibir las teclas del teclado y controlar las variables de control
            }
            
            if (yxjstjjsmz_1() || yxjstjjsmz_2())// Dos condiciones para dejar caer la vida
                break;

            gametime();                         // Actualiza el tiempo del juego

            Sleep(SPEED);
        }
        qcsytmslbhs();                          // Limpia los rastros dejados por la última serpiente y actualiza la información de vida
    }

    sbjsjmhs();                                 // No se pudo finalizar la interfaz

    return 0;
}

void HideCursor()
{
    CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

void gotoxy(int x, int y)
{
    COORD pos = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
