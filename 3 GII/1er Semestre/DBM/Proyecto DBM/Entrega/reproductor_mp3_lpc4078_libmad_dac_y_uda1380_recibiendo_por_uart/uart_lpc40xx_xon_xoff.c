/***************************************************************************//**
 * \file    uart_lpc40xx.c
 *
 * \brief   Funciones de manejo de las UARTs del LPC40xx.
 */

#include <LPC407x_8x_177x_8x.h>
#include "uart_lpc40xx_xon_xoff.h"
#include "iocon_lpc40xx.h"
#include "error.h"
#include <string.h>
#include <stdio.h>
#include <math.h>

/* El LPC40xx tiene 5 UARTs. Las UARTs 0, 2 y 3 son exactamente iguales entre
 * sí. La UART 1 añade señales de control de modem y tiene registros adicionales
 * a los de las UARTs 0, 2 y 3. La UART 4 puede funcionar en un modo síncrono y
 * puede comunicar con smart cards, así que también tiene registros adicionales.
 *
 * Las funciones de este módulo no usan ninguna de las características
 * especiales de las UARTs 1 y 4. Las posiciones de los registros comunes a todas
 * las UARTs coinciden, así que todas se manejarán mediante punteros a
 * estructura de tipo LPC_UART_TypeDef.
 */
#define LPC_UART1_  ((LPC_UART_TypeDef*)LPC_UART1_BASE)
#define LPC_UART4_  ((LPC_UART_TypeDef*)LPC_UART4_BASE)
static LPC_UART_TypeDef* const numero_uart_a_puntero[UART_NUMERO_INTERFACES]
    = {LPC_UART0,
       LPC_UART1_,
       LPC_UART2,
       LPC_UART3,
       LPC_UART4_};
    
/* Array con los números de vector de interrupción de cada UART.
 */ 
static const IRQn_Type numero_uart_a_numero_interrupcion[UART_NUMERO_INTERFACES]
    = {UART0_IRQn, UART1_IRQn, UART2_IRQn, UART3_IRQn, UART4_IRQn};
    
/* Indica si una UART ha sido ya inicializada o no.
 */
static bool_t uart_inicializado[UART_NUMERO_INTERFACES] =
    {FALSE, FALSE, FALSE, FALSE, FALSE};
       
/* Array con estructuras con información sobre el estado de las transferencias
 * de cada UART.
 */
//static uart_estado_transferencia_t estado_transferencia[UART_NUMERO_INTERFACES];
static uart_estado_transferencia_t estado_transferencia[1];
   
/* Array para obtener el orden del bit de PCONP que activa la alimentación
 * de cada UART.
 */
static const uint32_t numero_uart_a_bit_pconp[UART_NUMERO_INTERFACES] =
    {3, 4, 24, 25, 8};
    
uint32_t uart_puntero_a_numero(LPC_UART_TypeDef *uart_regs)
{
    if (uart_regs == UART0) return 0;
    if (uart_regs == UART1) return 1;
    if (uart_regs == UART2) return 2;
    if (uart_regs == UART3) return 3;
    if (uart_regs == UART4) return 4;
    ERROR("Puntero a UART incorrecto.");
    return 0;
}

void uart_enviar_xon(void)
{
	uart_estado_transferencia_t *est;
	char c = XON;
	est = &estado_transferencia[0];
	
	if (!est->ya_transmitido_xon)
  {
		uart_transmitir(UART0, 1, &c);
		est->ya_transmitido_xon = TRUE;
		est->ya_transmitido_xoff = FALSE;
	}
}

