#include <iostream>
#include "abin_E-S.h"
#include "ABIN.h"

using namespace std;
typedef char tElto;
const tElto fin = '#'; // fin de lectura

template <typename T> int profundidaditer(const Abin<T>& A, typename Abin<T>::nodo n);
template <typename T> int profundidadrec(const Abin<T>& A, typename Abin<T>::nodo n);
template <typename T> void encontrarNodo(const Abin<T>& A, typename Abin<T>::nodo n, tElto buscar, typename Abin<T>::nodo endo);

int main()
{
    int n, nrec;

    Abin<tElto> A;
    cout << "*** Lectura del árbol binario A ***\n";
    rellenarAbin(A, fin); // desde std::cin
    cout << "Arbol rellenado con exito."<<endl;
    imprimirAbin(A);

    typename Abin<tElto>::nodo encontrado=A.NODO_NULO;

    encontrado=A.hijoIzqdoB(A.hijoIzqdoB(A.raizB()));
    n=profundidaditer(A, encontrado);
    nrec=profundidadrec(A, encontrado);
    cout << "La profundidad es: "<<n<<endl;
    cout << "La profundidad es: "<<nrec<<endl;

    cout<<A.elemento(encontrado);
    return 0;
}

template <typename T> int profundidaditer(const Abin<T>& A, typename Abin<T>::nodo n){
    int p=-1;

    while(n!=Abin<T>::NODO_NULO)
    {
        p++;
        n=A.padreB(n);
    }
    return p;
}

template <typename T> int profundidadrec(const Abin<T>& A, typename Abin<T>::nodo n){

    if(n==A.raizB())
        return 0;
    else
        return 1 + profundidadrec(A,A.padreB(n));

}
