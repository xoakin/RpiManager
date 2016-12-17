/*
 * sevensegments.c
 *
 *  Created on: Mar 16, 2015
 *      Author: joaquin
 */
#include <wiringPi.h>
#include "sevensegments.h"


static constexpr auto segmentA =      19;
static constexpr auto segmentB =       6;
static constexpr auto segmentC =      12;
static constexpr auto segmentD =      20;
static constexpr auto segmentE =      21;
static constexpr auto segmentF =      13;
static constexpr auto segmentG =       7;
static constexpr auto segmentH =      16;

static constexpr auto enableDigit0 = 26;
static constexpr auto enableDigit1 =  5;
static constexpr auto enableDigit2 = 11;
static constexpr auto enableDigit3 =  8;

void sevensegments_init()
{
    wiringPiSetupGpio();
	/*Set all gpios as output*/
	pinMode(segmentA, OUTPUT);
	pinMode(segmentB, OUTPUT);
	pinMode(segmentC, OUTPUT);
	pinMode(segmentD, OUTPUT);
	pinMode(segmentE, OUTPUT);
	pinMode(segmentF, OUTPUT);
	pinMode(segmentG, OUTPUT);
	pinMode(segmentH, OUTPUT);
	pinMode(enableDigit0, OUTPUT);
	pinMode(enableDigit1, OUTPUT);
	pinMode(enableDigit2, OUTPUT);
	pinMode(enableDigit3, OUTPUT);

	/*Set all gpio to LOW*/
	digitalWrite(segmentA, LOW);
	digitalWrite(segmentB, LOW);
	digitalWrite(segmentC, LOW);
	digitalWrite(segmentD, LOW);
	digitalWrite(segmentE, LOW);
	digitalWrite(segmentF, LOW);
	digitalWrite(segmentG, LOW);
	digitalWrite(segmentH, LOW);
	digitalWrite(enableDigit0, HIGH);
	digitalWrite(enableDigit1, HIGH);
	digitalWrite(enableDigit2, HIGH);
	digitalWrite(enableDigit3, HIGH);

	return;
}

void sevensegments_display_0(void)
{
	digitalWrite(segmentA, HIGH);
	digitalWrite(segmentB, HIGH);
	digitalWrite(segmentC, HIGH);
	digitalWrite(segmentD, HIGH);
	digitalWrite(segmentE, HIGH);
	digitalWrite(segmentF, HIGH);
	digitalWrite(segmentG, LOW);
	digitalWrite(segmentH, LOW);
}

void sevensegments_display_1(void)
{
	digitalWrite(segmentA, LOW);
	digitalWrite(segmentB, HIGH);
	digitalWrite(segmentC, HIGH);
	digitalWrite(segmentD, LOW);
	digitalWrite(segmentE, LOW);
	digitalWrite(segmentF, LOW);
	digitalWrite(segmentG, LOW);
	digitalWrite(segmentH, LOW);
}

void sevensegments_display_2(void)
{
	digitalWrite(segmentA, HIGH);
	digitalWrite(segmentB, HIGH);
	digitalWrite(segmentC, LOW);
	digitalWrite(segmentD, HIGH);
	digitalWrite(segmentE, HIGH);
	digitalWrite(segmentF, LOW);
	digitalWrite(segmentG, HIGH);
	digitalWrite(segmentH, LOW);
}

void sevensegments_display_3(void)
{
	digitalWrite(segmentA, HIGH);
	digitalWrite(segmentB, HIGH);
	digitalWrite(segmentC, HIGH);
	digitalWrite(segmentD, HIGH);
	digitalWrite(segmentE, LOW);
	digitalWrite(segmentF, LOW);
	digitalWrite(segmentG, HIGH);
	digitalWrite(segmentH, LOW);
}

void sevensegments_display_4(void)
{
	digitalWrite(segmentA, LOW);
	digitalWrite(segmentB, HIGH);
	digitalWrite(segmentC, HIGH);
	digitalWrite(segmentD, LOW);
	digitalWrite(segmentE, LOW);
	digitalWrite(segmentF, HIGH);
	digitalWrite(segmentG, HIGH);
	digitalWrite(segmentH, LOW);
}

