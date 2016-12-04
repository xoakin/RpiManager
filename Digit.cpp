/*
 * Digit.cpp
 *
 *  Created on: Nov 27, 2016
 *      Author: joaquin
 */
#include "Digit.h"
#include "lib_gpio.h"
#include "sevensegments.h"

uint8_t Digit::digit = 0;

Digit::Digit() : currentDigit(digit++),
                 numValue(0)
{

    if(currentDigit == 0)
        sevensegments_init();

    displayValue.emplace(0, sevensegments_display_0);
    displayValue.emplace(1, sevensegments_display_1);
    displayValue.emplace(2, sevensegments_display_2);
    displayValue.emplace(3, sevensegments_display_3);
    displayValue.emplace(4, sevensegments_display_4);
    displayValue.emplace(5, sevensegments_display_5);
    displayValue.emplace(6, sevensegments_display_6);
    displayValue.emplace(7, sevensegments_display_7);
    displayValue.emplace(8, sevensegments_display_8);
    displayValue.emplace(9, sevensegments_display_9);
}



void Digit::setValue(void)
{
    displayValue[numValue]();
}

void Digit::enableDisplay(void)
{
    sevensegments_select_digit(currentDigit);
}

void Digit::updateValue(uint8_t value)
{
    if(value >= 0 && value <= 9)
        numValue = value;
}
