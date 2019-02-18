#include"alg_grafoPMC.h"
#include <iostream>

using namespace std;

struct casilla {
    int fila;
    int col;
};

struct pared {
    casilla c1;
    casilla c2;
};

casilla nodoToCasilla(size_t v, unsigned N)
{ return casilla{(int)(v/N), (int)(v%N)}; }

size_t casillaToNodo(casilla c, unsigned N)
{ return c.fila*N + c.col; }

bool adyacentes(casilla c1, casilla c2)
{
    return ((c1.fila == c2.fila and abs(c1.col - c2.col) == 1)
            or (c1.col == c2.col and abs(c1.fila - c2.fila) == 1));
}

bool hayPared(size_t v1, size_t v2,
              const vector<pared>& vP, unsigned N)
{
    for(size_t i = 0; i != vP.size(); ++i) {
        if((casillaToNodo(vP[i].c1, N) == v1 and
           casillaToNodo(vP[i].c2, N) == v2)
        or (casillaToNodo(vP[i].c1, N) == v2 and
             casillaToNodo(vP[i].c1, N) == v1))
            return true;
    }

    return false;
}

template<class tCoste> typename GrafoP<tCoste>::tCamino
laberinto_paredes(unsigned N, const vector<pared>& paredes,
                  casilla origen, casilla destino)
{
    typedef typename GrafoP<tCoste>::vertice vertice;

    GrafoP<tCoste> g(N*N);
    matriz<tCoste> m(N*N);
    vector<vertice> p;

    size_t n = g.numVert();

    for(vertice i = 0; i < n; ++i)
        for(vertice j = 0; j < n; ++j) {
            if(i == j)
                g[i][j] = 0;
            else if(adyacentes(nodoToCasilla(i, N), nodoToCasilla(j, N))
                    and !hayPared(i, j, paredes, N))
                g[i][j] = 1;
        }

    vertice o = casillaToNodo(origen, N);
    vertice d = casillaToNodo(destino, N);

    vector<tCoste> D = Dijkstra(g, o, p);

    cout << "El coste de ir de " << o << " a la casilla " << d << " es: "
         << D[d] << endl;

    return camino<tCoste>(o, d, p);
}
