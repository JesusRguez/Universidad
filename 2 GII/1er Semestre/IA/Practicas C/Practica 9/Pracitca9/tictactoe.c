/*******************************************/
/* 		    tictactoe.c                    */
/*       Estrategia MiniMax                */
/*						                   */
/* Asignatura: Inteligencia Artificial     */
/* Grado en Ingenieria Informatica - UCA   */
/*******************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tictactoe.h"

tNodo *estadoInicial()
{
   return crearNodo(tablero_inicial);
}

tNodo *crearNodo(int celdas[N])
{
   tNodo *Nodo = (tNodo *) malloc(sizeof(tNodo));
   int i, c;
   Nodo->vacias=0;
   for (i=0;i<N;i++){
         c=celdas[i];
         Nodo->celdas[i]=c;
         if (c==0)
	      Nodo->vacias=Nodo->vacias+1;
      }
   return Nodo;
}


tNodo *aplicaJugada(tNodo *actual, int jugador, int jugada){
    tNodo *nuevo = (tNodo *) malloc(sizeof(tNodo));
    memcpy(nuevo,actual,sizeof(tNodo));
    nuevo->celdas[jugada]=jugador;
    nuevo->vacias--;  // marca la posición que indica pone la marca del jugador
    return nuevo;
}

int esValida(tNodo *actual, int jugada){
    return (jugada>=0 && jugada<9 && actual->celdas[jugada]==0) ;  // si está vacía la posición, la jugada es válido
}

int opuesto( int jugador){
    return (jugador * -1);//Jugador 1 y Jugador -1
}

int lleno(tNodo *tablero){
    return (tablero->vacias != 0);
}

int terminal(tNodo *Nodo, int jugador)
{
    unsigned opciones[8][3] = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
    int i=0,res=0;
    while (res==0 && i<8) {
      if(Nodo->celdas[opciones[i][0]] != 0 &&
         Nodo->celdas[opciones[i][0]] == Nodo->celdas[opciones[i][1]] &&
         Nodo->celdas[opciones[i][0]] == Nodo->celdas[opciones[i][2]])
           res=Nodo->celdas[opciones[i][2]];  //indica que jugador ocupa las casillas ganadoras
      i++;
    }
    return res*100;
}

//0 1 2
//3 4 5
//6 7 8

int heuristica (tNodo *actual)
{
    int i,pMAX=0,pMIN=0,suma;
    for(i=0;i<3;i++)    //Columnas
    {
        suma=actual->celdas[i]+actual->celdas[i+3]+actual->celdas[i+6];

        if(suma==0 || (suma!=0 && (actual->celdas[i]!=0 && actual->celdas[i+3]!=0 && actual->celdas[i+6]!=0)))
        {
            //No hace nada pero así conseguimos negar la condición del if
        }
        else
        {
            if(suma>0)
                pMAX++;
            else
                pMIN++;
        }
    }

    for(i=0;i<9;i=i+3)    //Filas
    {
        suma=actual->celdas[i]+actual->celdas[i+1]+actual->celdas[i+2];

        if(suma==0 || (suma!=0 && (actual->celdas[i]!=0 && actual->celdas[i+1]!=0 && actual->celdas[i+2]!=0)))
        {
            //No hace nada pero así conseguimos negar la condición del if
        }
        else
        {
            if(suma>0)
                pMAX++;
            else
                pMIN++;
        }
    }

    suma=actual->celdas[0]+actual->celdas[4]+actual->celdas[8]; //Primera diagonal
    if(suma==0 || (suma!=0 && (actual->celdas[0]!=0 && actual->celdas[4]!=0 && actual->celdas[8]!=0)))
    {
        //No hace nada pero así conseguimos negar la condición del if
    }
    else
    {
        if(suma>0)
            pMAX++;
        else
            pMIN++;
    }

    suma=actual->celdas[2]+actual->celdas[4]+actual->celdas[6]; //Segunda diagonal
    if(suma==0 || (suma!=0 && (actual->celdas[2]!=0 && actual->celdas[4]!=0 && actual->celdas[6]!=0)))
    {
        //No hace nada pero así conseguimos negar la condición del if
    }
    else
    {
        if(suma>0)
            pMAX++;
        else
            pMIN++;
    }

    return pMAX-pMIN;
}

////////////////////////////////////////
//  VISUALIZACIÓN DE NodoS
////////////////////////////////////////

char marca(int i) {
   switch(i) {
     case 1:
          return 'X';
     case 0:
           return ' ';
     case -1:
          return 'O';
     default: return ' ';}
}

void dispNodo(tNodo *b) {
     printf("---+---+---\n");
     printf(" %c | %c | %c\n",marca(b->celdas[0]),marca(b->celdas[1]),marca(b->celdas[2]));
     printf("---+---+---\n");
     printf(" %c | %c | %c\n",marca(b->celdas[3]),marca(b->celdas[4]),marca(b->celdas[5]));
     printf("---+---+---\n");
     printf(" %c | %c | %c\n",marca(b->celdas[6]),marca(b->celdas[7]),marca(b->celdas[8]));
     printf("---+---+---\n\n");
}
