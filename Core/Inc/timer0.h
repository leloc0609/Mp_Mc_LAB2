/*
 * timer0.h
 *
 *  Created on: Oct 10, 2021
 *      Author: Win10
 */


#ifndef INC_TIMER0_H_
#define INC_TIMER0_H_

#define TIMER_CYCLE 10;

extern int timer0_counter;
extern int timer0_flag;
extern int led7seg_flag;
extern int matrixLED_flag;
extern int matrixLED_shift_flag;
void setTimer0(int duration);
void timer_run(void);

#endif /* INC_TIMER0_H_ */
