int pivote(posicionConValor* mapaOrdenado, int i, int j){
    int p = i;
    posicionConValor x = mapaOrdenado[i];
    posicionConValor aux;
    for (int k = i+1; k <= j; ++k) {
        if (mapaOrdenado[k] > x) {
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
    if (n > 1) {
        int p = pivote(mapaOrdenado, i, j);
        ordenacionRapido(mapaOrdenado, i, p-1);
        ordenacionRapido(mapaOrdenado, p+1, j);
    }
}
