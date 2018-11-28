void mochila(float* valores, unsigned int* coste, unsigned int ases, float** matriz, std::list<Defense*> defenses){

    for (int j = 0; j <= ases; ++j) {
        if (j < coste[0]) {
            matriz[0][j] = 0;
        }else{
            matriz[0][j] = valores[0];
        }
    }

    for (int i = 1; i < defenses.size(); ++i) {
        for (int j = 0; j <= ases; ++j) {
            if (j < coste[i]) {
                matriz[i][j] = matriz[i-1][j];
            }else{
                matriz[i][j] = std::max(matriz[i-1][j], matriz[i-1][j-coste[i]]+valores[i]);
            }
        }
    }
}
