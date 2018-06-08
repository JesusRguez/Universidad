#include <iostream>
#include "abin_E-S.h"
#include "ABIN.h"

using namespace std;

//typedef char T;
typedef struct{
        char operador;
        double operando;
    }T;
T fin;



//Con un struct, el char es el operador y el double es el operando. Si es una hoja será un operando y si es un nodo intermedio es un operador.
//Tendrá que haber un switch para poder contorlar todos los casos de operaciones disponibles en el sistema.

int main()
{
    fin.operador='#';   // fin de lectura
    Abin<T> A;
    cout << "*** Lectura del árbol binario A ***\n";
    rellenarAbin(A, fin); // desde std::cin
    cout << "Arbol A rellenado con exito."<<endl;

    return 0;
}
