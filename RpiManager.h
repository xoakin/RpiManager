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

template<typename T>
class RPiManager
{
public:
    RPiManager():display(){
    	display.displayUnsignedValue(0);
    	std::clog << "Leaving constructor\n";
    }
    void refreshValue(uint16_t x){ display.displayUnsignedValue(x); }
    void enableDisplay(){ display.displayTask();}
private:
    Display<T> display;
//    SerialCom serial;
//    StepperMotor28BYJ48 motor;
};




#endif /* RPIMANAGER_H_ */
