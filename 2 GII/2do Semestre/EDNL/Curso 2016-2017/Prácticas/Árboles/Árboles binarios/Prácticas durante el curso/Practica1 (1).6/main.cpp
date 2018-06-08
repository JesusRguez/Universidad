#include <iostream>
#include "abin_E-S.h"
#include "ABIN_VEC1.h"

using namespace std;

typedef char T;
const T fin = '#'; // fin de lectura

template <typename T> void preordenAbin (typename Abin<T>::nodo n, const Abin<T>& A);

int desequilibrio_nodo(Abin<T> A, Abin<T>::nodo n);

int altura (Abin<T>::nodo n, Abin<T> A);


int main()
{
    int n;
   Abin nodo;

    Abin<T> A;
    cout << "*** Lectura del árbol binario A ***\n";
    rellenarAbin(A, fin); // desde std::cin
    cout << "Arbol rellenado con exito."<<endl;
    n=desequilibrio(A, A.raizB());
    cout << "La profundidad es: ";
    cout << n;

    return 0;
}

template <typename T>
void preordenAbin (typename Abin<T>::nodo n, const Abin<T>& A)

{
if (n != Abin<T>::NODO_NULO)
{
desequilibrio_nodo(n, A);
preordenAbin(A.hijoIzqdoB(n), A, procesar);
preordenAbin(A.hijoDrchoB(n), A, procesar);
}
}


int desequilibrio_nodo(Abin<T> A, Abin<T>::nodo n)
{
    return abs((altura(A.hijoIzqdoB(n),A) - altura(A.hijoDrchoB(n),A)));
}


int altura (Abin<T>::nodo n, Abin<T> A)
{
 if(n==A.NODO_NULO)
    return 0;
 else
    return 1+maximo(altura(A.hijoIzqdoB(n),A),altura(A.hijoDrchoB(n),A));
}
