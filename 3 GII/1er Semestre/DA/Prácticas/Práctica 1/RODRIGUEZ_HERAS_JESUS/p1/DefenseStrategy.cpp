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

// Devuelve la posición en el mapa del centro de la celda (i,j)
// i - fila
// j - columna
// cellWidth - ancho de las celdas
// cellHeight - alto de las celdas
Vector3 cellCenterToPosition(int i, int j, float cellWidth, float cellHeight){ return Vector3((j * cellWidth) + cellWidth * 0.5f, (i * cellHeight) + cellHeight * 0.5f, 0); }

// Devuelve la celda a la que corresponde una posición en el mapa
// pos - posición que se quiere convertir
// i_out - fila a la que corresponde la posición pos (resultado)
// j_out - columna a la que corresponde la posición pos (resultado)
// cellWidth - ancho de las celdas
// cellHeight - alto de las celdas
void positionToCell(const Vector3 pos, int &i_out, int &j_out, float cellWidth, float cellHeight){ i_out = (int)(pos.y * 1.0f/cellHeight); j_out = (int)(pos.x * 1.0f/cellWidth); }

float cellValue(int row, int col, bool** freeCells, int nCellsWidth, int nCellsHeight, float mapWidth, float mapHeight, float cellWidth, float cellHeight, List<Object*> obstacles, List<Defense*> defenses) {

	//CAMBIAR

	float proximidad = 0;
    Vector3 dst,obj;
    dst.x = (nCellsWidth*0.5f) * cellWidth + (cellWidth*0.5f) - row * cellWidth +(cellWidth*0.5f);
    dst.y = (nCellsHeight*0.5f) * cellHeight + (cellHeight*0.5f) - col * cellHeight +(cellHeight*0.5f);

    for(std::list<Object*>::const_iterator it = obstacles.begin();
        it != obstacles.end();it++)
        {
        obj.x = (*it)->position.x - row * cellWidth + cellWidth*0.5f;
        obj.y = (*it)->position.y - col * cellHeight + cellHeight*0.5f;
        if((*it)->radio * 1.5 < obj.length())
          proximidad += 1;
        if((*it)->radio * 2 < obj.length())
          proximidad += 0.5;
        if((*it)->radio * 1.1 < obj.length())
          proximidad += 0.25;
        }
    return  std::max(mapWidth,mapHeight) - dst.length() + proximidad;
}

bool factibilidad(float x, float y, Defense* defensa, std::list<Object*> obstaculos, float mapWidth, float mapHeight, std::list<Defense*> defensas, float cellWidth, float cellHeight){

	bool entra = true;
	if (x-defensa->radio < 0 || x+defensa->radio > mapWidth || y-defensa->radio < 0 || y+defensa->radio > mapHeight) {
		entra = false; //No cabe porque se sale de los límites del mapa
	}

	std::list<Object*>::const_iterator iterObst = obstaculos.begin();
	std::list<Defense*>::const_iterator iterDef = defensas.begin();
	Vector3 posicionDefensa(x, y, 0);
	while (iterObst!=obstaculos.end()) {
		if ((defensa->radio + (*iterObst)->radio) > (_distance(posicionDefensa, (*iterObst)->position))) {
			entra = false; //Se choca con un obsaculo
		}else{
			while (iterDef!=defensas.end()) {
				if ((defensa->radio + (*iterDef)->radio) > (_distance(posicionDefensa, (*iterDef)->position))) {
					entra = false; //Se choca con una defensa
				}
				++iterDef;
			}
		}
		++iterObst;
	}

	return entra;
}

void seleccion(float** mapa, int nCellsWidth, int nCellsHeight, int* fila, int* columna){
	float maxi = 0;
	for (size_t i = 0; i < nCellsWidth; ++i) {
		for (size_t j = 0; j < nCellsHeight; ++j) {
			if (mapa[i][j] > maxi) {
				maxi = mapa[i][j];
				*fila = i;
				*columna = j;
			}
		}
	}
	mapa[*fila][*columna] = 0;
}

