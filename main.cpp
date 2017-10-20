/*
 * main.cpp
 *
 *  Created on: Dec 1, 2016
 *      Author: joaquin
 */
#include "RpiManager.h"
#include <iostream>
#include <future>
#include "gpioPolicies.h"
#include "Utils.hpp"


int main()
{
	typedef RPiManager<RPi1Policy> Manager;
	Manager manager;

    while(1)
    {
		manager.clockwiseTest();
        uint16_t x;
        std::cin >> x;
        manager.getMotor().stop();
        std::cin >> x;
        manager.getMotor().startCounterClockwise();
        std::cin >> x;
        manager.getMotor().stop();
        std::cin >> x;
    }

}

