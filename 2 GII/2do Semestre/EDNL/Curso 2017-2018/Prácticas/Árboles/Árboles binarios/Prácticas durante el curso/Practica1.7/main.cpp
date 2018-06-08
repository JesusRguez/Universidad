#include <iostream>
#include "abin_E-S.h"
#include "ABIN.h"

using namespace std;

typedef char tElto;
const tElto fin = '#'; // fin de lectura

template <typename T> void preorden(const Abin<T>& A, typename Abin<T>::nodo n, bool* p);
template <typename T> void pseudocompleto(const Abin<T>& A, typename Abin<T>::nodo n, bool* p);

int main()
{
    bool p;

    Abin<tElto> A;
    cout << "*** Lectura del árbol binario A ***\n";
    rellenarAbin(A, fin); // desde std::cin
    cout << "Arbol rellenado con exito."<<endl;

    int a=A.profundidad(A.hijoDrchoB(A.raizB()));
    int s= A.altura(A.raizB());

    //int alt=A.altura(A.raizB());
    preorden(A, A.raizB(), &p);

    if(p==true)
        cout << "El arbol si es pseudocompleto "<<endl;
    else
        cout << "El arbol no es pseudocompleto"<<endl;
    return 0;
}

template <typename T> void preorden(const Abin<T>& A, typename Abin<T>::nodo n, bool* p){
    if (n != Abin<T>::NODO_NULO)
        {
            pseudocompleto(A, n, p);
            preorden(A, A.hijoIzqdoB(n), p);
            preorden(A, A.hijoDrchoB(n), p);
        }
}

template <typename T> void pseudocompleto(const Abin<T>& A, typename Abin<T>::nodo n, bool* p){
    if(n!=Abin<T>::NODO_NULO)
    {
        if(((A.hijoIzqdoB(n)!=Abin<T>::NODO_NULO && A.hijoDrchoB(n)!=Abin<T>::NODO_NULO) || (A.hijoIzqdoB(n)==Abin<T>::NODO_NULO && A.hijoDrchoB(n)==Abin<T>::NODO_NULO)) && A.profundidad(n)==A.altura(A.raizB())-1)
            *p=true;
        else
            *p=false;
    }
}


//La condición se centra en el penúltimo nivel.
//Si tenemos un hijo hijo izquierdo alto y un hijo derecho pequeño, no nos importa el pequeño, solo el más alto de los dos.
//Si altura del izquierdo es mayor que la del derecho, return del hijo izquiero, si no, return del hijo derecho.
//Si la altura de ambos hijos es la misma, return un and de los dos.
