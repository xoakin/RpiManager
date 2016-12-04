/*
 * sevensegments.c
 *
 *  Created on: Mar 16, 2015
 *      Author: joaquin
 */
#include "sevensegments.h"
#include "lib_gpio.h"

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

static const bool inDir = false;
static const bool outDir = true;

static const bool valLow = false;
static const bool valHigh = true;

void sevensegments_init()
{
	/*Export all gpios*/
	lib_gpio_export(segmentA);
	lib_gpio_export(segmentB);
	lib_gpio_export(segmentC);
	lib_gpio_export(segmentD);
	lib_gpio_export(segmentE);
	lib_gpio_export(segmentF);
	lib_gpio_export(segmentG);
	lib_gpio_export(segmentH);
	lib_gpio_export(enableDigit0);
	lib_gpio_export(enableDigit1);
	lib_gpio_export(enableDigit2);
	lib_gpio_export(enableDigit3);

	/*Set all gpios as output*/
	lib_gpio_set_dir(segmentA, outDir);
	lib_gpio_set_dir(segmentB, outDir);
	lib_gpio_set_dir(segmentC, outDir);
	lib_gpio_set_dir(segmentD, outDir);
	lib_gpio_set_dir(segmentE, outDir);
	lib_gpio_set_dir(segmentF, outDir);
	lib_gpio_set_dir(segmentG, outDir);
	lib_gpio_set_dir(segmentH, outDir);
	lib_gpio_set_dir(enableDigit0, outDir);
	lib_gpio_set_dir(enableDigit1, outDir);
	lib_gpio_set_dir(enableDigit2, outDir);
	lib_gpio_set_dir(enableDigit3, outDir);

	/*Set all gpio to LOW*/
	lib_gpio_set_value(segmentA, valLow);
	lib_gpio_set_value(segmentB, valLow);
	lib_gpio_set_value(segmentC, valLow);
	lib_gpio_set_value(segmentD, valLow);
	lib_gpio_set_value(segmentE, valLow);
	lib_gpio_set_value(segmentF, valLow);
	lib_gpio_set_value(segmentG, valLow);
	lib_gpio_set_value(segmentH, valLow);
	lib_gpio_set_value(enableDigit0, valLow);
	lib_gpio_set_value(enableDigit1, valLow);
	lib_gpio_set_value(enableDigit2, valLow);
	lib_gpio_set_value(enableDigit3, valLow);

	return;
}

void sevensegments_display_0(void)
{
	lib_gpio_set_value(segmentA, valHigh);
	lib_gpio_set_value(segmentB, valHigh);
	lib_gpio_set_value(segmentC, valHigh);
	lib_gpio_set_value(segmentD, valHigh);
	lib_gpio_set_value(segmentE, valHigh);
	lib_gpio_set_value(segmentF, valHigh);
	lib_gpio_set_value(segmentG, valLow);
	lib_gpio_set_value(segmentH, valLow);
}

void sevensegments_display_1(void)
{
	lib_gpio_set_value(segmentA, valLow);
	lib_gpio_set_value(segmentB, valHigh);
	lib_gpio_set_value(segmentC, valHigh);
	lib_gpio_set_value(segmentD, valLow);
	lib_gpio_set_value(segmentE, valLow);
	lib_gpio_set_value(segmentF, valLow);
	lib_gpio_set_value(segmentG, valLow);
	lib_gpio_set_value(segmentH, valLow);
}

void sevensegments_display_2(void)
{
	lib_gpio_set_value(segmentA, valHigh);
	lib_gpio_set_value(segmentB, valHigh);
	lib_gpio_set_value(segmentC, valLow);
	lib_gpio_set_value(segmentD, valHigh);
	lib_gpio_set_value(segmentE, valHigh);
	lib_gpio_set_value(segmentF, valLow);
	lib_gpio_set_value(segmentG, valHigh);
	lib_gpio_set_value(segmentH, valLow);
}

void sevensegments_display_3(void)
{
	lib_gpio_set_value(segmentA, valHigh);
	lib_gpio_set_value(segmentB, valHigh);
	lib_gpio_set_value(segmentC, valHigh);
	lib_gpio_set_value(segmentD, valHigh);
	lib_gpio_set_value(segmentE, valLow);
	lib_gpio_set_value(segmentF, valLow);
	lib_gpio_set_value(segmentG, valHigh);
	lib_gpio_set_value(segmentH, valLow);
}

