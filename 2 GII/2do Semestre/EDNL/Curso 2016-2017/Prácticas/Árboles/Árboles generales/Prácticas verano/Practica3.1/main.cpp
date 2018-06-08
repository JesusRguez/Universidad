#include <iostream>
#include "agen_E-S.h"
#include "AGEN.h"

using namespace std;

typedef char T;
const T fin = '#';

int grado_arbol(const Agen<T>& A, Agen<T>::nodo n, int* maxi);
int grado_nodo(const Agen<T>& A, Agen<T>::nodo n);

int main()
{
    int grado;
    Agen<T> A;
    cout << "*** Lectura del árbol A ***\n";
    rellenarAgen(A, fin); // Desde std::cin
    cout << "Arbol rellenado con exito."<<endl;
    cout << "\n*** Arbol A guardado con exito ***\n";
    int maxi = 0;
    grado=grado_arbol(A,A.raiz(), &maxi);
    cout << "El grado del arbol es " << grado << endl;
    return 0;
}
//abe##c#dg#h###
//abd##ce#f#g###
int grado_arbol(const Agen<T>& A, Agen<T>::nodo n, int* maxi)
{
    int aux;
    if(n!=A.NODO_NULO)
    {
        cout<<"Elemento no nulo "<<A.elemento(n)<<"  ";
        cout << *maxi<<endl;
        aux=grado_nodo(A, n);
        if(aux>*maxi)
            *maxi=aux;
        while(A.hermDrcho(n)!=A.NODO_NULO)
        {
            cout<<"Tiene hermano "<<A.elemento(n)<<"   ";
            cout<< *maxi << endl;
            n=A.hermDrcho(n);
            aux=grado_nodo(A, n);
            if(aux>*maxi)
                *maxi=aux;
        }
        cout<< "No tengo mas hermanos  "<<A.elemento(n)<<endl;
        grado_arbol(A, A.hijoIzqdo(n), maxi);
    }
    else
        return *maxi;
}

//GRADO ES EL NUMERO DE HIJOS QUE TIENE
int grado_nodo(const Agen<T>& A, Agen<T>::nodo n)
{
    int herm=0;
    if (A.hijoIzqdo(n) != A.NODO_NULO)
    {
        n=A.hijoIzqdo(n);
        herm++;
    }
    while(A.hermDrcho(n) != A.NODO_NULO)
    {
        herm++;
        n=A.hermDrcho(n);
    }
    cout<<"tengo "<< herm<<" hermanos"<<endl;
    return herm;
}
