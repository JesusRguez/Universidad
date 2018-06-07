#include <iostream>
#include "ESpolinomio.h"
#include "polinom.h"

using namespace std;

void Entrada_Polinomio(polinomio P, int gr_max)
{
    int i=0;
    double c;
    while(i<=gr_max)
    {
        cout<<"Introduzca el coeficiente de grado:"<<i<<endl;
        cin>>c;
        P.coeficiente(i,c);
        i++;
    }
}

void Mostrar_Polinomio(polinomio P)
{
    int i;
    double x;
    i=P.grado();
    while(i>=0)
    {
        x=P.coeficiente(i);
        cout<<x<<"^"<<i<<"+";
        i--;
    }
}
