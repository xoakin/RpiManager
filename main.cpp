/*
 * main.cpp
 *
 *  Created on: Dec 1, 2016
 *      Author: joaquin
 */
#include "RpiManager.h"
#include <iostream>

int main()
{
    std::cout << "Hello world!" << std::endl;
    RPiManager manager;
    std::cout << "Hola mundo!" << std::endl;
    while(1)
    {
        uint16_t x;
        std::cin >> x;
        std::cout << (x+1);
        manager.refreshValue(x);
    }
}

