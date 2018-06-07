#include <iostream>
#include "ColaCircular.h"
#include "PilaDinamica.h"
#define N 6

void crearpila (Pila<int> P, int *v);
void crearcola (Cola<int> C, int *v);
bool isomorfica (Pila<int> P, Cola<int> C);

using namespace std;

int main()
{
    int vp[N]={5,4,3,2,1,0};
    int vc[N]={1,2,3,4,5,6};
    Pila<int> P;
    Cola<int> C(6);

    crearpila(P,vp);
    crearcola(C,vc);

    if(isomorfica(P,C)==true)
        cout<<"La pila es isomorfica."<<endl;
    else
        cout<<"La pila no es isomorfica."<<endl;

    return 0;
}

void crearpila(Pila<int> P, int *v)
{
    int i;
    for(i=0;i<N;i++)
        P.push(v[i]);
}

void crearcola(Cola<int> C, int *v)
{
    int i;
    for(i=0;i<N;i++)
        C.push(v[i]);
}

bool isomorfica (Pila<int> P, Cola<int> C)
{
    int i;
    bool valido;
    if(!P.vacia())
        P.pop();
    for(i=0;i<N;i=i+2)
    {
        if(!C.vacia())
        {
            if(P.tope()==C.frente())
                valido=true;
            else
                valido=false;
            P.pop();
            C.pop();
        }
    }
    return valido;
}