void cellValueDefensas(float** mapa, int nCellsWidth, int nCellsHeight, float cellWidth, float cellHeight, float mapWidth, float mapHeight, std::list<Defense*> defenses){
	std::list<Defense*>::const_iterator extractor = defenses.begin();
	Vector3 distancia;
	for (size_t i = 0; i < nCellsWidth; ++i) {
		for (size_t j = 0; j < nCellsHeight; ++j) {
			distancia.x = i*cellWidth + cellWidth*0.5f - (*extractor)->position.x;
			distancia.y = j*cellHeight + cellHeight*0.5f - (*extractor)->position.y;
			mapa[i][j] = std::max(mapWidth, mapHeight) - distancia.length();
		}
	}
}

void DEF_LIB_EXPORTED placeDefenses(bool** freeCells, int nCellsWidth, int nCellsHeight, float mapWidth, float mapHeight, std::list<Object*> obstacles, std::list<Defense*> defenses) {

    float cellWidth = mapWidth / nCellsWidth;
    float cellHeight = mapHeight / nCellsHeight;

    int maxAttemps = 1000;

	float** mapa = new float*[nCellsHeight];
	for (size_t i = 0; i < nCellsHeight; ++i) {
		mapa[i] = new float[nCellsWidth];
	}

	for (size_t i = 0; i < nCellsHeight; ++i) {
		for (size_t j = 0; j < nCellsHeight; ++j) {
			mapa[i][j] = cellValue(i, j, freeCells, nCellsWidth, nCellsHeight, mapWidth, mapHeight, cellWidth, cellHeight, obstacles, defenses);
		}
	}


	std::list<Defense*>::iterator currentDefense = defenses.begin();
	int fila = 0, columna = 0;
	float x = 0, y = 0;

	while(currentDefense == defenses.begin() && maxAttemps > 0){
		seleccion(mapa, nCellsWidth, nCellsHeight, &fila, &columna);
		x = fila*cellWidth + cellWidth*0.5f;
		y = columna*cellHeight + cellHeight*0.5f;
		if(factibilidad(x, y, (*currentDefense), obstacles, mapWidth, mapHeight, defenses, cellWidth, cellHeight)){
			(*currentDefense)->position.x = x;
			(*currentDefense)->position.y = y;
			(*currentDefense)->position.z = 0;

			cellValueDefensas(mapa, nCellsWidth, nCellsHeight, cellWidth, cellHeight, mapWidth, mapHeight, defenses);

			++currentDefense;
		}
		--maxAttemps;
	}

	maxAttemps = 1000 * std::max(nCellsWidth,nCellsHeight);

	while (currentDefense != defenses.end() && maxAttemps > 0) {
		seleccion(mapa, nCellsWidth, nCellsHeight, &fila, &columna);
		x = fila*cellWidth + cellWidth*0.5f;
		y = columna*cellHeight + cellHeight*0.5f;
		if(factibilidad(x, y, (*currentDefense), obstacles, mapWidth, mapHeight, defenses, cellWidth, cellHeight)){
			(*currentDefense)->position.x = x;
			(*currentDefense)->position.y = y;
			(*currentDefense)->position.z = 0;
			++currentDefense;
		}
		--maxAttemps;
	}

#ifdef PRINT_DEFENSE_STRATEGY

    float** cellValues = new float* [nCellsHeight];
    for(size_t i = 0; i < nCellsHeight; ++i) {
       cellValues[i] = new float[nCellsWidth];
       for(size_t j = 0; j < nCellsWidth; ++j) {
           cellValues[i][j] = ((int)(cellValue(i, j))) % 256;
       }
    }
    dPrintMap("strategy.ppm", nCellsHeight, nCellsWidth, cellHeight, cellWidth, freeCells, cellValues, std::list<Defense*>(), true);

    for(size_t i = 0; i < nCellsHeight ; ++i)
        delete [] cellValues[i];
	delete [] cellValues;
	cellValues = NULL;

#endif
}
