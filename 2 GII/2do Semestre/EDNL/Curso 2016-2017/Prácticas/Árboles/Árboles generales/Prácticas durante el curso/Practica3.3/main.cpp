#include <iostream>
#include "AGEN.h"
#include "agen_E-S.h"

using namespace std;

typedef char T;
const T fin = '#';

template <typename T> int altura(const Agen<T>& A, typename Agen<T>::nodo n, int maxi);
template <typename T> int desequilibrio(const Agen<T>& A, typename Agen<T>::nodo m);

int main()
{
    int des;
    Agen<T>::nodo m;
    Agen<T> A;
    cout << "*** Lectura del árbol A ***\n";
    rellenarAgen(A, fin); // Desde std::cin
    cout << "Arbol rellenado con exito."<<endl;
    cout << "\n*** Arbol A guardado con exito ***\n";


    des=altura(A, A.raiz(),0);
    cout << "La altura del arbol es " << des << endl;
    return 0;
}


template <typename T> int altura(const Agen<T>& A, typename Agen<T>::nodo n, int maxi)
{
    if(A.hijoIzqdo(n)!= Agen<T>::NODO_NULO){
      if (A.hijoIzqdo(n) == A.NODO_NULO)
        return 0;
      else{
        n = A.hijoIzqdo(n);
        while (n != A.NODO_NULO)
        {
          int a;
          a = altura(A,n,maxi);
          if (a > maxi)
            maxi = a;
          n = A.hermDrcho(n);

        }
        return 1+maxi;
      }
    }
}

template <typename T> int desequilibrio(const Agen<T>& A, typename Agen<T>::nodo m)
{
    int maxi, mini, a;
    if(A.hijoIzqdo(m)!=A.NODO_NULO)
    {
        m=A.hijoIzqdo(m);
        maxi=mini=altura(A, m, 0);
        // cout<< maxi <<mini <<A.elemento(m)<<endl;
        while(A.hermDrcho(m)!=A.NODO_NULO) //abc#d#e##f#ghi#j##k#l###
        {
            m=A.hermDrcho(m);
            //cout<<"entra"<<endl;
            a = altura(A,m,0);
            if(maxi<a/*altura(A, m, 0)*/)
            {
                maxi=a/*altura(A, m, 0)*/;
            }
            if(mini>a/*altura(A, m, 0)*/)
            {
                mini=a/*altura(A, m, 0)*/;
            }
        }

        return maxi-mini;
    }else
    {
        return 0;
    }
}
