#include <iostream>
#include "AGEN.h"
#include "agen_E-S.h"

using namespace std;

typedef char T;
const T fin = '#';

template <typename T> int profundidad(const Agen<T>& A, typename Agen<T>::nodo n);
template <typename T> typename Agen<T>::nodo preordenAgen(const Agen<T>& A, char n, typename Agen<T>::nodo m);

int main()
{
    int prof;
    char n;
    Agen<T>::nodo m;
    Agen<T> A;
    cout << "*** Lectura del árbol A ***\n";
    rellenarAgen(A, fin); // Desde std::cin
    cout << "Arbol rellenado con exito."<<endl;
    cout << "\n*** Arbol A guardado con exito ***\n";

    cout << "Introuce el elemento al que le quiere calcular la profundidad: " << endl;
    cin >> n;

    m=preordenAgen(A, n, A.raiz());

    prof=profundidad(A, m);
    cout << "La profundidad del arbol es " << prof << endl;
    return 0;
}


template <typename T> int profundidad(const Agen<T>& A, typename Agen<T>::nodo m)
{
    int prof=0;
    while(m!=A.raiz())
    {
        prof++;
        m=A.padre(m);
    }
    return prof;
}

template <typename T> typename Agen<T>::nodo preordenAgen(const Agen<T>& A, char e, typename Agen<T>::nodo m)
{
    typename Agen<T>::nodo res;
    res=Agen<T>::NODO_NULO;
    if(m!=Agen<T>::NODO_NULO)
    {
        if(e!=A.elemento(m))
        {
            m = A.hijoIzqdo(m);
            while (res==Agen<T>::NODO_NULO && m != Agen<T>::NODO_NULO) {
                res=preordenAgen(A, e, m);
                m = A.hermDrcho(m);
            }
            return res;
        }
        return m;
    }
    return res;
}

