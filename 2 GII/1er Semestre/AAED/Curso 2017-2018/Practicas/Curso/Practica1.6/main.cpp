#include <iostream>

using namespace std;

//Por referencia:

void intercambia(int &izquierda, int &medio, int &derecha);

int main()
{
    int izquierda, medio, derecha;
    cout<<"Introduzca el numero de la izquierda:"<<endl;
    cin>>izquierda;
    cout<<"Introduzca el numero del medio:"<<endl;
    cin>>medio;
    cout<<"Introudzca el numero de la derecha:"<<endl;
    cin>>derecha;

    intercambia(izquierda, medio, derecha);

    return 0;
}

void intercambia(int &izquierda, int &medio, int &derecha)
{
    int aux;

    aux=izquierda;
    izquierda=medio;
    medio=derecha;
    derecha=aux;

    cout<<izquierda<<"  "<<medio<<"  "<<derecha<<endl;
}

//Con punteros:
/*
void intercambia(int *izquierda, int *medio, int *derecha);

int main()
{
    int izquierda, medio, derecha;
    cout<<"Introduzca el numero de la izquierda:"<<endl;
    cin>>izquierda;
    cout<<"Introduzca el numero del medio:"<<endl;
    cin>>medio;
    cout<<"Introudzca el numero de la derecha:"<<endl;
    cin>>derecha;

    intercambia(&izquierda, &medio, &derecha);

    return 0;
}

void intercambia(int *izquierda, int *medio, int *derecha)
{
    int aux;

    aux=*izquierda;
    *izquierda=*medio;
    *medio=*derecha;
    *derecha=aux;

    cout<<*izquierda<<"  "<<*medio<<"  "<<*derecha<<endl;
}
*/
