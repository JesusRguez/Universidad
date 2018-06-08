/***************************************************************************//**
 * \file    lcd_hd44780_lpc40xx.c
 *
 * \brief   Funciones de manejo del display LCD basado en controlador HD44780.
 *
 * \detail  El controlador se usa en el modo de bus de datos de 4 bits. Las
 *          funciones se han desarrollado para un microcontrolador LPC40xx.
 */

#include <LPC407x_8x_177x_8x.h>
#include "lcd_hd44780_lpc40xx.h"
#include "timer_lpc40xx.h"
#include "tipos.h"
#include "error.h"
#include "retardo_software.h"

/***************************************************************************//**
 * \brief       Escribir en el registro de instrucción del LCD.
 *
 * \param[in]   instruccion     instrucción a escribir.
 */
void lcd_escribir_ir(uint8_t instruccion)
{
    uint8_t hi, lo;

    lcd_esperar_mientras_ocupado();

    hi = (instruccion & 0xF0 ) >> 4;
    lo = instruccion & 0x0F;

    LCD_DIR |= LCD_ALL_MASK;

    LCD_MASK = ~LCD_ALL_MASK;
    LCD_PIN = hi;
    retardo_software_us(1);
    LCD_PIN = hi | LCD_E_MASK;
    retardo_software_us(1);
    LCD_PIN = hi;
    retardo_software_us(1);

    LCD_PIN = lo;
    retardo_software_us(1);
    LCD_PIN = lo | LCD_E_MASK;
    retardo_software_us(1);
    LCD_PIN = lo;
    retardo_software_us(1);
    LCD_MASK = 0;
}

/***************************************************************************//**
 * \brief       Escribir en el registro de datos del LCD.
 *
 * \param[in]   dato    dato a escribir.
 */
void lcd_escribir_dr(uint8_t dato)
{
    uint8_t hi, lo;

    lcd_esperar_mientras_ocupado();

    hi = (dato & 0xF0 ) >> 4;
    lo = dato & 0x0F;

    LCD_DIR |= LCD_ALL_MASK;

    LCD_MASK = ~LCD_ALL_MASK;
    LCD_PIN = hi | LCD_RS_MASK;
    retardo_software_us(1);
    LCD_PIN = hi | LCD_E_MASK | LCD_RS_MASK;
    retardo_software_us(1);
    LCD_PIN = hi | LCD_RS_MASK;
    retardo_software_us(1);

    LCD_PIN = lo | LCD_RS_MASK;
    retardo_software_us(1);
    LCD_PIN = lo | LCD_E_MASK | LCD_RS_MASK;
    retardo_software_us(1);
    LCD_PIN = lo | LCD_RS_MASK;
    retardo_software_us(1);
    LCD_MASK = 0;
}

/***************************************************************************//**
 * \brief   Leer el contador de dirección y el flag de ocupado del LCD.
 *
 * \return  Entero sin signo de 8 bits en el que los 7 bits menos
 *          significativos es el valor actual del contador de dirección y
 *          el bit más significativo el flag de ocupado.
 */
uint8_t lcd_leer_acbf(void)
{
    uint8_t hi, lo;

    LCD_DIR |= LCD_RS_MASK | LCD_RW_MASK | LCD_E_MASK;
    LCD_DIR &= ~LCD_DATA_MASK;

    LCD_MASK = ~LCD_ALL_MASK;

    LCD_PIN = LCD_RW_MASK;
    retardo_software_us(1);
    LCD_PIN = LCD_E_MASK | LCD_RW_MASK;
    retardo_software_us(1);
    hi = (LCD_PIN & 0x0F) << 4;
    LCD_PIN = LCD_RW_MASK;
    retardo_software_us(1);

    LCD_PIN = LCD_RW_MASK;
    retardo_software_us(1);
    LCD_PIN = LCD_E_MASK | LCD_RW_MASK;
    retardo_software_us(1);
    lo = LCD_PIN & 0x0F;
    LCD_PIN = LCD_RW_MASK;
    retardo_software_us(1);

    return hi | lo;
}

/***************************************************************************//**
 * \brief   Leer el registro de datos del LCD.
 *
 * \return  Valor actual del registro de datos del LCD.
 */
