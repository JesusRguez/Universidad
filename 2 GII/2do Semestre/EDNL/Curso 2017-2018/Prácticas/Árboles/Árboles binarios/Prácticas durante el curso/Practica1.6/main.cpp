#include <iostream>
#include "abin_E-S.h"
#include "ABIN.h"
#include <math.h>

using namespace std;

typedef char tElto;
const tElto fin = '#'; // fin de lectura

template <typename T> int desequilibrio(const Abin<T>& A, typename Abin<T>::nodo n);
template <typename T> int maximog(int n, int m);
template <typename T> int alturag(const Abin<T>& A, typename Abin<T>::nodo n);


int main()
{
    int n;

    Abin<tElto> A;
    cout << "*** Lectura del árbol binario A ***\n";
    rellenarAbin(A, fin); // desde std::cin
    cout << "Arbol rellenado con exito."<<endl;

    n=desequilibrio(A, A.raizB());
    cout << "El desequilibrio es: "<<n<<endl;

    return 0;
}

template <typename T> int desequilibrio(const Abin<T>& A, typename Abin<T>::nodo n){
    if(n==A.NODO_NULO){
        return 0;
    }else{
        return max(alturag(A,A.hijoIzqdoB(n))-alturag(A,A.hijoDrchoB(n)), max(alturag(A, A.hijoIzqdoB(n)), alturag(A, A.hijoDrchoB(n))));
    }
}

int maximog(int n, int m){
    if(n<m){
        return m;
    }else{
        return n;
    }
}

template <typename T> int alturag (const Abin<T>& A, typename Abin<T>::nodo n)
{
 if(n==A.NODO_NULO)
    return 0;
 else
    return 1+maximog(alturag(A, A.hijoIzqdoB(n)), alturag(A, A.hijoDrchoB(n)));
}


