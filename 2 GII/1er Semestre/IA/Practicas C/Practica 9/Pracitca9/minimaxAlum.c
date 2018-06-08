/*******************************************/
/* 		    minimaxAlum.c                  */
/*       Estrategia MiniMax                */
/*						                   */
/* Asignatura: Inteligencia Artificial     */
/* Grado en Ingenieria Informatica - UCA   */
/*******************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIMITE 4
#include "tictactoe.h"



/*tNodo *PSEUDOminimax(tNodo *t) {
     int mejorJugada = -1;
     int puntos = -2;
     int i, temp;
     tNodo *intento=malloc(sizeof(tNodo));
     printf("\n Mi turno: \n");
     for(i = 0; i < 9; i++)
        {
            if (esValida(t,i))
                {
                    intento=aplicaJugada(t,1,i); //Intenta jugada
                    temp=terminal(intento,-1); // Calcula el valor minimax
                    if(temp > puntos)
                    {
                        puntos = temp;
                        mejorJugada = i;
                    }
                }
        }//for
      t=aplicaJugada(t,1,mejorJugada);
      return t;
}*/

tNodo *jugadaAdversario(tNodo *t) {
     int jugada = 0;
     printf("\nJugada ([0..8])?: ");
     scanf("%d", &jugada);
     while (!esValida(t,jugada))
     {
        printf("\n Intenta otra posicion del tablero \n");
        printf("\n");
        printf("\nJugada ([0..8])?: ");
        scanf("%d", &jugada);
     }
     t=aplicaJugada(t,-1,jugada);
     return t;
}

tNodo *minimax(tNodo *nodo, int jugador)
{
    int max, max_actual, jugada, mejor_jugada;
    int profundidad = 1;
    tNodo *intento=malloc(sizeof(tNodo));

    max=-10000;
    for(jugada=0;jugada<N;jugada++)
    {
        if(esValida(nodo,jugada))
        {
            intento=aplicaJugada(nodo,jugador,jugada);
            max_actual=valorMin(intento, profundidad);
            if(max_actual>max)
            {
                max=max_actual;
                mejor_jugada=jugada;
            }
        }
    }
    nodo=aplicaJugada(nodo,jugador,mejor_jugada);
    return nodo;
}

int valorMin(tNodo *nodo, int profundidad)
{
    int valor_min,jugada,jugador=-1;
    if(terminal(nodo,jugador)!=0 && profundidad<LIMITE)     //Aqui hay que comparar si la jugada en la que estamos es distinta del límite. Si lo es devuelve la Heuristica
        valor_min=heuristica(nodo);
    else if(profundidad!=LIMITE)
    {
        valor_min=100000;
        for(jugada=0;jugada<N;jugada++)
        {
            if(esValida(nodo,jugada))
                valor_min=min(valor_min,valorMax(aplicaJugada(nodo,jugador,jugada),profundidad+1));
        }
    }
    return valor_min;
}

int valorMax(tNodo *nodo, int profundidad)
{
    int valor_max,jugada,jugador=1;
    if(terminal(nodo,jugador)==0 && profundidad==LIMITE)    //Aqui hay que comparar si la jugada en la que estamos es distinta del límite. Si lo es devuelve la Heuristica
        valor_max=heuristica(nodo);
    else if(profundidad!=LIMITE)
    {
        valor_max=-100000;
        for(jugada=0;jugada<N;jugada++)
        {
            if(esValida(nodo,jugada))
                valor_max=max(valor_max,valorMin(aplicaJugada(nodo,jugador,jugada),profundidad+1));
        }
    }
    return valor_max;
}

tNodo *poda_ab(tNodo *nodo, int jugador)
{
    int max_actual, jugada, mejorJugada, prof=1, v;
    tNodo *intento=malloc(sizeof(tNodo));
    int alfa=-10000;
    int beta=10000;
    jugada=1;
    while(jugada<=N)
    {
        if (esValida(nodo,jugada))
        {
            intento=aplicaJugada(nodo,jugador,jugada);
            v=valorMin_ab(intento, opuesto(jugador),prof+1,alfa,beta);
            if(v>alfa)
            {
                alfa=v;
                mejorJugada=jugada;
            }
        }
        jugada=jugada+1;
    }
    if (esValida(nodo,mejorJugada))
        nodo=aplicaJugada(nodo,jugador,mejorJugada);
    return nodo;
}

int valorMin_ab(tNodo* nodo, int jugador, int prof, int alfa, int beta)
{
    int vmin, jugada;
    tNodo *intento=malloc(sizeof(tNodo));

    if(terminal(nodo,jugador)==0)
    {
        vmin=heuristica(nodo);
    }
    else if(prof==LIMITE)
    {
        vmin=heuristica(nodo);
    }
    else
    {
        jugada=1;
        while(jugada<=N && alfa<beta)
        {
            if(esValida(nodo,jugada))
            {
                intento=aplicaJugada(nodo,jugador,jugada);
                beta=min(beta,valorMax_ab(intento,opuesto(jugador),prof+1,alfa,beta));
            }
            jugada=jugada+1;
        }
        vmin=beta;
    }
    return vmin;
}

int valorMax_ab(tNodo* nodo, int jugador, int prof, int alfa, int beta)
{
    int vmax,jugada;
    tNodo *intento=malloc(sizeof(tNodo));

    if(terminal(nodo,jugador))
    {
        vmax=heuristica(nodo);
    }
    else if(prof==LIMITE)
    {
        vmax=heuristica(nodo);
    }
    else
    {
        jugada=1;
        while(jugada<=N && alfa<beta)
        {
            if(esValida(nodo,jugada))
            {
                intento=aplicaJugada(nodo,jugador,jugada);
                alfa=max(alfa,valorMin_ab(intento,opuesto(jugador),prof+1,alfa,beta));
            }
            jugada=jugada+1;
        }
        vmax=alfa;
    }
    return vmax;
}

int max(int a, int b)
{
    if (a>b)
        return a;
    else
        return b;
}

int min(int a, int b)
{
    if (a>b)
        return b;
    else
        return a;
}
