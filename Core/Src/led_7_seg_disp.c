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

void setLED(void){
	HAL_GPIO_WritePin(EN0_PORT, EN0_PIN,1);
	HAL_GPIO_WritePin(EN1_PORT, EN1_PIN,1);
	HAL_GPIO_WritePin(EN2_PORT, EN2_PIN,1);
	HAL_GPIO_WritePin(EN3_PORT, EN3_PIN,1);
	HAL_GPIO_WritePin(LED_BLINK_PORT, LED_BLINK_PIN, 0);
}
void update_clock_buffer(uint8_t hour, uint8_t minute){
	if (hour <24 && minute <60){
		numBuffer[0] = hour/10;
		numBuffer[1] = hour%10;
		numBuffer[2] = minute/10;
		numBuffer[3] = minute%10;
	}
	else return;
}
void update_seven_segment_driver(uint8_t index){
	if (index > 3 && index < 0) return;
	switch (index){
	case 0:
		HAL_GPIO_WritePin(EN3_PORT, EN3_PIN,1);
		HAL_GPIO_WritePin(EN0_PORT, EN0_PIN,0);
		buffer[0]=LED7Conversion[numBuffer[0]];
		seven_segment_driver(0);
		break;
	case 1:
		HAL_GPIO_WritePin(EN0_PORT, EN0_PIN,1);
		HAL_GPIO_WritePin(EN1_PORT, EN1_PIN,0);
		buffer[1]=LED7Conversion[numBuffer[1]];
		seven_segment_driver(1);
		break;
	case 2:
		HAL_GPIO_WritePin(EN1_PORT, EN1_PIN,1);
		HAL_GPIO_WritePin(EN2_PORT, EN2_PIN,0);
		buffer[2]=LED7Conversion[numBuffer[2]];
		seven_segment_driver(2);
		break;
	case 3:
		HAL_GPIO_WritePin(EN2_PORT, EN2_PIN,1);
		HAL_GPIO_WritePin(EN3_PORT, EN3_PIN,0);
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
