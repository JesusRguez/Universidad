#include <iostream>
#include "abin_E-S.h"
#include "ABIN_VEC1.h"

using namespace std;

typedef char T;
const T fin = '#'; // fin de lectura

bool similares(Abin<T> A, Abin<T> B);
bool similares_recur(Abin<T>::nodo m, Abin<T>::nodo n);

int main()
{
    bool s;
//    Abin nodo;

    Abin<T> A(500), B(500);
    cout << "*** Lectura del árbol binario A ***\n";
    rellenarAbin(A, fin); // desde std::cin
    cout << "Arbol A rellenado con exito."<<endl;
    cout << "*** Lectura del árbol binario B ***\n";
    rellenarAbin(B, fin); // desde std::cin
    cout << "Arbol B rellenado con exito."<<endl;
    s=similares(A, B);
    if(s==true)
        cout << "Son similares."<<endl;
    else
        cout << "No son ismilares:"<<endl;

    return 0;
}

bool similares(Abin<T> A, Abin<T> B){
    return similares_recur(A.raizB(),B.raizB());
}

bool similares_recur(Abin<T>::nodo m, Abin<T>::nodo n){

}
