void mochila(float* valores, unsigned int* coste, unsigned int ases, float** matriz, std::list<Defense*> defenses){
    int itCoste = 0;
    int itv = 0;

    for (size_t j = 0; j <= ases; ++j) {
        if (j < coste[itCoste]) {
            matriz[0][j] = 0;
        }else{
            matriz[0][j] = valores[itv];
        }
    }

    for (size_t i = 1; i < defenses.size(); ++i) {
        for (size_t j = 0; j < ases; ++j) {
            if (j < coste[i]) {
                matriz[i][j] = matriz[i-1][j];
            }else{
                matriz[i][j] = std::max(matriz[i-1][j], matriz[i-1][j-coste[i]]+valores[i]);
            }
        }
    }
}
