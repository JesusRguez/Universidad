// ###### Config options ################


// #######################################
#define BUILDING_DEF_STRATEGY_LIB 1

#include "../simulador/Asedio.h"
#include "../simulador/Defense.h"

using namespace Asedio;

float puntuacion(std::list<Defense*>::iterator defensa)
{
  return (*defensa)->damage *(*defensa)->attacksPerSecond *
         (*defensa)->dispersion * (*defensa)->range *(*defensa)->health;
}

void algoritmo_mochila(unsigned int ases, std::list<Defense*> defenses,
                       float rendimiento[], unsigned int coste[],float** matDef)
{

  for(int i=0;i<=ases;i++){
    if(i<coste[0])
    {
      matDef[0][i]=0;
    }
    else
    {
      matDef[0][i]=rendimiento[0];
    }
  }

  for(int i=1;i<defenses.size();i++){
  for(int j=0;j<=ases;j++)
    if(j<coste[i])
      matDef[i][j]=matDef[i-1][j];

    else
      matDef[i][j]=std::max(matDef[i-1][j], matDef[i-1][j-coste[i]] +
                                            rendimiento[i]);
  }

}

void DEF_LIB_EXPORTED selectDefenses(std::list<Defense*> defenses,
                                     unsigned int ases,
                                     std::list<int> &selectedIDs,
                                     float mapWidth, float mapHeight,
                                     std::list<Object*> obstacles){

    unsigned int ctotal = 0;

    for(std::list<Defense*>::iterator it=defenses.begin();it!=defenses.end();
        it++)
          ctotal += (*it)->cost;

    if(ctotal <= ases)
      for(std::list<Defense*>::iterator it=defenses.begin();it!= defenses.end();
          it++)
            selectedIDs.push_back((*it)->id);

    else{

    float rendimiento[defenses.size()];
    unsigned int coste[defenses.size()];
    float** matDef = new float*[defenses.size()];
    for(int i = 0; i < defenses.size(); ++i)
      matDef[i] = new float[ases+1];

    std::list<Defense*>::iterator centroExtraccion = defenses.begin();
    selectedIDs.push_back((*centroExtraccion)->id);
    ases -= (*centroExtraccion)->cost;
    defenses.erase(centroExtraccion);

    int i = 0;
    for(std::list<Defense*>::iterator it=defenses.begin(); it != defenses.end();
        it++){
        rendimiento[i]  = puntuacion(it);
        coste[i] = (*it)->cost;
        i++;
    }

    algoritmo_mochila(ases,defenses,rendimiento,coste,matDef);

    i = defenses.size()-1;
    int j = ases;
    std::list<Defense*>::iterator it = defenses.end();
    it--;

    while(i>=0 && j>0){
      if(i>0 && matDef[i][j] == matDef[i-1][j]){
        i--;
        it--;
      }
      else{
        selectedIDs.push_back((*it)->id);
        j = j - (*it)->cost;
        i--;
        it--;
      }
    }
  }
}
