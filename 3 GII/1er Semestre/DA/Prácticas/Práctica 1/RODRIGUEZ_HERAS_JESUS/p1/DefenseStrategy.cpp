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

float cellValue(int row, int col, bool** freeCells, int nCellsWidth, int nCellsHeight
	, float mapWidth, float mapHeight, List<Object*> obstacles, List<Defense*> defenses) {
	return 0; // implemente aqui la funci�n que asigna valores a las celdas
	//Aqui es donde va mi estrategia devoradora que es la que hay que programar y entregar, y sera llamada n*n veces en funcion del numero de celdas
}

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

bool factibilidad(int fila, int columna, Defense* defensa, std::list<Object*> obstaculos, float mapWidth, float mapHeight, std::list<Defense*> defensas, int nCellsWidth, int nCellsHeight){
	bool entra = true;
	Vector3 posicionDefensa = cellCenterToPosition(fila, columna, cellWidth, cellHeight));
	if (posicionDefensa.x-defensa.radio < 0 || posicionDefensa.x+defensa.radio > mapWidth || posicionDefensa.y-defensa.radio < 0 || posicionDefensa.y+defensa.radio > 0) {
		entra = false;//no cabe porque se sale de los límites del mapa
	}else{
		std::list<Object*>::const_iterator i = obstaculos.begin();
		std::list<Defense*>::const_iterator j = defensas.begin();
		while (i!=obstaculos.end()) {
			if ((defensa.radio + obstaculos[i].radio) > (_distance(posicionDefensa, obstaculos[i].position))) {
				entra = false;
			}else{
				while (j!=defensas.end()) {
					if ((defensa.radio + defensas[j].radio) > (_distance(posicionDefensa, defensas[j].position))) {
						entra = false;
					}
					++j;
				}
			}
			++i;
		}
	}
	return entra;
}

Defense& seleccion(std::list<Defense*> defensas, std::list<Obstacles*> obstaculos, float mapWidth, float mapHeight){
	//Ahora la cuestión es seleccionar la celda que mejor se adapta a nuestras especificaciones

}

void DEF_LIB_EXPORTED placeDefenses(bool** freeCells, int nCellsWidth, int nCellsHeight, float mapWidth, float mapHeight, std::list<Object*> obstacles, std::list<Defense*> defenses) {

    float cellWidth = mapWidth / nCellsWidth;
    float cellHeight = mapHeight / nCellsHeight;

    int maxAttemps = 1000;
    /*List<Defense*>::iterator currentDefense = defenses.begin();
    while(currentDefense != defenses.end() && maxAttemps > 0) {

        (*currentDefense)->position.x = ((int)(_RAND2(nCellsWidth))) * cellWidth + cellWidth * 0.5f;
        (*currentDefense)->position.y = ((int)(_RAND2(nCellsHeight))) * cellHeight + cellHeight * 0.5f;
        (*currentDefense)->position.z = 0;
        ++currentDefense;
    }*/

	Defense d;
	std::list<Defenses> defensesCopia = defenses;
	std::list<Defense*>::iterator currentDefense = defensesCopia.begin();
	while (currentDefense != defensesCopia.end() && masAttemps > 0) {
		d = seleccion(defensesCopia, obstacles, mapWidth, mapHeight);
		//defenses.remove(d); No puede ser así porque solo tnemos una lista de defensas que no podemos perder
		defensesCopia.remove(d);
		int fila = 0, columna = 0;
		positionToCell(d.position, fila, columna, cellWidth, cellHeight);
		if (factibilidad(fila, columna, d, obstacles, mapWidth, mapHeight, defenses, nCellsWidth, nCellsHeight)) {
			//defenses.insert(d); Por la misma razón que antes, debe de ser la misma, sin insertar nada
			//Es posible que aquí haya que modificar la matriz de freeCells
			freeCells[fila][columna] = false; //Luego, gracias a la función de factibiliad probaremos si entra la siguiente defensa o no
		}
		++currentDefense;
	}

#ifdef PRINT_DEFENSE_STRATEGY

    float** cellValues = new float* [nCellsHeight];
    for(int i = 0; i < nCellsHeight; ++i) {
       cellValues[i] = new float[nCellsWidth];
       for(int j = 0; j < nCellsWidth; ++j) {
           cellValues[i][j] = ((int)(cellValue(i, j))) % 256;
       }
    }
    dPrintMap("strategy.ppm", nCellsHeight, nCellsWidth, cellHeight, cellWidth, freeCells, cellValues, std::list<Defense*>(), true);

    for(int i = 0; i < nCellsHeight ; ++i)
        delete [] cellValues[i];
	delete [] cellValues;
	cellValues = NULL;

#endif
}
