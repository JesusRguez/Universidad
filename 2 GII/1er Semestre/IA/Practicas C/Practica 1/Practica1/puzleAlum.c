/*******************************************/
/* 		      PUZLE.C                      */
/*						                   */
/* Asignatura: Inteligencia Artificial     */
/* Grado en Ingenieria Informatica - UCA   */
/*******************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//esto es una prueba
#include "puzle.h"





tEstado *crearEstado(int celdas[N][N])
{
   tEstado *estado = (tEstado *) malloc(sizeof(tEstado));
   int i, j, ficha;

   for (i=0;i<N;i++)
      for (j=0;j<N;j++)
      {
         ficha=celdas[i][j];
         estado->celdas[i][j]=ficha;
         estado->fila[ficha]=i;
         estado->col[ficha]=j;
      }
   return estado;
}



tEstado *estadoInicial()
{
   return crearEstado(puzle_inicial);
}



tEstado *estadoObjetivo()
{
   return crearEstado(puzle_final);
}

int coste(unsigned op, tEstado *estado)
{
   return 1;
}

/* VISUALIZACIÓN DE ESTADOS Y OPERADORES*/


void dispEstado(tEstado *estado)
{
   int i,j;

   for (i=0; i<N; i++)
   {
      for (j=0; j<N; j++)
         printf("%d",estado->celdas[i][j]);
      printf("\n");
   }
   printf("\n");
}


void dispOperador(unsigned op)
{
   switch(op)
   {
      case ARRIBA:    printf("Movimiento ARRIBA:\n"); break;
      case ABAJO:     printf("Movimiento ABAJO:\n"); break;
      case IZQUIERDA: printf("Movimiento IZQUIERDA:\n"); break;
      case DERECHA:   printf("Movimiento DERECHA:\n"); break;
   }
}

// FUNCIONES QUE SE HAN DE IMPLEMENTAR EN LA PRACTICA 1










// Función auxiliar para comprobar si dos puzles tienen las fichas colocadas en el mismo orden en el tablero
int iguales(tEstado *s, tEstado *t)  //recibe dos estados, estado S y estado T
{
    int i,j;
    int n=1;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            if (s->celdas[i][j] != t->celdas[i][j]) //Comprobamos si algun elemento de la matriz S es distinto al de su posicion en T
                n=0;
        }
    }
return n; //Iguales=1 Distinto=0
}






int testObjetivo(tEstado *estado) //Comprueba si es estado "estado" es el estado objetivo
{

tEstado *estadoObjetivo= (tEstado *) malloc(sizeof(tEstado));
memcpy(estadoObjetivo, crearEstado(puzle_final) ,sizeof(tEstado));

return iguales(estado, estadoObjetivo); //Iguales=1 Distinto=0
}





int esValido(unsigned op, tEstado *estado) // Comprueba si se puede realizar el movimiento solicitado
{
    switch (op)
    {
    case ARRIBA:
        if (estado->fila[0] == 0) // Se comprueba las filas del vector en la posicion 0
            return 0;
        else
            return 1;
        break;
    case ABAJO:
        if (estado->fila[0] == (N-1)) // Se comprueba las filas del vector en la posicion 0
            return 0;
        else
            return 1;
        break;
    case IZQUIERDA:
        if (estado->col[0] == 0) // Se comprueba las columnas del vector en la posicion 0
            return 0;
        else
            return 1;
        break;
    case DERECHA:
        if (estado->col[0] == (N-1)) // Se comprueba las columnas del vector en la posicion 0
            return 0;
        else
            return 1;
        break;
    default:
        return 0; // ERROR
    }
}






tEstado *aplicaOperador(unsigned op, tEstado *estado)
{
    int ficha;
    //tEstado *nuevo= (tEstado *) malloc(sizeof(tEstado));
    // NO NECESARIO ***** memcpy(nuevo, estado,sizeof(tEstado)); ******  // Hace una copia del estado

    switch (op)
    {
    case ARRIBA:
        ficha=estado->celdas[estado->fila[0]-1][estado->col[0]]; // Ficha pasa a tomar el valor que tiene el numero colocado en la posicion encima del 0
        estado->celdas[estado->fila[0]-1][estado->col[0]] = 0;  // Dicha posicion pasa a tener el valor 0
        estado->celdas[estado->fila[0]][estado->col[0]]=ficha; // La posicion del 0 pasa a contener el valor de ficha

        break;
    case ABAJO:
        ficha=estado->celdas[estado->fila[0]+1][estado->col[0]]; // Ficha pasa a tomar el valor que tiene el numero colocado en la posicion debajo del 0
        estado->celdas[estado->fila[0]+1][estado->col[0]]=0;    // Dicha posicion pasa a tener el valor 0
        estado->celdas[estado->fila[0]][estado->col[0]]=ficha; // La posicion del 0 pasa a contener el valor de ficha

        break;
    case IZQUIERDA:
        ficha=estado->celdas[estado->fila[0]][estado->col[0]-1]; // Ficha pasa a tomar el valor que tiene el numero colocado en la posicion a la izquierda del 0
        estado->celdas[estado->fila[0]][estado->col[0]-1]=0;    // Dicha posicion pasa a tener el valor 0
        estado->celdas[estado->fila[0]][estado->col[0]]=ficha; // La posicion del 0 pasa a contener el valor de ficha

        break;
    case DERECHA:
        ficha=estado->celdas[estado->fila[0]][estado->col[0]+1]; // Ficha pasa a tomar el valor que tiene el numero colocado en la posicion a la derecha del 0
        estado->celdas[estado->fila[0]][estado->col[0]+1]=0;    // Dicha posicion pasa a tener el valor 0
        estado->celdas[estado->fila[0]][estado->col[0]]=ficha; // La posicion del 0 pasa a contener el valor de ficha

        break;
    default:
        break;
    }
    estado=crearEstado(estado->celdas);
return estado;
}




