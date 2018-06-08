#include <iostream>
#include "agen_E-S.h"
#include "AGEN.h"

using namespace std;

typedef char T;
const T fin = '#';

template <typename T> void busqueda(Agen<T>& A, typename Agen<T>::nodo n, char elem);
template <typename T> void eliminar(Agen<T>& A, typename Agen<T>::nodo n);

int main()
{
    char elem;
    Agen<T> A;
    cout << "*** Lectura del árbol A ***\n";
    rellenarAgen(A, fin); // Desde std::cin
    cout << "Arbol rellenado con exito."<<endl;
    cout << "\n*** Arbol A guardado con exito ***\n";
    cout<<"Introduce el elemento a partir del cual desea podar el arbol: "<<endl;
    cin>>elem;
    busqueda(A, A.raiz(), elem);   //abel##cf#g#h###dj#k###
    cout << "El arbol quedaria asi:" << endl;
    imprimirAgen(A);
    return 0;
}

template <typename T> void busqueda(Agen<T>& A, typename Agen<T>::nodo n, char elem){
    if (n != Agen<T>::NODO_NULO) {
        if(A.elemento(n)==elem){
            eliminar(A, n);
        }
        n = A.hijoIzqdo(n);
        while (n != Agen<T>::NODO_NULO) {
            busqueda(A, n, elem);
            n = A.hermDrcho(n);
        }
    }
}

template <typename T> void eliminar(Agen<T>& A, typename Agen<T>::nodo n){
    if(n!=Agen<T>::NODO_NULO){
        //n=A.hijoIzqdo(n);
        while(A.hijoIzqdo(n)!=Agen<T>::NODO_NULO){
            A.eliminarHijoIzqdo(n);
        }
    }
}
