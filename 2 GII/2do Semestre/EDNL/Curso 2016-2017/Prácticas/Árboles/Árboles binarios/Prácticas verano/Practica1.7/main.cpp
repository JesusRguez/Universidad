#include <iostream>
#include <stdlib.h>
#include "ABIN.h"
#include "abin_E-S.h"

using namespace std;

typedef char T;
const T fin = '#'; // fin de lectura

void preordenAbin (const Abin<T>& A, Abin<T>::nodo n, bool* a, int* alt);
void pseudocompleto(const Abin<T>& A, Abin<T>::nodo n, bool* a, int* alt);
int profundidad (const Abin<T>& A, Abin<T>::nodo n);
int altura (const Abin<T>& A, Abin<T>::nodo n);

int main()
{
    bool n;
    int alt;

    Abin<T> A;

    cout << "*** Lectura del árbol binario A ***\n";
    rellenarAbin(A, fin); // desde std::cin
    cout << "Arbol rellenado con exito."<<endl;

    alt=altura(A, A.raizB());

    preordenAbin(A, A.raizB(), &n, &alt);

    if(n==true)
        cout<<"Es pseudocompleto."<<endl;
    else
        cout<<"No es pseudocompleto."<<endl;

    return 0;
}

void preordenAbin (const Abin<T>& A, Abin<T>::nodo n, bool* a, int* alt)
{
    if (n != Abin<T>::NODO_NULO)
    {
        pseudocompleto(A, n, a, alt);
        preordenAbin(A, A.hijoIzqdoB(n), a, alt);
        preordenAbin(A, A.hijoDrchoB(n), a, alt);
    }

}

void pseudocompleto(const Abin<T>& A, Abin<T>::nodo n, bool* a, int* alt)
{
    if(n!=Abin<T>::NODO_NULO)
    {
        if(((A.hijoIzqdoB(n)!=Abin<T>::NODO_NULO && A.hijoDrchoB(n)!=Abin<T>::NODO_NULO) || (A.hijoIzqdoB(n)==Abin<T>::NODO_NULO && A.hijoDrchoB(n)==Abin<T>::NODO_NULO)) && profundidad(A, n)==*alt-1)
            *a=true;
        else
            *a=false;
    }
}

int profundidad (const Abin<T>& A, Abin<T>::nodo n)
{
    int prof = 0;
    while (n!=Abin<T>::NODO_NULO&&n != A.raizB())
    {
        prof++;
        n=A.padreB(n);
    }
    return prof;
}

int altura (const Abin<T>& A, Abin<T>::nodo n)
{
    if(n==A.NODO_NULO)
        return -1;
    else
        return 1+max(altura(A, A.hijoIzqdoB(n)), altura(A, A.hijoDrchoB(n)));
}

