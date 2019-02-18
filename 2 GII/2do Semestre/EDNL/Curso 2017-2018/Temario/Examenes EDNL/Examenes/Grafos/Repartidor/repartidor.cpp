
#include <iostream>
#include "alg_grafo_E-S.h"
#include "repartidor.hpp"

using namespace std;

class almacenes
{
public:
    using tCoste = unsigned;

    static void inicializar(map<GrafoP<tCoste>::vertice,
                            unsigned> const& capacidades)
    { almacenes::m_capacidades = capacidades; }

    static void inicializar(map<GrafoP<tCoste>::vertice,
                            unsigned>&& capacidades)
    { almacenes::m_capacidades = move(capacidades); }

    static void volcar(GrafoP<tCoste>::vertice cliente,
                       unsigned carga_camion)
    {
        auto it = m_capacidades.find(cliente);

        if (it == m_capacidades.end())
            return;

        it->second -= min(carga_camion, it->second);
    }

    static int capacidad_restante
    (GrafoP<tCoste>::vertice cliente)
    {
        auto it = m_capacidades.find(cliente);

        if (it == m_capacidades.end())
            return -1;

        return it->second;
    }

private:
    static std::map<GrafoP<tCoste>::vertice, unsigned> m_capacidades;
};

std::map<GrafoP<unsigned>::vertice, unsigned>
almacenes::m_capacidades;

map<GrafoP<unsigned>::vertice, unsigned>
adapt(std::vector<unsigned>&& capacidades)
{
    map<GrafoP<unsigned>::vertice, unsigned> ret;

    for (size_t i = 0; i < capacidades.size(); ++i)
        ret[i] = capacidades[i];

    return ret;
}

int pedido(GrafoP<unsigned>::vertice cliente)
{ return almacenes::capacidad_restante(cliente); }

void cargar(GrafoP<unsigned>::vertice cliente, unsigned& carga_camion)
{ return almacenes::volcar(cliente, carga_camion); }

int main()
{
    GrafoP<unsigned>::tCoste tCoste;

    GrafoP<unsigned> g("repartidor.txt");

    almacenes::inicializar(adapt({0, 300, 200, 400, 500}));

    cout << repartidor(g, 0, 350) << endl;

    return 0;
}
