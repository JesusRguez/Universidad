void ordenacionInsercion(posicionConValor* mapaOrdenado, int i, int j){
    posicionConValor temp;
    int tam = j-i+1;
    for (i; i<tam; ++i){
        temp = mapaOrdenado[i];
        j=i-1;
        while ((mapaOrdenado[j]>temp)&&(j>=0)) {
            mapaOrdenado[j+1]=mapaOrdenado[j];
            --j;
        }
        mapaOrdenado[j+1] = temp;
    }
}

int pivote(posicionConValor* mapaOrdenado, int i, int j){
    int p = i;
    posicionConValor x = mapaOrdenado[i];
    posicionConValor aux;
    for (size_t k = i+1; k < j; ++k) {
        if (mapaOrdenado[k] <= x) {
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
