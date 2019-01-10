void DEF_LIB_EXPORTED placeDefenses3(bool** freeCells, int nCellsWidth, int nCellsHeight, float mapWidth, float mapHeight, List<Object*> obstacles, List<Defense*> defenses) {

    float cellWidth = mapWidth / nCellsWidth;
    float cellHeight = mapHeight / nCellsHeight;

    cronometro c1;
    long int r1 = 0;
    c1.activar();
    do {
        placeDefensesSinOrdenacion(freeCells, nCellsWidth, nCellsHeight,
            mapWidth, mapHeight, obstacles, defenses);
        ++r1;
    } while(c1.tiempo() < 1.0);
    c1.parar();

    cronometro c2;
    long int r2 = 0;
    c2.activar();
    do {
        placeDefensesFusion(freeCells, nCellsWidth, nCellsHeight, mapWidth,
            mapHeight, obstacles, defenses);
        ++r2;
    } while(c2.tiempo() < 1.0);
    c2.parar();

    cronometro c3;
    long int r3 = 0;
    c3.activar();
    do {
        placeDefensesRapido(freeCells, nCellsWidth, nCellsHeight, mapWidth,
            mapHeight, obstacles, defenses);
        ++r3;
    } while(c3.tiempo() < 1.0);
    c3.parar();

    cronometro c4;
    long int r4 = 0;
    c4.activar();
    do {
        placeDefensesMonticulo(freeCells, nCellsWidth, nCellsHeight,
            mapWidth, mapHeight, obstacles, defenses);
        ++r4;
    } while(c4.tiempo() < 1.0);
    c4.parar();


    std::cout << (nCellsWidth * nCellsHeight) << '\t' << c1.tiempo() / r1 <<
    '\t' << c2.tiempo() / r2 << '\t' << c3.tiempo() / r3 << '\t' <<
    c4.tiempo() / r4 << std::endl;
}
