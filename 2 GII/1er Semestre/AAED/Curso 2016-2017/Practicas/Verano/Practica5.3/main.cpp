#include <iostream>
#include "pilapseudoestatica.h"

using namespace std;

Pila<int> crearpila (int *cadena,Pila<int> P);
Pila<int> invierte (Pila<int> P);
void imprimepila (Pila<int> P);

int main()
{
    int cadena[20]={4,7,8,9,9,2,8,6,7,9,6,1,4,8,9,3,4,3,0};

    Pila<int> P(19);
    Pila<int> I(19);

    P=crearpila(cadena, P);

    I=invierte(P);

    imprimepila(I);

    return 0;
}

Pila<int> crearpila (int *cadena,Pila<int> P)
{
    int i=0;
    while (i<20 && !P.llena())
    {
        P.push(cadena[i]);
        i++;
    }
    return P;
}

Pila<int> invierte (Pila<int> P)
{
    Pila<int> Q(19);
    Pila<int> I(19);

    while(!P.vacia() && P.tope()!=1)
    {
        Q.push(P.tope());
        P.pop();
    }
    while(!P.vacia() && P.tope()!=2)
    {
        I.push(P.tope());
        P.pop();
    }
    if(!P.vacia())
    {
        I.push(P.tope());
        P.pop();
    }
    while(!I.vacia())
    {
        Q.push(I.tope());
        I.pop();
    }
    while(!Q.vacia())
    {
        P.push(Q.tope());
        Q.pop();
    }
    return P;
}

void imprimepila (Pila<int> P)
{
    while(!P.vacia())
    {
        cout<<P.tope();
        P.pop();
    }
}
