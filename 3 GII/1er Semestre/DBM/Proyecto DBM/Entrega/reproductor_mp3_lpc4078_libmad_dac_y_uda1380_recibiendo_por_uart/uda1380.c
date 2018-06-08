/***************************************************************************//**
 *
 */
 
#include "uda1380.h"
#include "i2c_lpc40xx.h"

#define UDA1380_I2C_INTERFACE   LPC_I2C2
#define UDA1380_I2C_ADDRESS	    0x1A

void uda1380_inicializar(void)
{
    i2c_inicializar(UDA1380_I2C_INTERFACE,
                         uint32_t frecuencia_scl,                       
                         LPC_GPIO_TypeDef *puerto_sda,
                         uint32_t mascara_pin_sda,
                         LPC_GPIO_TypeDef *puerto_scl,
                         uint32_t mascara_pin_scl)
    i2c_inicializar(UDA1380_I2C_INTERFACE, 100000);
    
    /* Configurar P0[27] como I2C0_SDA y P0[28] como I2C0_SCL.
     */
    LPC_IOCON->P0_27 = 1;
    LPC_IOCON->P0_28 = 1;
    
    uda1380_escribir_registro(UDA1380_REG_L3, 0);
    uda1380_escribir_registro(UDA1380_REG_I2S, 0);   
    uda1380_escribir_registro(UDA1380_REG_MSTRMUTE, 0);
    uda1380_escribir_registro(UDA1380_REG_MIXSDO, 0);        
    uda1380_escribir_registro(UDA1380_REG_EVALCLK, 
        EVALCLK_DEC_EN | EVALCLK_DAC_EN | EVALCLK_INT_EN |
        EVALCLK_DAC_SEL_WSPLL | EVALCLK_WSPLL_SEL25_50K);                        
    uda1380_escribir_registro(UDA1380_REG_PWRCTRL,
              PWR_PON_PLL_EN | PWR_PON_HP_EN | PWR_PON_DAC_EN |
              PWR_PON_BIAS_EN);
}

/***************************************************************************//**
 * \brief       Escribir en un registro interno del UDA1380.
 *
 * \param[in]   registro_a_escribir     número del registro a escribir.
 * \param[in]   dato_a_escribir         dato a escribir en el registro.
 */
void uda1380_escribir_registro(uint8_t registro_a_escribir,
                               uint16_t dato_a_escribir)
{
    i2c_start(UDA1380_I2C_INTERFACE);
			
    i2c_transmitir_byte(UDA1380_I2C_INTERFACE, UDA1380_I2C_ADDRESS << 1);
    i2c_transmitir_byte(UDA1380_I2C_INTERFACE, registro_a_escribir);
    
    i2c_transmitir_byte(UDA1380_I2C_INTERFACE, dato_a_escribir >> 8);
    i2c_transmitir_byte(UDA1380_I2C_INTERFACE, dato_a_escribir &  0xFF);
    
    i2c_stop(UDA1380_I2C_INTERFACE);
}

/***************************************************************************//**
 * \brief   Leer un registro interno del UDA1380.
 *
 * \param[in]   registro_a_leer     número del registro a leer.
 *
 * \return      Valor leído del registro .
 */
uint16_t uda1380_leer_registro(uint8_t  registro_a_leer)
{
    uint8_t byte_alto, byte_bajo;
    		 
    i2c_start(UDA1380_I2C_INTERFACE);
    i2c_transmitir_byte(UDA1380_I2C_INTERFACE, UDA1380_I2C_ADDRESS << 1);
    i2c_transmitir_byte(UDA1380_I2C_INTERFACE, registro_a_leer);
    i2c_start(UDA1380_I2C_INTERFACE);
    i2c_transmitir_byte(UDA1380_I2C_INTERFACE, (UDA1380_I2C_ADDRESS << 1) + 1);
    
    i2c_recibir_byte(UDA1380_I2C_INTERFACE, &byte_alto, ACK);
    i2c_recibir_byte(UDA1380_I2C_INTERFACE, &byte_bajo, NACK);
    
    i2c_stop(UDA1380_I2C_INTERFACE);
     
    return (byte_alto << 8) | byte_bajo;
}