void uart_enviar_xoff(void)
{
	uart_estado_transferencia_t *est;
	char c = XOFF;
	est = &estado_transferencia[0];
	if (!est->ya_transmitido_xoff)
  { 		
		uart_transmitir(UART0, 1, &c);
		est->ya_transmitido_xon = FALSE;
		est->ya_transmitido_xoff = TRUE;
	}
}
	
     
/***************************************************************************//**
 * \brief       Inicializar una UART del LPC40xx.
 *
 * \param[in]   uart_regs               ptr. al bloque de registros de la UART.
 * \param[in]   baudrate                velocidad en baudios requerida.
 * \param[in]   numero_bits_datos       bits de datos a usar. De 5 a 8.
 * \param[in]   tipo_paridad            paridad a usar (NINGUNA, IMPAR o PAR).
 * \param[in]   numero_bits_stop        bits de stop a usar (1 ó 2).
 * \param[in]   puerto_txd              puerto que se desea para la señal TXD.
 * \param[in]   pin_txd                 pin que se desea para la señal TXD.
 * \param[in]   puerto_rxd              puerto que se desea para la señal RXD.
 * \param[in]   pin_rxd                 pin que se desea para la señal RXD.
 * \param[in]   prioridad_interrupcion  prioridad a asignar a int. de la UART.
 * \param[out]  baudrate_real_obtenido  puntero a float32_t donde almacenar el
 *                                      mejor baudrate que se pudo ajustar.
 *                                      Si es NULL no se usa.
 *
 * \note        La razón de especificar los puertos y los pines mediante punteros
 *              a los registros GPIO y máscaras de pin en lugar de números
 *              de puerto y números de pin es conseguir que la forma de
 *              especificar un pin sea igual que la usada en los módulos
 *              gpio_lpc40xx e iocon_lpc40xx. Esto permite usar los mismos
 *              símbolos PUERTOx y PINx definidos en gpio_lpc40xx.h.
 */
