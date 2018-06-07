#include <iostream>
#include <fstream>
#include <string>
#include "PilaDinamica.h"

Pila<int> suma(Pila<int> P, Pila<int> Q);

using namespace std;

fstream& operator >>(fstream& fe, Pila<int>& P)
{
    char cifra ;
    while (fe.get( cifra ) && cifra != '\n') // leer caracteres hasta fin de línea
        P.push(cifra -= '0'); // convierte un dígito en su valor numérico
    return fe;
}

// Inserta en el flujo de salida fs la pila P
fstream& operator <<(fstream& fs, Pila<int> P)
{
    while (!P.vacia()) {
        fs << P.tope();
        P.pop();
    }
    fs << endl;
return fs;
}

int main()
{
    int aux1,aux2,sum;
    string nombre_f;
    cout<<"Introduce el nombre del fichero:"<<endl;
    cin>>nombre_f;
    fstream f(nombre_f);

    Pila<int> P,Q,R;

    f>>P>>Q;

    R=suma(P,Q);

    while(!R.vacia()){
        cout<<R.tope();
        R.pop();
    }

    f<<R;

    f.close();

    return 0;
}


Pila<int> suma(Pila<int> P, Pila<int> Q){
    int llevada=0, res;
    Pila<int> R;

    while(!P.vacia()&&!Q.vacia()){
        res=P.tope()+Q.tope()+llevada;
        llevada=0;
        if(res>10){
            llevada=1;
            res=res-10;
        }
        R.push(res);
        P.pop();
        Q.pop();
    }
    while(!P.vacia()){
        R.push(P.tope());
        P.pop();
    }
    while(!Q.vacia()){
        R.push(Q.tope());
        Q.pop();
    }
    return R;
}
