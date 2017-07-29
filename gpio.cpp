/*
 * gpio.cpp
 *
 *  Created on: Jul 2, 2017
 *      Author: joaquin
 */

#include "gpio.hpp"

Gpio::Gpio(uint8_t nGpio):gpio(nGpio),direction(INPUT),value(LOW){ configureGpio();}

Gpio::Gpio(uint8_t nGpio, uint8_t direc, uint8_t defaultValue):
		gpio(nGpio),direction(direc),value(defaultValue){ configureGpio();}


void Gpio::configureGpio(){
	pinMode(gpio, direction);
    digitalWrite(gpio, value);
}

void Gpio::changeDirection(uint8_t newDirection){
	if(direction != newDirection)
		direction = newDirection;
	configureGpio();
}

void Gpio::clear(){
	if(direction == OUTPUT && value){
		value = LOW;
		digitalWrite(gpio, value);
	}
}

void Gpio::set(){
	if(direction == OUTPUT && !value){
		value = HIGH;
		digitalWrite(gpio, value);
	}
}

void Gpio::write(uint8_t val){
	val? set():clear();
}
