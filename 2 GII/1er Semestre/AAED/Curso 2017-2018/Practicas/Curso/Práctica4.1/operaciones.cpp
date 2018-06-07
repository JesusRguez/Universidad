#include "polinom.h"
#include "operaciones.h"

int GradoMaximo1(polinomio p1, polinomio p2){
    int maximo=0;
    if(p1.grado()>p2.grado())
        maximo=p1.grado();
    else
        maximo=p2.grado();
    return maximo;
}

polinomio operator +(const polinomio& p1, const polinomio& p2){
    int i, coeficienteA, coeficienteB, gradoTotal=0;

    gradoTotal=GradoMaximo1(p1, p2);
    polinomio resultado(gradoTotal);

    for(i=0;i<=gradoTotal;i++)
    {
        coeficienteA=p1.coeficiente(i);
        coeficienteB=p2.coeficiente(i);
        resultado.coeficiente(i,(coeficienteA+coeficienteB));
    }
    return resultado;
}

polinomio operator -(const polinomio& p1, const polinomio& p2){
    int i, coeficienteA, coeficienteB, gradoTotal=0;

    gradoTotal=GradoMaximo1(p1, p2);
    polinomio resultado(gradoTotal);

    for(i=0;i<=gradoTotal;i++)
    {
        coeficienteA=p1.coeficiente(i);
        coeficienteB=p2.coeficiente(i);
        resultado.coeficiente(i,(coeficienteA-coeficienteB));
    }
    return resultado;
}

polinomio operator *(const polinomio& p1, const polinomio& p2){
    int i, j, grA, grB, coeficienteA, coeficienteB;

    grA=p1.grado();
    grB=p2.grado();
    polinomio resultado(grA+grB);

    for(i=0;i<=grA;i++)
    {
        for(j=0;j<=grB;j++)
        {
            coeficienteA=p1.coeficiente(i);
            coeficienteB=p2.coeficiente(j);
            resultado.coeficiente(i+j,coeficienteA*coeficienteB);
        }
    }
    return resultado;
}

polinomio derivada(const polinomio& p1){
    int i,grA;
    double coeficienteA;

    grA=p1.grado();
    polinomio resultado(1-grA);

    for(i=0;i<=grA;i++)
    {
        coeficienteA=p1.coeficiente(i);
        resultado.coeficiente(i-1,coeficienteA*i);
    }

    return resultado;
}
