/*
 * main.cpp
 *
 *  Created on: Dec 1, 2016
 *      Author: joaquin
 */
#include "RpiManager.h"
#include <iostream>
#include <future>

int main()
{
    RPiManager manager;
    auto fut = std::async(std::launch::async, &RPiManager::enableDisplay, &manager);
    while(1)
    {
        uint16_t x;
        std::cin >> x;
        manager.refreshValue(x);
    }
}

