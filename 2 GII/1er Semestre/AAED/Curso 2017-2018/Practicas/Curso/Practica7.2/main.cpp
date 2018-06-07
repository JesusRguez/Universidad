#include <iostream>
#include "ListaEnlazada.h"

using namespace std;

int main()
{
    int n;
    Lista<int>::posicion p;
    Lista<int> L;
    L.insertar(0);
    L.insertar(5);
    L.insertar(3);
    L.insertar(7);
    cout<<"guardo"<<endl;
    p=L.primera();
    while(p!=L.fin()){
        n=L.elemento(p);
        cout<<n<<endl;
        p=L.siguiente(p);
    }
    return 0;
}
