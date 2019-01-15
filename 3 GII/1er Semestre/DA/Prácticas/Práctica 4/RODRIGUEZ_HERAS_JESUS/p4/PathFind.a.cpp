// ###### Config options ################

#define PRINT_PATHS 1

// #######################################

#define BUILDING_DEF_STRATEGY_LIB 1

#include "../simulador/Asedio.h"
#include "../simulador/Defense.h"

#ifdef PRINT_PATHS
#include "ppm.h"
#endif
#include<vector>
using namespace Asedio;
using namespace std;

Vector3 cellCenterToPosition(int i, int j, float cellWidth, float cellHeight){
    return Vector3((j * cellWidth) + cellWidth * 0.5f, (i * cellHeight) + cellHeight * 0.5f, 0);
}
//hay que rellenar adecuadamente la matriz additionalCost
//additionalCost le pone valor diferente a cada celda del terreno que influye en la heuristica

void DEF_LIB_EXPORTED calculateAdditionalCost(float** additionalCost
, int cellsWidth, int cellsHeight, float mapWidth, float mapHeight
, List<Object*> obstacles, List<Defense*> defenses)
{

    float cellWidth = mapWidth / cellsWidth;
    float cellHeight = mapHeight / cellsHeight;
    Vector3 distmanhattan,posuco;
for(list<Defense*>::iterator it=defenses.begin();it!=defenses.end();++it)
{    for(int i = 0 ; i < cellsHeight ; ++i)
    {
        for(int j = 0 ; j < cellsWidth ; ++j)
        {
            Vector3 posuco = cellCenterToPosition(i,j, cellWidth, cellHeight);
            distmanhattan.x=(*it)->position.x-posuco.x;
            distmanhattan.y=(*it)->position.y-posuco.y;
            additionalCost[i][j]=distmanhattan.length();
            for(list<Object*>::iterator obj=obstacles.begin();
            obj!=obstacles.end();++obj)
            {
              if((*obj)->position.x==posuco.x&&(*obj)->position.y==posuco.y)
              {
                additionalCost[i][j]=mapWidth*mapHeight;
              }
            }
        }
    }
  }

}

void DEF_LIB_EXPORTED calculatePath(AStarNode* originNode, AStarNode* targetNode
, int cellsWidth, int cellsHeight, float mapWidth, float mapHeight
, float** additionalCost, std::list<Vector3> &path)
{
  bool found=false;
  vector<AStarNode*> abiertos,cerrados;
  AStarNode* current=originNode;
  abiertos.push_back(current);
  float cellWidth = mapWidth/cellsWidth;
  float cellHeight = mapHeight/cellsHeight;

  while(found==false&&!abiertos.size()!=0)
  {
    current=abiertos.front();
    abiertos.erase(abiertos.begin());
    cerrados.push_back(current);
    if(current==targetNode)
    {
      found=true;
      path.push_front(current->position);
    }else
    {
      float dist;
      int x,y;
      for(List<AStarNode*>::iterator j=current->adjacents.begin();
      j!=current->adjacents.end();++j)
      {
        if(find(cerrados.begin(),cerrados.end(),(*j))==cerrados.end())
        {
          if(find(abiertos.begin(),abiertos.end(),(*j))==abiertos.end())
          {
            x=(*j)->position.x/cellWidth;
            y=(*j)->position.y/cellHeight;
            (*j)->G=current->G+_distance((*j)->position,targetNode->position)
            +additionalCost[x][y];
            (*j)->H=_sdistance((*j)->position,targetNode->position);
            (*j)->F=(*j)->G+(*j)->H;
            (*j)->parent=current;
            abiertos.push_back(*j);
          }else
          {
            dist=_distance(current->position,(*j)->position);
            if((*j)->G>current->G+dist)
            {
              (*j)->G=current->G+dist;
              (*j)->F=(*j)->G+(*j)->H;
              (*j)->parent=current;
            }
          }
        }
      }
      sort(abiertos.begin(), abiertos.end());
    }
  }
  while(current->parent!=originNode)
  {
    current=current->parent;
    path.push_front(current->position);
  }

}
