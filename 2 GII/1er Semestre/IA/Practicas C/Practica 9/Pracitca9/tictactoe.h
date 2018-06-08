/*******************************************/
/* 		    tictactoe.h                    */
/*       Estrategia MiniMax                */
/*						                   */
/* Asignatura: Inteligencia Artificial     */
/* Grado en Ingenieria Informatica - UCA   */
/*******************************************/

#define N 9


typedef struct tNodo { //Se define el tNodo
        int celdas[N];
        int vacias;
} tNodo;

static int tablero_inicial[N] ={0,0,0, 0,0,0, 0,0,0};

// las posiciones serán numeradas de 0 a 8 de la siguiente forma:
//0 1 2
//3 4 5
//6 7 8


//Cabecera: tNodo *crearNodo(int *)
//Precondición: El vector celdas ha de estar inicializado
//Postcondición: Crea el primer nodo a partir del vector celdas
tNodo *crearNodo(int celdas[N]);

//Cabecera: *NodoInicial()
//Precondición:
//Postcondición: Crea el nodo inicial
tNodo *NodoInicial();

/*tNodo *aplicaJugada(tNodo *actual, int jugador, int jugada)
 actual: es el tablero actual,
 jugador: la marca del jugador que tiene el turno
 jugada: indica en qué posición del tablero pondrá la marca
 devuelve: el nuevo Nodo tras aplicar la jugada */
tNodo *aplicaJugada(tNodo *actual, int jugador, int jugada);

//Cabecera: int esValida(tNodo *, int)
//Precondición: Tanto el tipo tNodo como la jugada han de existir y estar inicializados
//Postcondición: Devuelve 1 si la jugada que vamos a realizar es válida y 0 en caso contrario
int esValida(tNodo *actual, int jugada);

//int terminal(tNodo *actual, int jugador)
// funcion que determina si un nodo es terminal, ha ganado MAX o MIN
// actual: tablero actual
// jugador: 1 si es Max -1 si es Min
//devuelve:  si ha gando MAX 100, si ha ganado MIN -100, empate 0
// si no es terminal tambiŽn devuelve 0
int terminal(tNodo *actual, int jugador);

//Cabecera: void dispNodo(tNodo *)
//Precondición: Ha de existir el tipo tNodo
//Postcondición: Imprime el nodo actual
void dispNodo(tNodo *s);

//Cabecera: int opuesto(int)
//Precondición: La variable jugador ha de estar inicializada
//Postcondición: Devuelve el identificador del jugador contrario
int opuesto( int jugador);

//Cabecera: int lleno (tNodo *)
//Precondición: Ha de existir el tipo tNodo
//Postcondición: Devuelve 1 si el tablero se encuentra lleno y 0 en caso contrario
int lleno(tNodo *s);
