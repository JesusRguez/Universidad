#include <iostream>
#include <math.h>
#include <stdlib.h>
#include "alg_grafoPMC.h"
#include "alg_grafoP_E-S.h"

using namespace std;

typedef float tElto;

struct ciudad{
    ciudad() {}
    ciudad(float x, float y, string i): cx(x), cy(y), isla(i) {}
    float cx, cy;
    string isla;
};

ostream& operator <<(ostream& os, ciudad c){
    os << "ciudad con coordenadas (" << c.cx << ", " << c.cy << ") de " << c.isla;
    return os;
}

struct puente{
    puente() {}
    ciudad c1;
    ciudad c2;
};

ostream& operator <<(ostream& os, puente p){
    os << "Puente que une la " << p.c1 << " y la ciudad " << p.c2;
    return os;
}

float sumar(vector<tElto> vec)
{
    float Res = 0;
    for(size_t i = 0; i < vec.size(); i++){
        Res = Res + vec[i];
    }
    return Res;
}

float Distancia(ciudad c1, ciudad c2)
{
    return sqrt(pow(c2.cx - c1.cx,2) + pow(c2.cy - c1.cy,2));
}

puente viaje(Grafo& Fobos, Grafo& Deimos, vector<ciudad> CiudadesFobos, vector<ciudad> CiudadesDeimos, vector<bool> FobosCosta, vector<bool> DeimosCosta)
{
    GrafoP<float> costes(Fobos.numVert()+Deimos.numVert());
    vector<float> vec;
    vector<unsigned> P;
    puente Res;

    { //Fobos
    for(size_t i = 0; i < Fobos.numVert(); i++)
    {
        for(size_t j = i+1; j < Fobos.numVert(); j++)
        {
            if(Fobos[i][j]){
            costes[i][j] = Distancia(CiudadesFobos[i], CiudadesFobos[j]);
            costes[j][i] = Distancia(CiudadesFobos[i], CiudadesFobos[j]);}
        }
    }
    cout << "Fobos:" << setprecision(2) << endl << costes << endl;
    }

    { //Deimos
    for(size_t i = Fobos.numVert(); i < Fobos.numVert()+Deimos.numVert(); i++)
    {
        for(size_t j = i+1; j < Fobos.numVert()+Deimos.numVert(); j++)
        {
            if(Deimos[i-Fobos.numVert()][j-Fobos.numVert()]){
            costes[i][j] = Distancia(CiudadesDeimos[i-Fobos.numVert()], CiudadesDeimos[j-Fobos.numVert()]);
            costes[j][i] = Distancia(CiudadesDeimos[i-Fobos.numVert()], CiudadesDeimos[j-Fobos.numVert()]);}
        }
    }
    cout << "Fobos:" << endl << costes << endl;
    }

    float minimo = costes.INFINITO;

    for(size_t i = 0; i < Fobos.numVert(); i++)
    {
        for(size_t j = Fobos.numVert(); j < Fobos.numVert()+Deimos.numVert(); j++)
        {
            if(FobosCosta[i] == true && DeimosCosta[j-Fobos.numVert()] == true)
            {
                costes[i][j] = Distancia(CiudadesFobos[i],CiudadesDeimos[j-Fobos.numVert()]);
                costes[j][i] = costes[i][j];
                cout << costes << endl;
                vec = Dijkstra(costes,i,P);
                cout << "Para las ciudades " << i << " y " << j << " Dijkstra es " << vec << "\ny la suma es " << sumar(vec) << endl;
                if(sumar(vec) < minimo)
                {
                    minimo = sumar(vec);
                    Res.c1 = CiudadesFobos[i];
                    Res.c2 = CiudadesDeimos[j-Fobos.numVert()+1];
                }
                costes[i][j] = costes.INFINITO;
                costes[j][i] = costes.INFINITO;
            }
        }
    }

    return Res;
}

int main ()
{
    Grafo Fobos(5), Deimos(4);
    vector<bool> v;

    /* Fobos */
    {
    v.push_back(false);
    v.push_back(true);
    v.push_back(false);
    v.push_back(false);
    v.push_back(false);
    Fobos[0] = v;
    v.clear();
    v.push_back(true);
    v.push_back(false);
    v.push_back(false);
    v.push_back(true);
    v.push_back(false);
    Fobos[1] = v;
    v.clear();
    v.push_back(false);
    v.push_back(false);
    v.push_back(false);
    v.push_back(true);
    v.push_back(false);
    Fobos[2] = v;
    v.clear();
    v.push_back(false);
    v.push_back(true);
    v.push_back(true);
    v.push_back(false);
    v.push_back(true);
    Fobos[3] = v;
    v.clear();
    v.push_back(false);
    v.push_back(false);
    v.push_back(false);
    v.push_back(true);
    v.push_back(false);
    Fobos[4] = v;
    v.clear();
    }

    /* Deimos */
    {
    v.push_back(false);
    v.push_back(false);
    v.push_back(true);
    v.push_back(true);
    Deimos[0] = v;
    v.clear();
    v.push_back(false);
    v.push_back(false);
    v.push_back(true);
    v.push_back(false);
    Deimos[1] = v;
    v.clear();
    v.push_back(true);
    v.push_back(true);
    v.push_back(false);
    v.push_back(true);
    Deimos[2] = v;
    v.clear();
    v.push_back(true);
    v.push_back(false);
    v.push_back(true);
    v.push_back(false);
    Deimos[3] = v;

    v.clear();
    }


    //cout << "Fobos: " << endl << Fobos << endl;
    //cout << "Deimos: " << endl << Deimos << endl;

    puente Res;
    vector<ciudad> CiudadesFobos, CiudadesDeimos;
    vector<bool> CostaFobos, CostaDeimos;

    CostaFobos.push_back(false);
    CostaFobos.push_back(true);
    CostaFobos.push_back(false);
    CostaFobos.push_back(false);
    CostaFobos.push_back(true);
    CostaDeimos.push_back(true);
    CostaDeimos.push_back(true);
    CostaDeimos.push_back(false);
    CostaDeimos.push_back(false);

    CiudadesFobos.push_back(ciudad(0,1,"Fobos"));
    CiudadesFobos.push_back(ciudad(1,1,"Fobos"));
    CiudadesFobos.push_back(ciudad(3,0,"Fobos"));
    CiudadesFobos.push_back(ciudad(3,1,"Fobos"));
    CiudadesFobos.push_back(ciudad(3,3,"Fobos"));
    CiudadesDeimos.push_back(ciudad(3,6,"Deimos"));
    CiudadesDeimos.push_back(ciudad(5,4,"Deimos"));
    CiudadesDeimos.push_back(ciudad(5,5,"Deimos"));
    CiudadesDeimos.push_back(ciudad(6,6,"Deimos"));


    Res = viaje(Fobos, Deimos, CiudadesFobos, CiudadesDeimos, CostaFobos, CostaDeimos);

    cout << endl << "El puente une:\n" << Res.c1 << endl << Res.c2 << endl;
}
