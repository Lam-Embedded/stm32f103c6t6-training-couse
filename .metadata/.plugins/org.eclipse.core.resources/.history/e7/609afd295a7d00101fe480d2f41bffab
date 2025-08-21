#ifndef LCD_H
#define LCD_H

#include <stdint.h>
#include "stm32f1xx_hal.h"

#define MDATA 0x01
#define MCMD  0x00

void LCD_Init();

void LCD_Write_Byte(uint8_t data, uint8_t mode);

void LCD_Write_data(uint8_t data);

void LCD_Write_cmd(uint8_t data);

void LCD_printf(char *str);

#endif
