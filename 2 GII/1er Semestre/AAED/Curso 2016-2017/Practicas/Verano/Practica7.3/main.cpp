#include <iostream>
#include "ListaEnlazada.h"

using namespace std;

Lista<int> crearlista(Lista<int> L, int *v, int Tvector);
Lista<int> buscaborra(Lista<int> L, int x);
void imprimelista(Lista<int>& L);

int main()
{
    int x=2;
    int v[]={1,2,3,2,4,2};
    Lista<int> L;

    int Tvector = sizeof v / sizeof v[0];

    L=crearlista(L, v, Tvector);

    L=buscaborra(L, x);

    imprimelista(L);

    return 0;
}

Lista<int> crearlista(Lista<int> L, int *v, int Tvector)
{
    L.insertar(v[0],L.primera());
    Lista<int>::posicion a=L.primera();
    for(int i=1; i<=Tvector; i++)
    {
        L.siguiente(a);
        L.insertar(v[i],a);
    }
    return L;
}

Lista<int> buscaborra(Lista<int> L, int x)
{
    Lista<int>::posicion a=L.buscar(x);
    while(a!=L.fin())
    {
        L.eliminar(a);
        a=L.buscar(x);
    }

    return L;
}

void imprimelista(Lista<int>& L)
{
    Lista<int>::posicion a=L.primera();
    while(a!=L.fin())
    {
        cout<<L.elemento(a);
        a=L.siguiente(a);
    }
}
