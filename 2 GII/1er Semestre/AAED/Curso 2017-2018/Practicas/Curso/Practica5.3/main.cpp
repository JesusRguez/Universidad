#include <iostream>
#include "PilaDinamica.h"

using namespace std;

Pila<int> rellenarPila(Pila<int> P, int *v);
Pila<int> invertir(Pila<int> P, int a, int b);

int main()
{
    int a=1, b=2;
    Pila<int> P;
    int v[20]={0,1,2,3,9,8,4,2,6,9,7,6,8,1,9,9,8,7,4};//0123984269768199874

    P=rellenarPila(P, v);

    if(P.vacia())
    P=invertir(P, a, b);

    while(!P.vacia()){
        cout<<P.tope()<<",";
        P.pop();
    }

    return 0;
}

Pila<int> rellenarPila(Pila<int> P, int *v){
    int i=0;
    while(i<19){
        P.push(v[i]);
        i++;
    }
    return P;
}

Pila<int> invertir(Pila<int> P, int a, int b){
    Pila<int> Q, A;

    while(!P.vacia()&&P.tope()!=a){
        Q.push(P.tope());
        P.pop();
    }
    while(!P.vacia()&&P.tope()!=b){
        A.push(P.tope());
        P.pop();
    }
    while(!A.vacia()){
        Q.push(A.tope());
        A.pop();
    }
    while(!P.vacia()){
        Q.push(P.tope());
        P.pop();
    }
    while(!Q.vacia()){
        P.push(Q.tope());
        Q.pop();
    }
    return P;
}