uint8_t lcd_leer_dr(void)
{
    uint8_t hi, lo;

    lcd_esperar_mientras_ocupado();

    LCD_DIR |= LCD_RS_MASK | LCD_RW_MASK | LCD_E_MASK;
    LCD_DIR &= ~LCD_DATA_MASK;

    LCD_MASK = ~LCD_ALL_MASK;

    LCD_PIN = LCD_RW_MASK | LCD_RS_MASK;
    retardo_software_us(1);
    LCD_PIN = LCD_E_MASK | LCD_RW_MASK | LCD_RS_MASK;
    retardo_software_us(1);
    hi = (LCD_PIN & 0x0F) << 4;
    LCD_PIN = LCD_RW_MASK | LCD_RS_MASK;
    retardo_software_us(1);

    LCD_PIN = LCD_E_MASK | LCD_RW_MASK | LCD_RS_MASK;
    retardo_software_us(1);
    lo = LCD_PIN & 0x0F;
    LCD_PIN = LCD_RW_MASK | LCD_RS_MASK;
    retardo_software_us(1);

    return hi | lo;
}

/***************************************************************************//**
 * \brief   Esperar mientras el flag de ocupado del LCD esté a 1.
 */
void lcd_esperar_mientras_ocupado(void)
{
    uint8_t temp;
    
    LCD_DIR |= LCD_RS_MASK | LCD_RW_MASK | LCD_E_MASK;
    LCD_DIR &= ~LCD_DATA_MASK;

    LCD_MASK = ~LCD_ALL_MASK;

    do
    {
        LCD_PIN = LCD_RW_MASK;
        retardo_software_us(1);
        LCD_PIN = LCD_E_MASK | LCD_RW_MASK;
        retardo_software_us(1);
        temp = LCD_PIN;
        LCD_PIN = LCD_RW_MASK;
        retardo_software_us(1);
    
        LCD_PIN = LCD_E_MASK | LCD_RW_MASK;
        retardo_software_us(1);
        LCD_PIN = LCD_RW_MASK;
        retardo_software_us(1);
    }
    while(temp & 0x08);
    
    LCD_MASK = 0;
}


/***************************************************************************//**
 * \brief   Inicializar el LCD.
 */
void lcd_inicializar(void)
{    
    /* Secuencia de inicialización para bus de 4 bits:
     *
     *    1. Esperar 15 ms después de aplicar la alimentación.
     *    2. Escribir 0011xxxx en el IR. No debe comprobarse BUSY antes.
     *    3. Esperar más de 4.1 ms.
     *    4. Escribir 0011xxxx en el IR. No debe comprobarse BUSY antes.
     *    5. Esperar más de 100 us.
     *    6. Escribir 0011xxxx en el IR. No debe comprobarse BUSY antes.
     *    7. Escribir 0010xxxx en el IR. No debe comprobarse BUSY antes.
     *
     *    A partir de aquí se supone que el HD44780 ha empezado a
     *    funcionar correctamente por lo que se realiza una comprobación
     *    del bit BUSY antes de escribir sobre el IR.
     *
     *    8. Escribir configuración 0010NFxx en el IR. N = nº de líneas, F = font.
     *    9. Borrar display.
     * 10. Cursor al inicio.
     * 11. Display ON, cursor ON, etc.
     */

    retardo_software_inicializar();
     
    retardo_software_us(15000);

    LCD_DIR |= LCD_ALL_MASK;
    LCD_MASK = ~LCD_ALL_MASK;
    LCD_PIN = 0x03;
    retardo_software_us(1);
    LCD_PIN = 0x03 | LCD_E_MASK;
    retardo_software_us(1);
    LCD_PIN = 0x03;
    LCD_MASK = 0x00;

    retardo_software_us(5000);

    LCD_PIN = 0x03;
    retardo_software_us(1);
    LCD_PIN = 0x03 | LCD_E_MASK;
    retardo_software_us(1);
    LCD_PIN = 0x03;
    LCD_MASK = 0x00;

    retardo_software_us(200);

    LCD_PIN = 0x03;
    retardo_software_us(1);
    LCD_PIN = 0x03 | LCD_E_MASK;
    retardo_software_us(1);
    LCD_PIN = 0x03;
    LCD_MASK = 0x00;

    LCD_PIN = 0x02;
    retardo_software_us(1);
    LCD_PIN = 0x02 | LCD_E_MASK;
    retardo_software_us(1);
    LCD_PIN = 0x02;
    retardo_software_us(1);
        
    LCD_MASK = 0;

    lcd_escribir_ir(0x28);
    lcd_escribir_ir(1);
    lcd_escribir_ir(2);
    lcd_escribir_ir(15);
}

/***************************************************************************//**
 * \brief   Borrar la pantalla LCD.
 */
void lcd_borrar(void)
{
    lcd_escribir_ir(1);
}

/***************************************************************************//**
 * \brief       Colocar el cursor en una posición de una pantalla LCD de 16x2.
 *
 * \param[in]        x        coordenada x (columna).
 * \param[in]   y        coordenada y (fila).
 */

void lcd_cursor_xy_16x2(uint32_t x, uint32_t y)
{
    lcd_escribir_ir(0x80 | y*64 | x);
}

