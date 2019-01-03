// ###### Config options ################



// #######################################

#define BUILDING_DEF_STRATEGY_LIB 1

#include "../simulador/Asedio.h"
#include "../simulador/Defense.h"
#include "cronometro.h"
#include <vector>

using namespace Asedio;

class posicionConValor{
public:
    int i, j;
    float valor;
    posicionConValor(){i=j=0;valor=0.0;};

    bool operator <(posicionConValor p){
        return this->valor < p.valor;
    }

    bool operator >(posicionConValor p){
        return this->valor > p.valor;
    }

    bool operator ==(posicionConValor p){
        return this->valor == p.valor;
    }

    bool operator >=(posicionConValor p){
        return this->valor >= p.valor;
    }
};

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

void ordenacionInsercion(posicionConValor* mapaOrdenado, int i, int j){
    posicionConValor temp;
    int tam = j-i+1;
    for (i; i < tam; ++i){
        temp = mapaOrdenado[i];
        j = i-1;
        while ((mapaOrdenado[j] < temp) && (j >= 0)){
            mapaOrdenado[j+1] = mapaOrdenado[j];
            --j;
        }
        mapaOrdenado[j+1] = temp;
    }
}

void fusion(posicionConValor* mapaOrdenado, int i, int k, int j){
    int n = j-i+1;
    int p = i;
    int q = k+1;
    posicionConValor w[n];

    for (int l = 0; l < n; ++l) {
        if ((p <= k) && (q > j || mapaOrdenado[p] >= mapaOrdenado[q])) {
            w[l] = mapaOrdenado[p];
            ++p;
        }else{
            w[l] = mapaOrdenado[q];
            ++q;
        }
    }

    for (int l = 1; l < n; ++l) {
        mapaOrdenado[i-1+l] = w[l];
    }
}

void ordenacionFusion(posicionConValor* mapaOrdenado, int i, int j){
    int n = j-i+1;
    if (n < 3) {
        ordenacionInsercion(mapaOrdenado, i, j);
    }else{
        int k = i-1+n/2;
        ordenacionFusion(mapaOrdenado, i, k);
        ordenacionFusion(mapaOrdenado, k+1, j);
        fusion(mapaOrdenado, i, k, j);
    }
}

void seleccionConOrdenacion(posicionConValor* mapaOrdenado, int s, posicionConValor* p){
    *p=mapaOrdenado[s];
}

void DEF_LIB_EXPORTED placeDefensesFusion(bool** freeCells, int nCellsWidth, int nCellsHeight, float mapWidth, float mapHeight, std::list<Object*> obstacles, std::list<Defense*> defenses) {

    float cellWidth = mapWidth / nCellsWidth;
    float cellHeight = mapHeight / nCellsHeight;
    int maxAttemps = 1000;
    bool cajaNegraFusion = false;

	float** mapa = new float*[nCellsHeight];
	for (size_t i = 0; i < nCellsHeight; ++i) {
		mapa[i] = new float[nCellsWidth];
	}

	for (size_t i = 0; i < nCellsHeight; ++i) {
		for (size_t j = 0; j < nCellsHeight; ++j) {
			mapa[i][j] = defaultCellValue(i, j, freeCells, nCellsWidth, nCellsHeight, mapWidth, mapHeight, obstacles, defenses);
		}
	}

    posicionConValor mapaOrdenado[nCellsWidth*nCellsHeight];
    for (int i = 0; i < nCellsWidth; ++i) {
        for (int j = 0; j < nCellsHeight; ++j) {
            mapaOrdenado[i*nCellsWidth+j].i = i;
            mapaOrdenado[i*nCellsWidth+j].j = j;
            mapaOrdenado[i*nCellsWidth+j].valor = mapa[i][j];
        }
    }

    ordenacionFusion(mapaOrdenado, 0, nCellsWidth*nCellsHeight);
    //Cuando esto termine, me lo devuelve ordenado

    for (int i = 0; i < (nCellsHeight*nCellsWidth - 1); ++i) {
        if (mapaOrdenado[i].valor < mapaOrdenado[i+1].valor) {
            cajaNegraFusion = true; // Se pone a true cuando falla el algoritmo
        }
    }

	int fila = 0, columna = 0;
    int s = 0;
	float x = 0, y = 0;
    posicionConValor p;

	std::list<Defense*>::iterator currentDefense = defenses.begin();
	while(currentDefense == defenses.begin() && maxAttemps > 0){
		seleccionConOrdenacion(mapaOrdenado, s, &p);
        ++s;

		x = p.i*cellWidth + cellWidth*0.5f;
		y = p.j*cellHeight + cellHeight*0.5f;
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
		seleccionConOrdenacion(mapaOrdenado, s, &p);
        ++s;
		x = p.i*cellWidth + cellWidth*0.5f;
		y = p.j*cellHeight + cellHeight*0.5f;
		if(factibilidad(x, y, (*currentDefense), obstacles, mapWidth, mapHeight, defenses, cellWidth, cellHeight)){
			(*currentDefense)->position.x = x;
			(*currentDefense)->position.y = y;
			(*currentDefense)->position.z = 0;
			++currentDefense;
		}
		--maxAttemps;
	}
}

