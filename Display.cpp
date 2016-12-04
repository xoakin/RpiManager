/*
 * Display.cpp
 *
 *  Created on: Nov 27, 2016
 *      Author: joaquin
 */
#include "Display.h"
#include <unistd.h>
#include <future>

static const uint8_t nbDigits = 4;


Display::Display()
{
    for(auto i = 0; i < nbDigits; i++)
        digits.push_back(Digit());


}


void Display::displayUnsignedValue(uint16_t value)
{
    vector<uint8_t> values;
    values.push_back(value / 1000);
    values.push_back((value%1000) / 100);
    values.push_back((value%100) / 10);
    values.push_back(value%10);

    for(auto i = 0; i < nbDigits; i++)
        digits[i].updateValue(values[i]);
}
void Display::displaySignedValue(int16_t)
{

}


void Display::enableDisplay(void)
{
    while(1)
    {
        for(auto i = 0; i < nbDigits; i++)
        {
            digits[i].enableDisplay();
            digits[i].setValue();
            usleep(5000);
            //clear?
        }
    }
}

void Display::beginDisplayTask()
{
    auto fut = std::async(enableDisplay);
}


