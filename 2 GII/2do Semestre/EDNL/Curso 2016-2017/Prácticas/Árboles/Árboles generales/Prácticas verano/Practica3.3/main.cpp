#include <iostream>
#include <stdlib.h>
#include "agen_E-S.h"
#include "AGEN.h"

using namespace std;

typedef char T;
const T fin = '#';

int altura(const Agen<T>& A, Agen<T>::nodo n);
int desequilibrio(const Agen<T>& A, Agen<T>::nodo n, int* maxi);
void preorden(const Agen<T>& A, Agen<T>::nodo n);

int main()
{
    int alt=0;
    Agen<T> A;
    cout << "*** Lectura del árbol A ***\n";
    rellenarAgen(A, fin); // Desde std::cin
    cout << "Arbol rellenado con exito."<<endl;
    cout << "\n*** Arbol A guardado con exito ***\n";
    int p;
    alt=altura(A, A.raiz());
    cout << "El desequilibrio es " << alt << endl;
    return 0;
}


int desequilibrio(const Agen<T>& A, Agen<T>::nodo n, int* alt)
{

}

/*void altura(const Agen<T>& A, Agen<T>::nodo n, int* alt)
{
    if(n!=A.NODO_NULO)
    {

        n=A.hijoIzqdo(n);
        *alt=*alt+1;
        if(n!= A.NODO_NULO)
        cout<< "entra 1  " << A.elemento(n)<<"  alt=    " << *alt<<endl;
        altura(A, n, alt);
        while(n!=A.NODO_NULO)
        {
            cout<< "entra 2  " << A.elemento(n)<<"  alt=    "<< *alt<<endl;
            n=A.hermDrcho(n);
            altura(A, n, alt);
        }
    }
}*/

int altura(const Agen<T>& A, Agen<T>::nodo n)
{
    int i=0,maxi=0,aux;
    if(n==A.NODO_NULO)
        return 0;
    else{
        if(n!=A.NODO_NULO)
        cout<<"el padre  "<< A.elemento(n)<<endl;
        n=A.hijoIzqdo(n);
        if(n!=A.NODO_NULO)
        cout<<"el hijo   "<< A.elemento(n)<<endl;
        while (A.hermDrcho(n) != A.NODO_NULO)
        {
            if(n!=A.NODO_NULO)
            cout<<"el elemento " << A.elemento(n)<<endl;
            aux = altura(A,n);
            if (maxi<aux)
                maxi=aux;
            if(A.hermDrcho(n)!=A.NODO_NULO && n!= A.NODO_NULO)
            n=A.hermDrcho(n);
            if(n!=A.NODO_NULO)
            cout<<"el hermano  "<<A.elemento(n)<<endl;
            i++;
        }
        aux = altura(A,A.hijoIzqdo(n));
        if (aux>maxi)
            maxi=aux;
    }
        return i+maxi;

}


/*void alturapabajo(const Agen<T>& A, Agen<T>::nodo n, int* alt)
{
    while(n!=A.NODO_NULO)
    {

    }
}*/
