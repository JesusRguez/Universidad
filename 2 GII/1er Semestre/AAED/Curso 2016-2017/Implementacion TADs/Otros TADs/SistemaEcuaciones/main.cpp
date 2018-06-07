/* sistecu.cpp - Resolución de un sistema de 2
ecuaciones con 2 incógnitas y
coeficientes racionales.
*/
#include <iostream>
#include "Racional.h"

using namespace std;

void LeerEcu (racional& a, racional& b, racional& c);

int SistEcu (racional a1, racional b1, racional c1, racional a2, racional b2, racional c2, racional& x, racional& y);
racional Det (racional a11, racional a12, racional a21, racional a22);

int main()
{
    racional a1, b1, c1, a2, b2, c2, x, y;
    int s;
    /* Entrada de datos */
    cout << "Ecuacion 1 (a1*x + b1*y = c1):\n";
    LeerEcu(a1, b1, c1);
    cout << endl;
    cout << "Ecuacion 2 (a2*x + b2*y = c2):\n";
    LeerEcu(a2, b2, c2);
    cout << endl;
    /* Cálculo de las soluciones */
    s = SistEcu(a1, b1, c1, a2, b2, c2, x, y);
    /* Salida de datos */
    if (s == 0)
    {
        cout << "Solucion:\n\n";
        cout << "x = " << x.num() << " / " << x.den() << endl;
        cout << "y = " << y.num() << " / " << y.den() << endl;
    }
    else if (s == -1)
        cout << "Sistema incompatible\n";
    else // s == 1
        cout << "Infinitas soluciones\n";
    }

void LeerEcu (racional& a, racional& b, racional& c)
{
    long num, den;
    cout << "Coeficiente de x:\n";
    cout << "  Numerador = "; cin >> num;
    cout << "  Denominador = "; cin >> den;
    a = racional(num, den);
    cout << "Coeficiente de y:\n";
    cout << "  Numerador = "; cin >> num;
    cout << "  Denominador = "; cin >> den;
    b = racional(num, den);
    cout << "Término independiente:\n";
    cout << "  Numerador = "; cin >> num;
    cout << "  Denominador = "; cin >> den;
    c = racional(num, den);
}

int SistEcu (racional a1, racional b1, racional c1, racional a2, racional b2, racional c2, racional& x, racional& y)
{
    racional A, B, C;
    A = Det(a1, b1, a2, b2);
    B = Det(c1, b1, c2, b2);
    C = Det(a1, c1, a2, c2);
    if (A.num() != 0)
    {
        x = B * inv(A);
        y = C * inv(A);
        return 0;
    }
    else if (B.num() != 0 && C.num() != 0)
        return -1; /* Sistema incompatible */
    else
        return 1; /* Infinitas soluciones */
}

racional Det (racional a11, racional a12, racional a21, racional a22)
{
    return a11 * a22 + -a21 * a12;
}
