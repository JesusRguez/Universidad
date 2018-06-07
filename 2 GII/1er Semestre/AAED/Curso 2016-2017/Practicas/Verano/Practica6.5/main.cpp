#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "ColaPseudoestatica.h"
#include "ListaDoble.h"

using namespace std;

typedef struct{
    char matricula[3];
    char codigo;
}avion;

Lista<avion> Avionetas;

//avion *v_avioneta;

void rellenar_avioneta(FILE* f_avioneta, Lista<avion>& Avionetas, Cola<avion>& Parking, Lista<avion>& Aire);
//Cola<avion> crearcola (avion **v_avioneta,Cola<avion> C, int *n_avioneta_aparcada);
//Lista<avion> crearlista (avion **v_avioneta,Lista<avion> L, int *n_avioneta_aire);
void imprimircola(Cola<avion>& C);
void imprimirlitsa(Lista<avion>& L);
void meteravion(Lista<avion>& Aire, Cola<avion>& Parking);
void sacaravion(Lista<avion>& Aire, Cola<avion>& Parking);
void guardarfichero(FILE* f_avioneta, Lista<avion>& Aire, Cola<avion>& Parking);
avion buscaravioneta(Lista<avion>& Aire, Cola<avion>& Parking);
Lista<avion>::posicion buscamos(Lista<avion>& Aire, avion a);


int main()
{
    FILE *f_avioneta;
    int respuesta, respuesta2;

    if((f_avioneta=fopen("avioneta.txt", "r"))==NULL)
        cout<<"No se pudo abrir."<<endl;

    //v_avioneta=(avion *)calloc(1, sizeof(avion));

    Cola<avion> Parking(12);
    Lista<avion> Aire;

    rellenar_avioneta(f_avioneta, Avionetas, Parking, Aire);

    fclose(f_avioneta);

    //Cola<avion> C(12);

    //C=crearcola(&v_avioneta, C, &n_avioneta_aparcada);

    //Lista<avion> L;

    //L=crearlista(&v_avioneta, L, &n_avioneta_aire);

    do
    {
        system("cls");
        cout<<"MENU DEL AEROPUERTO:"<<endl<<"Que desea hacer?"<<endl<<"1. Ver estado del aeropuerto"<<endl<<"2. Modificar estado del aeropuerto"<<endl<<"3. Guardar y salir"<<endl;
        cin>>respuesta;

        switch(respuesta)
        {
        case 1:
            imprimircola(Parking);
            imprimirlitsa(Aire);
            system("pause");
            break;
        case 2:
            do
            {
                cout<<"MODIFICACION DEL AEROPUERTO:"<<endl<<"1. Aparcar avion"<<endl<<"2. Despegar avion"<<endl<<"3. Nuevo avion"<<endl<<"4. Salir"<<endl;
                cin>>respuesta2;

                switch(respuesta2)
                {
                case 1:
                    meteravion(Aire, Parking);
                    break;
                case 2:
                    sacaravion(Aire, Parking);
                    break;
                case 3:

                    break;
                case 4:
                    break;
                }
            }while(respuesta2!=4);
            break;
        case 3:
            break;
        }
    }while(respuesta!=3);


    guardarfichero(f_avioneta, Aire, Parking);

    //sacaravion(C, matr);    //Para sacar el avión hay que comprobar que el código del avión sea 'S', y luego ejecuta la función que está ya programada

    //meteravion(C, a);       //Para meter el avión hay que comprobar que el código del avión sea 'E' como en el crearcola y hacer una función parecida a la de crearcola

    //Luego, habría que hacer un menú con las opciones de cambiar los códigos de entrada y salida de los aviones para que se puedan modificar mientras que el programa se está ejecutando

    return 0;
}

void rellenar_avioneta(FILE* f_avioneta, Lista<avion>& Avionetas, Cola<avion>& Parking, Lista<avion>& Aire)
{
    char cadena[6];         //Guardará todas las líneas que leamos del fichero.
    char *token;            //Usamos la función strtoken para separar las cadenas de caracteres entre guiones.
    avion a;
    Lista<avion>::posicion p=Aire.primera();

    while(!feof(f_avioneta))
    {
        fgets(cadena,6,f_avioneta);

        if (strcmp(cadena,"\0"))
        {
            //*v_avioneta=(avion *)realloc((avion *)(*v_avioneta),((*n_act_avioneta)+1)*sizeof(avion));


            token=strtok(cadena,"-");
            strcpy(a.matricula,token);

            token=strtok(NULL,"\n");
            a.codigo=*token;

            if(a.codigo=='E' && !Parking.llena())
                Parking.push(a);
            else if(a.codigo=='S')
            {
                if(Aire.primera()==Aire.fin())
                    Aire.insertar(a, p);
                else
                {
                    p=Aire.siguiente(p);
                    Aire.insertar(a, p);
                }
            }

        }
    }
}

/*Cola<avion> crearcola (avion **v_avioneta,Cola<avion> C, int *n_avioneta_aparcada)
{
    for(int i=0; i<*n_avioneta_aparcada; i++)
    {
        if(*v_avioneta[i]->codigo=='E' && !C.llena())
        {
            C.push(*v_avioneta[i]);
        }
    }
    return C;
}*/

/*Lista<avion> crearlista (avion **v_avioneta, Lista<avion> L, int *n_avioneta_aire)
{
    if(*v_avioneta[0]->codigo=='S')
    {
        L.insertar(*v_avioneta[0],L.primera());
    }

    Lista<avion>::posicion a=L.primera();
    for(int i=1; i<*n_avioneta_aire; i++)
    {
        if(*v_avioneta[i]->codigo=='S')
        {
            L.siguiente(a);
            L.insertar(*v_avioneta[i],a);
        }
    }
    return L;
}*/

