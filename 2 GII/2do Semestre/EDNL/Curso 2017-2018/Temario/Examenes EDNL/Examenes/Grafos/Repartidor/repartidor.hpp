#include "alg_grafoPMC.h"
#include <map>

using namespace std;

int pedido(GrafoP<unsigned>::vertice cliente);
void cargar(GrafoP<unsigned>::vertice cliente, unsigned& carga_camion);

template <class tCoste>
typename GrafoP<tCoste>::vertice
ciudad_min(const vector<tCoste>& costes, const vector<bool>& visitados,
           typename GrafoP<tCoste>::vertice origen)
{
    typedef typename GrafoP<tCoste>::vertice vertice;

    vertice siguiente = origen;
    unsigned costeMin = GrafoP<tCoste>::INFINITO;

    for(vertice j = 0; j < costes.size(); ++j)
        if(j != origen and costes[j] < costeMin and !visitados[j]) {
            siguiente = j;
            costeMin = costes[j];
        }

    return siguiente;
}

template <class tCoste>
tCoste repartidor(const GrafoP<tCoste>& g,
                  typename GrafoP<tCoste>::vertice origen,
                  unsigned cap_max)
{
    typedef typename GrafoP<tCoste>::vertice vertice;

    size_t n = g.numVert();

    matriz<vertice> p;
    matriz<tCoste> floyd = Floyd(g, p);

    unsigned camion = cap_max;

    vector<bool> visitados(n, false);
    vertice actual = origen;

    unsigned costeTotal = 0;

    while(!visitados[origen]) {

        vertice sig = ciudad_min(floyd[actual], visitados, origen);

        if(sig == origen)
            visitados[origen] = true;
        else {
            if(camion == 0) {
                costeTotal += floyd[actual][origen];
                actual = origen;
                camion = cap_max;
            }
            else {
                costeTotal += floyd[actual][sig];

                if(camion >= pedido(sig)) {
                    actual = sig;
                    camion -= pedido(sig);
                    visitados[actual] = true;
                }
                else {
                    actual = sig;
                    camion -= pedido(sig);
                }
            }

        }
    }

    return costeTotal += floyd[actual][origen];
}
