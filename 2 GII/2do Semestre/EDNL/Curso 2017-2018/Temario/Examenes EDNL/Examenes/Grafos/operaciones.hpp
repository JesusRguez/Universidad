#include <alg_grafoPMC.h>

//Ejercicio 1
template <typename tCoste>
matriz<tCoste> FloydMax(const GrafoP<tCoste>& G,
                     matriz<typename GrafoP<tCoste>::vertice>& P)
{
   const size_t n = G.numVert();
   matriz<tCoste> A(n);   // matriz de costes mínimos
   const tCoste INFINITO = GrafoP<tCoste>::INFINITO;

   // Iniciar A y P con caminos directos entre cada par de vértices.
   P = matriz<vertice>(n);
   for (vertice i = 0; i < n; i++) {
      A[i] = G[i];                    // copia costes del grafo
      A[i][i] = INFINITO;             // diagonal a 0
      P[i] = vector<vertice>(n, i);   // caminos directos
   }

   for (vertice k = 0; k < n; k++)
      for (vertice i = 0; i < n; i++)
         for (vertice j = 0; j < n; j++) {
            tCoste ikj = suma(A[i][k], A[k][j]);
            if (A[i][j] == INFINITO)
                A[i][j] = ikj;
            else{
               if(ikj > A[i][j] and ikj != INFINITO) {
                   A[i][j] = ikj;
                   P[i][j] = k;
               }
            }
         }
   return A;
}

template <class tCoste>
matriz<tCoste>(typename GrafoP<tCoste> G)
{
    matriz<tCoste> m;
    matriz<vertice> p;

    m = Floyd(G, p);

    return m;
}

//Ejercicio2
struct casilla {
    int fil;
    int col;
};

struct pared {
    casilla c1;
    casilla c2;
};

casilla nodoTuCasilla(unsigned v, unsigned N)
{
    casilla c;

    c.fil = v/N;
    c.col = v%N;

    return c;
}

bool adyacentes(casilla c1, casilla c2)
{
    return ((c1.fil == c2.fil and abs(c1.col - c2.col) == 1) or
            (c1.col == c2.col and abs(c1.fil - c2.fil) == 1);
}

vertice casillaTuNodo(casilla c, unsigned N)
{
    return c.fil * N + c.col;
}

bool hayPared(unsigned v1, unsigned v2, vector<pared> vP, unsigned N)
{
    for(const auto& i : vP)
        if((casillaTuNodo(vP[i].c1, N) == v1 and
            casillaTuNodo(vP[i].c2, N) == v2) or
           casillaTuNodo(vP[i].c2, N) == v1 and
           casillaTuNodo(vP[i].c1, N) == v2))
           return true;

    return false;
}

vector<vertice> LaberintoParedes(unsigned N, vector<pared> vP, vertice e,
                                 vertice s)
{
    GrafoP<unsigned> G(N*N);
    vector<unsigned> D(N*N);
    vector<vertice> P(N*N);

    vertice o, v;

    for(size_t i = 0; i < G.numVert(); ++i)
        for(size_t j = 0; j < G.numVert(); ++j)
        {
            if(i == j)
                G[i][j] = 0;
            else if(Adyacentes(nodoTuCasilla(i, N), nodoTuCasilla(j, N))
                    and !hayPared(i, j, vP, N))
                G[i][j] = 1;
            else
                G[i][j] = GrafoP<size_t>::INFINITO;
        }

    o = casillaTuNodo(e, N);
    v = casillaTuNodo(s, N);

    D = Dijkstra(G, o, P);

    return P;
}

//Ejercicio 3
struct almacen{
    float subvencion;
    size_t capacidad;
    size_t actual = 0;
};

void empresa_distribucion(const matriz<double>& M, vertice origen,
                          unsigned unidades, vector<almacen> almacenes)
{
    GrafoP<double> G = M;
    vector<vertice> P;
    vector<double> D = Dijkstra(G, origen, P);
    unsigned descargas = G.numVert() - 1;
    double costeTotal = 0;

    for (size_t i = 0; i < D.size(); ++i)
        D[i] *= (1 - almacenes[i].subvencion);

    while(unidades > 0 and descargas > 0)
    {
        vertice ciudadMin;
        unsigned costeMin = GrafoP<double>::INFINITO;

        for(vertice i = 0; i < D.size(); ++i)
        {
            if(D[i] < costeMin and almacenes[i].actual
               < almacenes[i].capacidad)
            {
                costeMin = D[i];
                ciudadMin = i;
            }
        }

        if(unidades > almacenes[ciudadMin].capacidad)
        {
            unidades -= almacenes[ciudadMin].capacidad;
            almacenes[ciudadMin].actual = almacenes[ciudadMin].capacidad;
        }
        else
        {
            almacenes[ciudadMin].actual = unidades;
            unidades = 0;
        }

        costeTotal += (almacenes[ciudadMin].actual * minCoste);

        --descargas;
    }
}

