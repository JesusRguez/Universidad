#include <iostream>
#include "ListaEnlazada.h"

using namespace std;

Lista<int> eliminar (Lista<int> L, int n);
Lista<int> insertarelementos (Lista<int> L, int *v);

int main()
{
    Lista <int> L;
    int v[10]={1,2,3,4,1,1,5,6,1,1};

    L=insertarelementos(L, v);

    int n=1;
    L=eliminar(L, n);
    Lista<int>::posicion p=L.primera();
    while(p!=L.fin()){
        cout<<L.elemento(p);
        p=L.siguiente(p);
    }
    return 0;
}

Lista<int> insertarelementos (Lista<int> L, int *v){
    Lista<int>::posicion p=L.primera();
    for(int i=0;i<10;i++){
        L.insertar(v[i],p);
        p=L.siguiente(p);
    }
    return L;
}

Lista<int> eliminar (Lista<int> L, int n){
    Lista<int>::posicion p=L.primera();
    while(p!=L.fin()){
        if(L.elemento(p)==n){
            L.eliminar(p);
        }else
            p=L.siguiente(p);
    }
    return L;
}
