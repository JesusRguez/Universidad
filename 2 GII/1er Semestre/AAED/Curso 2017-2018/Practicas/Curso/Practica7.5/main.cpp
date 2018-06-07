#include <iostream>
#include "ListaEnlazada.h"
#include "PilaDinamica.h"

using namespace std;

void ImprimeInverso (Lista<int> L, int pos);
Lista<int> insertarelementos (Lista<int> L, int *v);

int main()
{
    Lista <int> L;
    int v[10]={1,2,3,4,1,1,5,6,1,1};

    L=insertarelementos(L, v);

    int pos;
    cout<<"Elija la posicion:"<<endl;
    cin>>pos;
    ImprimeInverso(L, pos);

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

void ImprimeInverso (Lista<int> L, int pos){
    Lista<int>::posicion p=L.primera(), q, t;
    Pila<int> P;
    for(int i=0;i<pos;i++){
        cout<<L.elemento(p);
        p=L.siguiente(p);
    }
    q=p;
    t=p;
    //meter en pila
    while(q!=L.fin()){
        P.push(L.elemento(q));
        L.eliminar(q);
    }
    while(!P.vacia()){
        L.insertar(P.tope(),t);
        P.pop();
        t=L.siguiente(t);
    }
    while(p!=L.fin()){
        cout<<L.elemento(p);
        p=L.siguiente(p);
    }
}
