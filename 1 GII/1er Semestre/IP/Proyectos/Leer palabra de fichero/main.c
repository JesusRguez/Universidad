#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    char *a,l;
    FILE *f;
    a=(char*)malloc(1*sizeof(char));

    if((f=fopen("Mispalabras.txt","r"))==NULL)
        puts("El fichero no existe.");
    else
    {
        i=0;
        l=fgetc(f);
        while (l!="\n"||l!=' '||l!=EOF)
        {
            a[i]=l;
            i++;
            a=(char*)realloc(a,(i+1)*sizeof(char));
            l=fgetc(f);
        }
    }
    fclose(f);
    printf("%s",a);

    return 0;
}