void sevensegments_display_4(void)
{
	lib_gpio_set_value(segmentA, valLow);
	lib_gpio_set_value(segmentB, valHigh);
	lib_gpio_set_value(segmentC, valHigh);
	lib_gpio_set_value(segmentD, valLow);
	lib_gpio_set_value(segmentE, valLow);
	lib_gpio_set_value(segmentF, valHigh);
	lib_gpio_set_value(segmentG, valHigh);
	lib_gpio_set_value(segmentH, valLow);
}

void sevensegments_display_5(void)
{
	lib_gpio_set_value(segmentA, valHigh);
	lib_gpio_set_value(segmentB, valLow);
	lib_gpio_set_value(segmentC, valHigh);
	lib_gpio_set_value(segmentD, valHigh);
	lib_gpio_set_value(segmentE, valLow);
	lib_gpio_set_value(segmentF, valHigh);
	lib_gpio_set_value(segmentG, valHigh);
	lib_gpio_set_value(segmentH, valLow);
}

void sevensegments_display_6(void)
{
	lib_gpio_set_value(segmentA, valHigh);
	lib_gpio_set_value(segmentB, valLow);
	lib_gpio_set_value(segmentC, valHigh);
	lib_gpio_set_value(segmentD, valHigh);
	lib_gpio_set_value(segmentE, valHigh);
	lib_gpio_set_value(segmentF, valHigh);
	lib_gpio_set_value(segmentG, valHigh);
	lib_gpio_set_value(segmentH, valLow);
}

void sevensegments_display_7(void)
{
	lib_gpio_set_value(segmentA, valHigh);
	lib_gpio_set_value(segmentB, valHigh);
	lib_gpio_set_value(segmentC, valHigh);
	lib_gpio_set_value(segmentD, valLow);
	lib_gpio_set_value(segmentE, valLow);
	lib_gpio_set_value(segmentF, valLow);
	lib_gpio_set_value(segmentG, valLow);
	lib_gpio_set_value(segmentH, valLow);
}

void sevensegments_display_8(void)
{
	lib_gpio_set_value(segmentA, valHigh);
	lib_gpio_set_value(segmentB, valHigh);
	lib_gpio_set_value(segmentC, valHigh);
	lib_gpio_set_value(segmentD, valHigh);
	lib_gpio_set_value(segmentE, valHigh);
	lib_gpio_set_value(segmentF, valHigh);
	lib_gpio_set_value(segmentG, valHigh);
	lib_gpio_set_value(segmentH, valLow);
}

void sevensegments_display_9(void)
{
	lib_gpio_set_value(segmentA, valHigh);
	lib_gpio_set_value(segmentB, valHigh);
	lib_gpio_set_value(segmentC, valHigh);
	lib_gpio_set_value(segmentD, valLow);
	lib_gpio_set_value(segmentE, valLow);
	lib_gpio_set_value(segmentF, valHigh);
	lib_gpio_set_value(segmentG, valHigh);
	lib_gpio_set_value(segmentH, valLow);
}

void sevensegments_display_period(void)
{

	lib_gpio_set_value(segmentH, valHigh);
}

void sevensegments_clear(void)
{
	lib_gpio_set_value(segmentA, valLow);
	lib_gpio_set_value(segmentB, valLow);
	lib_gpio_set_value(segmentC, valLow);
	lib_gpio_set_value(segmentD, valLow);
	lib_gpio_set_value(segmentE, valLow);
	lib_gpio_set_value(segmentF, valLow);
	lib_gpio_set_value(segmentG, valLow);

}
void sevensegments_clear_period(void)
{
	lib_gpio_set_value(segmentH, valLow);
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
			lib_gpio_set_value(enableDigit0,valLow);
			lib_gpio_set_value(enableDigit1,valHigh);
			lib_gpio_set_value(enableDigit2,valHigh);
			lib_gpio_set_value(enableDigit3,valHigh);
			break;
		case 1:
			lib_gpio_set_value(enableDigit0,valHigh);
			lib_gpio_set_value(enableDigit1,valLow);
			lib_gpio_set_value(enableDigit2,valHigh);
			lib_gpio_set_value(enableDigit3,valHigh);
			break;
		case 2:
			lib_gpio_set_value(enableDigit0,valHigh);
			lib_gpio_set_value(enableDigit1,valHigh);
			lib_gpio_set_value(enableDigit2,valLow);
			lib_gpio_set_value(enableDigit3,valHigh);
			break;
		case 3:
			lib_gpio_set_value(enableDigit0,valHigh);
			lib_gpio_set_value(enableDigit1,valHigh);
			lib_gpio_set_value(enableDigit2,valHigh);
			lib_gpio_set_value(enableDigit3,valLow);
			break;
		default:
			return;
	}
}
