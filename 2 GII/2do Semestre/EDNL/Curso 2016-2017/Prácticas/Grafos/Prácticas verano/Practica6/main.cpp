#include <iostream>
#include <ostream>
#include "alg_grafoMA.h"
#include "alg_grafoPMC.h"
#include "alg_grafo_E-S.h"
#include "colaenla.h"
#include "grafoMA.h"
#include "grafoPMC.h"
#include "listaenla.h"
#include "matriz.h"
#include "pilaenla.h"

using namespace std;

template <typename tCoste> typename GrafoP<tCoste>::vertice  pseudocentro(GrafoP<tCoste>& G);
template <typename tCoste> bool ciclico(GrafoP<tCoste>& G);
template <typename tCoste> matriz<tCoste> Zuelandia(GrafoP<tCoste>& G, int* ciudades, int* carreteras, int capital);

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}


template <typename tCoste> typename GrafoP<tCoste>::vertice  pseudocentro(GrafoP<tCoste>& G)
{
    int maxi=0,x,y,d=G.INFINITO,verti;
    int v[G.numVert()][2], b[G.numVert()][2], res[G.numVert()];
    matriz<typename GrafoP<tCoste>::vertice> P;
    matriz<tCoste> C;
    C=Floyd(G, P);
    for(int i=0; i<G.numVert(); i++) //Sacamos la distancia hasta el nodo más alejado
    {
        for(int j=0; j<G.numVert(); j++)
        {
            if(C[i][j]>maxi)
            {
                maxi=C[i][j];
                x=i;
                y=j;
            }
        }
        C[x][y]=0;
        v[i][0]=maxi;
        v[i][1]=y;
        maxi=0;
    }
    maxi=0;
    for(int i=0; i<G.numVert(); i++) //Sacamos la distancia hacia el segundo nodo más alejado
    {
        for(int j=0; j<G.numVert(); j++)
        {
            if(C[i][j]>maxi)
            {
                maxi=C[i][j];
                x=i;
                y=j;
            }
        }
        C[x][y]=0;
        b[i][0]=maxi;
        b[i][1]=y;
        maxi=0;
    }
    for(int i=0; i<G.numVert(); i++) //Buscamos el mínimo de las distancias sumandolas debido a que son dos cosas diferentes
    {
        res[i]=v[i][0]+b[i][0];
    }
    for(int i=0; i<G.numVert(); i++)
    {
        if(res[i]<d)
            d=res[i];
    }
    return d; //Devolvemos el valor del diámetro
}


template <typename tCoste> bool ciclico(GrafoP<tCoste>& G)
{
    bool flag=false;
    bool visitados[G.numVert()];

    for(int i=0; i<G.numVert(); i++)
        visitados[i]=false;

    int origen=0;
    int v=origen; //Comienzo a buscar del ciclo
    while(visitados[0]==false && v<G.numVert())
    {
        for(int j=0; j<G.numVert(); j++) //Bucle que recorre las filas de la matriz
        {
            if(G[v][j]!=G.INFINITO && j!=v)
            {
                visitados[j]==true;
            }
        }
        v++;
    }
    return visitados;
}


template <typename tCoste> matriz<tCoste> Zuelandia(GrafoP<tCoste>& G, int* ciudades, int carreteras[][2], int capital)
{
    int tciudades=8, tcarreteras=8;
    for(int i=0; i<tciudades; i++) //Recorrer vector de ciudades
    {
        for(int j=0; j<G.numVert(); j++) //Recorrer la matriz en vertical
        {
            G[ciudades[i]][j]=G.INFINITO;
        }
    }
    for(int i=0; i<tcarreteras; i++) //Pone a infinito las carreteras en la posicion carretera[i][0] y carretera[i][1]
    {
        G[carreteras[i][0]][carreteras[i][1]]=G.INFINITO;
    }
    GrafoP<tCoste> Gt=G;
    int aux;
    for(int i=0; i<G.numVert(); i++) //Esto ers un dijkstra inverso hecho a lo porri
    {
        for(int j=0; j<G.numVert(); j++)
        {
            if(i<j)
            {
                aux=Gt[i][j];
                Gt[i][j]=Gt[j][i];
                Gt[j][i]=aux;
            }
        }
    }
    vector<typename GrafoP<tCoste>::vertice> P, Pt;
    matriz<tCoste> C, Ct, result;

    C=Dijkstra(G, capital, P);
    Ct=Dijkstra(Gt, capital, Pt);

    result=C+Ct;

    return result;
}
