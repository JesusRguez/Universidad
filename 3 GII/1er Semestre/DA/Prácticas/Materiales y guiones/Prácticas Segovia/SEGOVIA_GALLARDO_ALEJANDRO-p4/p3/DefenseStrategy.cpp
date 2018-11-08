// ###### Config options ################



// #######################################

#define BUILDING_DEF_STRATEGY_LIB 1

#include "../simulador/Asedio.h"
#include "../simulador/Defense.h"
#include "cronometro.h"
#include <algorithm>
#include <vector>

using namespace Asedio;

typedef struct Defensas{
  float puntuacion;
  int x,y;
  bool operator <(Defensas D){ return puntuacion < D.puntuacion; }
  bool operator <(float f){ return puntuacion < f; }
} Defensas;

float defaultCellValue(int row, int col, bool** freeCells, int nCellsWidth,
    int nCellsHeight, float mapWidth, float mapHeight,
    List<Object*> obstacles, List<Defense*> defenses)
    {

    float cellWidth = mapWidth / nCellsWidth;
    float cellHeight = mapHeight / nCellsHeight;

    Vector3 cellPosition((col * cellWidth) + cellWidth * 0.5f,
                        (row * cellHeight) + cellHeight * 0.5f, 0);

    float val = 0;
    for (List<Object*>::iterator it=obstacles.begin(); it != obstacles.end();
      ++it) {
	    val += _distance(cellPosition, (*it)->position);
    }

    return val;
}

std::vector<Defensas> fusion(const std::vector<Defensas>& v1,
                        const std::vector<Defensas>& v2)
{
    std::vector<Defensas> aux(v1.size() + v2.size());
    int i, j, k;
    i = j = k = 0;
    while(i < v1.size() and j < v2.size()) {
        if(v1[i].puntuacion <= v2[j].puntuacion) {
            aux[k].puntuacion = v1[i].puntuacion;
            ++i;
        }
        else {
            aux[k].puntuacion = v2[j].puntuacion;
            ++j;
        }
        ++k;
    }
    while(i < v1.size()) {
        aux[k].puntuacion = v1[i].puntuacion;
        ++k;
        ++i;
    }
    while(j < v2.size()) {
        aux[k].puntuacion = v2[j].puntuacion;
        ++k;
        ++j;
    }
    return aux;
}

void ordenacionFusion(std::vector<Defensas>& v)
{
  int m = v.size()/2;
  if(m != 0) {
      std::vector<Defensas> aux1(m);
      for(int i = 0; i < aux1.size() - 1; ++i)
          aux1[i].puntuacion = v[i].puntuacion;

      std::vector<Defensas> aux2(v.size()-aux1.size());
      for(int i = 0; i < aux2.size() - 1; ++i)
        aux1[i].puntuacion = v[aux1.size()+i].puntuacion;

        ordenacionFusion(aux1);
        ordenacionFusion(aux2);
        v = fusion(aux1, aux2);
  }
}


int divide(std::vector<Defensas>& array, int start, int end) {
  int p = start;
  float x = array[start].puntuacion;
  for(int i = start+1; i<=end; i++)
    if(array[i].puntuacion <= x){
      p++;
      Defensas aux = array[i];
      array[i] = array[p];
      array[p] = aux;
    }
  Defensas array_aux = array[start];
  array[start] = array[p];
  array[p].x = array_aux.x;
  array[p].y = array_aux.y;
  array[p].puntuacion = x;
}