int pivote(posicionConValor* mapaOrdenado, int i, int j){
    int p = i;
    posicionConValor x = mapaOrdenado[i];
    posicionConValor aux;
    for (int k = i+1; k < j; ++k) {
        if (mapaOrdenado[k] >= x) {
            ++p;
            aux = mapaOrdenado[k];
            mapaOrdenado[k] = mapaOrdenado[p];
            mapaOrdenado[p] = aux;
        }
    }
    mapaOrdenado[i] = mapaOrdenado[p];
    mapaOrdenado[p] = x;
    return p;
}

void ordenacionRapido(posicionConValor* mapaOrdenado, int i, int j){
    int n = j-i+1;
    if (n < 3) {
        ordenacionInsercion(mapaOrdenado, i, j);
    }else{
        int p = pivote(mapaOrdenado, i, j);
        ordenacionFusion(mapaOrdenado, i, p-1);
        ordenacionFusion(mapaOrdenado, p+1, j);
    }
}

void DEF_LIB_EXPORTED placeDefensesRapido(bool** freeCells, int nCellsWidth, int nCellsHeight, float mapWidth, float mapHeight, std::list<Object*> obstacles, std::list<Defense*> defenses) {

    float cellWidth = mapWidth / nCellsWidth;
    float cellHeight = mapHeight / nCellsHeight;
    int maxAttemps = 1000;
    bool cajaNegraRapido = false;

	float** mapa = new float*[nCellsHeight];
	for (size_t i = 0; i < nCellsHeight; ++i) {
		mapa[i] = new float[nCellsWidth];
	}

	for (size_t i = 0; i < nCellsHeight; ++i) {
		for (size_t j = 0; j < nCellsHeight; ++j) {
			mapa[i][j] = defaultCellValue(i, j, freeCells, nCellsWidth, nCellsHeight, mapWidth, mapHeight, obstacles, defenses);
		}
	}

    posicionConValor mapaOrdenado[nCellsWidth*nCellsHeight];
    for (int i = 0; i < nCellsWidth; ++i) {
        for (int j = 0; j < nCellsHeight; ++j) {
            mapaOrdenado[i*nCellsWidth+j].i = i;
            mapaOrdenado[i*nCellsWidth+j].j = j;
            mapaOrdenado[i*nCellsWidth+j].valor = mapa[i][j];
        }
    }

    ordenacionRapido(mapaOrdenado, 0, nCellsWidth*nCellsHeight);
    //Cuando esto termine, me lo devuelve ordenado

    for (int i = 0; i < (nCellsHeight*nCellsWidth - 1); ++i) {
        if (mapaOrdenado[i].valor < mapaOrdenado[i+1].valor) {
            cajaNegraRapido = true; // Se pone a true cuando falla el algoritmo
        }
    }

	int fila = 0, columna = 0;
    int s = 0;
	float x = 0, y = 0;
    posicionConValor p;

	std::list<Defense*>::iterator currentDefense = defenses.begin();
	while(currentDefense == defenses.begin() && maxAttemps > 0){
        seleccionConOrdenacion(mapaOrdenado, s, &p);
        ++s;

		x = p.i*cellWidth + cellWidth*0.5f;
		y = p.j*cellHeight + cellHeight*0.5f;
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
        seleccionConOrdenacion(mapaOrdenado, s, &p);
        ++s;
		x = p.i*cellWidth + cellWidth*0.5f;
		y = p.j*cellHeight + cellHeight*0.5f;
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
    bool cajaNegraMonticulo = false;

	float** mapa = new float*[nCellsHeight];
	for (size_t i = 0; i < nCellsHeight; ++i) {
		mapa[i] = new float[nCellsWidth];
	}

	for (size_t i = 0; i < nCellsHeight; ++i) {
		for (size_t j = 0; j < nCellsHeight; ++j) {
			mapa[i][j] = defaultCellValue(i, j, freeCells, nCellsWidth, nCellsHeight, mapWidth, mapHeight, obstacles, defenses);
		}
	}

    posicionConValor mapaOrdenado[nCellsWidth*nCellsHeight];
    for (int i = 0; i < nCellsWidth; ++i) {
        for (int j = 0; j < nCellsHeight; ++j) {
            mapaOrdenado[i*nCellsWidth+j].i = i;
            mapaOrdenado[i*nCellsWidth+j].j = j;
            mapaOrdenado[i*nCellsWidth+j].valor = mapa[i][j];
        }
    }

    std::vector<posicionConValor> vectorOrdenado;

    for (int i = 0; i < nCellsWidth*nCellsHeight; ++i) {
        vectorOrdenado.push_back(mapaOrdenado[i]);
    }

    std::make_heap(vectorOrdenado.begin(), vectorOrdenado.end());
    std::sort_heap(vectorOrdenado.begin(), vectorOrdenado.end());

    for (int i = 0; i < (nCellsHeight*nCellsWidth - 1); ++i) {
        if (vectorOrdenado[i].valor > vectorOrdenado[i+1].valor) {
            cajaNegraMonticulo = true; // Se pone a true cuando falla el algoritmo
        }
    }

	int fila = 0, columna = 0;
	float x = 0, y = 0;
    posicionConValor p;

	std::list<Defense*>::iterator currentDefense = defenses.begin();
	while(currentDefense == defenses.begin() && maxAttemps > 0){

        p = vectorOrdenado.front();

        std::pop_heap(vectorOrdenado.begin(), vectorOrdenado.end());
        vectorOrdenado.pop_back();

		x = p.i*cellWidth + cellWidth*0.5f;
		y = p.j*cellHeight + cellHeight*0.5f;
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
        p = vectorOrdenado.front();

        std::pop_heap(vectorOrdenado.begin(), vectorOrdenado.end());
        vectorOrdenado.pop_back();

		x = p.i*cellWidth + cellWidth*0.5f;
		y = p.j*cellHeight + cellHeight*0.5f;
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
    do {
		placeDefensesSinOrdenacion(freeCells, nCellsWidth, nCellsHeight, mapWidth, mapHeight, obstacles, defenses);
		++r1;
    } while(c1.tiempo() < 1.0);
    c1.parar();

    cronometro c2;
    long int r2 = 0;
    c2.activar();
    do {
		placeDefensesFusion(freeCells, nCellsWidth, nCellsHeight, mapWidth, mapHeight, obstacles, defenses);
		++r2;
    } while(c2.tiempo() < 1.0);
    c2.parar();

    cronometro c3;
    long int r3 = 0;
    c3.activar();
    do {
		placeDefensesRapido(freeCells, nCellsWidth, nCellsHeight, mapWidth, mapHeight, obstacles, defenses);
		++r3;
    } while(c3.tiempo() < 1.0);
    c3.parar();

    cronometro c4;
    long int r4 = 0;
    c4.activar();
    do {
		placeDefensesMonticulo(freeCells, nCellsWidth, nCellsHeight, mapWidth, mapHeight, obstacles, defenses);
		++r4;
    } while(c4.tiempo() < 1.0);
    c4.parar();


    std::cout << (nCellsWidth * nCellsHeight) << '\t' << c1.tiempo() / r1 << '\t' << c2.tiempo() / r2 << '\t' << c3.tiempo() / r3 << '\t' << c4.tiempo() / r4 << std::endl;
}
