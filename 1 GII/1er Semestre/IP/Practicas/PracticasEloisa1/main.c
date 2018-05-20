#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *in, *in2;
    char ch;
    if ((in=fopen("test.txt","r"))!=NULL)
    {
        in2=fopen("testcopia.txt","w");
        ch=getc(in);
        while (!feof(in))
        {
            putc(ch,in2);
            ch=getc(in);
        }

        fclose(in);
        fclose(in2);
        puts("Copia realizada correctamente");
    }
    else
        puts("No se puede abrir \"test.txt\".");

    return 0;
}
