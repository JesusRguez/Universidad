#include <iostream>
#include "abin_E-S.h"
#include "ABIN_VEC1.h"

using namespace std;

typedef char T;
const T fin = '#'; // fin de lectura

int profundidad(Abin<T> A, Abin<T>::nodo n);

int main()
{
    int n;
//    Abin nodo;

    Abin<T> A(500);
    cout << "*** Lectura del árbol binario A ***\n";
    rellenarAbin(A, fin); // desde std::cin
    cout << "Arbol rellenado con exito."<<endl;
    n=profundidad(A, A.raizB());
    cout << "La profundidad es: ";
    cout << n;

    return 0;
}

int profundidad(Abin<T> A, Abin<T>::nodo n){

}
