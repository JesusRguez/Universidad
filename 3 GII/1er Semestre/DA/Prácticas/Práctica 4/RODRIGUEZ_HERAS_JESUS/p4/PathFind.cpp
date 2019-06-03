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

    std::list<Defense*>::iterator it = defenses.begin();

    for(int i = 0 ; i < cellsHeight ; ++i) {
        for(int j = 0 ; j < cellsWidth ; ++j) {
            Vector3 cellPosition = cellCenterToPosition(i, j, cellWidth, cellHeight);
            additionalCost[i][j] = _sdistance(cellPosition, (*it)->position);
        }
    }
}

void DEF_LIB_EXPORTED calculatePath(AStarNode* originNode, AStarNode* targetNode, int cellsWidth, int cellsHeight, float mapWidth, float mapHeight, float** additionalCost, std::list<Vector3> &path) {

    int maxIter = 100;
    AStarNode* current = originNode;
    std::vector<AStarNode*> opened;
    std::vector<AStarNode*> closed;
    bool encontrado = false;
    float cellWidth = mapWidth / cellsWidth;
    float cellHeight = mapHeight / cellsHeight;

    opened.push_back(current);

    while (current != targetNode && !opened.empty() && encontrado == false) {
        current = opened.front();
        opened.erase(opened.begin());
        closed.push_back(current);

        if (current == targetNode) {
            encontrado = true;
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
                        d = _distance(current->position, (*iter)->position);
                        if ((*iter)->G > current->G + d) {
                            (*iter)->G = current->G + d;
                            (*iter)->F = (*iter)->G + (*iter)->H;
                            (*iter)->parent = current;
                        }
                    }
                    std::sort(opened.begin(), opened.end());
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
