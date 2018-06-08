#include <iostream>
#include "agen_E-S.h"
#include "AGEN.h"

using namespace std;

typedef char T;
const T fin = '#';

int profundidad(const Agen<T>& A, Agen<T>::nodo n);

int main()
{
    Agen<T> A;
    cout << "*** Lectura del árbol A ***\n";
    rellenarAgen(A, fin); // Desde std::cin
    cout << "Arbol rellenado con exito."<<endl;
    cout << "\n*** Arbol A guardado con exito ***\n";
    int p;
    p=profundidad(A,A.hijoIzqdo(A.hermDrcho(A.hermDrcho(A.hijoIzqdo(A.hermDrcho(A.hijoIzqdo(A.raiz())))))));
    cout << "La profundidad es " << p << endl;
    return 0;
}
//abd##ce#ft##glp#####
//abd##ce#f#glp#####
int profundidad(const Agen<T>& A, Agen<T>::nodo n)
{
    int a=0;
    while(n!=A.raiz())
    {
        a++;
        n=A.padre(n);
    }
    return a;
}
