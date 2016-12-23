/*
 * RPiManager.cpp
 *
 *  Created on: Dec 6, 2016
 *      Author: joaquin
 */
#include "RpiManager.h"
#include <iostream>

RPiManager::RPiManager()
:display()//,
// serial("hola"),
// motor(1,2,3,4,5,6)
{
    display.displayUnsignedValue(0);
    std::clog << "Leaving constructor\n";
}


void RPiManager::refreshValue(uint16_t x)
{
    display.displayUnsignedValue(x);
}

void RPiManager::enableDisplay()
{
    display.beginDisplayTask();
}