void uart_inicializar(LPC_UART_TypeDef *uart_regs,
                      uint32_t baudrate,
                      uint32_t numero_bits_datos,
                      uart_tipo_paridad_t tipo_paridad,
                      uint32_t numero_bits_stop,
                      LPC_GPIO_TypeDef *puerto_txd,
                      uint32_t mascara_pin_txd,
                      LPC_GPIO_TypeDef *puerto_rxd,
                      uint32_t mascara_pin_rxd,
                      uint32_t prioridad_interrupcion,
                      float32_t *baudrate_real_obtenido)
{
    uint32_t lcr_word_length_select;
    uint32_t lcr_stop_bit_select;
    uint32_t lcr_parity_enable;
    uint32_t lcr_parity_select;
    uint32_t dlmdll;
    uint32_t divaddval;
    uint32_t mulval;
    uint32_t temp;
    uint32_t i;
    uint32_t num;
    uint32_t den;
    float32_t error_relativo;
    float32_t mejor_error_relativo;
    uint32_t numero_uart;
    IRQn_Type numero_interrupcion;
    volatile uint32_t dummy;
    uart_estado_transferencia_t *est;

    /* Comprobar que los parámetros son correctos.
     */
    ASSERT(uart_regs == UART0 || uart_regs == UART1 || uart_regs == UART2 ||
           uart_regs == UART3 || uart_regs == UART4,  
           "Puntero a registros de UART incorrecto.");
    
    ASSERT(numero_bits_datos >= 5 && numero_bits_datos <= 8,
           "Número de bits de datos seleccionado incorrecto.");
    
    ASSERT(tipo_paridad == UART_PARIDAD_NINGUNA ||
           tipo_paridad == UART_PARIDAD_PAR ||
           tipo_paridad == UART_PARIDAD_IMPAR,
           "Paridad seleccionada incorrecta.");
           
    ASSERT(numero_bits_stop == 1 || numero_bits_stop == 2,
           "Número de bits de stop seleccionado incorrecto.");
           
    ASSERT(prioridad_interrupcion < (1u << __NVIC_PRIO_BITS),
        "Prioridad de interrupción incorrecta.");
        
    /* Los números de puerto y pin se comprueban en las funciones de
     * configuración de pines.
     */
     
    numero_uart = uart_puntero_a_numero(uart_regs);

    /* Activar la alimentación de la UART.
     */   
    LPC_SC->PCONP |= 1u << numero_uart_a_bit_pconp[numero_uart];
  
    /* Ajustar la velocidad de comunicación en baudios solicitada.
     *    
     * Primero, calcular la parte entera del divisor de baudrate.
     */
    dlmdll = PeripheralClock/(16*baudrate);  /* dlmdll = 256*DLM + DLL */
    if (dlmdll == 0)
    {
        dlmdll = 1;
    }

    /* Si es neceario, calcular la parte fraccionario del divisor.
     */
    num = 0;
    den = 1;
    divaddval = num;
    mulval = den;    

    if (16*(int32_t)baudrate*(int32_t)dlmdll != PeripheralClock)
    {
        /* La mejor configuración de DIVADDVAL y MULVAL se encontrará probando
         * todos los valores posibles y seleccionando aquellos que hacen mínima
         * el valor absoluto de
         *
         *      DIVADDVAL*a - MULVAL*(PeripheralClock - a)
         *
         *  donde
         *
         *      a = 16*baudrate*(256*DLM + DLL)
         */
        temp = dlmdll;
        mejor_error_relativo =
            fabs(((float)baudrate -
                ((float)PeripheralClock/(16*dlmdll)))/(float)baudrate);
        for (i = temp - 1; i <= temp + 1; i++)
        {
            for (den = 1; den < 16; den++)
            {
                for (num = 1; num < den; num++)
                {
                    error_relativo =
                        fabs(((float)baudrate -
                          ((float)PeripheralClock/((16*i)*(1+(float)num/den))))/
                            (float)baudrate);
                    
                    if (error_relativo < mejor_error_relativo)
                    {
                        dlmdll = i;
                        divaddval = num;
                        mulval = den;
                        mejor_error_relativo = error_relativo;
                    }
                }
            }
        }
    }
      
    /* Escribir los valores calculados en DLM, DLL y FDR.
     */
    uart_regs->LCR |= 0x80;
    uart_regs->DLM = dlmdll >> 8;
    uart_regs->DLL = dlmdll & 0xFF;
    uart_regs->FDR = (mulval << 4) | divaddval;

    if (baudrate_real_obtenido != NULL)
    {
        *baudrate_real_obtenido = (float32_t)(PeripheralClock*mulval)/
                                  (16*dlmdll*(mulval + divaddval));
    }

    /* Configurar el resto de parámetros en el registro LCR.
     */
    lcr_word_length_select = numero_bits_datos - 5;
    lcr_stop_bit_select = numero_bits_stop - 1;
    lcr_parity_enable = tipo_paridad == UART_PARIDAD_NINGUNA ? 0 : 1;
    lcr_parity_select = tipo_paridad == UART_PARIDAD_PAR ? 1 : 0;
    uart_regs->LCR = (lcr_parity_select << 4) |
                        (lcr_parity_enable << 3) |
                        (lcr_stop_bit_select << 2) |
                        lcr_word_length_select;

    /* Activar y limpiar las FIFOs.
     */
    uart_regs->FCR = 0x07;

    /* Según explica el manual del LPC40xx, para que salte la interrupción por
     * Transmit Holding Register Empty deden pasar al menor dos bytes por el
     * THR. Esto no nos conviene en nuestro sistema de gestión de la
     * transmisión así que enviamos dos bytes y esperamos a que salgan.
     * Esto se hace antes de configurar los pines para que la transmisión serie
     * no salga realmente al exterior.
     *
     * Se espara a que tanto el THR como el registro de desplazamiento de
     * transmisión estén vacíos.
     */
//    ptr_interfaz->THR = 0;
//    ptr_interfaz->THR = 0;
//    while ((ptr_interfaz->LSR & (3u << 5)) != (3u << 5)) {}
    
    /* Configurar la interrupción. Se habilita la interrupción por datos
     * disponibles y la interrupción de registro de transmisión vacío.
     */  
    uart_regs->IER = (1u << 0) | (1u << 1);
    //uart_regs->IER = (1u << 0);
    dummy = uart_regs->IIR;  /* Borrar interrupciones. */
    numero_interrupcion = numero_uart_a_numero_interrupcion[numero_uart];        
    NVIC_ClearPendingIRQ(numero_interrupcion);
    NVIC_SetPriority(numero_interrupcion, prioridad_interrupcion);
    __enable_irq();

    /* Configurar los pines indicados.
     */
    switch (numero_uart)
    {
    case 0:
        iocon_configurar_pin(puerto_txd, mascara_pin_txd, U0_TXD,
            IOCON_NO_PULL_UP_NO_PULL_DOWN);
        iocon_configurar_pin(puerto_rxd, mascara_pin_rxd, U0_RXD, IOCON_PULL_UP);
        break;

    case 1:
        iocon_configurar_pin(puerto_txd, mascara_pin_txd, U1_TXD,
            IOCON_NO_PULL_UP_NO_PULL_DOWN);
        iocon_configurar_pin(puerto_rxd, mascara_pin_rxd, U1_RXD, IOCON_PULL_UP);
        break;
    case 2:
        iocon_configurar_pin(puerto_txd, mascara_pin_txd, U2_TXD,
            IOCON_NO_PULL_UP_NO_PULL_DOWN);
        iocon_configurar_pin(puerto_rxd, mascara_pin_rxd, U2_RXD, IOCON_PULL_UP);
        break;
    case 3:
        iocon_configurar_pin(puerto_txd, mascara_pin_txd, U3_TXD,
            IOCON_NO_PULL_UP_NO_PULL_DOWN);
        iocon_configurar_pin(puerto_rxd, mascara_pin_rxd, U3_RXD, IOCON_PULL_UP);
        break;        
    default:
        iocon_configurar_pin(puerto_txd, mascara_pin_txd, U4_TXD,
            IOCON_NO_PULL_UP_NO_PULL_DOWN);
        iocon_configurar_pin(puerto_rxd, mascara_pin_rxd, U4_RXD, IOCON_PULL_UP);
        break;
    }    
    
    /* Inicializar la estructura de estado de transferencia correspondiente.
     */        
    est = &estado_transferencia[numero_uart];
    est->tamano_buffer_transmision = UART_TAMANO_BUFFER_TRANSMISION;
    est->indice_escritura_transmision = 0;
    est->indice_lectura_transmision = 0;
    est->quedan_por_transmitir = 0;
    est->tamano_buffer_recepcion = UART_TAMANO_BUFFER_RECEPCION;
    est->indice_escritura_recepcion = 0;
    est->indice_lectura_recepcion = 0;
    est->disponibles_para_leer = 0;
    est->nivel_inferior = (70*UART_TAMANO_BUFFER_RECEPCION)/100;
    est->nivel_superior = (90*UART_TAMANO_BUFFER_RECEPCION)/100;
    est->ya_transmitido_xoff = FALSE;
    est->ya_transmitido_xon = FALSE;

    /* Indicar que la UART ya ha sido configurada.
     */
    uart_inicializado[numero_uart] = TRUE;
}

