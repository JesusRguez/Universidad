#include <iostream>
#include <windows.h>
#include "abin_E-S.h"
#include "ABIN.h"

using namespace std;

typedef char tElto;
const tElto fin = '#'; // fin de lectura

int cuenta_nodos(Abin<tElto> A, Abin<tElto>::nodo n);

int main()
{
    int n;

    Abin<tElto> A;
    cout << "*** Lectura del árbol binario A ***\n";
    rellenarAbin(A, fin); // desde std::cin
    cout << "Arbol rellenado con exito."<<endl;
    n=cuenta_nodos(A,A.raizB());
    cout << "Hay unos cuantos nodos pero no se cuantos churra mia."<<endl;
    Sleep(2000);
    cout << "Vaaaaaaaaaaaaale, hay ";
    cout << n;

    return 0;
}

int cuenta_nodos(Abin<tElto> A, Abin<tElto>::nodo n){
    if(n==A.NODO_NULO)
        return 0;
    else
        return 1 + cuenta_nodos(A, A.hijoIzqdoB(n)) + cuenta_nodos(A,A.hijoDrchoB(n));
}
