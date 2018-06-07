#include <iostream>
#include "pilapseudoestatica.h"

Pila<int> crearpila (int *v,Pila<int> P);
Pila<int> invertirpila (Pila<int> P, int a, int b);
void imprimirpila (Pila<int> P);

using namespace std;

int main()
{
    int a=1, b=2;
    int v[20]={0,1,2,3,9,8,4,2,6,9,7,6,8,1,9,9,8,7,4,5};

    Pila<int> P(20);
    Pila<int> PInv(20);

    P=crearpila(v,P);

    cout<<"La pila inicial es:"<<endl;
    imprimirpila(P);

    PInv=invertirpila(P,a,b);

    cout<<"\nLa pila invertida es:"<<endl;
    imprimirpila(PInv);


    return 0;
}

Pila<int> crearpila(int *v, Pila<int> P)
{
    int i=0;
    while (i!=20)
    {
        P.push(v[i]);
        i++;
    }
    return P;
}

Pila<int> invertirpila (Pila<int> P, int a, int b)
{
    Pila<int> Paux1(20);
    Pila<int> Paux2(20);

    while (P.tope()!=a)
    {
        Paux1.push(P.tope());
        P.pop();
    }
    while (P.tope()!=b)
    {
        Paux2.push(P.tope());
        P.pop();
    }
    while (Paux2.tope()!=a)
    {
        P.push(Paux2.tope());
        Paux2.pop();
    }
    while (!Paux1.vacia())
    {
        Paux2.push(Paux1.tope());
        Paux1.pop();
    }
    while (!Paux2.vacia())
    {
        P.push(Paux2.tope());
        Paux2.pop();
    }

    return P;
}

void imprimirpila (Pila<int> P)
{
    while(!P.vacia())
    {
        cout<<P.tope();
        P.pop();
    }
}
