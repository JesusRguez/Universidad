#include "cabeceras/Abin.h"
#include <iostream>

using namespace std;

/*

    Parcial Primero de 2016.

    Determinar número de nodos prósperos. Un nodo es próspero si su valor
    es mayor que el de todos y cada uno de sus ascendientes y menor que el de
    todos y cada uno de sus ancestros.
*/


template <typename T>
int numNodosProsperos(const Abin<T>& A){
	return numNodosProsperosRec(A.raizB(), A);
}

template <typename T>
int numNodosProsperosRec(typename Abin<T>::nodo n, const Abin<T>& A){
	if(n == Abin<T>::NODO_NULO)
		return 0;
	else if(esMasPobreQueSusDescendientes(n, n, A) && esMasRicoQueSusAncestros(n, n, A))
		return 1 + numNodosProsperosRec(A.hijoIzqdoB(n), A) + numNodosProsperosRec(A.hijoDrchoB(n), A);
	else
		return numNodosProsperosRec(A.hijoIzqdoB(n), A) + numNodosProsperosRec(A.hijoDrchoB(n), A);

}

template <typename T>
bool esMasPobreQueSusDescendientes(typename Abin<T>::nodo n, typename Abin<T>::nodo r, const Abin<T>& A){
	if(n == Abin<T>::NODO_NULO)
		return true;
	else if(A.elemento(n) > A.elemento(r))
		return esMasPobreQueSusDescendientes(A.hijoIzqdoB(n), r, A) && esMasPobreQueSusDescendientes(A.hijoDrchoB(n), r, A);

	else
		return false;
}


template <typename T>
bool esMasRicoQueSusAncestros(typename Abin<T>::nodo n, typename Abin<T>::nodo r, const Abin<T>& A){
	if(n == Abin<T>::NODO_NULO)
		return true; // No comenzamos pasando el nodo raiz porque pudiera ser nulo
	else if(A.elemento(n) < A.elemento(r))
		return (esMasRicoQueSusAncestros(A.padreB(n), r, A));
	else
		return false;
}