/*
 * 7segments.h
 *
 *  Created on: Mar 16, 2015
 *      Author: joaquin
 */

#ifndef SEGMENTS_H_
#define SEGMENTS_H_

#include <array>
#include <vector>
#include <wiringPi.h>
#include <stdexcept>
#include <memory>
#include <algorithm>
#include <chrono>
#include <thread>

using namespace std::chrono_literals;

static constexpr auto nbSegments = 7;
static constexpr auto nbDigits = 4;


template<typename GpioPolicy>
class SevenSegments: GpioPolicy{
	using GpioPolicy::segmentGpios;
	using GpioPolicy::enableGpios;

private:


	static std::array<std::array<uint8_t, nbSegments>, 10> numbers;

	static std::array<std::array<uint8_t, nbDigits>, nbDigits> enables;


public:
	static void init() {
		wiringPiSetup();

		for(auto& gpio : GpioPolicy::segmentVector){
			gpio.changeDirection(OUTPUT);
			gpio.clear();
			std::this_thread::sleep_for(100ms);
		}

	    for(auto& gpio : GpioPolicy::enableVector){
	    	gpio.changeDirection(OUTPUT);
	    	gpio.set();
	    	std::this_thread::sleep_for(100ms);
	    }

	}

	static void selectDigit(const uint8_t digit) {
		if(digit >= nbDigits)
			throw std::out_of_range("Digit >= 4");

		for(size_t i = 0; i < GpioPolicy::enableGpios().size(); i++)
			GpioPolicy::enableVector[i].write(enables[digit][i]);

	}

	static void displayNumber(const uint8_t number) {
		if(number < 0 || number > 9)
			throw std::out_of_range("0<=Number<10");

		for(size_t i = 0; i < GpioPolicy::segmentGpios().size() - 1 ; i++)
			GpioPolicy::segmentVector[i].write(numbers[number][i]);
	}

	static void displayPeriod(void) { GpioPolicy::segmentGpios().back().set();}

	static void clearPeriod(void) { GpioPolicy::segmentGpios().back().clear();}

	static void clear(void) {
		for(auto& gpio : GpioPolicy::segmentGpios())
			gpio.clear();
	}
};

template<typename T>
std::array<std::array<uint8_t, nbSegments>, 10> SevenSegments<T>::numbers = {{
															{HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW},
															{LOW, HIGH, HIGH, LOW, LOW, LOW, LOW},
															{HIGH, HIGH, LOW, HIGH, HIGH, LOW, HIGH},
															{HIGH, HIGH, HIGH, HIGH, LOW, LOW, HIGH},
															{LOW, HIGH, HIGH, LOW, LOW, HIGH, HIGH},
															{HIGH, LOW, HIGH, HIGH, LOW, HIGH, HIGH},
															{HIGH, LOW, HIGH, HIGH, HIGH, HIGH, HIGH},
															{HIGH, HIGH, HIGH, LOW, LOW, LOW, LOW},
															{HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH},
															{HIGH, HIGH, HIGH, LOW, LOW, HIGH, HIGH} }};

template<typename T>
std::array<std::array<uint8_t, nbDigits>, nbDigits> SevenSegments<T>::enables = {{
															{LOW, HIGH, HIGH, HIGH},
															{HIGH, LOW, HIGH, HIGH},
															{HIGH, HIGH, LOW, HIGH},
															{HIGH, HIGH, HIGH, LOW}	}};



#endif /* 7SEGMENTS_H_ */
