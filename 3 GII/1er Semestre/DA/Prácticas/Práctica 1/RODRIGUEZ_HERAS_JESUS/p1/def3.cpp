void DEF_LIB_EXPORTED placeDefenses(bool** freeCells, int nCellsWidth, int nCellsHeight, float mapWidth, float mapHeight, std::list<Object*> obstacles, std::list<Defense*> defenses) {

    float cellWidth = mapWidth / nCellsWidth;
    float cellHeight = mapHeight / nCellsHeight;
    int maxAttemps = 1000;
    int fila = 0, columna = 0;
    float x = 0, y = 0;

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
    while(currentDefense == defenses.begin() && maxAttemps > 0){
    	seleccion(mapa, nCellsWidth, nCellsHeight, &fila, &columna);
    	x = fila*cellWidth + cellWidth*0.5f;
    	y = columna*cellHeight + cellHeight*0.5f;
    	if(factibilidad(x, y, (*currentDefense), obstacles, mapWidth, mapHeight, defenses, cellWidth, cellHeight)){
            (*currentDefense)->position.x = x;
            (*currentDefense)->position.y = y;
            (*currentDefense)->position.z = 0;

            cellValueCentro(mapa, nCellsWidth, nCellsHeight, cellWidth, cellHeight, mapWidth, mapHeight, defenses);

            ++currentDefense;
    	}
    	--maxAttemps;
    }
    //El resto del codigo no pertenece al caso del centro de extraccion de minerales
}
