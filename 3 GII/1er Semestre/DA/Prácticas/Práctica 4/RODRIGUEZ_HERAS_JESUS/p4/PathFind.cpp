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

void DEF_LIB_EXPORTED calculateAdditionalCost(float** additionalCost, int cellsWidth, int cellsHeight, float mapWidth, float mapHeight, List<Object*> obstacles, List<Defense*> defenses) {

    float cellWidth = mapWidth / cellsWidth;
    float cellHeight = mapHeight / cellsHeight;

    for(int i = 0 ; i < cellsHeight ; ++i) {
        for(int j = 0 ; j < cellsWidth ; ++j) {
            Vector3 cellPosition = cellCenterToPosition(i, j, cellWidth, cellHeight);
            float cost = 0;
            if( (i+j) % 2 == 0 ) {
                cost = cellWidth * 100; //Cambiar el coste adicional
            }
            additionalCost[i][j] = cost;
        }
    }
}

bool ordena(AStarNode* n1, AStarNode* n2){
    return n1.F < n2.F;
}

float heuristica(AStarNode* current, AStarNode* target){
    //Implementar la distancia de manhattan
}

void DEF_LIB_EXPORTED calculatePath(AStarNode* originNode, AStarNode* targetNode, int cellsWidth, int cellsHeight, float mapWidth, float mapHeight, float** additionalCost, std::list<Vector3> &path) {

    int maxIter = 100;
    AStarNode* current = originNode;
    std::vector<AStarNode*> opened;
    std::vector<AStarNode*> closed;
    bool encontrado = false;

    current->G = 0;
    current->H = heuristica(current, target);
    current->P = NULL;
    current->F = current->G + current->H;

    opened.push_back(current);
    std::make_heap(opened.begin(), opened.end());
    std::sort_heap(opened.begin(), opened.end(), ordena);

    while (current != target && !opened.empty() && encontrado == true) {
        opened.pop_back(current);
        std::pop_heap(opened.begin(), opened.end(), ordena);

        closed.push_back(current);
        std::make_heap(closed.begin(), closed.end());
        std::sort_heap(closed.begin(), closed.end());

        if (current == tarjet) {
            encontrado == true;
        }else{
            int i, j;
            float d;
            std::list<AStarNode*>::iterator iter = current->adjacents.begin();
            while (iter != current->adjacents.end()) {
                if (closed.end() == std::find(closed.begin(), closed.end(), (*iter))) {
                    if (opened.end() == std::find(opened.begin(), opened.end(), (*iter))) {
                        i = (*iter)->position.x / cellWidth;
                        j = (*iter)->position.y / cellHeight;
                        (*iter)->G = current->G + _distance(current->position, (*iter)->position) + additionalCost[i][j];
                        (*iter)->H = _sdistance((*iter)->position, targetNode->position);
                        (*iter)->F = (*iter)->G + (*iter)->H;
                        (*iter)->parent = current;

                        opened.push_back(*iter);
                    }else{
                        d = _sdistance(current->position, (*iter)->position);
                        if ((*iter)->G > current->G + d) {
                            (*iter)->G = current->G + d;
                            (*iter)->F = (*iter)->G + (*iter)->H;
                            (*iter)->parent = current;
                        }
                    }
                    std::make_heap(opened.begin(), opened.end());
                    std::sort_heap(opened.begin(), opened.end(), ordena);
                }
                ++iter;
            }
        }
    }

    while (current->parent != originNode) {
        current = current->parent;
        path.push_front(current->position);
    }

}
