#include <iostream>
#include "abin_E-S.h"
#include "ABIN_VEC1.h"

using namespace std;

typedef char T;
const T fin = '#'; // fin de lectura

int altura(Abin<T> A, Abin<T>::nodo n);

int main()
{
    int n;
//    Abin nodo;

    Abin<T> A(500);
    cout << "*** Lectura del árbol binario A ***\n";
    rellenarAbin(A, fin); // desde std::cin
    cout << "Arbol rellenado con exito."<<endl;
    cout << "Introduzca el nodo al que quiere calcularle la altura: "<<endl;
    cin >> nodo;
    n=altura(A, nodo);
    cout << "La altura es: ";
    cout << n;

    return 0;
}

int altura(Abin<T> A, Abin<T>::nodo n){
    altura_rec(A, nodo);
}