/***************************************************************************//**
 * \brief      
 */
void uart_transmitir(LPC_UART_TypeDef *uart_regs,
                     uint32_t numero_bytes_a_transmitir,
                     void *buffer)
{
    uart_estado_transferencia_t *est;
    uint32_t i;
    IRQn_Type numero_interrupcion;
    LPC_UART_TypeDef *ptr_interfaz;
    uint8_t *ptr;
    uint32_t numero_uart;
    
    ASSERT(uart_regs == UART0 || uart_regs == UART1 || uart_regs == UART2 ||
           uart_regs == UART3 || uart_regs == UART4, "uart_regs incorrecto.")       

    numero_uart = uart_puntero_a_numero(uart_regs);
    ASSERT(uart_inicializado[numero_uart],
        "El interfaz no está inicializado."); 
    
    ASSERT(buffer != NULL, "Puntero a buffer es nulo.");
    ASSERT(numero_bytes_a_transmitir != 0,
        "El número de datos a transmitir es 0.");

    est = &estado_transferencia[numero_uart];

    ASSERT(numero_bytes_a_transmitir <=
        UART_TAMANO_BUFFER_TRANSMISION - est->quedan_por_transmitir,
        "No hay espacio suficiente en el buffer de transmisión.");

    /* LA COPIA AL BUFFER DE TRANSMISIÓN NO ESTÁ OPTIMIZADA. SERÍA MEJOR
     * COPIAR EN BLOQUES CON memcpy.
     */

    /* Deshabilitar momentáneamente la interrupción de la UART para tener
     * acceso exclusido a sus variables de estado.
      */
    numero_interrupcion = numero_uart_a_numero_interrupcion[numero_uart];
    NVIC_DisableIRQ(numero_interrupcion);

    i = numero_bytes_a_transmitir;
    ptr = buffer;

    /* Si en este momento no hay datos a transmitir en el buffer de transmisión
     * se envían a la FIFO de transmisión de la UART tantos bytes como se pueda.
     */
    if (est->quedan_por_transmitir == 0)
    {
        while (i > 0 && (ptr_interfaz->LSR & (1u << 5)))    /* bit 5: THRE */ 
        {
            ptr_interfaz->THR = *ptr;
            ptr++;
            i--;
        }                    
    }

    /* Después de enviar directamente a la UART todos los datos que se puedan,
     * colocar el resto en el buffer de transmisión.
     */
    while (i > 0)
    {
        est->buffer_transmision[est->indice_escritura_transmision] = *ptr;       
        if (est->indice_escritura_transmision < UART_TAMANO_BUFFER_TRANSMISION - 1)
        {
            est->indice_escritura_transmision++;
        }
        else
        {
            est->indice_escritura_transmision = 0;
        }
        ptr++;
        est->quedan_por_transmitir++;
        i--;
    }
    
    /* Volver a habilitar las interrupciones de esta UART.
     */
    NVIC_EnableIRQ(numero_interrupcion);
}