void quicksort(std::vector<Defensas>& array, int start, int end)
{
    int n = end - start + 1;
    if(n <= 2){
      std::sort(array.begin(),array.end());
    }
    else{

        int pivot = divide(array, start, end);

        // Ordeno la lista de los menores
        quicksort(array, start, pivot - 1);

        // Ordeno la lista de los mayores
        quicksort(array, pivot + 1, end);
    }
}
/*
int divide(std::vector<Defensas>& v, int izq, int der)
{
  int i = izq, j = der;
  float tmp;
  float pivot = v[(izq + der) / 2].puntuacion;
  while (i <= j) {

    while (v[i].puntuacion < pivot)
      i++;
      while (v[j].puntuacion > pivot)
      j--;

      if (i <= j)
      {
        tmp = v[i].puntuacion;
        v[i].puntuacion = v[j].puntuacion;
        v[j].puntuacion = tmp;
        i++;
        j--;
      }

  }
  if (izq < j) ordenacionRapida(v, izq, j);
  if (i < der) ordenacionRapida(v, i, der);
}
*/
/*
bool factibilidad(float x, float y, float rDef, float mapWidth,
                  float mapHeight, float cellWidth,
                  float cellHeight,std::list<Object*> obstacles,
                  std::list<Defense*> defenses)
{

    if (x - rDef  < 0 || x + rDef > mapWidth ||y - rDef< 0 ||
        y + rDef > mapHeight)
          return false;

    Vector3 dst;
    for(std::list<Object*>::const_iterator obs = obstacles.begin();
        obs != obstacles.end();obs++)
    {
      dst.x = (*obs)->position.x - x;
      dst.y = (*obs)->position.y - y;
      if(dst.length() - (*obs)->radio - rDef <= 0)
        return false;
    }

    for(std::list<Defense*>::const_iterator defensaconst = defenses.begin();
        defensaconst != defenses.end();defensaconst++)
    {
      dst.x = (*defensaconst)->position.x - x;
      dst.y = (*defensaconst)->position.y - y;
      if(dst.length() - (*defensaconst)->radio - rDef <= 0)
        return false;
    }

    return true;
}

*/
bool factibilidad(float f, float c, float radio_def, float mapWidth,
                  float mapHeight,std::list<Object*> obstaculos,
                  std::list<Defense*> defensas)
{
  //QUE SALGA DEL MAPA
    if (f - radio_def  < 0
       or f+radio_def > mapWidth
       or c - radio_def < 0
       or c+radio_def > mapHeight)
      return false;

  //QUE NO HAYA OBSTACULOS
    for(std::list<Object*>::iterator obs = obstaculos.begin();
        obs != obstaculos.end();obs++)
    {
      Vector3 v;
      v.x = (*obs)->position.x - f;
      v.y = (*obs)->position.y - c;
      if(v.length() - (*obs)->radio - radio_def <= 0)
        return false;
    }
    //QUE NO HAYA DEFENSAS

    for(std::list<Defense*>::iterator it = defensas.begin();
        it != defensas.end();++it)
    {
      Vector3 v;
      v.x = abs((*it)->position.x - f);
      v.y = abs((*it)->position.y - c);
      if(v.length() - (*it)->radio - radio_def <= 0)
        return false;
    }
    return true;
}


