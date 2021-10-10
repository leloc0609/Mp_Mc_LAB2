/*
 * matrix_led.c
 *
 *  Created on: Oct 10, 2021
 *      Author: Win10
 */
#include "main.h"
#include "matrix_led.h"


static uint8_t letterA_row[8]={
		0x00,		// 1st dot in row/column
		0x3c,		// 2nd dot
		0x66,		// 3rd dot
		0x66,    	// 4th dot
		0x7e,		// 5th dot
		0x66,		// 6th dot
		0x66,		// 7th dot
		0x00 		// 8th dot
};


void setCol(uint8_t val){
	HAL_GPIO_WritePin(COL_1_PORT, COL_1_PIN, ((val>>7)&0x01));
	HAL_GPIO_WritePin(COL_2_PORT, COL_2_PIN, ((val>>6)&0x01));
	HAL_GPIO_WritePin(COL_3_PORT, COL_3_PIN, ((val>>5)&0x01));
	HAL_GPIO_WritePin(COL_4_PORT, COL_4_PIN, ((val>>4)&0x01));
	HAL_GPIO_WritePin(COL_5_PORT, COL_5_PIN, ((val>>3)&0x01));
	HAL_GPIO_WritePin(COL_6_PORT, COL_6_PIN, ((val>>2)&0x01));
	HAL_GPIO_WritePin(COL_7_PORT, COL_7_PIN, ((val>>1)&0x01));
	HAL_GPIO_WritePin(COL_8_PORT, COL_8_PIN, ((val>>0)&0x01));
}

void resetMatrix(void){
	HAL_GPIO_WritePin(ROW_1_PORT, ROW_1_PIN, 1);
	HAL_GPIO_WritePin(ROW_2_PORT, ROW_2_PIN, 1);
	HAL_GPIO_WritePin(ROW_3_PORT, ROW_3_PIN, 1);
	HAL_GPIO_WritePin(ROW_4_PORT, ROW_4_PIN, 1);
	HAL_GPIO_WritePin(ROW_5_PORT, ROW_5_PIN, 1);
	HAL_GPIO_WritePin(ROW_6_PORT, ROW_6_PIN, 1);
	HAL_GPIO_WritePin(ROW_7_PORT, ROW_7_PIN, 1);
	HAL_GPIO_WritePin(ROW_8_PORT, ROW_8_PIN, 1);

}
void updateMatrix(uint8_t index, uint8_t shift){
	resetMatrix();
	uint8_t shiftBuffer = (letterA_row[index]<<shift) | (letterA_row[index]>>(8-shift));
	switch (index){
	case 0:
		HAL_GPIO_WritePin(ROW_8_PORT, ROW_8_PIN, 0);
		HAL_GPIO_WritePin(ROW_1_PORT, ROW_1_PIN, 1);
		setCol(shiftBuffer );
		break;
	case 1:
		HAL_GPIO_WritePin(ROW_1_PORT, ROW_1_PIN, 0);
		HAL_GPIO_WritePin(ROW_2_PORT, ROW_2_PIN, 1);
		setCol(shiftBuffer );
		break;
	case 2:
		HAL_GPIO_WritePin(ROW_2_PORT, ROW_2_PIN, 0);
		HAL_GPIO_WritePin(ROW_3_PORT, ROW_3_PIN, 1);
		setCol(shiftBuffer );
		break;
	case 3:
		HAL_GPIO_WritePin(ROW_3_PORT, ROW_3_PIN, 0);
		HAL_GPIO_WritePin(ROW_4_PORT, ROW_4_PIN, 1);
		setCol(shiftBuffer );
		break;
	case 4:
		HAL_GPIO_WritePin(ROW_4_PORT, ROW_4_PIN, 0);
		HAL_GPIO_WritePin(ROW_5_PORT, ROW_5_PIN, 1);
		setCol(shiftBuffer );
		break;
	case 5:
		HAL_GPIO_WritePin(ROW_5_PORT, ROW_5_PIN, 0);
		HAL_GPIO_WritePin(ROW_6_PORT, ROW_6_PIN, 1);
		setCol(shiftBuffer );
		break;
	case 6:
		HAL_GPIO_WritePin(ROW_6_PORT, ROW_6_PIN, 0);
		HAL_GPIO_WritePin(ROW_7_PORT, ROW_7_PIN, 1);
		setCol(shiftBuffer );
		break;
	case 7:
		HAL_GPIO_WritePin(ROW_7_PORT, ROW_7_PIN, 0);
		HAL_GPIO_WritePin(ROW_8_PORT, ROW_8_PIN, 1);
		setCol(shiftBuffer );
		break;

	}
}