/***************************************************************************//**
 * \brief
 */
void uart_esperar_fin_transmision(LPC_UART_TypeDef *uart_regs)
{
    uint32_t numero_uart;
    uart_estado_transferencia_t *est;
    
    ASSERT(uart_regs == UART0 || uart_regs == UART1 || uart_regs == UART2 ||
           uart_regs == UART3 || uart_regs == UART4, "uart_regs incorrecto.");
    
    numero_uart = uart_puntero_a_numero(uart_regs);
    est = &estado_transferencia[numero_uart];
    
    while (est->quedan_por_transmitir != 0) {}
}

/***************************************************************************//**
 * \brief      
 */
bool_t uart_probar_transmitir(LPC_UART_TypeDef *uart_regs,
                              uint32_t numero_bytes_a_transmitir,
                              void *buffer)
{
    uart_estado_transferencia_t *est;
    uint32_t i;
    IRQn_Type numero_interrupcion;
    LPC_UART_TypeDef *ptr_interfaz;
    uint8_t *ptr;
    uint32_t numero_uart;
    
    ASSERT(uart_regs == UART0 || uart_regs == UART1 || uart_regs == UART2 ||
           uart_regs == UART3 || uart_regs == UART4, "uart_regs incorrecto.");

    numero_uart = uart_puntero_a_numero(uart_regs);    
    ASSERT(uart_inicializado[numero_uart],
        "El interfaz no está inicializado.");      
    
    ASSERT(buffer != NULL, "Puntero a buffer es nulo.");
    ASSERT(numero_bytes_a_transmitir != 0,
        "El número de datos a transmitir es 0.");

    est = &estado_transferencia[numero_uart];

    if (numero_bytes_a_transmitir >
        UART_TAMANO_BUFFER_TRANSMISION - est->quedan_por_transmitir)
    {
        return FALSE;
    }

    /* LA COPIA AL BUFFER DE TRANSMISIÓN NO ESTÁ OPTIMIZADA. SERÍA MEJOR
     * COPIAR EN BLOQUES CON memcpy.
     */

    ptr_interfaz = numero_uart_a_puntero[numero_uart];

    /* Deshabilitar momentáneamente la interrupción de la UART para tener
     * acceso exclusido a sus variables de estado.
      */
    numero_interrupcion = numero_uart_a_numero_interrupcion[numero_uart];
    NVIC_DisableIRQ(numero_interrupcion);

    i = numero_bytes_a_transmitir;
    ptr = buffer;

    /* Si en este momento no hay datos a transmitir en el buffer de transmisión
     * se envían a la FIFO de transmisión de la UART tantos bytes como se pueda.
     */
    if (est->quedan_por_transmitir == 0)
    {
        while (i > 0 && (ptr_interfaz->LSR & (1u << 5)))    /* bit 5: THRE */ 
        {
            ptr_interfaz->THR = *ptr;
            ptr++;
            i--;
        }                    
    }

    /* Después de enviar directamente a la UART todos los datos que se puedan,
     * colocar el resto en el buffer de transmisión.
     */
    while (i > 0)
    {
        est->buffer_transmision[est->indice_escritura_transmision] = *ptr;       
        if (est->indice_escritura_transmision < UART_TAMANO_BUFFER_TRANSMISION - 1)
        {
            est->indice_escritura_transmision++;
        }
        else
        {
            est->indice_escritura_transmision = 0;
        }
        ptr++;
        est->quedan_por_transmitir++;
        i--;
    }
    
    /* Volver a habilitar las interrupciones de esta UART.
     */
    NVIC_EnableIRQ(numero_interrupcion);

    return TRUE;
}

