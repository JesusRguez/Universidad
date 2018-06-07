#include <iostream>
#include "PilaDinamica.h"

using namespace std;

void rellenarPila(Pila<char> P, char *cadena);
bool compara(Pila<char> P, char *cadena);

int main()
{
    char cadena[10];
    Pila<char> P;

    cout<<"Introduce la cadena:"<<endl;
    cin>>cadena;

    rellenarPila(P, cadena);
    if(compara(P, cadena)==true){
        cout<<"Las cadenas son complementarias."<<endl;
    }else{
        cout<<"Las cadenas no son complementarias."<<endl;
    }

    return 0;
}

void rellenarPila(Pila<char> P, char *cadena){
    int i=0;
    while(cadena[i]!='&'){
        i++;
    }
    i++;

    while(cadena[i]!='\0'){
        cout<<cadena[i]<<endl;
        P.push(cadena[i]);
        i++;
    }
}

bool compara(Pila<char> P, char *cadena){
    int i=0;
    Pila<char> Q;
    while(!P.vacia()){
        Q.push(P.tope());
        P.pop();
    }
    bool iguales=true;
    while(cadena[i]!='&'&&!Q.vacia()){
        if(cadena[i]!=Q.tope())
            iguales=false;
        Q.pop();
        i++;
    }
}