/***************************************************************************//**
 * \brief       Colocar el cursor en una posición de una pantalla LCD de 20x4.
 *
 * \param[in]   x   coordenada x (columna).
 * \param[in]   y   coordenada y (fila).
 */
void lcd_cursor_xy_20x4(uint32_t x, uint32_t y)
{
    if (y == 1)
    {
        x += 64;
    }
    else if (y == 2)
    {
        x += 20;
    }
    else if (y == 3)
    {
        x += 84;
    }

    lcd_escribir_ir(0x80 | x);
}

/***************************************************************************//**
 * \brief       Imprimir en el un caracter en la posición actual del cursor.
 *
 * \param[in]        c        carácter a imprimir.
 */
void lcd_imprimir_caracter(char c)
{
    lcd_escribir_dr(c);
}

/***************************************************************************//**
 * \brief       Imprimir en el un caracter en la posición (x, y) de una pantalla
 *              LCD de 16x2 caracteres.
 *
 * \param[in]        c        carácter a imprimir.
 * \param[in]   x   coordenada x (columna).
 * \param[in]   y   coordenada y (fila).
 */
void lcd_imprimir_caracter_xy_16x2(char c, uint32_t x, uint32_t y)
{
    lcd_cursor_xy_16x2(x, y);
    lcd_escribir_dr(c);
}

/***************************************************************************//**
 * \brief       Imprimir en el un caracter en la posición (x, y) de una pantalla
 *              LCD de 20x4 caracteres.
 *
 * \param[in]   c   carácter a imprimir.
 * \param[in]   x   coordenada x (columna).
 * \param[in]   y   coordenada y (fila).
 */
void lcd_imprimir_caracter_xy_20x4(char c, uint32_t x, uint32_t y)
{
    lcd_cursor_xy_20x4(x, y);
    lcd_escribir_dr(c);
}

/***************************************************************************//**
 * \brief       Imprimir en el LCD una cadena de caracteres ASCIIZ en la posición
 *              actual del cursor.
 *
 * \param[in]   ptr        puntero a la cadena a imprimir.
 */
void lcd_imprimir_cadena(char *ptr)
{
    while(*ptr)
    {
        lcd_escribir_dr(*ptr++);
    }
}

/***************************************************************************//**
 * \brief       Imprimir una cadena de caracteres ASCIIZ en una posición de una
 *              pantalla LCD de 16x2 caracteres.
 *
 * \param[in]   ptr     puntero a la cadena a imprimir.
 * \param[in]    x       coordenada x (columna).
 * \param[in]    y       coordenada y (fila).
 */
void lcd_imprimir_cadena_xy_16x2(char *ptr, uint32_t x, uint32_t y)
{
    ASSERT(ptr != NULL, "Puntero ptr nulo.");
    
    lcd_cursor_xy_16x2(x, y);

    while(*ptr)
    {
        lcd_escribir_dr(*ptr++);
    }
}

/***************************************************************************//**
 * \brief       Imprimir una cadena de caracteres ASCIIZ en una posición de una
 *              pantalla LCD de 20x4 caracteres.
 *
 * \param[in]   ptr     puntero a la cadena a imprimir.
 * \param[in]   x       coordenada x (columna).
 * \param[in]   y       coordenada y (fila).
 */
void lcd_imprimir_cadena_xy_20x4(char *ptr, uint32_t x, uint32_t y)
{
    ASSERT(ptr != NULL, "Puntero ptr nulo.");    
    
    lcd_cursor_xy_20x4(x, y);

    while(*ptr)
    {
        lcd_escribir_dr(*ptr++);
    }
}

/***************************************************************************//**
 * \brief       Definir caracteres de usuario.
 *
 * \param[in]   primer_caracter     código del primer carácter a definir.
 * \param[in]   numero_caracteres   número de caracteres a definir.
 * \param[in]   ptr                 puntero a las definiciones de los caracteres.
 */
void lcd_definir_caracteres(uint8_t primer_caracter, uint8_t numero_caracteres, uint8_t *ptr)
{
    uint32_t i;
    uint8_t dir_actual_en_DDRAM;    
    
    ASSERT(primer_caracter < 16,
        "El primer carácter a definir debe estar entre 0 y 15");
    ASSERT(primer_caracter + numero_caracteres < 16,
        "Se sobrepasa el rango de caracteres definibles.");
    ASSERT(ptr != NULL, "Puntero ptr a definiciones de caracter nulo.");

    dir_actual_en_DDRAM = lcd_leer_acbf() & 0x7F;

    lcd_escribir_ir(0x40 | primer_caracter*8);

    for (i = numero_caracteres*8; i != 0; i--)
    {
        lcd_escribir_dr(*ptr++);
    }

    lcd_escribir_ir(0x80 | dir_actual_en_DDRAM);    
}
