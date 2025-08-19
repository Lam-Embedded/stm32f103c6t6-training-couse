#include "LCD.h"

void LCD_Init() {
	HAL_Delay(50);
	LCD_Write_cmd(0x38);
	HAL_Delay(50);
	LCD_Write_cmd(0x0C);
	HAL_Delay(50);
	LCD_Write_cmd(0x01);
	HAL_Delay(50);
	LCD_Write_cmd(0x06);
	HAL_Delay(50);
}

void LCD_Write_Byte(uint8_t data, uint8_t mode){
	if (mode == 0x01) {
		// data
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_SET);		//RS = 1
	}
	else if (mode == 0x00) {
		//cmd
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET);		//RS = 0
	}

	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, (data & 0x01) ? 1 : 0);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, (data & 0x02) ? 1 : 0);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, (data & 0x04) ? 1 : 0);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, (data & 0x08) ? 1 : 0);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, (data & 0x10) ? 1 : 0);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, (data & 0x20) ? 1 : 0);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, (data & 0x40) ? 1 : 0);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, (data & 0x80) ? 1 : 0);

	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_RESET);
	HAL_Delay(1);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_SET);
	HAL_Delay(1);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_RESET);
	HAL_Delay(1);
}


void LCD_Write_data(uint8_t data) {
	LCD_Write_Byte(data, MDATA);
}

void LCD_Write_cmd(uint8_t data) {
	LCD_Write_Byte(data, MCMD);
}

void LCD_printf(char *str) {
	while (*str) {
		LCD_Write_data(*str++);
	}
}
