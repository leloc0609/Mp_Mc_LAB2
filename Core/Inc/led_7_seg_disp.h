/*
 * led_7_seg_disp.h
 *
 *  Created on: Oct 3, 2021
 *      Author: Win10
 */

#ifndef INC_LED_7_SEG_DISP_H_
#define INC_LED_7_SEG_DISP_H_


void update_seven_segment_driver(uint8_t index);
void seven_segment_driver(uint8_t index);
void update_clock_buffer(uint8_t hour, uint8_t minute);
void setLED(void);

#endif /* INC_LED_7_SEG_DISP_H_ */
