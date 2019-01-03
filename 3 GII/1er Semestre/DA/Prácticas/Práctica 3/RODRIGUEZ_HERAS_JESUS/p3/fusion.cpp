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
