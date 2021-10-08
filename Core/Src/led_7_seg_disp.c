/*
 * led_7_seg_disp.c
 *
 *  Created on: Oct 3, 2021
 *      Author: Win10
 */

#include "main.h"
#include "led_7_seg_disp.h"
#define NUMBER_OF_7_SEG_LED 4

static uint8_t LED7Conversion[10]={
		0x3f,  // 0
		0x06,  // 1
		0x5b,  // 2
		0x4f,  // 3
		0x66,  // 4
		0x6d,  // 5
		0x7d,  // 6
		0x07,  // 7
		0x7f,  // 8
		0x67   // 9
};
static uint8_t numBuffer[NUMBER_OF_7_SEG_LED];
static uint8_t buffer[NUMBER_OF_7_SEG_LED];
void update_clock_buffer(uint8_t num, uint8_t index){
	numBuffer[index] = num;
}
void update_seven_segment_driver(uint8_t index){
	switch (index){
	case 0:
		buffer[0]=LED7Conversion[numBuffer[0]];
		seven_segment_driver(0);
		break;
	case 1:
		buffer[1]=LED7Conversion[numBuffer[1]];
		seven_segment_driver(1);
		break;
	case 2:
		buffer[2]=LED7Conversion[numBuffer[2]];
		seven_segment_driver(2);
		break;
	case 3:
		buffer[3]=LED7Conversion[numBuffer[3]];
		seven_segment_driver(3);
		break;
	}
}

void seven_segment_driver(uint8_t index){
	HAL_GPIO_WritePin(SEG_A_1_PORT, SEG_A_1_PIN, !((buffer[index]>>0)&0x01));
	HAL_GPIO_WritePin(SEG_B_1_PORT, SEG_B_1_PIN, !((buffer[index]>>1)&0x01));
	HAL_GPIO_WritePin(SEG_C_1_PORT, SEG_C_1_PIN, !((buffer[index]>>2)&0x01));
	HAL_GPIO_WritePin(SEG_D_1_PORT, SEG_D_1_PIN, !((buffer[index]>>3)&0x01));
	HAL_GPIO_WritePin(SEG_E_1_PORT, SEG_E_1_PIN, !((buffer[index]>>4)&0x01));
	HAL_GPIO_WritePin(SEG_F_1_PORT, SEG_F_1_PIN, !((buffer[index]>>5)&0x01));
	HAL_GPIO_WritePin(SEG_G_1_PORT, SEG_G_1_PIN, !((buffer[index]>>6)&0x01));
}
