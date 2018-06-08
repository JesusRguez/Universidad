#include <iostream>
#include "abin_E-S.h"
#include "ABIN.h"

using namespace std;

typedef char tElto;
const tElto fin = '#'; // fin de lectura

int altura(Abin<tElto> A, Abin<tElto>::nodo n);
int alturarec(Abin<tElto> A, Abin<tElto>::nodo n, int maxima, int actual);

int main()
{
    int n;

    Abin<tElto> A;

    cout << "*** Lectura del árbol binario A ***\n";
    rellenarAbin(A, fin); // desde std::cin
    cout << "Arbol rellenado con exito."<<endl;

    n=altura(A, A.raizB());

    cout<<"La altura es: "<<n<<endl;

    return 0;
}

int altura(Abin<tElto> A, Abin<tElto>::nodo n)
{
    return alturarec(A, n, 0, 0);
}

int alturarec(Abin<tElto> A, Abin<tElto>::nodo n, int maxima, int actual)   //No se si funciona o no, pero da miedo probarlo
{
    if(n==A.NODO_NULO)
        return maxima;
    else
        if(maxima<actual)
            return 1 + alturarec(A, A.hijoIzqdoB(n), actual, actual) + alturarec(A, A.hijoDrchoB(n), actual, actual);
        else
            if(maxima>actual)
                return 1 + alturarec(A, A.hijoIzqdoB(n), maxima, actual) + alturarec(A, A.hijoDrchoB(n), maxima, actual);
}
