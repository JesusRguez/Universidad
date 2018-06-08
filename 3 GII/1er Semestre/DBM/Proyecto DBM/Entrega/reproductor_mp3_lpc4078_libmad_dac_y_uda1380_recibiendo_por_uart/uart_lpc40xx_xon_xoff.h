/***************************************************************************//**
 * \file    uart_lpc40xx.h
 *
 * \brief   Funciones de manejo de las UARTs del LPC40x.
 */

#ifndef UART_LPC40XX_XON_XOFF_H
#define UART_LPC40XX_XON_XOFF_H

#include "tipos.h"
#include "gpio_lpc40xx.h"

/*===== Constantes =============================================================
 */
 
/*==============================================================================
 * El LPC40xx tiene 5 UARTs. Las UARTs 0, 2 y 3 son exactamente iguales entre
 * sí. La UART 1 añade señales de control de modem y tiene registros adicionales
 * a los de las UARTs 0, 2 y 3. La UART 4 puede funcionar en un modo síncrono y
 * puede comunicar con smart cards, así que también tiene registros adicionales.
 *
 * Las funciones de este módulo no usan ninguna de las características
 * especiales de las UARTs 1 y 4. Las posiciones de los registros comunes a
 * todas las UARTs coinciden, así que todas se manejarán mediante punteros a
 * estructura de tipo LPC_UART_TypeDef.
 */
#define LPC_UART1_  ((LPC_UART_TypeDef*)LPC_UART1_BASE)
#define LPC_UART4_  ((LPC_UART_TypeDef*)LPC_UART4_BASE)

#define UART_NUMERO_INTERFACES  5u
#define UART0                   LPC_UART0
#define UART1                   LPC_UART1_
#define UART2                   LPC_UART2
#define UART3                   LPC_UART3
#define UART4                   LPC_UART4_

/* Símbolos para especificar baudrates estándar.
 */
 
#define UART_BAUDRATE_110       110u
#define UART_BAUDRATE_300       300u
#define UART_BAUDRATE_600       600u
#define UART_BAUDRATE_1200      1200u
#define UART_BAUDRATE_2400      2400u
#define UART_BAUDRATE_4800      4800u
#define UART_BAUDRATE_9600      9600u
#define UART_BAUDRATE_14400     14400u
#define UART_BAUDRATE_19200     19200u
#define UART_BAUDRATE_28800     28800u
#define UART_BAUDRATE_38400     38400u
#define UART_BAUDRATE_57600     57600u
#define UART_BAUDRATE_115200    115200u

/* Símbolos para especificar el número de bits de datos.
 */

#define UART_BITS_DATOS_5       5u
#define UART_BITS_DATOS_6       6u
#define UART_BITS_DATOS_7       7u
#define UART_BITS_DATOS_8       8u

/* Símbolos para especificar el número de bits de stop.
 */

#define UART_BITS_STOP_1        1u
#define UART_BITS_STOP_2        2u

/* Tamaño de los buffer de transmisión y recepción.
 */

#define UART_TAMANO_BUFFER_TRANSMISION  128u
#define UART_TAMANO_BUFFER_RECEPCION    (30*1024u)

#define XON  17u
#define XOFF 19u

/*===== Tipos de datos =========================================================
 */

/* Puntero a función void(void).
 */
typedef void (*funcion_void_t)(void);

/* Puntero a función void(uint32_t).
 */
typedef void (*uart_funcion_callback_t)(uint32_t);

/* Estructura con el estado de transmision/recepción actual.
 */
typedef struct
{
    volatile uint32_t tamano_buffer_transmision;
    volatile uint32_t indice_escritura_transmision; /**< Del siguiente elemento a escribir. */
    volatile uint32_t indice_lectura_transmision;   /**< Del siguiente elemento a leer. */
    volatile uint32_t quedan_por_transmitir;
    volatile uint32_t tamano_buffer_recepcion;
    volatile uint32_t indice_escritura_recepcion;
    volatile uint32_t indice_lectura_recepcion;
    volatile uint32_t disponibles_para_leer;
    volatile uint8_t  buffer_transmision[UART_TAMANO_BUFFER_TRANSMISION];
    volatile uint8_t  buffer_recepcion[UART_TAMANO_BUFFER_RECEPCION];
    volatile uint32_t nivel_inferior;
    volatile uint32_t nivel_superior;
    volatile bool_t   ya_transmitido_xon;
    volatile bool_t   ya_transmitido_xoff;
} uart_estado_transferencia_t;

/* Tipos de paridad.
 */
typedef enum
{
    UART_PARIDAD_NINGUNA,
    UART_PARIDAD_IMPAR,
    UART_PARIDAD_PAR
} uart_tipo_paridad_t;

/*===== Prototipos de funciones ================================================
 */

void uart_enviar_xoff(void);
void uart_enviar_xon(void);

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
                      float32_t *baudrate_real_obtenido);

void uart_transmitir(LPC_UART_TypeDef *uart_regs,
                     uint32_t numero_bytes_a_transmitir,
                     void *buffer);

void uart_esperar_fin_transmision(LPC_UART_TypeDef *uart_regs);

bool_t uart_probar_transmitir(LPC_UART_TypeDef *uart_regs,
                              uint32_t numero_bytes_a_transmitir,
                              void *buffer);

uint32_t uart_bytes_disponibles(LPC_UART_TypeDef *uart_regs);
                                                                             
void uart_leer(LPC_UART_TypeDef *uart_regs,
               uint32_t numero_bytes_a_leer,
               void *buffer,
               uint32_t* numero_bytes_leidos);

void uart_esperar_leer(LPC_UART_TypeDef *uart_regs,
                       uint32_t numero_bytes_a_leer,
                       void *buffer,
                       uint32_t *numero_bytes_leidos);
                                                                                            
void UART0_IRQHandler(void);
void UART1_IRQHandler(void);
void UART2_IRQHandler(void);
void UART3_IRQHandler(void);
void UART4_IRQHandler(void);
                                        
void uart_manejador_interrupciones(uint32_t numero_interfaz);
                                       
#endif /* UART_LPC40XX_H */
