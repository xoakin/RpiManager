/*
 * 7segments.h
 *
 *  Created on: Mar 16, 2015
 *      Author: joaquin
 */

#ifndef SEGMENTS_H_
#define SEGMENTS_H_


void sevensegments_init(void);

void sevensegments_select_digit(unsigned char digit);

void sevensegments_display_0(void);
void sevensegments_display_1(void);
void sevensegments_display_2(void);
void sevensegments_display_3(void);
void sevensegments_display_4(void);
void sevensegments_display_5(void);
void sevensegments_display_6(void);
void sevensegments_display_7(void);
void sevensegments_display_8(void);
void sevensegments_display_9(void);
void sevensegments_display_period(void);

void sevensegments_clear(void);
void sevensegments_clear_period(void);

void sevensegments_display_number(unsigned char number);


#endif /* 7SEGMENTS_H_ */
