/*--------------------------------------------------------*/
/* alg_grafo_E-S.cpp                                      */
/*                                                        */
/* Implementación de operadores de inserción en flujos de */
/* salida para visualizar los resultados de los           */
/* algoritmos de grafos implementados en                  */
/* alg_grafoMA.[h|cpp]                                    */
/*                                                        */
/* Estructuras de Datos no Lineales                       */
/* ©2016 José Fidel Argudo                                */
/*--------------------------------------------------------*/

#include "grafoMA.h"   // grafo no ponderado
#include "listaenla.h" // para mostrar recorridos
#include "matriz.h"    // matriz cuadrada
#include <ostream>
#include <iomanip>           // std::setw

using std::ostream;

// Inserción de una Lista<Grafo::vertice> en un ostream (para probar recorridos)
ostream& operator <<(ostream& os, const Lista<Grafo::vertice>& L)
{
   typedef Lista<Grafo::vertice>::posicion posicion;
   for (posicion i = L.primera(); i != L.fin(); i = L.siguiente(i))
      os << L.elemento(i) << ' ';
   return os;
}

// Inserta una matriz<T> en un flujo de salida (para probar Floyd)
template <typename T>
ostream& operator << (ostream& os, const matriz<T>& m);

// Inserta una matriz<bool> en un flujo de salida (para probar Warshall)
template <>
ostream& operator << <bool>(ostream& os, const matriz<bool>& m)
{
   const size_t n = m.dimension();
   os << "   ";
   for (size_t j = 0; j < n; ++j)
      os << std::setw(3) << j;
   os << std::endl;
   for (size_t i = 0; i < n; ++i) {
      os << std::setw(3) << i;
      for (size_t j = 0; j < n; ++j)
         os << std::setw(3) << m[i][j];
      os << std::endl;
   }
   return os;
}
