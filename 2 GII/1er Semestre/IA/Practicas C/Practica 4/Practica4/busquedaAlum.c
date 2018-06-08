/*******************************************/
/* 		    BUSQUEDA.C                     */
/*						                   */
/* Asignatura: Inteligencia Artificial     */
/* Grado en Ingenieria Informatica - UCA   */
/*******************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "puzle.h"
#include "nodo.h"
#include "listaia.h"
#include "busquedaAlum.h"


void dispCamino(tNodo *nodo)
{
   if (nodo->padre==NULL)
   {
      printf("\n\nInicio:\n");
      dispEstado(nodo->estado);
   }
   else
   {
      dispCamino(nodo->padre);
      dispOperador(nodo->operador);
      dispEstado(nodo->estado);
      printf("\n");
   }
}


void dispSolucion(tNodo *nodo)
{
   dispCamino(nodo);
   printf("Profundidad=%d\n",nodo->profundidad);
   printf("Coste=%d\n",nodo->costeCamino);
}


/* Crea el nodo raíz. */
tNodo *nodoInicial()
{
   tNodo *inicial=(tNodo *) malloc(sizeof(tNodo));

   inicial->estado=estadoInicial();
   inicial->padre=NULL;
   inicial->costeCamino=0;
   inicial->profundidad=0;
   return inicial;
}


/* Expande un nodo. */
Lista expandir(tNodo *nodo)
{
   unsigned op;
   Lista sucesores=CrearLista(MAXI);
  // printf("\nLista de Sucesores de Actual: \n");
   for (op=1;op<=NUM_OPERADORES;op++)
   {
      if (esValido(op,nodo->estado))
      {
         tNodo *nuevo=(tNodo *) malloc(sizeof(tNodo));
         tEstado *s=(tEstado *) malloc(sizeof(tEstado));
         s=aplicaOperador(op,nodo->estado);
         nuevo=(tNodo *) malloc(sizeof(tNodo));
         nuevo->estado=s;
         nuevo->padre=nodo;
         nuevo->operador=op;
         nuevo->costeCamino=nodo->costeCamino + coste(op,nodo->estado);
         nuevo->profundidad=nodo->profundidad+1;
         nuevo->valHeuristica=mal_colocadas(nuevo->estado, estadoObjetivo());
         if (!ListaLlena(sucesores)){
            InsertarUltimo((void *) nuevo,sucesores);
      //      dispEstado(nuevo->estado);
         }
      }
  }
  //system("pause");
  return sucesores;
}


int busqueda()
{
   int objetivo=0;
   int repetido;
   int j=0;
   tNodo *Actual=(tNodo*) malloc(sizeof(tNodo));
   tNodo *insertado=(tNodo*) malloc(sizeof(tNodo));

   tNodo *Inicial=nodoInicial();
   tEstado *Final=estadoObjetivo();

   Lista Abiertos= (Lista) CrearLista(MAXI);
   Lista Cerrados= (Lista) CrearLista(MAXI);
   Lista Sucesores;
   InsertarUltimo((void *) Inicial, Abiertos);

   while (!ListaVacia(Abiertos) && !objetivo)
   {
      Actual= (void *) ExtraerPrimero(Abiertos);
       repetido=buscaRepe(Actual->estado,Cerrados); //Si encuentra algún estado repetido se lo salta para que no entre en él
       if (!repetido)
       {
        InsertarUltimo(Actual, Cerrados);   //Anchura
        system("cls"); //Como está por anchura, no tiene sentido la impresión
        printf("\n ACTUAL: \n");
        dispEstado(Actual->estado);
        system("pause");
        EliminarPrimero(Abiertos);
        objetivo=testObjetivo(Actual->estado);
        }
        else
            objetivo=0;
      if (!objetivo)
      {
         Sucesores = expandir(Actual);
         Abiertos=Concatenar(Abiertos, Sucesores);
         while(j<Sucesores->Nelem)
         {
             insertado=ExtraerElem(Sucesores,j);
             ordena(Abiertos, insertado);
             j++;
         }
      }
   }
    dispSolucion(Actual);
   return objetivo;
}

int buscaRepe(tEstado *s, Lista L1) //Busca estados repetidos y los almacena
{
    int igual = 0, i=0;

    tNodo *extraido=(tNodo*)malloc(sizeof(tNodo));

    while( !igual && i < L1->inicio )
    {
        extraido=ExtraerElem(L1, i);
        if( iguales(s,extraido->estado)==1 )
            igual = 1;
        i++;
    }

    return igual;
}

