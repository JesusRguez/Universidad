#include <iostream>
#include "AritmeticaPolinomio.h"
#include "polinom.h"
polinomio operator +(const polinomio& Pol1, const polinomio& Pol2)
{
    int i,coeficiente_a,coeficiente_b,gradototal;

    gradototal=GradoMaximo(Pol1,Pol2);
    polinomio PolSol(gradototal);

    for(i=0;i<=gradototal;i++)
    {
        coeficiente_a=Pol1.coeficiente(i);
        coeficiente_b=Pol2.coeficiente(i);
        PolSol.coeficiente(i,(coeficiente_a+coeficiente_b));
    }
    return PolSol;
}

polinomio operator -(const polinomio& Pol1, const polinomio& Pol2)
{
    int i,coeficiente_a,coeficiente_b,gradototal;

    gradototal=GradoMaximo(Pol1,Pol2);
    polinomio PolSol(gradototal);

    for(i=0;i<=gradototal;i++)
    {
        coeficiente_a=Pol1.coeficiente(i);
        coeficiente_b=Pol2.coeficiente(i);
        PolSol.coeficiente(i,(coeficiente_a-coeficiente_b));
    }
    return PolSol;
}

polinomio operator *(const polinomio& Pol1, const polinomio& Pol2)
{
    int i,j,gr_a,gr_b;
    double coeficiente_a,coeficiente_b;

    gr_a=Pol1.grado();
    gr_b=Pol2.grado();
    polinomio PolSol(gr_a*gr_b);

    for(i=0;i<=gr_a;i++)
    {
        for(j=0;j<=gr_b;j++)
        {
            coeficiente_a=Pol1.coeficiente(i);
            coeficiente_b=Pol2.coeficiente(j);
            PolSol.coeficiente(i+j,coeficiente_a*coeficiente_b);
        }
    }

    return PolSol;
}

polinomio derivada (const polinomio& Pol1)
{
    int i,gr_a;
    double coeficiente_a;

    gr_a=Pol1.grado();
    polinomio PolSol(1-gr_a);

    for(i=0;i<=gr_a;i++)
    {
        coeficiente_a=Pol1.coeficiente(i);
        PolSol.coeficiente(i-1,coeficiente_a*i);
    }

    return PolSol;
}

int GradoMaximo(polinomio Pol1, polinomio Pol2)
{
    int resultado;

    if (Pol1.grado()<Pol2.grado())
    {
        resultado=Pol2.grado();
    }else
    {
        resultado=Pol1.grado();
    }

    return resultado;
}
