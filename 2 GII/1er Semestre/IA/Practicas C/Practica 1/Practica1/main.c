#include <stdio.h>
#include <stdlib.h>
#include "puzle.h"
//El índice hace referencia a la pieza y el contenido a la posición de dicha pieza.
int main()
{
    int op;
    tEstado *actual=(tEstado *)malloc(sizeof(tEstado));
    tEstado *terminado=(tEstado *)malloc(sizeof(tEstado));
    actual=estadoInicial();
    terminado=estadoObjetivo();
    puts("Bienvenido. El objetivo del juego es completar el puzle para obtener la siguiente combinacion:");
    dispEstado(terminado);
    puts("Comienza el juego con la siguiente combinacion:");
    dispEstado(actual);

    while(testObjetivo(actual)!=1)
    {
        puts("Elige un movimiento: ARRIBA 1, ABAJO 2, IZQUIERDA 3, DERECHA 4\n");
        scanf("%d",&op);
        system("cls");
        dispOperador(op);
        if(esValido(op, actual)==1)
            actual=aplicaOperador(op, actual);
        else
            printf("Movimiento incorreceto.\n");
        dispEstado(actual);
    }

    printf("Objetivo compleatado. Has terminado el puzzle con exito.");

    return 0;
}
