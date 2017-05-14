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


int main()
{
	typedef RPiManager<RPi1Policy> Manager;
    Manager manager;
    auto fut = std::async(std::launch::async, &Manager::enableDisplay, &manager);
    manager.enableDisplay();
    while(1)
    {
        uint16_t x;
        std::cin >> x;
        manager.refreshValue(x);
    }
}

