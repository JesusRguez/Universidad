#include <iostream>
#include "cronometro.h"

using namespace std;

int main()
{
    cronometro c;
    double n,cuadrado;
    int repeticiones=0;

    cout<<"Introduce el número al que le desea calcular el cuadrado:"<<endl;
    cin>>n;
    c.activar();
    while(c.tiempo()<=1)
    {
        cuadrado=n*n;
        repeticiones++;
    }
    c.parar();

    cout<<"Se ha realizado la operacion "<<repeticiones<<" veces en un segundo"<<endl;

    return 0;
}