void sevensegments_display_5(void)
{
	digitalWrite(segmentA, HIGH);
	digitalWrite(segmentB, LOW);
	digitalWrite(segmentC, HIGH);
	digitalWrite(segmentD, HIGH);
	digitalWrite(segmentE, LOW);
	digitalWrite(segmentF, HIGH);
	digitalWrite(segmentG, HIGH);
	digitalWrite(segmentH, LOW);
}

void sevensegments_display_6(void)
{
	digitalWrite(segmentA, HIGH);
	digitalWrite(segmentB, LOW);
	digitalWrite(segmentC, HIGH);
	digitalWrite(segmentD, HIGH);
	digitalWrite(segmentE, HIGH);
	digitalWrite(segmentF, HIGH);
	digitalWrite(segmentG, HIGH);
	digitalWrite(segmentH, LOW);
}

void sevensegments_display_7(void)
{
	digitalWrite(segmentA, HIGH);
	digitalWrite(segmentB, HIGH);
	digitalWrite(segmentC, HIGH);
	digitalWrite(segmentD, LOW);
	digitalWrite(segmentE, LOW);
	digitalWrite(segmentF, LOW);
	digitalWrite(segmentG, LOW);
	digitalWrite(segmentH, LOW);
}

void sevensegments_display_8(void)
{
	digitalWrite(segmentA, HIGH);
	digitalWrite(segmentB, HIGH);
	digitalWrite(segmentC, HIGH);
	digitalWrite(segmentD, HIGH);
	digitalWrite(segmentE, HIGH);
	digitalWrite(segmentF, HIGH);
	digitalWrite(segmentG, HIGH);
	digitalWrite(segmentH, LOW);
}

void sevensegments_display_9(void)
{
	digitalWrite(segmentA, HIGH);
	digitalWrite(segmentB, HIGH);
	digitalWrite(segmentC, HIGH);
	digitalWrite(segmentD, LOW);
	digitalWrite(segmentE, LOW);
	digitalWrite(segmentF, HIGH);
	digitalWrite(segmentG, HIGH);
	digitalWrite(segmentH, LOW);
}

void sevensegments_display_period(void)
{

	digitalWrite(segmentH, HIGH);
}

void sevensegments_clear(void)
{
	digitalWrite(segmentA, LOW);
	digitalWrite(segmentB, LOW);
	digitalWrite(segmentC, LOW);
	digitalWrite(segmentD, LOW);
	digitalWrite(segmentE, LOW);
	digitalWrite(segmentF, LOW);
	digitalWrite(segmentG, LOW);

}
void sevensegments_clear_period(void)
{
	digitalWrite(segmentH, LOW);
}

void sevensegments_display_number(unsigned char number)
{
	switch(number)
	{
	case 0:
		sevensegments_display_0();
		break;
	case 1:
		sevensegments_display_1();
		break;
	case 2:
		sevensegments_display_2();
		break;
	case 3:
		sevensegments_display_3();
		break;
	case 4:
		sevensegments_display_4();
		break;
	case 5:
		sevensegments_display_5();
		break;
	case 6:
		sevensegments_display_6();
		break;
	case 7:
		sevensegments_display_7();
		break;
	case 8:
		sevensegments_display_8();
		break;
	case 9:
		sevensegments_display_9();
		break;
	default:
		return;
	}
}

void sevensegments_select_digit(unsigned char digit)
{
	switch(digit)
	{
		case 0:
			digitalWrite(enableDigit0,LOW);
			digitalWrite(enableDigit1,HIGH);
			digitalWrite(enableDigit2,HIGH);
			digitalWrite(enableDigit3,HIGH);
			break;
		case 1:
			digitalWrite(enableDigit0,HIGH);
			digitalWrite(enableDigit1,LOW);
			digitalWrite(enableDigit2,HIGH);
			digitalWrite(enableDigit3,HIGH);
			break;
		case 2:
			digitalWrite(enableDigit0,HIGH);
			digitalWrite(enableDigit1,HIGH);
			digitalWrite(enableDigit2,LOW);
			digitalWrite(enableDigit3,HIGH);
			break;
		case 3:
			digitalWrite(enableDigit0,HIGH);
			digitalWrite(enableDigit1,HIGH);
			digitalWrite(enableDigit2,HIGH);
			digitalWrite(enableDigit3,LOW);
			break;
		default:
			return;
	}
}
