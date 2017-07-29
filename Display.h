/*
 * Display.h
 *
 *  Created on: Nov 27, 2016
 *      Author: joaquin
 */

#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <array>
#include <chrono>
#include <iostream>
#include <future>

#include "sevensegments.h"

using namespace std::chrono_literals;

template<typename T>
class Display {
private:
    std::array<uint8_t, nbDigits> valueToDisplay;
    SevenSegments<T> sevenSegments;

public:
    Display():sevenSegments(){}

    void displayUnsignedValue(uint16_t value){
    	valueToDisplay[0] = (value/1000);
    	valueToDisplay[1] = (value%1000) / 100;
    	valueToDisplay[2] = (value%100) / 10;
    	valueToDisplay[3] = value%10;
    }
    void displaySignedValue(int16_t value){

    }

    void displayTask(){
    	std::clog<< "In display task, about to get to while\n";
    	while(1){
    		for(auto i = 0; i < nbDigits; i++){
    			sevenSegments.selectDigit(i);
    			sevenSegments.displayNumber(valueToDisplay[i]);
    			std::this_thread::sleep_for(1ms);
    		}
    	}
    }

    void beginDisplayTask(void){
        std::clog << "About to launch task\n";
        //auto fut = std::async(std::launch::async, &Display<T>::displayTask, this);
        std::clog << "Task running \n";
    }
};

#endif /* DISPLAY_H_ */
