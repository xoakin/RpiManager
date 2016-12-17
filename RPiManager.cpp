/*
 * RPiManager.cpp
 *
 *  Created on: Dec 6, 2016
 *      Author: joaquin
 */
#include "RpiManager.h"

RPiManager::RPiManager()
:display()//,
// serial("hola"),
// motor(1,2,3,4,5,6)
{
    display.displayUnsignedValue(0);
    display.beginDisplayTask();
}


void RPiManager::refreshValue(uint16_t x)
{
    display.displayUnsignedValue(x);
}
