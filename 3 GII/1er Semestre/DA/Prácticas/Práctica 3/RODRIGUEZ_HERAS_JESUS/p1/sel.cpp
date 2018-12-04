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
