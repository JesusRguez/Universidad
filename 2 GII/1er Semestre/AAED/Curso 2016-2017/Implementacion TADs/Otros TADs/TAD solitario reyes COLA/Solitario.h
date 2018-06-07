#ifndef SOLITARIO_H
#define SOLITARIO_H

typedef Cola<tCarta> tMonton;

bool solitario(tCarta* baraja, tfig inicio, tMonton& reyes)
{
    //Elementos del juego:
    tMonton cv(5);
    tMonton Monton[10] = {cv,cv,cv,cv,cv,cv,cv,cv,cv,cv};
    //Número de cartas ya colocadas en cada figura:
    int cont[10] = {0,0,0,0,0,0,0,0,0,0};
    //Repartir 4 cartas em cada montón
    for(int i=0,f=AS;f<=REY;i++)
    {
        for(int k=0;k<4;k++,i++)
        {
            Monton[f].push(baraja[i]);
            //Contar las cartas ya colocadas en su montón
            if (baraja[k]==f)
                cont[f]++;
        }
    }
    //Jugar
    tfig figura=inicio;
    tCarta carta;
    //Parar si 4 reyes colocados o al colocar carta 4 de figura
    while(cont[rey]<4 && cont[figura]<4)
    {
        //extraer
        //falta mucho codigo
    }
}

#endif // SOLITARIO_H
