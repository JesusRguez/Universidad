#include <iostream>
#include "AGEN.h"
#include "agen_E-S.h"

using namespace std;

typedef char T;
const T fin = '#';

template <typename T> int grado_arbol(const Agen<T>& A, typename Agen<T>::nodo n);
template <typename T> int grado_nodo(const Agen<T>& A, typename Agen<T>::nodo n);

int main()
{
    int grado;
    Agen<T> A;
    cout << "*** Lectura del árbol A ***\n";
    rellenarAgen(A, fin); // Desde std::cin
    cout << "Arbol rellenado con exito."<<endl;
    cout << "\n*** Arbol A guardado con exito ***\n";
    grado=grado_arbol(A,A.raiz());
    cout << "El grado del arbol es " << grado << endl;
    return 0;
}


template <typename T> int grado_arbol(const Agen<T>& A, typename Agen<T>::nodo n)
{
    int grado;
    if(n!=Agen<T>::NODO_NULO)
    {
        grado=grado_nodo(A, n);
        n=A.hijoIzqdo(n);
        while(n!=Agen<T>::NODO_NULO)
        {
            grado=max(grado, grado_arbol(A, n));
            n=A.hermDrcho(n);
        }
    }
    return grado;
}

template <typename T> int grado_nodo(const Agen<T>& A, typename Agen<T>::nodo n)
{
    int grado=0;
    if(A.hijoIzqdo(n)!=Agen<T>::NODO_NULO)
    {
        grado=1;
        n=A.hijoIzqdo(n);
        while(A.hermDrcho(n)!=Agen<T>::NODO_NULO)
        {
            grado++;
            n=A.hermDrcho(n);
        }
    }
    return grado;
}
