#include <iostream>
#include "ABIN.h"
#include "abin_E-S.h"

using namespace std;

typedef char tElto;
const tElto fin = '#'; // fin de lectura

int contarnodos(Abin<tElto> A, Abin<tElto>::nodo n);

int main()
{
    int n;

    Abin<tElto> A;

    cout << "*** Lectura del árbol binario A ***\n";
    rellenarAbin(A, fin); // desde std::cin
    cout << "Arbol rellenado con exito."<<endl;

    n=contarnodos(A, A.raizB());

    cout<<"Hay "<<n<<" nodos en el arbol."<<endl;

    return 0;
}

int contarnodos(Abin<tElto> A, Abin<tElto>::nodo n)
{
    int a=0;
    if(n==A.NODO_NULO)
        return a;
    else
        return 1 + contarnodos(A, A.hijoIzqdoB(n)) + contarnodos(A, A.hijoDrchoB(n));
}