void imprimircola(Cola<avion>& C)
{
    avion a;
    Cola<avion> AUX(25);
    AUX=C;
    cout<<"En el parking estan las siguientes avionetas:"<<endl;
    while(!AUX.vacia())
    {
        a=AUX.frente();
        cout<<a.matricula<<"   ";
        AUX.pop();
    }
    cout<<endl;
}

void imprimirlitsa(Lista<avion>& L)
{
    avion a;
    Lista<avion>::posicion p=L.primera();
    cout<<"En el aire se encuentran las siguientes avionetas:"<<endl;
    while(p!=L.fin())
    {
        a=L.elemento(p);
        cout<<a.matricula<<"   ";
        p=L.siguiente(p);
    }
    cout<<endl;
}

void sacaravion(Lista<avion>& Aire, Cola<avion>& Parking)
{
    bool valido=false;
    avion a;
    char matr[3];
    Cola<avion> AUX(12);

    cout<<"Indique el numero de matricula de la avioneta que desea aparcar:"<<endl;
    cin>>matr;

    if(!Parking.vacia())
        a=Parking.frente();

    while(!Parking.vacia()&& valido==false)
    {
        if(a.matricula==matr) //Probar a hacerlo con C.elemento o algo parecido para saber si podemos concretar la matricula del avion
        {
            Parking.pop();
            valido=true;
        }
        else
        {
            AUX.push(Parking.frente());
            Parking.pop();
        }
    }
    while(!Parking.vacia())
    {
        AUX.push(Parking.frente());
        Parking.pop();
    }
    while(!AUX.vacia())
    {
        Parking.push(AUX.frente());
        AUX.pop();
    }
}

void meteravion(Lista<avion>& Aire, Cola<avion>& Parking)
{
    avion a;
    Lista<avion>::posicion p;

    a=buscaravioneta(Aire, Parking);    //Esata función devuelve correctamente el primer o el ultimo elmento de la lista Aire, pero no devuelve el que yo quiero que devuelva
    //cout<<a.codigo<<", "<<a.matricula;

    if(!Parking.llena())
    {
        Parking.push(a);
        //p=Aire.buscar(a); //Esto peta al pasarle a porque no lo busca bien en la función de antes
        p=buscamos(Aire, a);    //Al hacerlo con esta función, si "aparca" el avión, pero hay un pequeño problema y es que no lo elimina de la lista Aire.
        Aire.eliminar(p);       //Esta función no elimina la avioneta de la lista aire la cual recibe el parámetro p con la poisción de la lista donde se encuentra la avioneta, que es la que tiene que eliminar
        cout<<"Avioneta con matricula "<<a.matricula<<" aparcada correctamente"<<endl; //Esta instrucción funciona si se quitan las de arriba, igual habría que hacer b=a o algo para tener dos variables iguales una
                                                                                        //vez que termine la operacion de buscaravioneta
    }
    else
        cout<<"El aparcamiento está lleno."<<endl;
}

avion buscaravioneta(Lista<avion>& Aire, Cola<avion>& Parking)
{
    avion a, b;
    char matr[3];
    Cola<avion> AUX(12);
    AUX=Parking;

    do
    {
        cout<<"Indique el numero de matricula de la avioneta que desea aparcar:"<<endl;
        cin>>matr;

        Lista<avion>::posicion p=Aire.primera();
        if(p!=Aire.fin())
        {
            a=Aire.elemento(p);
            while(p!=Aire.fin() && a.matricula!=matr)
            {
                p=Aire.siguiente(p);
                if(p!=Aire.fin())
                    a=Aire.elemento(p);
            }
        }

        if(!AUX.vacia())
        {
            b=AUX.frente();
            while(b.matricula!=matr && !AUX.vacia())
            {
                AUX.pop();
                if(!AUX.vacia())
                    b=AUX.frente();
            }
        }

        cout<<a.codigo<<", "<<a.matricula;

        if(b.matricula==matr)       //Aquí hay un fallo porque siempre me pilla la 20 y no la que quiero que utilice
            cout<<"Esta avioneta ya esta aparcada."<<endl;
        else if(a.matricula!=matr)
            cout<<"No existe un avion con dicha matricula."<<endl;

        }while(a.matricula==matr);

        cout<<a.codigo<<", "<<a.matricula;

        return a;
}

Lista<avion>::posicion buscamos(Lista<avion>& Aire, avion a)
{
    avion b;
    Lista<avion>::posicion p=Aire.primera();

    if(p!=Aire.fin())
    {
        b=Aire.elemento(p);
        if(a.codigo==b.codigo && a.matricula==b.matricula)
            return p;
    }
    while(p!=Aire.fin())
    {
        p=Aire.siguiente(p);
        if(p!=Aire.fin())
        {
            b=Aire.elemento(p);
            if(a.codigo==b.codigo && a.matricula==b.matricula)
                return p;
        }

    }
}

void guardarfichero(FILE* f_avioneta, Lista<avion>& Aire, Cola<avion>& Parking)
{
    avion a;

    if((f_avioneta=fopen("avioneta.txt", "w"))==NULL)
        cout<<"No se pudo abrir."<<endl;

    Lista<avion>::posicion p=Aire.primera();

    if(p!=Aire.fin())
    {
        a=Aire.elemento(p);
        while(p!=Aire.fin())
        {
            fprintf(f_avioneta,"%s-%s", a.matricula, a.codigo);
            p=Aire.siguiente(p);
        }
    }

    while(!Parking.vacia())
    {
        a=Parking.frente();
        fprintf(f_avioneta, "%s-%s", a.matricula, a.codigo);
        Parking.pop();
    }

    fclose(f_avioneta);
}
