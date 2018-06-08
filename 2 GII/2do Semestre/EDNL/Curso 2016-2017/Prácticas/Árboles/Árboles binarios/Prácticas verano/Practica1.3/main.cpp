#include <iostream>
#include "abin_E-S.h"
#include "ABIN.h"

using namespace std;

typedef char tElto;
const tElto fin = '#'; // fin de lectura

int profundidad(Abin<tElto> A, Abin<tElto>::nodo n);

int main()
{
    int n;

    Abin<tElto> A;
    Abin<tElto>::nodo m;

    cout << "*** Lectura del árbol binario A ***\n";
    rellenarAbin(A, fin); // desde std::cin
    cout << "Arbol rellenado con exito."<<endl;

    n=profundidad(A, m);

    cout<<"La profundidad es: "<<n<<endl;

    return 0;
}

int profundidad(Abin<tElto> A, Abin<tElto>::nodo m)
{
    int p=0;

    while(m!=A.raizB())
    {
        p++;
        m=A.padreB(m);
    }
    return p;
}
