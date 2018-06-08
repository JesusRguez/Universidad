/***************************************************************************//**
 */
 
#include <stdio.h>
#include "retarget_itm.h"
//#include <rt_misc.h>

extern int sendchar (int c);
extern int getkey   (void);

FILE __stdout;
FILE __stdin;
FILE __stderr;

int fputc(int c, FILE *f)
{
    if (DEMCR & TRCENA)
    {
        while (ITM_Port32(0) == 0);
        ITM_Port8(0) = c;
    }
    return(c);
}


int fgetc(FILE *f)
{
    //return (getkey());
    return 0;
}

int ferror(FILE *f)
{
    /* Your implementation of ferror */
    return EOF;
}

void _sys_exit(int return_code)
{
    while (1) {}
}
