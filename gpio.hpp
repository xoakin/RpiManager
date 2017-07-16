/*
 * gpio.hpp
 *
 *  Created on: Jul 2, 2017
 *      Author: joaquin
 */

#ifndef GPIO_HPP_
#define GPIO_HPP_

#include <cstdint>
#include <wiringPi.h>

class Gpio{
public:
	Gpio(uint8_t nGpio);
	Gpio(uint8_t nGpio, uint8_t direction, uint8_t defaultValue);
	void changeDirection(uint8_t newDirection);
	void clear();
	void set();
	void write(uint8_t val);
private:
	void configureGpio();
	uint8_t gpio;
	uint8_t direction;
	uint8_t value;
};



#endif /* GPIO_HPP_ */
