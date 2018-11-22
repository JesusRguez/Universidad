// ###### Config options ################


// #######################################

#define BUILDING_DEF_STRATEGY_LIB 1

#include "../simulador/Asedio.h"
#include "../simulador/Defense.h"

using namespace Asedio;

void mochilita(float* valores, unsigned int* coste, unsigned int ases, float** matriz, std::list<Defense*> defenses){
    int itCoste = 0;
    int itv = 0;

    int j = 0;
    while (j < ases) {
        if (j < coste[itCoste]) {
            matriz[0][j] = 0;
            ++j;
        }else{
            matriz[0][j] = valores[itv];
            ++j;
        }
    }

    for (size_t i = 1; i < defenses.size(); ++i) {
        for (size_t j = 0; j < ases; ++j) {
            if (j < coste[i]) {
                matriz[i][j] = matriz[i-1][j];
            }else{
                matriz[i][j] = std::max(matriz[i-1][j], matriz[i-1][j-coste[i]]+valores[i]);
            }
        }
    }
}

void DEF_LIB_EXPORTED selectDefenses(std::list<Defense*> defenses, unsigned int ases, std::list<int> &selectedIDs, float mapWidth, float mapHeight, std::list<Object*> obstacles) {

    std::list<Defense*>::const_iterator itDef = defenses.begin();

    unsigned int coste[defenses.size()];
    float valores[defenses.size()];
    for (size_t i = 0; i < defenses.size(); ++i) {
        coste[i] = 0;
        valores[i] = 0;
    }

    int i = 0;
    while (itDef != defenses.end()) {
        valores[i] = 0; //((*itDef)->range*(*itDef)->damage*(*itDef)->attacksPerSecond*(*itDef)->health)/((*itDef)->dispersion*(*itDef)->cost);
        coste[i] = (*itDef)->cost;
        ++i;
        ++itDef;
    }

    float** matriz = new float*[defenses.size()];
	for (size_t i = 0; i < defenses.size(); ++i) {
		matriz[i] = new float[ases];
	}

    mochilita(valores, coste, ases, matriz, defenses);

}
