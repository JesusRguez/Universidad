#include <stdio.h>
#include <stdlib.h>

    typedef struct{
        int dia;
        char mes[10];
        int ano;
    }reg_fecha;
    typedef struct{
        char nom_cliente[12];
        char localidad[15];
        char provincia[15];
        char producto[10];
        int cantidad;
        float precio;
        reg_fecha fecha;
    }ventas;



int main()
{
    ventas V[1000];


    return 0;
}
