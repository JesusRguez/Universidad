// ###### Config options ################

#define PRINT_PATHS 1

// #######################################

#define BUILDING_DEF_STRATEGY_LIB 1

#include "../simulador/Asedio.h"
#include "../simulador/Defense.h"

#ifdef PRINT_PATHS
#include "ppm.h"
#endif

using namespace Asedio;

Vector3 cellCenterToPosition(int i, int j, float cellWidth, float cellHeight){ 
    return Vector3((j * cellWidth) + cellWidth * 0.5f, (i * cellHeight) + cellHeight * 0.5f, 0); 
}

void DEF_LIB_EXPORTED calculateAdditionalCost(float** additionalCost,
                                              int cellsWidth, int cellsHeight,
                                              float mapWidth, float mapHeight,
                                              List<Object*> obstacles,
                                              List<Defense*> defenses)
{
    Vector3 dst;  
    for(std::list<Defense*>::const_iterator def = defenses.begin();
      def != defenses.end();def++)
        for(int i = 0 ; i < cellsHeight ; ++i) {
            for(int j = 0 ; j < cellsWidth ; ++j) {
                dst.x = (*def)->position.x - (i*cellsWidth + cellsWidth);
                dst.y = (*def)->position.y - (j*cellsHeight + cellsHeight);

                additionalCost[i][j]=dst.length();
            }
        }
}

void DEF_LIB_EXPORTED calculatePath(AStarNode* originNode, AStarNode* targetNode
                   , int cellsWidth, int cellsHeight, float mapWidth, float mapHeight
                   , float** additionalCost, std::list<Vector3> &path) {

    bool nodoTerminal = false;
    float cellWidth = mapWidth/cellsWidth;
    float cellHeight = mapHeight/cellsHeight;

    AStarNode* current = originNode;

    std::vector<AStarNode*> abiertos;
    abiertos.push_back(current);
    std::vector<AStarNode*> cerrados;

    while(abiertos.size() != 0 and nodoTerminal == false){

        current = abiertos.front();
        abiertos.erase(abiertos.begin());
        cerrados.push_back(current);

        if(current == targetNode){
            nodoTerminal = true;
            path.push_front(current->position);
            current = targetNode;
        }

        else{
            int i,j;
            float distancia;
            for(List<AStarNode*>::iterator nodo = current->adjacents.begin();
                nodo != current->adjacents.end(); ++nodo)
                if(cerrados.end() == std::find(cerrados.begin(), cerrados.end(), (*nodo)))
                    if(abiertos.end() == std::find(abiertos.begin(), abiertos.end(), (*nodo))) {
                        i = (*nodo)->position.x / cellWidth;
                        j = (*nodo)->position.y / cellHeight;
                        (*nodo)->G = current->G +
                            _distance(current->position, (*nodo)->position)
                            + additionalCost[i][j];
                        (*nodo)->H =_sdistance((*nodo)->position, targetNode->position);
                        (*nodo)->F = (*nodo)->G + (*nodo)->H;
                        (*nodo)->parent = current;

                        abiertos.push_back(*nodo);
                    }
                    
                    else {
                        distancia = _distance(current->position,(*nodo)->position);

                        if((*nodo)->G > current->G + distancia) {
                            (*nodo)->G = current->G + distancia;
                            (*nodo)->F = (*nodo)->G + (*nodo)->H;
                            (*nodo)->parent = current;
                        }
                    }
                    std::sort(abiertos.begin(), abiertos.end());
        }     
    }

    while(current->parent != originNode) {
        current = current->parent;
        path.push_front(current->position);
    }
}