//Ejercicio 4
template <class km>
km cementosZuelandia(const GrafoP<km>& g, vertice capital,
                     const vector<unsigned>& parte)
{
    vector<vertice> pi, pv;
    vector<km> dd = Dijkstra(g, capital, pi);
    vector<km> di = DijkstraInv(g, capital, pv);

    km distancia = 0;

    for(size_t i = 0; i < parte.size(); ++i)
        distancia += parte[i] * suma(dd[i], di[i]);

    return distancia;
}

//Ejercicio 5
template <class tCoste>
vector<bool> viajeroAlergico(const GrafoP<tCoste>& coche,
                                const GrafoP<tCoste>& tren,
                                const GrafoP<tCoste>& avion, float dinero
                                , const char* alergia, vertice origen)
{
    int nCiudades = coche.numVert();

    vector<bool> ok_viaje(nCiudades, false);

    vector<vertice> p1, p2;
    vector<tCoste> d1, d2;

    if(alergia == 'coche')
    {
        d1 = Dijkstra(tren, origen, p1);
        d2 = Dijkstra(avion, origen, p2);
    }
    else if (alergia == 'tren')
    {
        d1 = Dijkstra(coche, origen, p1);
        d2 = Dijkstra(avion, origen, p2);
    }
    else
    {
        d1 = Dijkstra(coche, origen, p1);
        d2 = Dijkstra(tren, origen, p2);
    }

    for(vertice i = 1; i < nCiudades; ++i){
        if (dinero <= d1[i] or dinero <= d2[i])
            ok_viaje[i] = true;
    }

    return ok_viaje;
}

//Ejercicio 6
template<class tCoste>
matriz<tCoste> transporteCiudades(const GrafoP<tCoste>& A,
                                  const GrafoP<tCoste>& T,
                                  vertice ciudadUnida)
{
    const size_t n = A.numVert();

    matriz<vertice> pA, pT;
    matriz<tCoste> costeA = Floyd(A, pA);
    matriz<tCoste> costeT = Floyd(T, pT);

    matriz<tCoste> coste_min(n);

    for(vertice i = 0; i < n; ++i)
        for(vertice j = 0; j < n; ++j){
            coste_min[i][j] = min(min(costesA[i][j], costesT[i][j]),
                                  min(suma(costesA[i][ciudadUnida],
                                           costesT[ciudadUnida][j]),
                                      suma(costesT[i][ciudadUnida],
                                           costesA[ciudadUnida][j])));
        }

    return coste_min;
}

//Ejercicio 7
template <class tCoste>
vector<vertice> rutaOrigenDestino(const GrafoP<tCoste>& tren,
                                  const GrafoP<tCoste>& bus,
                                  vertice origen, vertice destino,
                                  vertice cambio1, vertice cambio2)
{
    vector<vertice> pT, pA;
    vector<tCoste> costeT = Dijkstra(tren, origen, pT);
    vector<tCoste> costeA = DijkstraInv(bus, destino, pA);

    return min(suma(costeT[cambio1], costeA[cambio1]),
               suma(costeT[cambio2], costeA[cambio2]));
}


//Ejercicio 9
template <class tCoste>
tCoste ejercicio9(const GrafoP<tCoste>& tren, const GrafoP<tCoste>& bus,
                          vertice origen, vertice destino, const tCoste coste)
{
    matriz<vertice> pT, pA;
    size_t n = tren.numVert();

    matriz<tCoste> m_total(2*n, GrafoP<tCoste>::INFINITO);

    for(vertice i = 0; i < 2*n; ++i)
        for(vertice j = 0; j < 2*n; ++j){
            if(i < n-1 and j < n-1)
                m_total[i][j] = tren[i][j];
            if(i < n-1 and j >= n)
                if(j - i == n)
                    m_total[i][j] = coste;
            if(i >= n and j < n)
                if(i - j == n)
                    m_total[i][j] = coste;
            if(i >= n and j >= n)
                m_total[i][j] = bus[i][j];
        }

    vector<tCoste> costeT = Dijkstra(m_total, origen, pT);
    vector<tCoste> costeB = Dijkstra(m_total, origen + n, pA);

    return min(costeT[destino], costeB[destino]);
}

//Ejercicio 10
template <class tCoste>
tCoste ejercicio10(const GrafoP<tCoste>& tren,
                           const GrafoP<tCoste>& bus,
                           const GrafoP<tCoste>& avion,
                           vertice origen, vertice destino,
                           tCoste costeTrenBus,
                           tCoste costeAeropuerto)
{
    vector<vertice> pT, pB, pA;

    size_t n = tren.numVert();

    GrafoP<tCoste> m_total(3*n, GrafoP<tCoste>::INFINITO);

    //Cuadrantes 1, 5, 9
    for(vertice i = 0; i < n; ++i)
        for(vertice j = 0; j < n; ++j)
        {
            m_total[i][j] = tren[i][j];
            m_total[i+n][j+n] = bus[i][j];
            m_total[i+2*n][j+2*n] = avion[i][j];
        }

    //Cuadrantes 2, 3, 4, 6, 7, 8
    for(vertice i = 0; i < n; ++i)
    {
        m_total[i][i+n] = m_total[i+n][i] = costeTrenBus;
        m_total[i][i+2*n] = m_total[i+2*n][i] = costeAeropuerto;
        m_total[i+n][i+2*n] = m_total[i+2*n][i+n] = costeAeropuerto;
    }

    vector<tCoste> costeT = Dijkstra(tren, origen, pT);
    vector<tCoste> costeB = Dijkstra(bus, origen + n, pB);
    vector<tCoste> costeA = Dijkstra(avion, origen + 2*n, pA);

    return min(costeT[destino], min(costeB[destino], costeA[destino]));
}

