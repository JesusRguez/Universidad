#include <iostream>
#include <string.h>
#include "pilapseudoestatica.h"

using namespace std;

Pila<char> crearpila (char *cadena,Pila<char> P);
bool inversa(char *cadena,Pila<char> P);

int main()
{
    char *c1,*c2,*c3;
    char cadena[]="hola&aloh#Hola&aloH#pene&enep";
    char *token;
    token=strtok(cadena,"#");
    c1=token;
    token=strtok(NULL,"#");
    c2=token;
    token=strtok(NULL,"\0");
    c3=token;

    Pila<char> P1(4);
    Pila<char> P2(4);
    Pila<char> P3(4);

    P1=crearpila(c1, P1);
    P2=crearpila(c2, P2);
    P3=crearpila(c3, P3);

    if(inversa(c1, P1)==true && inversa(c2, P2)==true && inversa(c3,P3))
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
