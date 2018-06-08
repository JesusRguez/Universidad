/***************************************************************************//**
 * \file   retardo_software.c
 *
 * \brief  Funciones para generar retardos mediante bucle software. Evita tener
 *         que gastar un timer para realizar el retardo y puede ser suficiente
 *         en muchas ocasiones.
 */

#include "retardo_software.h"
#include <LPC407x_8x_177x_8x.h>

/*===== Variables globales privadas ============================================
 */
static bool_t inicializado = FALSE;

/***************************************************************************//**
 * \brief  Realiza la calibración del retardo software. Debe ser llamada
 *         antes de la primera llamada a retardo_software_us.
 */
void retardo_software_inicializar(void)
{
    volatile uint32_t t;
    uint32_t primask;
    
    if (inicializado) return;

    /* Programa el timer 0 para que su registro contador de incremente una vez
     * por microsegundo.
     */
    LPC_SC->PCONP |= 1u << 1;
    LPC_TIM0->TCR = 0;
    LPC_TIM0->TC = 0;
    LPC_TIM0->PC = 0;
    LPC_TIM0->PR = PeripheralClock/1000000 - 1;
    LPC_TIM0->MCR = 0;
    LPC_TIM0->IR = 1;

    /* Fijar la escala de calibración a 1. Esto hará que la función
     * retardo_software_us realice justo tantas interaciones de su bucle interno
     * como valga el argumento de entrada.
     */
    retardo_software_fijar_escala(1);

    /* La calibración debe hacerse con las interrupciones deshabilitadas. En
     * caso contrario, el tiempo de procesamiento de las interrupciones que
     * se produjesen durante la calibración falsearían la medida.
     * Antes de deshabilitas las interrupciones se lee el registro PRIMASK para
     * restituir el estado de habilitación/deshabilitación de interrupciones
     * a su estado previo a la deshabilitación.
     */
    primask = __get_PRIMASK();
    __disable_irq();

    /* Poner en marcha el timer 0. Empezará a incrementarse cada us.
     */
    LPC_TIM0->TCR = 1;
       
    /* Pedir que retardo_software_us realice 1000000 de iteraciones.
     */
    retardo_software_us(1000000);

    /* El registro contador TC del timer 0 indica ahora el número de
     * microsegundos que han tardado 1000000 de iteraciones.
     */
    t = LPC_TIM0->TC;

    /* Restituir el estado de habilitación/deshabilitación de interrupciones
     * a su estado previo a la deshabilitación.
     */
    if ((primask & 1) == 0) __enable_irq();

    /* Ajustar el número de iteraciones que es necesario que la función
     * retardo_software_us realice por cada microsegundo de retardo requerido.
     */
    retardo_software_fijar_escala(1000000/t);
    
    inicializado = TRUE;
}
