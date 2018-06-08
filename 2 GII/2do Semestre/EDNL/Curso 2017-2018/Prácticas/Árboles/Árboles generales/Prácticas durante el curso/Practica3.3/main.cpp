#include <iostream>
#include "agen_E-S.h"
#include "AGEN.h"

using namespace std;

typedef char T;
const T fin = '#';

template <typename T> int desequilibrio(const Agen<T>& A, typename Agen<T>::nodo n);
template <typename T> int altura(const Agen<T>& A, typename Agen<T>::nodo m, int maxi);

int main()
{
    int des;
    Agen<T> A;
    cout << "*** Lectura del �rbol A ***\n";
    rellenarAgen(A, fin); // Desde std::cin
    cout << "Arbol rellenado con exito."<<endl;
    cout << "\n*** Arbol A guardado con exito ***\n";
    des=desequilibrio(A,A.hermDrcho(A.hijoIzqdo(A.raiz())));
    cout << "El desequilibrio del arbol es " << grado << endl;
    return 0;
}

template <typename T> int desequilibrio(const Agen<T>& A, typename Agen<T>::nodo n){
    int maxi, mini, a;
    if(A.hijoIzqdo(n)!=Agen<T>::NODO_NULO){
        n=A.hijoIzqdo(n);
        maxi=mini=altura(A, n, 0);
        while(A.hermDrcho(n)!=Agen<T>::NODO_NULO){
            n=A.hermDrcho(n);
            a=altura(A, n, 0);
            if(maxi<a)
                maxi=a;
            if(mini>a)
                mini=a;
        }
        return maxi-mini;
    }else{
        return 0;
    }
}

template <typename T> int altura(const Agen<T>& A, typename Agen<T>::nodo m, int maxi){
    if(A.hijoIzqdo(m)!=Agen<T>::NODO_NULO){
        if(A.hijoIzqdo(m)==Agen<T>::NODO_NULO){
            return 0;
        }else{
            m=A.hijoIzqdo(m);
            while (m != Agen<T>::NODO_NULO){
                int a;
                a = altura(A,m,maxi);
                if (a > maxi)
                    maxi = a;
                m = A.hermDrcho(m);

            }
            return 1+maxi;
        }
    }
}
