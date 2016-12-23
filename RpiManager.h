/*
 * RpiManager.h
 *
 *  Created on: Dec 6, 2016
 *      Author: joaquin
 */

#ifndef RPIMANAGER_H_
#define RPIMANAGER_H_

#include "Display.h"
#include "SerialCom.h"
#include "StepperMotor28BYJ48.hpp"

class RPiManager
{
public:
    RPiManager();
    void refreshValue(uint16_t x);
    void enableDisplay();
private:
    Display display;
//    SerialCom serial;
//    StepperMotor28BYJ48 motor;
};




#endif /* RPIMANAGER_H_ */