/***************************************************************************//**
 * \brief       Indica el número de bytes disponibles en el buffer de recepción
 *              de una UART.
 *
 * \param[in]   numero_interfaz     Número de la UART.
 *
 * \return      Número de bytes disponibles en el buffer de recepción.
 */
uint32_t uart_bytes_disponibles(LPC_UART_TypeDef *uart_regs)
{
    uint32_t disponibles;
    IRQn_Type numero_interrupcion;
    uint32_t numero_uart;

    ASSERT(uart_regs == UART0 || uart_regs == UART1 || uart_regs == UART2 ||
           uart_regs == UART3 || uart_regs == UART4, "uart_regs incorrecto.");
    
    numero_uart = uart_puntero_a_numero(uart_regs);
    ASSERT(uart_inicializado[numero_uart],
        "El interfaz no está inicializado."); 

    numero_interrupcion = numero_uart_a_numero_interrupcion[numero_uart];        
    NVIC_DisableIRQ(numero_interrupcion);
    disponibles = estado_transferencia[numero_uart].disponibles_para_leer;
    NVIC_EnableIRQ(numero_interrupcion);

    return disponibles;
}

/***************************************************************************//**
 * \brief       Lee del buffer de recepción de una UART el número de bytes
 *              indicado. Si el número de bytes disponibles en el buffer de
 *              recepción es menor que el número de bytes solicitado se leen
 *              los que hay disponibles. Si no hay ningún dato disponible no
 *              se lee nada.
 *
 * \param[in]   numero_interfaz     número de la UART.
 * \param[in]   numero_bytes_a_leer número de bytes que se quieren leer.
 * \param[out]  buffer              buffer donde colocar los datos leídos.
 * \param[out]  numero_bytes_leidos número de bytes que realmente se han
 *                                  colocado en el buffer.
 */
