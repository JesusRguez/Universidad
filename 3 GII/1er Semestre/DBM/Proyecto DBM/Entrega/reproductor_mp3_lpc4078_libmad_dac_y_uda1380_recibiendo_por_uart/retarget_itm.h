/***************************************************************************//**
 */
 
#ifndef RETARGET_ITM_H
#define RETARGET_ITM_H

#define ITM_Port8(n)    (*((volatile unsigned char *)(0xE0000000+4*n)))
#define ITM_Port16(n)   (*((volatile unsigned short*)(0xE0000000+4*n)))
#define ITM_Port32(n)   (*((volatile unsigned long *)(0xE0000000+4*n)))

#define DEMCR           (*((volatile unsigned long *)(0xE000EDFC)))
#define TRCENA          0x01000000

//#pragma import(__use_no_semihosting_swi)

struct __FILE
{
    int handle;
     /* Add whatever you need here */ 
};

int fputc(int c, FILE *f);
int fgetc(FILE *f);
int ferror(FILE *f);
void _sys_exit(int return_code);

#endif
