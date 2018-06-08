#include <iostream>
#include "agen_E-S.h"
#include "AGEN.h"

using namespace std;

typedef char T;
const T fin = '#';

template <typename T> int profundidad(const Agen<T>& A, typename Agen<T>::nodo n);

int main()
{
    int grado;
    Agen<T> A;
    cout << "*** Lectura del árbol A ***\n";
    rellenarAgen(A, fin); // Desde std::cin
    cout << "Arbol rellenado con exito."<<endl;
    cout << "\n*** Arbol A guardado con exito ***\n";
    grado=profundidad(A,A.hermDrcho(A.hijoIzqdo(A.raiz())));
    cout << "La profundidad del arbol es " << grado << endl;
    return 0;
}

template <typename T> int profundidad(const Agen<T>& A, typename Agen<T>::nodo n){
    if(n==A.raiz()){
        return 0;
    }else{
        return 1+profundidad(A, A.padre(n));
    }
}