void uart_leer(LPC_UART_TypeDef *uart_regs,
               uint32_t numero_bytes_a_leer,
               void *buffer,
               uint32_t* numero_bytes_leidos)
{
    uart_estado_transferencia_t *est;
    IRQn_Type numero_interrupcion;
    uint32_t i;
    uint8_t *ptr;
    uint32_t numero_uart;

    ASSERT(uart_regs == UART0 || uart_regs == UART1 || uart_regs == UART2 ||
           uart_regs == UART3 || uart_regs == UART4, "uart_regs incorrecto.");

    numero_uart = uart_puntero_a_numero(uart_regs);
    ASSERT(uart_inicializado[numero_uart],
        "El interfaz no está inicializado."); 
    
    ASSERT(numero_bytes_leidos != NULL,
        "Puntero numero_bytes_leidos es nulo.");

    est = &estado_transferencia[numero_uart];

    if (est->disponibles_para_leer < numero_bytes_a_leer)
    {
        numero_bytes_a_leer = est->disponibles_para_leer;
    }

    if (numero_bytes_a_leer == 0)
    {
        *numero_bytes_leidos = 0;
        return;
    }

    i = numero_bytes_a_leer;
    ptr = buffer;

    numero_interrupcion = numero_uart_a_numero_interrupcion[numero_uart];        
    NVIC_DisableIRQ(numero_interrupcion);

    while (i > 0)
    {
        *ptr = est->buffer_recepcion[est->indice_lectura_recepcion];
        ptr++;
        if (est->indice_lectura_recepcion < UART_TAMANO_BUFFER_RECEPCION - 1)
        {
            est->indice_lectura_recepcion++;
        }
        else
        {
            est->indice_lectura_recepcion = 0;
        }
        est->disponibles_para_leer--;
        i--;
    }
        
    NVIC_EnableIRQ(numero_interrupcion);

    *numero_bytes_leidos = numero_bytes_a_leer;
    
    if (est->disponibles_para_leer < est->nivel_inferior)
    {
//        uart_regs->THR = XON;
			uart_enviar_xon();
//        if (!est->ya_transmitido_xon)
//        {
//            char c = XON;
//            uart_transmitir(uart_regs, 1, &c);
//            est->ya_transmitido_xon = TRUE;
//            est->ya_transmitido_xoff = FALSE;
//        }
    }
}

/***************************************************************************//**
 * \brief       Esperar a que haya algún dato en el el buffer de recepción de
 *              una UART y leer número de bytes indicado. Si el número de bytes
 *              disponibles en el buffer de recepción es menor que el número de
 *              bytes solicitado se leen los que hay disponibles.
 *
 * \param[in]   numero_interfaz     número de la UART.
 * \param[in]   numero_bytes_a_leer número de bytes que se quieren leer.
 * \param[out]  buffer              buffer donde colocar los datos leídos.
 * \param[out]  numero_bytes_leidos número de bytes que realmente se han
 *                                  colocado en el buffer.
 */
void uart_esperar_leer(LPC_UART_TypeDef *uart_regs,
                       uint32_t numero_bytes_a_leer,
                       void *buffer,
                       uint32_t *numero_bytes_leidos)
{
    uint32_t numero_uart;

    ASSERT(uart_regs == UART0 || uart_regs == UART1 || uart_regs == UART2 ||
           uart_regs == UART3 || uart_regs == UART4, "uart_regs incorrecto.");

    numero_uart = uart_puntero_a_numero(uart_regs);
    ASSERT(uart_inicializado[numero_uart],
        "El interfaz no está inicializado."); 
    
    ASSERT(numero_bytes_leidos != NULL,
        "Puntero numero_bytes_leidos es nulo.");
    
    while (uart_bytes_disponibles(uart_regs) == 0) {}

    uart_leer(uart_regs,
              numero_bytes_a_leer,
              buffer,
              numero_bytes_leidos);
}

