#include <iostream>
#include <cassert>
#include "mipolinomio.h"

using namespace std;

polinomio::polinomio()
{
    coef = new float[1];
    assert(coef!=0);
    Grado=0;
}

polinomio::polinomio(unsigned int gradoMax)
{
    coef=new float[gradoMax+1];
}

unsigned polinomio::grado() const
{
    return Grado;
}

double polinomio::coeficiente (unsigned int n) const
{
    assert (0 <= n);
    if (n > Grado)
        return 0;
    return coef[n];
}

void polinomio::coeficiente(unsigned n, double c)
{
    polinomio p;
    unsigned int a=p.grado();

    if (n<=a)
        p.coef[n]=a;
}

polinomio::~polinomio()
{
    delete [] coef;
}
