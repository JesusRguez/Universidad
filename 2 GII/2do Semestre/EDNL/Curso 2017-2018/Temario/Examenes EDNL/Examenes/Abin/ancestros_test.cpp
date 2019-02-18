#include "ancestros.hpp"
#include "cabeceras/abin_E-S.h"


/*

    Parcial Primero de 2016.

    Determinar número de nodos prósperos. Un nodo es próspero si su valor
    es mayor que el de todos y cada uno de sus ascendientes y menor que el de
    todos y cada uno de sus ancestros.

    Ejemplo de árbol:

*/



int main(){
	Abin<int> A;
	rellenarAbin(A, -1);
	cout << numNodosProsperos(A) << " nodos prósperos." << endl;
	return 0;
}