/***************************************************************************//**
 * \brief      Manejador de interrupción de la UART0. Llama al
 *             manejador común para las cinco interfaces.
 */
void UART0_IRQHandler(void)
{
    uart_manejador_interrupciones(0);
}

/***************************************************************************//**
 * \brief      Manejador de interrupción de la UART1. Llama al
 *             manejador común para las cinco interfaces.
 */
void UART1_IRQHandler(void)
{
    uart_manejador_interrupciones(1);
}

/***************************************************************************//**
 * \brief      Manejador de interrupción de la UART2. Llama al
 *             manejador común para las cinco interfaces.
 */
void UART2_IRQHandler(void)
{
    uart_manejador_interrupciones(2);
}

/***************************************************************************//**
 * \brief      Manejador de interrupción de la UART3. Llama al
 *             manejador común para las cinco interfaces.
 */
void UART3_IRQHandler(void)
{
    uart_manejador_interrupciones(3);
}

/***************************************************************************//**
 * \brief      Manejador de interrupción de la UART4. Llama al
 *             manejador común para las cinco interfaces.
 */
void UART4_IRQHandler(void)
{
    uart_manejador_interrupciones(4);
}

/***************************************************************************//**
 * \brief      Manjador de interrupción común para los cinco interfaces.
 */
void uart_manejador_interrupciones(uint32_t numero_interfaz)
{
    uart_estado_transferencia_t *est;
    LPC_UART_TypeDef            *ptr_interfaz;
    uint32_t                    iir;
        
    ptr_interfaz = numero_uart_a_puntero[numero_interfaz];
    est = &estado_transferencia[numero_interfaz];

    /* Leer el registro de identificación de interrupción.
     */
    iir = ptr_interfaz->IIR;

    if (iir & 1) return;

    /* El campo INTID (bits 1 a 3) del registro IIR indica la causa de la
     * interrupción.
     */
    switch ((iir >> 1) & 0x07)
    {
        /* 1 => Transmit Holding Register Empty.
         * Acción: si hay datos que transmitir, transmitir el siguiente. En caso
         * contrario no hacer nada.
         */        
        case 1:
            if (est->quedan_por_transmitir != 0)
            {
                ptr_interfaz->THR =
                    est->buffer_transmision[est->indice_lectura_transmision];
                if (est->indice_lectura_transmision < UART_TAMANO_BUFFER_TRANSMISION - 1)
                {
                    est->indice_lectura_transmision++;
                }
                else
                {
                    est->indice_lectura_transmision = 0;
                } 
                est->quedan_por_transmitir--;
            }
            break;

        /* 2 => Receive Data Available.
         * 6 => Character Time-out Indicator.
         * Acción: Recoger el dato y colocarlo en el buffer de recepción.
         */        
        case 2:
        case 6:
            /* Mientras haya datos en la FIFO de recepción del interfaz.
             */
            while (ptr_interfaz->LSR & (1u << 0))
            {
                est->buffer_recepcion[est->indice_escritura_recepcion] =
                    ptr_interfaz->RBR;
                if (est->indice_escritura_recepcion < UART_TAMANO_BUFFER_RECEPCION - 1)
                {
                    est->indice_escritura_recepcion++;
                }
                else
                {
                    est->indice_escritura_recepcion = 0;
                } 
                est->disponibles_para_leer++;
            }
            
            if (est->disponibles_para_leer > est->nivel_superior)
            {
//                ptr_interfaz->THR = XOFF;
							uart_enviar_xoff();
//                if (!est->ya_transmitido_xoff)
//                {
//                    char c = XOFF;
//                    uart_transmitir(ptr_interfaz, 1, &c);
//                    est->ya_transmitido_xoff = TRUE;
//                    est->ya_transmitido_xon = FALSE;
//                }
            }
            
            break;
        
        /* Resto de casos. No deberían presentarse.
         */
        default:
            ERROR("Interrupción imprevista en UART.");
            break;
    }
}
