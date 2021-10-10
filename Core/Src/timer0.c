/*
 * timer0.c
 *
 *  Created on: Oct 10, 2021
 *      Author: Win10
 */
#include "main.h"
#include "timer0.h"

int timer0_counter = 0;
int timer0_flag = 0;
int led7seg_flag = 0;
int matrixLED_flag = 0;
void setTimer0(int duration){
	timer0_counter = duration /TIMER_CYCLE;
	timer0_flag = 0;
	led7seg_flag = 0;
	matrixLED_flag =0;
}

void timer_run(){
	if (timer0_counter > 0){
		timer0_counter--;
		if (timer0_counter == 0) {
			timer0_flag = 1, led7seg_flag = 0;
			HAL_GPIO_TogglePin(LED_BLINK_PORT, LED_BLINK_PIN);
			HAL_GPIO_TogglePin(LED_BLINK_PORT, LED_BLINK_PIN);
		}
		if (timer0_counter % 25 == 0) led7seg_flag++;
		if (timer0_counter % 3== 0) matrixLED_flag=(matrixLED_flag+1)%8;
	}
}

