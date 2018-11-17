void DEF_LIB_EXPORTED placeDefenses(bool** freeCells, int nCellsWidth, int nCellsHeight, float mapWidth, float mapHeight, std::list<Object*> obstacles, std::list<Defense*> defenses) {

    float cellWidth = mapWidth / nCellsWidth;
    float cellHeight = mapHeight / nCellsHeight;
    int maxAttemps = 1000;
    int fila = 0, columna = 0;
	float x = 0, y = 0;

    // ...
	// Ejercicio 3
    // ...
    // Continuacion del ejercicio 3

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

    // Resto de codigo de PRINT_DEFENSE_STRATEGY que no hemos modificado

}
