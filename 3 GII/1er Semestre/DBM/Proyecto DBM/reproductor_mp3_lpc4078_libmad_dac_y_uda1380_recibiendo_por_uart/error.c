/***************************************************************************//**
 * \file    error.c
 *
 * \brief   Tratamiento de errores.
 */

#include "error.h"
#include <stdio.h>

/***************************************************************************//**
 * \brief   Función que es llamada por la macros ASSERT es caso de que no
 *          se cumpla su expresión.
 *
 *          Imprime la función, fichero fuente y línea donde se produjo el
 *          error seguido del mensaje descriptivo del error que se indicó en
 *          ASSERT. A continuación el programa queda en un bucle sin fin. Este
 *          comportamiento puede cambiarse modificando la función.
 *
 * \param[in]   fichero     nombre del fichero fuente donde se produjo el error.
 * \param[in]   funcion     nombre de la función donde se produjo el error.
 * \param[in]   linea       número de línea del fichero fuente donde produjo el
 *                          error.
 * \param[in]   mensaje     mensaje descriptivo del error.
 */
void parar_con_error(const char* fichero, const char* funcion, const uint32_t linea,
                     const char* mensaje)
{   
    /* Dashabilitar las interrupciones.
     */
    __disable_irq();
    
    for (;;)
    {
        /* Evitar que los argumentos de la función salgan de ámbito en el
         * depurador de Keil para que sigan siendo visibles cuando se entre
         * en este bucle.
         */
        volatile char a;
        volatile char b;
        volatile int  c;
        volatile char d;
        
        a = *fichero;
        b = *funcion;
        c = linea;
        d = *mensaje;
    }
}
