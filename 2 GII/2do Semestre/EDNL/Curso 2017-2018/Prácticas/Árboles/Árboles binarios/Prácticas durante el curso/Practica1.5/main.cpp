#include <iostream>
#include "abin_E-S.h"
#include "ABIN.h"

using namespace std;

typedef char tElto;
const tElto fin = '#'; // fin de lectura

int main()
{
    int n, m;

    Abin<tElto> A;
    cout << "*** Lectura del árbol binario A ***\n";
    rellenarAbin(A, fin); // desde std::cin
    cout << "Arbol rellenado con exito."<<endl;

    n=A.altura(A.raizB());
    cout << "La altura es: "<<n<<endl;

    m=A.profundidad(A.hijoIzqdoB(A.hijoIzqdoB(A.raizB())));
    cout<<"La profundidad es: "<<m<<endl;

    return 0;
}
