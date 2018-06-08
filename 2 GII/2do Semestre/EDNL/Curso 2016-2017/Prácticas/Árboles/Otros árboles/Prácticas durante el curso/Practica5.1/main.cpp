#include <iostream>
#include "ABIN.h"
#include "abin_E-S.h"

using namespace std;

typedef char T;
const T fin = '#'; // fin de lectura

template <typename T> void BorraNodo(const Abin<T>& A, typename Abin<T>::nodo n);

int main()
{
    Abin<T> A;
    cout << "*** Lectura del árbol binario A ***\n";
    rellenarAbin(A, fin); // desde std::cin
    cout << "Arbol A rellenado con exito."<<endl;
    //BorraNodo(A,);
    return 0;
}

template <typename T> void BorraNodo(const Abin<T>& A, typename Abin<T>::nodo n)
{

}
