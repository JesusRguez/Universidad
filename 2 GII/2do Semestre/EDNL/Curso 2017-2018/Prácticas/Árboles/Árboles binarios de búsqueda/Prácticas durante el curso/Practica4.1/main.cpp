#include <iostream>
#include "TADArbolBinarioBusqueda.h"

typedef int T;
const T fin = '#';

template <typename T> void creararbol(Abb<T>& A, int *v, int derecha, int izquierda);
template <typename T> void eliminarElementos(const Abb<T>& A, int elem);
template <typename T> void borrar(const Abb<T>& A);

using namespace std;

int main()
{
    int v[10]={0,1,2,3,4,5,6,7,8,9};
    int n=9;

    Abb<T> A;

    creararbol(A, v, n, 0);

    int elem;

    cout<<"Introduce el elemento por el que pordar: "<<endl;
    cin>>elem;

    eliminarElementos(A, elem);

    return 0;
}

template <typename T> void creararbol(Abb<T>& A, int *v, int derecha, int izquierda){
    int i,j,central;
    int pivote,aux;

    i=izquierda;
    j=derecha;
    central=(i+j)/2;
    pivote=v[central];
    A.insertar(pivote); //Esta es la raiz del árbol en la primera pasada

    while(i<=j){
        while(v[j]>pivote){
            j--;
        }
        while(v[i]<pivote){
            i++;
        }
        if(i<=j){
            aux=v[j];
            v[j]=v[i];
            v[i]=aux;
            i++;
            j--;
        }
    }
    if(izquierda<j)
        creararbol(A,v,j,izquierda);
    if(derecha>i)
        creararbol(A,v,derecha,i);
}

template <typename T> void eliminarElementos(const Abb<T>& A, int elem){
    Abb<T> B=A.buscar(elem);
    if(!B.vacio()){
        borrar(B);
    }
}

template <typename T> void borrar(const Abb<T>& A){
    if(!A.vacio()){
        borrar(A.drcho());
        borrar(A.izqdo());
        A.eliminar(A.elemento());
    }
}
