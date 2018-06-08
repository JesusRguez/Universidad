/*******************************************/
/* 		    minimaxAlum.h                  */
/*       Estrategia MiniMax                */
/*						                   */
/* Asignatura: Inteligencia Artificial     */
/* Grado en Ingenieria Informatica - UCA   */
/*******************************************/

//Cabecera: tNodo *jugadaAfversario(tNodo *)
//Precondición: Ha de existir el tipo tNodo
//Postcondición: Lleva a cabo la jugada de cada jugador
tNodo *jugadaAdversario(tNodo *t);

//Cabecera: tNodo *PSEUDOminimax(tNodo *)
//Precondición: Ha de existir el tipo tNodo
//Postcondición: Devuelve un nodo con la jugada de MAX
tNodo *PSEUDOminimax(tNodo *Nodo);

tNodo *minimax(tNodo *nodo, int jugador);

int valorMin(tNodo *nodo, int profundidad);

int valorMax(tNodo *nodo, int profundidad);

tNodo *poda_ab(tNodo *nodo, int jugador);

int valorMin_ab(tNodo* nodo, int jugador, int prof, int alfa, int beta);

int valorMax_ab(tNodo* nodo, int jugador, int prof, int alfa, int beta);

int max(int a, int b);

int min(int a, int b);
