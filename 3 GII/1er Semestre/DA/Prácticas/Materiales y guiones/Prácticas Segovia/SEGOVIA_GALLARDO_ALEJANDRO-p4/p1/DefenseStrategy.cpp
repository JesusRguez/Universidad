// ###### Config options ################

//#define PRINT_DEFENSE_STRATEGY 1    // generate map images

// #######################################

#define BUILDING_DEF_STRATEGY_LIB 1

#include "../simulador/Asedio.h"
#include "../simulador/Defense.h"

#ifdef PRINT_DEFENSE_STRATEGY
#include "ppm.h"
#endif

#ifdef CUSTOM_RAND_GENERATOR
RAND_TYPE SimpleRandomGenerator::a;
#endif

using namespace Asedio;

float cellValue(int row, int col, bool** freeCells, int nCellsWidth,
               int nCellsHeight, float mapWidth, float mapHeight,
               float cellWidth, float cellHeight,
               List<Object*> obstacles, List<Defense*> defenses)
{
    float proximidad = 0;
    Vector3 dst,obj;
    dst.x = (nCellsWidth/2) * cellWidth + (cellWidth/2) - row * cellWidth +
              (cellWidth/2);
    dst.y = (nCellsHeight/2) * cellHeight + (cellHeight/2) - col * cellHeight +
            (cellHeight/2);

    for(std::list<Object*>::const_iterator it = obstacles.begin();
        it != obstacles.end();it++)
        {
        obj.x = (*it)->position.x - row * cellWidth + cellWidth/2;
        obj.y = (*it)->position.y - col * cellHeight + cellHeight/2;
        if((*it)->radio * 1.5 < obj.length())
          proximidad += 1;
        if((*it)->radio * 2 < obj.length())
          proximidad += 0.5;
        if((*it)->radio * 1.1 < obj.length())
          proximidad += 0.5;
        }
    return  std::max(mapWidth,mapHeight) - dst.length() + proximidad;
}


bool factible(float x, float y, float rDef, float mapWidth,
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


void cellValueDefensas(float** cellValue, int  nCellsWidth, int nCellsHeight,
              float cellWidth, float cellHeight,float mapWidth, float mapHeight,
              std::list<Defense*> defenses)
{
    List<Defense*>::const_iterator centroExtraccion = defenses.begin();
    Vector3 dst;
    for(int i = 0; i < nCellsWidth; ++i)
        for(int j = 0; j < nCellsHeight; ++j)
        {
          dst.x = i*cellWidth + cellWidth/2 - (*centroExtraccion)->position.x;
          dst.y = j*cellHeight + cellHeight/2 - (*centroExtraccion)->position.y;
          cellValue[i][j] = std::max(mapWidth, mapHeight) - dst.length();
        }
}


void seleccion(float** cellValues, int nCellsWidth,
               int nCellsHeight, int* x, int* y)
{
  float masPrometedora = 0;
  for(int i = 0; i < nCellsWidth; i++)
    for(int j = 0; j < nCellsHeight; ++j)
      if(masPrometedora < cellValues[i][j])
      {
        masPrometedora = cellValues[i][j];
        *x = i;
        *y = j;
      }
  cellValues[*x][*y] = -1;
}

void DEF_LIB_EXPORTED placeDefenses(bool** freeCells, int nCellsWidth,
                                    int nCellsHeight, float mapWidth,
                                    float mapHeight,
                                    std::list<Object*> obstacles,
                                    std::list<Defense*> defenses)
{
    int fila = 0, columna = 0;
    float x = 0, y = 0;
    float** cellValues = new float*[nCellsHeight];

		for(int i = 0; i < nCellsHeight; ++i)
	    cellValues[i] = new float[nCellsWidth];

    float cellWidth = mapWidth / nCellsWidth;
    float cellHeight = mapHeight / nCellsHeight;

    for(int i = 0; i < nCellsHeight; i++)
  		for(int j = 0; j < nCellsWidth; j++)
  			cellValues[i][j] = cellValue(i, j, freeCells, nCellsWidth, nCellsHeight,
  				mapWidth,mapHeight,cellWidth, cellHeight, obstacles, defenses);

    int maxAttemps = 1000;

    List<Defense*>::iterator currentDefense = defenses.begin();

    while(currentDefense == defenses.begin() and maxAttemps > 0)
    {
        seleccion(cellValues, nCellsWidth, nCellsHeight, &fila, &columna);

        x = fila*cellWidth + cellWidth/2;
        y = columna*cellHeight + cellHeight/2;

        if(factible(x, y, (*currentDefense)->radio, mapWidth, mapHeight,
           cellWidth,cellHeight,obstacles, defenses))
        {
            (*currentDefense)->position.x = x;
            (*currentDefense)->position.y = y;
            (*currentDefense)->position.z = 0;

            cellValueDefensas(cellValues, nCellsWidth, nCellsHeight,cellWidth,
              cellHeight,mapWidth,mapHeight,defenses);

            currentDefense++;
        }
        maxAttemps--;
    }

    maxAttemps = 1000 * std::max(nCellsWidth,nCellsHeight);

    while(currentDefense != defenses.end() && maxAttemps > 0)
    {
        seleccion(cellValues, nCellsWidth, nCellsHeight, &fila, &columna);

        x = fila*cellWidth + cellWidth/2;
        y = columna*cellHeight + cellHeight/2;

        if(factible(x, y, (*currentDefense)->radio, mapWidth, mapHeight,
        cellWidth,cellHeight, obstacles, defenses))
        {
            (*currentDefense)->position.x = x;
            (*currentDefense)->position.y = y;
            (*currentDefense)->position.z = 0;
            currentDefense++;
        }
        maxAttemps--;
    }

  }



#ifdef PRINT_DEFENSE_STRATEGY

    dPrintMap("strategy.ppm", nCellsHeight, nCellsWidth, cellHeight,
              cellWidth, freeCells, cellValues, std::list<Defense*>(), true);

    for(int i = 0; i < nCellsHeight ; ++i)
        delete [] cellValues[i];

    delete [] cellValues;

    cellValues = NULL;

#endif
