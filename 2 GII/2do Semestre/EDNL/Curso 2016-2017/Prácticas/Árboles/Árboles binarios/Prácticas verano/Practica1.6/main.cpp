#include <iostream>
#include <stdlib.h>
#include "ABIN.h"
#include "abin_E-S.h"

using namespace std;

typedef char T;
const T fin = '#'; // fin de lectura

void preordenAbin (const Abin<T>& A, Abin<T>::nodo n, int* a);
int desequilibrio(const Abin<T>& A, Abin<T>::nodo n);
int altura (const Abin<T>& A, Abin<T>::nodo n);

int main()
{
    int n=0;

    Abin<T> A;

    cout << "*** Lectura del árbol binario A ***\n";
    rellenarAbin(A, fin); // desde std::cin
    cout << "Arbol rellenado con exito."<<endl;

    preordenAbin(A, A.raizB(), &n);

    cout<<"El desequilibrio es: "<<n<<endl;

    return 0;
}

int altura (const Abin<T>& A, Abin<T>::nodo n)
{
    if(n==A.NODO_NULO)
        return 0;
    else
        return 1+max(altura(A, A.hijoIzqdoB(n)), altura(A, A.hijoDrchoB(n)));
}

int desequilibrio(const Abin<T>& A, Abin<T>::nodo n)
{
    return abs(altura(A, A.hijoIzqdoB(n)) - altura(A, A.hijoDrchoB(n)));
}

void preordenAbin (const Abin<T>& A, Abin<T>::nodo n, int* a)
{
    if (n != Abin<T>::NODO_NULO)
    {
        *a=max(*a, desequilibrio(A, n));
        preordenAbin(A, A.hijoIzqdoB(n), a);
        preordenAbin(A, A.hijoDrchoB(n), a);
    }

}
