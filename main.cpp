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
    auto fut = reallyAsync([&manager](){manager.enableDisplay();});
    while(1)
    {
        uint16_t x;
        std::cin >> x;
        manager.refreshValue(x);
    }
	std::cout << "Hola a todo el mundo\n";
}

