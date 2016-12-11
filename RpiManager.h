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

class RPiManager
{
public:
    RPiManager();
private:
    Display display;
    SerialCom serial;
    Stepper motor;
};




#endif /* RPIMANAGER_H_ */
