#include <iostream>
#include <stdlib.h>
#include "agen_E-S.h"
#include "AGEN.h"

using namespace std;

typedef char T;
const T fin = '#';


//void postorden(Agen<T>& A, Agen<T>::nodo n);
void postordenAgen( Agen<T>::nodo n, Agen<T>& A);
void eliminar(Agen<T>& A, Agen<T>::nodo n);

int main()
{
    int alt=0;
    Agen<T> A;
    cout << "*** Lectura del árbol A ***\n";
    rellenarAgen(A, fin); // Desde std::cin
    cout << "Arbol rellenado con exito."<<endl;
    cout << "\n*** Arbol A guardado con exito ***\n";
    int p;
    imprimirAgen(A);
    postordenAgen( A.raiz(),A);
    cout<<endl<<endl;
    imprimirAgen(A);
    return 0;
}

void postordenAgen(Agen<T>::nodo n, Agen<T>& A)
{
if (n != Agen<T>::NODO_NULO) {
 Agen<T>::nodo hijo = A.hijoIzqdo(n);
while (hijo != Agen<T>::NODO_NULO) {
postordenAgen(hijo, A);
hijo = A.hermDrcho(hijo);
}
cout<<A.elemento(n);
eliminar(A, n);
}
}

void eliminar(Agen<T>& A, Agen<T>::nodo n)
{
    /*if(A.hijoIzqdo(n)!=A.NODO_NULO){
        if(A.hijoIzqdo(A.padre(n))==n)
            A.eliminarHijoIzqdo(A.padre(n));

    else
        {
            Agen<T>::nodo aux=A.hijoIzqdo(n);
            while(n!=A.hermDrcho(aux))
            {
                aux=A.hermDrcho(aux);
            }
            A.eliminarHermDrcho(aux);
        }
    }*/

    if(A.hijoIzqdo(n) == A.NODO_NULO)
    {
        if(n==A.raiz())
            A.eliminarRaiz();
        else
            A.eliminarHijoIzqdo(A.padre(n));
    }
    else
    {
        eliminar(A,A.hijoIzqdo(n));
    }
}






