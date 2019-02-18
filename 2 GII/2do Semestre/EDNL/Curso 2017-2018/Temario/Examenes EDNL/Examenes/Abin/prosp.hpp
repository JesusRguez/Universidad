#ifndef ABIN_E_S_H
#define ABIN_E_S_H

#include <cassert>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Abindinamico.h"

using std::istream;
using std::ostream;
using std::cin;
using std::cout;
using std::endl;

template<class T>
int cuentaProsperos(const Abin<T>& A)
{ return cuentaProsperosRec(A.raizB(), A); }

template<class T>
int cuentaProsperosRec(typename Abin<T>::nodo n, const Abin<T>& A)
{
    if(n == A.NODO_NULO)
        return 0;
    else
    {
        if(esProspero(n, A)) {
            cout << "Soy el nodo " << n << " tengo el valor " << A.elemento(n)
                 << " Y SOY PROSPERO" << endl;
            return 1 + cuentaProsperosRec(A.hijoIzqdoB(n), A)
                + cuentaProsperosRec(A.hijoDrchoB(n), A);

        }
        else{
            cout << "Soy el nodo " << n << " tengo el valor " << A.elemento(n)
                 << " Y-- NO --SOY PROSPERO" << endl;
            return cuentaProsperosRec(A.hijoIzqdoB(n), A)
                + cuentaProsperosRec(A.hijoDrchoB(n), A);
        }
    }
}

template<class T>
bool esProspero(typename Abin<T>::nodo n, const Abin<T>& A)
{
    if(masRicoQueAncestros(n, n, A) and masPobreQueDescendientes(n, n, A))
        return true;
    else
        return false;
}

template<class T>
bool masRicoQueAncestros(typename Abin<T>::nodo n, typename Abin<T>::nodo r, const Abin<T>& A)
{
    if(A.padreB(r) == A.NODO_NULO)
        return true;
    else if(A.elemento(n) > A.elemento(A.padreB(r)))
        return masRicoQueAncestros(n, A.padreB(r), A);
    else
        return false;
}

template<class T>
bool masPobreQueDescendientes(typename Abin<T>::nodo n, T valor, const Abin<T>& A)
{
    if(A.elemento(n) == A.NODO_NULO)
        return true;
    else
    {
        if(valor < A.elemento(n))
            return masPobreQueDescendientes(A.hijoIzqdoB(n),valor, A),masPobreQueDescendientes(A.hijoDrchoB(n),valor, A);
        else
            return false;
    }
}
#endif   // ABIN_E_S_H