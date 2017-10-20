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

using namespace std::chrono_literals;

template<typename T>
class RPiManager
{
public:
    RPiManager():display(),motor(5ms){

    	display.displayUnsignedValue(0);


    	std::clog << "Leaving constructor\n";
    }
    void refreshValue(uint16_t x){ display.displayUnsignedValue(x); }
    void enableDisplay(){ display.displayTask();}
    auto motorDemo() { return motor.performDemo(); }

    void  clockwiseTest(){
    	motor.setSteppingMethod(StepperMotor28BYJ48<T>::SteppingMethod::FULL_STEP);
    	motor.startClockwise();
    }

    auto& getDisplay() { return display;}
    auto& getMotor()  {return motor;}
private:
    Display<T> display;
//    SerialCom serial;
    StepperMotor28BYJ48<T> motor;
};




#endif /* RPIMANAGER_H_ */
