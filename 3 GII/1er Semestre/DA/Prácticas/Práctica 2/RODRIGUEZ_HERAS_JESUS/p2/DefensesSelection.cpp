// ###### Config options ################


// #######################################

#define BUILDING_DEF_STRATEGY_LIB 1

#include "../simulador/Asedio.h"
#include "../simulador/Defense.h"

using namespace Asedio;

void mochila(float* valores, unsigned int* coste, unsigned int ases, float** matriz, std::list<Defense*> defenses){
    int itCoste = 0;
    int itv = 0;

    for (size_t j = 0; j <= ases; ++j) {
        if (j < coste[itCoste]) {
            matriz[0][j] = 0;
        }else{
            matriz[0][j] = valores[itv];
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

    unsigned int costeTotal = 0;

    std::list<Defense*>::const_iterator it = defenses.begin();
    while (it != defenses.end()) {
        costeTotal += (*it)->cost;
        ++it;
    }

    if (costeTotal <= ases) {
        std::list<Defense*>::const_iterator iter = defenses.begin();
        while (iter != defenses.end()) {
            selectedIDs.push_back((*iter)->id);
            ++iter;
        }
    }else{
        unsigned int coste[defenses.size()];
        float valores[defenses.size()];

        for (size_t i = 0; i < defenses.size(); ++i) {
            coste[i] = 0;
            valores[i] = 0;
        }

        float** matriz = new float*[defenses.size()];
    	for (size_t i = 0; i < defenses.size(); ++i) {
    		matriz[i] = new float[ases+1];
    	}

        std::list<Defense*>::const_iterator extractor = defenses.begin();
        selectedIDs.push_back((*extractor)->id);
        ases -= (*extractor)->cost;
        defenses.erase(extractor);

        int i = 0;
        std::list<Defense*>::const_iterator itDef = defenses.begin();
        while (itDef != defenses.end()) {
            //((*itDef)->range * (*itDef)->damage * (*itDef)->attacksPerSecond * (*itDef)->health) / ((*itDef)->dispersion * (*itDef)->cost);
            valores[i] = ((*itDef)->range * (*itDef)->damage * (*itDef)->attacksPerSecond * (*itDef)->health) / ((*itDef)->dispersion * (*itDef)->cost);
            coste[i] = (*itDef)->cost;
            ++i;
            ++itDef;
        }

        mochila(valores, coste, ases, matriz, defenses);

        // Nos posicionamos al final de la fila y la columna
        i = defenses.size() - 1;
        int j = ases;

        std::list<Defense*>::const_iterator iterDef = defenses.end();
        --iterDef;

        while (i>=0 && j>0) {
            if(i>0 && matriz[i][j] == matriz[i-1][j]){
                --i;
                --iterDef;
            }else{
                selectedIDs.push_back((*iterDef)->id);
                j -= (*iterDef)->cost;
                --i;
                --iterDef;
            }
        }
    }
}
