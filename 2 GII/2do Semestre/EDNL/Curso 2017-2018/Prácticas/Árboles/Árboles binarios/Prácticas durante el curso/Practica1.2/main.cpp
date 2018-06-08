#include <iostream>
#include "abin_E-S.h"
#include "ABIN.h"

using namespace std;
typedef char tElto;
const tElto fin = '#'; // fin de lectura

template <typename T> int altura(const Abin<T>& A, typename Abin<T>::nodo n);

int main()
{
    int n;

    Abin<tElto> A;
    cout << "*** Lectura del árbol binario A ***\n";
    rellenarAbin(A, fin); // desde std::cin
    cout << "Arbol rellenado con exito."<<endl;

    n=altura(A, A.raizB());
    cout << "La altura es: "<<n<<endl;

    return 0;
}

template <typename T> int altura(const Abin<T>& A, typename Abin<T>::nodo n){
    if(n==A.NODO_NULO){
        return -1;
    }else{
        return 1 + max(altura(A,A.hijoIzqdoB(n)), altura(A,A.hijoDrchoB(n)));
    }
}
