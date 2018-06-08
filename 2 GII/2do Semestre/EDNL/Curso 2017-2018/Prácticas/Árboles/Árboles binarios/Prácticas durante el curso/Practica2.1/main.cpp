#include <iostream>
#include "abin_E-S.h"
#include "ABIN.h"

using namespace std;

typedef char T;
const T fin = '#'; // fin de lectura

template <typename T> bool similarrec(const Abin<T>&A, typename Abin<T>::nodo n, const Abin<T>&B, typename Abin<T>::nodo m);


int main()
{
    Abin<T> A;
    cout << "*** Lectura del árbol binario A ***\n";
    rellenarAbin(A, fin); // desde std::cin
    cout << "Arbol A rellenado con exito."<<endl;

    Abin<T> B;
    cout << "*** Lectura del árbol binario B ***\n";
    rellenarAbin(B, fin); // desde std::cin
    cout << "Arbol B rellenado con exito."<<endl;

    bool p;

    p=similarrec(A, A.raizB(), B, B.raizB());

    return 0;
}


template <typename T> bool similarrec(const Abin<T>&A, typename Abin<T>::nodo n, const Abin<T>&B, typename Abin<T>::nodo m){
    if((n!=Abin<T>::NODO_NULO && m==Abin<T>::NODO_NULO)||(n==Abin<T>::NODO_NULO && m!=Abin<T>::NODO_NULO)){
        return true;
    }else
        return similarrec(A, A.hijoIzqdoB(n), B, B.hijoIzqdoB(m))&&similarrec(A, A.hijoDrchoB(n), B, B.hijoDrchoB(m));
}
