#include <iostream>
#include "ABIN.h"
#include "abin_E-S.h"

using namespace std;

typedef char tElto;
const tElto fin = '#'; // fin de lectura

template <typename T> int cuentaNodos(const Abin<T>& A, typename Abin<T>::nodo n);

int main()
{
    int n;

    Abin<tElto> A;
    cout << "*** Lectura del árbol binario A ***\n";
    rellenarAbin(A, fin); // desde std::cin
    cout << "Arbol rellenado con exito."<<endl;

    n=cuentaNodos(A,A.raizB());
    cout << "Hay "<<n<<" nodos."<<endl;

    return 0;
}

template <typename T> int cuentaNodos(const Abin<T>& A, typename Abin<T>::nodo n){
    if(n==A.NODO_NULO){
        return 0;
    }else{
        return 1 + cuentaNodos(A, A.hijoIzqdoB(n)) + cuentaNodos(A, A.hijoDrchoB(n));
    }
}
