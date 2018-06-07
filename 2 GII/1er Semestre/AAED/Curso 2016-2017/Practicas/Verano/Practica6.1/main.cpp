#include <iostream>
#include "PilaDinamica.h"
#include "ColaDinamica.h"

using namespace std;

Pila<int> crearpila (int *pilita,Pila<int> P, int Tpila);
Cola<int> crearcola (int *colita,Cola<int> C, int Tcola);
bool isomorfica (Pila<int> P, Cola<int> C);


//No funciona por el paso de los parametros pilita y colita a la función ya que tenemos que calcular
//el tamaño de los vectroes y no se como hacerlo después de hacer el paso a las funciones.


int main()
{
    int pilita[]={7,8,5,0,2,1};
    int colita[]={2,3,5,6,7};

    int Tpila = sizeof pilita / sizeof pilita[0];
    int Tcola = sizeof colita / sizeof colita[0];

    Pila<int> P;
    Cola<int> C;

    P=crearpila(pilita, P, Tpila);
    C=crearcola(colita, C, Tcola);

    if(isomorfica(P, C)==true)
        cout<<"Hay isomorfismo"<<endl;
    else
        cout<<"No hay isomorfismo"<<endl;

    return 0;
}

Pila<int> crearpila (int *pilita,Pila<int> P, int Tpila)
{
    int i;
    for(i=0;i<Tpila;i++)
    {
        P.push(pilita[i]);
    }
    return P;
}

Cola<int> crearcola (int *colita,Cola<int> C, int Tcola)
{
    int i;
    for(i=0;i<Tcola;i++)
    {
        C.push(colita[i]);
    }
    return C;
}

bool isomorfica (Pila<int> P, Cola<int> C)
{
    bool valido=false;

    P.pop();
    while(!C.vacia()&&!P.vacia())
    {
        if(P.tope()==C.frente())
            valido=true;
        if (!C.vacia())
            C.pop();
        if (!C.vacia())
            C.pop();
        if (!P.vacia())
            P.pop();
        if (!P.vacia())
            P.pop();
    }
    return valido;
}
