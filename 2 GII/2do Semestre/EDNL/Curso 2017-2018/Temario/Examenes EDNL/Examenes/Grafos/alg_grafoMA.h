/*--------------------------------------------------------*/
/* alg_grafoMA.h                                          */
/*                                                        */
/* Algoritmos para grafos no ponderados representados     */
/* mediante matriz de adyacencia.                         */
/*                                                        */
/* Estructuras de Datos no Lineales                       */
/* ©2016 José Fidel Argudo                                */
/*--------------------------------------------------------*/
/*
Funciones:

   matriz<bool> Warshall(const Grafo& G);
      Determina si hay un camino entre cada par de vértices
      del grafo G.
      Devuelve una matriz booleana A de tamaño n x n, tal que
      A[i][j] == true si existe al menos un camino entre
      el vértice i y el vértice j, y A[i][j] == false si no
      existe ningún camino entre los vértices i y j.

   Lista<Grafo::vertice> Profundidad(const Grafo& G, Grafo::vertice v);
   Lista<Grafo::vertice> Profundidad2(const Grafo& G, Grafo::vertice v);
      Devuelve la lista de vértices del grafo G en el orden dado
      por el recorrido en profundidad, comenzando en el vértice v.

   Lista<Grafo::vertice> Anchura(const Grafo& G, Grafo::vertice v);
      Devuelve la lista de vértices del grafo G en el orden dado
      por el recorrido en anchura, comenzando en el vértice v.

*/

#ifndef ALG_GRAFO_H
#define ALG_GRAFO_H

class Grafo;                         // grafo no ponderado
template <typename T> class matriz;  // matriz cuadrada
template <typename T> class Lista;

matriz<bool> Warshall(const Grafo& G);

/*----------------------------------------------------------------------------*/
/* Recorridos de grafos no ponderados                                         */
/*----------------------------------------------------------------------------*/
template <typename T> class Lista;

Lista<Grafo::vertice> Profundidad(const Grafo& G, Grafo::vertice v);

Lista<Grafo::vertice> Profundidad2(const Grafo& G, Grafo::vertice v);

Lista<Grafo::vertice> Anchura(const Grafo& G, Grafo::vertice v);

#endif   // ALG_GRAFO_H