void DEF_LIB_EXPORTED placeDefenses3(bool** freeCells, int nCellsWidth,
                                    int nCellsHeight, float mapWidth,
                                    float mapHeight,
                                    std::list<Object*> obstacles,
                                    std::list<Defense*> defenses)
{
    double tMonticulo = 0.0, tSinOrdenacion = 0.0, tOrdenacionRapida = 0.0,
           tOrdenacionFusion = 0.0;
    cronometro c;
    float eAbs = 0.1, eRel = 0.01;
    long int r1 = 0, r2 = 0, r3 = 0, r4 = 0;
    int fila = 0, columna = 0;
    float x = 0, y = 0;
    bool cajaNegraFusion = false, cajaNegraRapida = false,
         cajaNegraMonticulo = false;


    float cellWidth = mapWidth / nCellsWidth;
    float cellHeight = mapHeight / nCellsHeight;

    std::vector<Defensas> v(nCellsWidth*nCellsHeight);

    for(int i = 0; i < nCellsHeight; i++){
  		for(int j = 0; j < nCellsWidth; j++){
  			v[i+j].puntuacion = defaultCellValue(i, j, freeCells, nCellsWidth,
          nCellsHeight, mapWidth, mapHeight, obstacles, defenses);
        v[i+j].x = i;
        v[i+j].y = j;
    }
  }

    std::vector<Defensas> aux(v);
    int maxAttemps = 1000;
    int cont = 0;
    int index = 0;


//ALGORITMO SIN ORDENACION
    c.activar();
    do{

      List<Defense*>::iterator currentDefense = defenses.begin();
      cont = 0;
      while(currentDefense == defenses.begin() && maxAttemps > 0)
      {
        Defensas base;
        base.puntuacion = -1;
        for(int i=1; i<nCellsWidth*nCellsHeight - 1; i++)
        {
          if(v[i].puntuacion > base.puntuacion ){
            base.puntuacion = v[i].puntuacion;
            index = i;
            base.x = v[i].x;
            base.y = v[i].y;
          }

          v[index].puntuacion = -1000;
         }

        x = v[cont].x * cellWidth + cellWidth/2;
        y = v[cont].y * cellHeight + cellHeight/2;

        if(factibilidad(x, y, (*currentDefense)->radio, mapWidth, mapHeight,
           obstacles, defenses))
        {
          (*currentDefense)->position.x = x;
          (*currentDefense)->position.y = y;
          (*currentDefense)->position.z = 0;

          currentDefense++;
        }
        v[index].puntuacion = -10;
        maxAttemps--;
      }
      cont = 0;
      while(currentDefense != defenses.end() && maxAttemps > 0)
      {
          int aux = 0;
          Defensas defensa;
          for(int i=1; i<nCellsWidth*nCellsHeight - 1; i++)
          {
              if(v[i].puntuacion > defensa.puntuacion ){
                defensa.puntuacion = v[i].puntuacion;
                index = i;
                defensa.x = v[i].x;
                defensa.y = v[i].y;
          }
          v[index].puntuacion = -1000;
          }

          x = v[cont].x*cellWidth + cellWidth/2;
          y = v[cont].y*cellHeight + cellHeight/2;

          if(factibilidad(x, y, (*currentDefense)->radio, mapWidth, mapHeight,
             obstacles, defenses))
          {
            (*currentDefense)->position.x = x;
            (*currentDefense)->position.y = y;
            (*currentDefense)->position.z = 0;

            currentDefense++;
          }
          maxAttemps--;
      }

      ++r1;
    }while(c.tiempo() < 1.0);
    c.parar();
    tSinOrdenacion = c.tiempo();
//FIN ALGORITMO SIN ORDENACION


  maxAttemps = 1000;
  v = aux;


//ALGORITMO ORDENACION POR FUSION
c.activar();
do{
    List<Defense*>::iterator currentDefense = defenses.begin();
    cont = v.size()-1;
    ordenacionFusion(v);
    while (cont >= 0 && maxAttemps > 0 && currentDefense != defenses.begin()) {
    x = v[cont].x * cellWidth + cellWidth/2;
    y = v[cont].y * cellHeight + cellHeight/2;
    cont--;
    if(factibilidad(x, y, (*currentDefense)->radio, mapWidth, mapHeight,
       obstacles, defenses))
      {
        (*currentDefense)->position.x = x;
        (*currentDefense)->position.y = y;
        (*currentDefense)->position.z = 0;

        currentDefense++;
      }
      maxAttemps--;
    }

    while(currentDefense != defenses.end() && maxAttemps > 0)
    {
      x = v[cont].x*cellWidth + cellWidth/2;
      y = v[cont].y*cellHeight + cellHeight/2;
      cont--;

      if(factibilidad(x, y, (*currentDefense)->radio, mapWidth, mapHeight,
         obstacles, defenses))
        {
          (*currentDefense)->position.x = x;
          (*currentDefense)->position.y = y;
          (*currentDefense)->position.z = 0;

          currentDefense++;
        }
      maxAttemps--;
    }
    ++r2;
  }while(c.tiempo() < 1.0);
  c.parar();
  tOrdenacionFusion = c.tiempo();

  for(int i = 0;i != v.size() - 1; i++ ){
    if(v[i].puntuacion > v[i+1].puntuacion)
      cajaNegraFusion = true; //Estará a true cuando falle el algoritmo
  }

//FIN ORDENACION POR FUSION

  maxAttemps = 1000;
  v = aux;

//ALGORITMO ORDENACION RAPIDA
  c.activar();
  do{
      List<Defense*>::iterator currentDefense = defenses.begin();
      cont = v.size() - 1;
      while(cont >= 0 && currentDefense != defenses.begin() && maxAttemps > 0){
      quicksort(v,0,v.size()-1);
      if(v[cont].puntuacion != 0){
      x = v[cont].x * cellWidth + cellWidth/2;
      y = v[cont].y * cellHeight + cellHeight/2;
    }

      if(factibilidad(x, y, (*currentDefense)->radio, mapWidth, mapHeight,
         obstacles, defenses))
        {
          (*currentDefense)->position.x = x;
          (*currentDefense)->position.y = y;
          (*currentDefense)->position.z = 0;

          currentDefense++;
        }
        maxAttemps--;
      }
        cont--;

      while(currentDefense != defenses.end() && maxAttemps > 0 && cont >= 0)
      {
        x = v[cont].x*cellWidth + cellWidth/2;
        y = v[cont].y*cellHeight + cellHeight/2;
        cont--;

        if(factibilidad(x, y, (*currentDefense)->radio, mapWidth, mapHeight,
           obstacles, defenses))
          {
            (*currentDefense)->position.x = x;
            (*currentDefense)->position.y = y;
            (*currentDefense)->position.z = 0;

            currentDefense++;
          }
        maxAttemps--;
      }
      ++r3;
    }while(c.tiempo() < 1.0);
    c.parar();
    tOrdenacionRapida = c.tiempo();

    for(int i = 0;i != v.size() - 1; i++){
      if(v[i].puntuacion > v[i+1].puntuacion)
        cajaNegraRapida = true; //Estará a true cuando falle el algoritmo
    }

//FIN ORDENACION RAPIDA

  maxAttemps = 1000;
  v = aux;
  std::make_heap(v.begin(),v.end());
  std::sort_heap(v.begin(),v.end());
  for (size_t i = 0; i < v.size()-1; i++) {
    if(v[i].puntuacion > v[i+1].puntuacion)
      cajaNegraMonticulo= true; //Estaráa true cuando falle el algoritmo
  }

//ALGORITMO MONTICULO
  c.activar();
  do{
  List<Defense*>::iterator currentDefense = defenses.begin();

  while(currentDefense == defenses.begin() and maxAttemps > 0)
  {
    std::make_heap(v.begin(),v.end());
    if (v.size() != 0){
      x = v[0].x*cellWidth + cellWidth/2;
      y = v[0].y*cellHeight + cellHeight/2;
      std::pop_heap(v.begin(), v.end());
      v.pop_back();

      if(factibilidad(x, y, (*currentDefense)->radio, mapWidth, mapHeight,
         obstacles, defenses)){
          (*currentDefense)->position.x = x;
          (*currentDefense)->position.y = y;
          (*currentDefense)->position.z = 0;

          currentDefense++;
      }

    }
    maxAttemps--;
  }

  while(currentDefense != defenses.end() and maxAttemps > 0)
  {

      x = v[0].x*cellWidth + cellWidth/2;
      y = v[0].y*cellHeight + cellHeight/2;
      std::pop_heap(v.begin(), v.end());
      v.pop_back();
      if(factibilidad(x, y, (*currentDefense)->radio, mapWidth, mapHeight,
       obstacles, defenses))
      {
          (*currentDefense)->position.x = x;
          (*currentDefense)->position.y = y;
          (*currentDefense)->position.z = 0;
          currentDefense++;
      }
      maxAttemps--;

  }
  ++r4;
}while(c.tiempo() < 1.0);

  c.parar();
  tMonticulo = c.tiempo();
//FIN MONTICULO

  std::cout << (nCellsWidth * nCellsHeight) << '\t' << tSinOrdenacion / r1 << '\t'
            << tOrdenacionFusion / r2 << '\t' << tOrdenacionRapida / r3 << '\t'
            << tMonticulo / r4 << std::endl;

}
