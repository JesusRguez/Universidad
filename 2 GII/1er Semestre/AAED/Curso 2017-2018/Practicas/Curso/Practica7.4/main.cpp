#include <iostream>
#include "ListaEnlazada.h"

using namespace std;

Lista<int> concatena (Lista<int> L1, Lista<int> L2);
Lista<int> insertarelementos (Lista<int> L, int *v);

int main()
{
    Lista <int> L1, L2, F;
    int v1[10]={1,2,3,4,5,6,7,8,9,10};
    int v2[10]={1,2,3,4,5,6,7,8,9,10};

    L1=insertarelementos(L1, v1);
    L2=insertarelementos(L2, v2);

    F=concatena(L1, L2);

    Lista<int>::posicion p=F.primera();
    while(p!=F.fin()){
        cout<<F.elemento(p);
        p=F.siguiente(p);
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

Lista<int> concatena (Lista<int> L1, Lista<int> L2){
    Lista<int>::posicion p=L1.primera();
    Lista<int>::posicion q=L2.primera();
    Lista<int> F;
    Lista<int>::posicion f=F.primera();

    while(p!=L1.fin() || q!=L2.fin()){
        if(p!=L1.fin()&&q!=L2.fin()){
            if(L1.elemento(L1.primera())<L2.elemento(L2.primera())){
                F.insertar(L1.elemento(L1.primera()),F.fin());
                L1.eliminar(L1.primera());
            }else{
                F.insertar(L2.elemento(L2.primera()),F.fin());
                L2.eliminar(L2.primera());
            }
        }
        if(p==L1.fin()&&q!=L2.fin()){
            F.insertar(L2.elemento(L2.primera()),F.fin());
            L2.eliminar(L2.primera());
        }
        if(p!=L1.fin()&&q==L2.fin()){
            F.insertar(L1.elemento(L1.primera()),F.fin());
            L1.eliminar(L1.primera());
        }

    }


    /*while(q!=L1.fin()){
        aux=L1.buscar(L2.elemento(q));
        L1.insertar(L2.elemento(q),aux);
        if(q!=L2.fin()){
            q=L2.siguiente(q);
        }
    }*/
    /*aux=L1.buscar(L2.elemento(q));
    L1.insertar(L2.elemento(q),aux);*/

    /*while(p!=L1.fin()){
        p=L1.siguiente(p);
    }
    while(q!=L2.fin()){
        L1.insertar(L2.elemento(q),p);
        q=L2.siguiente(q);
    }*/
    return F;
}
