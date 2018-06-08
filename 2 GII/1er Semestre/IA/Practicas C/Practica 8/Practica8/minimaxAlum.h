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
