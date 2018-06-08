/***************************************************************************//**
 * \file    lcd_hd44780_lpc40xx.h
 *
 * \brief   Funciones de manejo del display LCD basado en controlador HD44780.
 *
 * \detail  El controlador se usa en el modo de bus de datos de 4 bits. Las
 *          funciones se han desarrollado para un microcontrolador LPC40xx.
 */ 

#ifndef LCD_HD44780_LPC40XX_H
#define LCD_HD44780_LPC40XX_H

#include "tipos.h"

/* Registros de GPIO del microcontrolador usados para manejar el LCD.
 */
#define LCD_DIR     LPC_GPIO2->DIR
#define LCD_CLR     LPC_GPIO2->CLR
#define LCD_SET     LPC_GPIO2->SET
#define LCD_PIN     LPC_GPIO2->PIN
#define LCD_MASK    LPC_GPIO2->MASK

/* Máscaras para actuar sobre las señales RS, RW y E del LCD.
 */

#define LCD_DATA_MASK   0x0F    
#define LCD_RS_MASK     (1u << 4)
#define LCD_RW_MASK     (1u << 5)
#define LCD_E_MASK      (1u << 6)
#define LCD_ALL_MASK    (LCD_DATA_MASK | LCD_RS_MASK | LCD_RW_MASK | LCD_E_MASK)

/* Con las definiciones anteriores las conexiones entre el microcontrolador y
 * el LCD son las siguientes:
 *
 * P2[0] -> DB4
 * P2[1] -> DB5
 * P2[2] -> DB6
 * P2[3] -> DB7
 * P2[4] -> RS
 * P2[5] -> RW
 * P2[6] -> E
 */
 
/* Prototipos de funciones
 */

void lcd_escribir_ir(uint8_t instruccion);

void lcd_escribir_dr(uint8_t dato);

uint8_t lcd_leer_acbf(void);

uint8_t lcd_leer_dr(void);

void lcd_esperar_mientras_ocupado(void);

void lcd_inicializar(void);

void lcd_borrar(void);

void lcd_cursor_xy_16x2(uint32_t x,
                        uint32_t y);
                        
void lcd_cursor_xy_20x4(uint32_t x,
                        uint32_t y);
                        
void lcd_imprimir_caracter(char c);

void lcd_imprimir_caracter_xy_16x2(char c,
                                   uint32_t x,
                                   uint32_t y);
                                   
void lcd_imprimir_caracter_xy_20x4(char c,
                                   uint32_t x,
                                   uint32_t y);
                                   
void lcd_imprimir_cadena(char *ptr);

void lcd_imprimir_cadena_xy_16x2(char *ptr,
                                 uint32_t x,
                                 uint32_t y);
                                 
void lcd_imprimir_cadena_xy_20x4(char *ptr,
                                 uint32_t x,
                                 uint32_t y);
                                 
void lcd_definir_caracteres(uint8_t primer_caracter,
                            uint8_t numero_caracteres,
                            uint8_t *ptr);
                            
void retardo_con_timer1(unsigned int microsegundos);

#endif  /* LCD_HD44780_LPC40XX_H */
