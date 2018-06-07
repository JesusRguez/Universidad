#include <iostream>
#include "pilapseudoestatica.h"

using namespace std;

Pila<char> crearpila (char *cadena,Pila<char> P);
bool inversa(char *cadena,Pila<char> P);

int main()
{
    char cadena[]="Amor&romA";

    Pila<char> P(4);

    P=crearpila(cadena, P);

    if(inversa(cadena, P)==true)
        cout<<"Las cadenas son inversas."<<endl;
    else
        cout<<"Las cadenas no son inversas."<<endl;

    return 0;
}

Pila<char> crearpila (char *cadena,Pila<char> P)
{
    int i=0;
    while(cadena[i]!='&')
        i++;
    i++;
    while (cadena[i]!='\0')
    {
        P.push(cadena[i]);
        i++;
    }
    return P;
}

bool inversa(char *cadena,Pila<char> P)
{
    int i=0, cont=0;
    bool valido=false;
    while(cadena[i]!='&')
    {
        if(cadena[i]==P.tope())
        {
            cont++;
            P.pop();
        }
        i++;
    }
    if(cont==i && P.vacia())
        valido=true;
    return valido;
}
