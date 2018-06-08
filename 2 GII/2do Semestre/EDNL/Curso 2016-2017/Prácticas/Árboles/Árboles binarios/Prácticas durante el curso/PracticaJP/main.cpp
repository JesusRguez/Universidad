#include <iostream>
#include <fstream>
#include "ABIN.h"
#include "abin_E-S.h"
#include <stdlib.h>

using namespace std;

typedef char T;
const T fin = '#';


int numnodos (Abin<T> A, Abin<T>::nodo n)
{
    if(n==A.NODO_NULO)
        return 0;
    else
        return 1 + numnodos(A,A.hijoIzqdoB(n)) + numnodos(A,A.hijoDrchoB(n));
}
int maximo(int x,int y)
{
    if(x>y)
        return x;
    else
        return y;
}


int altura (Abin<T>::nodo n, Abin<T> A)
{
 if(n==A.NODO_NULO)
    return -1;
 else
    return 1+maximo(altura(A.hijoIzqdoB(n),A),altura(A.hijoDrchoB(n),A));
}


bool similares(Abin<T> A, Abin<T> B, Abin<T>::nodo na, Abin<T>::nodo nb)
{

    bool simil = true;
    if (na != A.NODO_NULO && nb == B.NODO_NULO)
        return false;
    if (na == A.NODO_NULO && nb != B.NODO_NULO)
        return false;

    return similares(A, B, A.hijoIzqdoB(na), B.hijoIzqdoB(nb));
    return similares(A, B, A.hijoDrchoB(na), B.hijoDrchoB(nb));

    return simil;

}

void reflejar(Abin<T> A, Abin<T> B,Abin<T>::nodo na,Abin<T>::nodo nb)
{
    if(na != A.NODO_NULO)
    {
        if(A.hijoIzqdoB(na) != A.NODO_NULO)
            B.insertarHijoDrchoB(nb,A.elemento(na));
        if(A.hijoDrchoB(na) != A.NODO_NULO)
            B.insertarHijoIzqdoB(nb,B.elemento(na));
         reflejar(A,B,A.hijoIzqdoB(na),B.hijoDrchoB(nb));
         reflejar(A,B,A.hijoDrchoB(na),B.hijoIzqdoB(nb));
    }

}

Abin<T> llamada_reflejada(Abin<T> A)
{
    Abin<T> B;
    B.insertarRaizB(A.elemento(A.raizB()));
    reflejar(A, B, A.raizB(), B.raizB());
    return B;
}












int deseq_nodo(Abin<T>::nodo n,Abin<T> A)
{
    return altura(A.hijoIzqdoB(n),A) - altura(A.hijoDrchoB(n),A);
}




float opera (float a,char operador, float b)
{
    float res;
    cout<<a <<operador<< b<<endl;
    a=a-48;
    b=b-48;
    cout<<a <<operador<< b<<endl;
    switch(operador)
    {
    case '+':
        res = a+b;
    break;
    case '-':
        res = a-b;
    break;
    case '*':
        res = a*b;
    break;
    case '/':
        res = a/b;
    break;
    default:
        res = 0;
    }
return res;
}



template <typename T>
float preordenAbin (typename Abin<T>::nodo n, const Abin<T>& A)
{
    if (A.hijoIzqdoB(n) != Abin<T>::NODO_NULO)
    {

        return opera (preordenAbin(A.hijoIzqdoB(n), A), A.elemento(n), preordenAbin(A.hijoDrchoB(n), A));

    }
    cout<<"elemento"<< A.elemento(n)<<endl;
    return A.elemento(n);
}





int main()
{
    int num;
    float result;
    Abin<T> A;
    rellenarAbin(A, fin);
    imprimirAbin(A);
    result=preordenAbin(A.raizB(),A);
    cout << "resultado es:" <<endl;
    cout << result<<endl;
    num=numnodos(A,A.raizB());
    cout << num <<endl;
    return 0;
}















