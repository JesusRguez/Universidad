#ifndef ARITMETICAPOLINOMIO_H_INCLUDED
#define ARITMETICAPOLINOMIO_H_INCLUDED
#include "mipolinomio.h"
int GradMax(polinomio Pol1, polinomio Pol2);
polinomio operator +(const polinomio& Pol1, const polinomio& Pol2);
polinomio operator -(const polinomio& Pol1, const polinomio& Pol2);
polinomio operator *(const polinomio& Pol1, const polinomio& Pol2);
polinomio derivada (const polinomio& Pol1);
#endif //ARITMETICAPOLINOMIO_H:INCLUDED

