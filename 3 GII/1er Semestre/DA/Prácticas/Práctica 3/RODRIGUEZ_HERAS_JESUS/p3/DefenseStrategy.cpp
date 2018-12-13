// ###### Config options ################



// #######################################

#define BUILDING_DEF_STRATEGY_LIB 1

#include "../simulador/Asedio.h"
#include "../simulador/Defense.h"
#include "cronometro.h"
#include <vector>

using namespace Asedio;

float defaultCellValue(int row, int col, bool** freeCells, int nCellsWidth, int nCellsHeight, float mapWidth, float mapHeight, List<Object*> obstacles, List<Defense*> defenses) {

    float cellWidth = mapWidth / nCellsWidth;
    float cellHeight = mapHeight / nCellsHeight;

    Vector3 cellPosition((col * cellWidth) + cellWidth * 0.5f, (row * cellHeight) + cellHeight * 0.5f, 0);

    float val = 0;
    for (List<Object*>::iterator it=obstacles.begin(); it != obstacles.end(); ++it) {
	    val += _distance(cellPosition, (*it)->position);
    }

    return val;
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
			while ((*iterDef)!=defensa) {
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

void seleccionSinOrdenacion(float** mapa, int nCellsWidth, int nCellsHeight, int* fila, int* columna){
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

void DEF_LIB_EXPORTED placeDefensesSinOrdenacion(bool** freeCells, int nCellsWidth, int nCellsHeight, float mapWidth, float mapHeight, std::list<Object*> obstacles, std::list<Defense*> defenses) {

    float cellWidth = mapWidth / nCellsWidth;
    float cellHeight = mapHeight / nCellsHeight;
    int maxAttemps = 1000;

	float** mapa = new float*[nCellsHeight];
	for (size_t i = 0; i < nCellsHeight; ++i) {
		mapa[i] = new float[nCellsWidth];
	}

	for (size_t i = 0; i < nCellsHeight; ++i) {
		for (size_t j = 0; j < nCellsHeight; ++j) {
			mapa[i][j] = defaultCellValue(i, j, freeCells, nCellsWidth, nCellsHeight, mapWidth, mapHeight, obstacles, defenses);
		}
	}

	int fila = 0, columna = 0;
	float x = 0, y = 0;

	std::list<Defense*>::iterator currentDefense = defenses.begin();
	while(currentDefense == defenses.begin() && maxAttemps > 0){
		seleccionSinOrdenacion(mapa, nCellsWidth, nCellsHeight, &fila, &columna);
		x = fila*cellWidth + cellWidth*0.5f;
		y = columna*cellHeight + cellHeight*0.5f;
		if(factibilidad(x, y, (*currentDefense), obstacles, mapWidth, mapHeight, defenses, cellWidth, cellHeight)){
			(*currentDefense)->position.x = x;
			(*currentDefense)->position.y = y;
			(*currentDefense)->position.z = 0;

			//defaultCellValue(mapa, nCellsWidth, nCellsHeight, cellWidth, cellHeight, mapWidth, mapHeight, defenses);

			++currentDefense;
		}
		--maxAttemps;
	}

	while (currentDefense != defenses.end() && maxAttemps > 0) {
		seleccionSinOrdenacion(mapa, nCellsWidth, nCellsHeight, &fila, &columna);
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
}

void DEF_LIB_EXPORTED placeDefensesFusion(bool** freeCells, int nCellsWidth, int nCellsHeight, float mapWidth, float mapHeight, std::list<Object*> obstacles, std::list<Defense*> defenses) {

    float cellWidth = mapWidth / nCellsWidth;
    float cellHeight = mapHeight / nCellsHeight;
    int maxAttemps = 1000;

	float** mapa = new float*[nCellsHeight];
	for (size_t i = 0; i < nCellsHeight; ++i) {
		mapa[i] = new float[nCellsWidth];
	}

	for (size_t i = 0; i < nCellsHeight; ++i) {
		for (size_t j = 0; j < nCellsHeight; ++j) {
			mapa[i][j] = defaultCellValue(i, j, freeCells, nCellsWidth, nCellsHeight, mapWidth, mapHeight, obstacles, defenses);
		}
	}

    class posicionConValor{
    public:
        int i, j;
        float valor;
        posicionConValor();
        posicionConValor(int i2, int j2, float valor2) : i(i2), j(j2), valor(valor2){};
    };

    std::vector<posicionConValor> mapaOrdenado;
    std::cout<< mapaOrdenado.size();
    for (int i = 0; i < nCellsHeight; ++i) {
        for (int j = 0; j < nCellsWidth; ++j) {
            mapaOrdenado.push_back(pepe);
        }
    }

    std::vector<posicionConValor>::iterator i = mapaOrdenado.begin();
    std::vector<posicionConValor>::iterator j = mapaOrdenado.end();
    ordenacionFusion(mapaOrdenado, i, j);
    //Cuando esto termine, me lo devuelve ordenado, falta la implementación de esta funcion

	int fila = 0, columna = 0;
	float x = 0, y = 0;

	std::list<Defense*>::iterator currentDefense = defenses.begin();
	while(currentDefense == defenses.begin() && maxAttemps > 0){
		//seleccionConOrdenacion(mapa, nCellsWidth, nCellsHeight, &fila, &columna);

		x = fila*cellWidth + cellWidth*0.5f;
		y = columna*cellHeight + cellHeight*0.5f;
		if(factibilidad(x, y, (*currentDefense), obstacles, mapWidth, mapHeight, defenses, cellWidth, cellHeight)){
			(*currentDefense)->position.x = x;
			(*currentDefense)->position.y = y;
			(*currentDefense)->position.z = 0;

			//defaultCellValue(mapa, nCellsWidth, nCellsHeight, cellWidth, cellHeight, mapWidth, mapHeight, defenses);

			++currentDefense;
		}
		--maxAttemps;
	}

	while (currentDefense != defenses.end() && maxAttemps > 0) {
		seleccionConOrdenacion(mapa, nCellsWidth, nCellsHeight, &fila, &columna);
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
}


void DEF_LIB_EXPORTED placeDefensesRapido(bool** freeCells, int nCellsWidth, int nCellsHeight, float mapWidth, float mapHeight, std::list<Object*> obstacles, std::list<Defense*> defenses) {

    float cellWidth = mapWidth / nCellsWidth;
    float cellHeight = mapHeight / nCellsHeight;
    int maxAttemps = 1000;

	float** mapa = new float*[nCellsHeight];
	for (size_t i = 0; i < nCellsHeight; ++i) {
		mapa[i] = new float[nCellsWidth];
	}

	for (size_t i = 0; i < nCellsHeight; ++i) {
		for (size_t j = 0; j < nCellsHeight; ++j) {
			mapa[i][j] = defaultCellValue(i, j, freeCells, nCellsWidth, nCellsHeight, mapWidth, mapHeight, obstacles, defenses);
		}
	}

	int fila = 0, columna = 0;
	float x = 0, y = 0;

	std::list<Defense*>::iterator currentDefense = defenses.begin();
	while(currentDefense == defenses.begin() && maxAttemps > 0){
		seleccionSinOrdenacion(mapa, nCellsWidth, nCellsHeight, &fila, &columna);
		x = fila*cellWidth + cellWidth*0.5f;
		y = columna*cellHeight + cellHeight*0.5f;
		if(factibilidad(x, y, (*currentDefense), obstacles, mapWidth, mapHeight, defenses, cellWidth, cellHeight)){
			(*currentDefense)->position.x = x;
			(*currentDefense)->position.y = y;
			(*currentDefense)->position.z = 0;

			//defaultCellValue(mapa, nCellsWidth, nCellsHeight, cellWidth, cellHeight, mapWidth, mapHeight, defenses);

			++currentDefense;
		}
		--maxAttemps;
	}

	while (currentDefense != defenses.end() && maxAttemps > 0) {
		seleccionSinOrdenacion(mapa, nCellsWidth, nCellsHeight, &fila, &columna);
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
}

void DEF_LIB_EXPORTED placeDefensesMonticulo(bool** freeCells, int nCellsWidth, int nCellsHeight, float mapWidth, float mapHeight, std::list<Object*> obstacles, std::list<Defense*> defenses) {

    float cellWidth = mapWidth / nCellsWidth;
    float cellHeight = mapHeight / nCellsHeight;
    int maxAttemps = 1000;

	float** mapa = new float*[nCellsHeight];
	for (size_t i = 0; i < nCellsHeight; ++i) {
		mapa[i] = new float[nCellsWidth];
	}

	for (size_t i = 0; i < nCellsHeight; ++i) {
		for (size_t j = 0; j < nCellsHeight; ++j) {
			mapa[i][j] = defaultCellValue(i, j, freeCells, nCellsWidth, nCellsHeight, mapWidth, mapHeight, obstacles, defenses);
		}
	}

    std::vector<float> mapaOrdenado(0, nCellsHeight*nCellsWidth);
    std::vector<float>::const_iterator itMapa = mapaOrdenado.begin();
    for (size_t i = 0; i < nCellsHeight; ++i) {
        for (size_t j = 0; j < nCellsWidth; ++j) {
            mapaOrdenado.insert(itMapa, mapa[i][j]);
            ++itMapa;
        }
    }

    std::make_heap(mapaOrdenado.begin(), mapaOrdenado.end());
    std::sort_heap(mapaOrdenado.begin(), mapaOrdenado.end(), std::greater<float>());

	int fila = 0, columna = 0;
	float x = 0, y = 0;

	std::list<Defense*>::iterator currentDefense = defenses.begin();
	while(currentDefense == defenses.begin() && maxAttemps > 0){
		seleccionSinOrdenacion(mapa, nCellsWidth, nCellsHeight, &fila, &columna);
		x = fila*cellWidth + cellWidth*0.5f;
		y = columna*cellHeight + cellHeight*0.5f;
		if(factibilidad(x, y, (*currentDefense), obstacles, mapWidth, mapHeight, defenses, cellWidth, cellHeight)){
			(*currentDefense)->position.x = x;
			(*currentDefense)->position.y = y;
			(*currentDefense)->position.z = 0;

			//defaultCellValue(mapa, nCellsWidth, nCellsHeight, cellWidth, cellHeight, mapWidth, mapHeight, defenses);

			++currentDefense;
		}
		--maxAttemps;
	}

	while (currentDefense != defenses.end() && maxAttemps > 0) {
		seleccionSinOrdenacion(mapa, nCellsWidth, nCellsHeight, &fila, &columna);
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
}

void DEF_LIB_EXPORTED placeDefenses3(bool** freeCells, int nCellsWidth, int nCellsHeight, float mapWidth, float mapHeight, List<Object*> obstacles, List<Defense*> defenses) {

    float cellWidth = mapWidth / nCellsWidth;
    float cellHeight = mapHeight / nCellsHeight;

	cronometro c1;
    long int r1 = 0;
    c1.activar();
    do { // Este do-while tiene el esequema de medida adaptativo
		placeDefensesSinOrdenacion(freeCells, nCellsWidth, nCellsHeight, mapWidth, mapHeight, obstacles, defenses);
        //Funciona
		++r1;
    } while(c1.tiempo() < 1.0);
    c1.parar();

    cronometro c2;
    long int r2 = 0;
    c2.activar();
    do { // Este do-while tiene el esequema de medida adaptativo
		placeDefensesFusion(freeCells, nCellsWidth, nCellsHeight, mapWidth, mapHeight, obstacles, defenses);
        //Este no funciona
		++r2;
    } while(c2.tiempo() < 1.0);
    c2.parar();

    cronometro c3;
    long int r3 = 0;
    c3.activar();
    do { // Este do-while tiene el esequema de medida adaptativo
		placeDefensesRapido(freeCells, nCellsWidth, nCellsHeight, mapWidth, mapHeight, obstacles, defenses);
        //Este no se si funciona, pero no
		++r3;
    } while(c3.tiempo() < 1.0);
    c3.parar();

    cronometro c4;
    long int r4 = 0;
    c4.activar();
    do { // Este do-while tiene el esequema de medida adaptativo
		placeDefensesMonticulo(freeCells, nCellsWidth, nCellsHeight, mapWidth, mapHeight, obstacles, defenses);
        //Por descarte, tampoco funciona
		++r4;
    } while(c4.tiempo() < 1.0);
    c4.parar();


    std::cout << (nCellsWidth * nCellsHeight) << '\t' << c1.tiempo() / r1 << '\t' << c2.tiempo() / r2 << '\t' << c3.tiempo() / r3 << '\t' << c4.tiempo() / r4 << std::endl;
}