//Ejercicio 11
template <class tCoste>
struct puente {
    typedef typename GrafoP<tCoste>::vertice vertice;

    puente(const vertice& a, const vertice& b)
        : origen(a), destino(b)
    {}

    vertice origen;
    vertice destino;
};

template <class tCoste>
matriz<tCoste> archipielagoHuries(const GrafoP<tCoste>& isla1,
                                  const GrafoP<tCoste>& isla2,
                                  const GrafoP<tCoste>& isla3,
                                  const Lista<puente>& puentes)
{
    typedef typename GrafoP<tCoste>::vertice vertice;
    typedef typename Lista<puente>::posicion pos_l;

    matriz<vertice> p;

    size_t n1 = isla1.numVert();
    size_t n2 = isla2.numVert();
    size_t n3 = isla3.numVert();

    GrafoP<tCoste> m_total(n1+n2+n3, GrafoP<tCoste>::INFINITO);

    for(vertice i = 0; i < n1; ++i)
        for(vertice j = 0; j < n1; ++j)
            m_total[i][j] = m_total[j][i] = isla1[i][j];

    for(vertice i = 0; i < n2; ++i)
        for(vertice j = 0; j < n2; ++j)
            m_total[i+n1][j+n1] = m_total[j+n1][i+n1] = isla2[i][j];

    for(vertice i = 0; i < n3; ++i)
        for(vertice j = 0; j < n3; ++j)
            m_total[i+n1+n2][j+n1+n2] = m_total[j+n1+n2][i+n1+n2] = isla3[i][j];

    for (pos_l beg = puentes.primera(); beg != puentes.fin();
         beg = puentes.siguiente(beg))
    {
        puente sig_puente = puentes.elemento(beg);

        m_total[sig_puente.origen][sig_puente.destino] =
            m_total[sig_puente.destino][sig_puente.origen] = 0;
    }

    return Floyd(m_total, p);
}

//Ejercicio 12
template<class tCoste>
typename GrafoP<tCoste>::vertice
mejor_costera(const GrafoP<tCoste>& isla,
              const Lista<typename GrafoP<tCoste>::vertice> costeras)
{
    typedef typename GrafoP<tCoste>::vertice vertice;
    typedef typename Lista<vertice>::posicion pos;

    tCoste  min_isla = GrafoP<tCoste>::INFINITO;
    vertice costera;

    for (pos i = costeras.primera(); i != costeras.fin();
         i = costeras.siguiente(i))
    {
        vertice sig_c = costeras.elemento(i);

        vector<vertice> p1, p2;
        vector<tCoste> costeD = Dijkstra(isla, sig_c, p1);
        vector<tCoste> costeI = DijkstraInv(isla, sig_c, p2);

        tCoste coste_total = 0;

        for(vertice i = 0; i < costeD.size(); ++i)
            coste_total = suma(coste_total, suma(costeD[i],  costeI[i]));

        if (coste_total <= min_isla) {
            min_isla = coste_total;
            costera = sig_c;
        }

    }

    return costera;
}

template <class tCoste>
puente Grecoland(const GrafoP<tCoste>& Fobos,
                 const GrafoP<tCoste>& Deimos,
                 const Lista<vertice>& f_costeras,
                 const Lista<vertice>& d_costeras)
{
    return puente<tCoste>(mejor_costera(Fobos, f_costeras),
                          mejor_costera(Deimos, d_costeras));
}


//Ejercicio 13
template<class tCoste>
struct puentesMin{
    typedef puente<tCoste> puente;

    puentesMin(puente const& a, puente const& b)
        : p1(a), p2(b)
    {}

    puente p1;
    puente p2;
};

template<class tCoste>
puentesMin<tCoste> archipielagoDevastado(const GrafoP<tCoste>& isla1,
                                         const GrafoP<tCoste>& isla2,
                                         const GrafoP<tCoste>& isla3,
                                         const Lista<vertice>& c1_costeras,
                                         const Lista<vertice>& c2_costeras,
                                         const Lista<vertice>& c3_costeras)
{
    typedef GrafoP<tCoste>::vertice vertice;
    vertice c1_mejor = mejor_costera(isla1, c1_costeras);
    vertice c2_mejor = mejor_costera(isla2, c2_costeras);
    vertice c3_mejor = mejor_costera(isla3, c3_costeras);

    return puentesMin<tCoste>(puente<tCoste>(c1_mejor, c2_mejor),
                              puente<tCoste>(c1_mejor, c3_mejor));
}
