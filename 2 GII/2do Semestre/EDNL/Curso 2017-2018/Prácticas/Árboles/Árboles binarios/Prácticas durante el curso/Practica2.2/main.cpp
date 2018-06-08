#include <iostream>
#include "abin_E-S.h"
#include "ABIN.h"

using namespace std;

typedef char T;
const T fin = '#'; // fin de lectura

template <typename T> Abin<T> reflejar(const Abin<T>& A, typename Abin<T>::nodo n, const Abin<T>&B, typename Abin<T>::nodo m);


int main()
{
    Abin<T> A;
    cout << "*** Lectura del árbol binario A ***\n";
    rellenarAbin(A, fin); // desde std::cin
    cout << "Arbol A rellenado con exito."<<endl;

    Abin<T> B;
    B=reflejar(A, A.raizB(), B, B.raizB());
    cout << "Arbol reflejado: "<<endl;
    imprimirAbin(B);

    return 0;
}

template <typename T> Abin<T> reflejar(const Abin<T>& A, typename Abin<T>::nodo n, const Abin<T>&B, typename Abin<T>::nodo m){

    if(n!=Abin<T>::NODO_NULO){
        if(n==A.raizB()){
            m=n;
            return reflejar(A, n, B, m);
        }
        if(A.hijoIzqdoB(n)!=Abin<T>::NODO_NULO){
            B.hijoDrchoB(m)=A.hijoIzqdoB(n);
            n=A.hijoIzqdoB(n);
            return reflejar(A, n, B, m);
        }
        if(A.hijoDrchoB(n)!=Abin<T>::NODO_NULO){
            B.hijoIzqdoB(m)=A.hijoDrchoB(n);
            n=A.hijoDrchoB(n);
            return reflejar(A, n, B, m);
        }
    }
}
