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


	const std::array<std::array<uint8_t, nbSegments>, 10> numbers = {{
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


	const std::array<std::array<uint8_t, nbDigits>, nbDigits> digits = {{
																		{LOW, HIGH, HIGH, HIGH},
																		{HIGH, LOW, HIGH, HIGH},
																		{HIGH, HIGH, LOW, HIGH},
																		{HIGH, HIGH, HIGH, LOW}	}};


public:
	SevenSegments() {
		wiringPiSetup();

		for(auto& gpio : segmentGpios()){
			gpio.changeDirection(OUTPUT);
			gpio.clear();
		}

	    for(auto& gpio : enableGpios()){
	    	gpio.changeDirection(OUTPUT);
	    	gpio.set();
	    }

	}

	void selectDigit(const uint8_t digit) {
		if(digit >= nbDigits)
			throw std::out_of_range("Digit >= 4");

		for(size_t i = 0; i < enableGpios().size(); i++)
			enableGpios()[i].write(digits[digit][i]);

	}

	void displayNumber(const uint8_t number) {
		if(number < 0 || number > 9)
			throw std::out_of_range("0<=Number<10");

		for(size_t i = 0; i < segmentGpios().size() - 1 ; i++)
			segmentGpios()[i].write(numbers[number][i]);
	}

	void displayPeriod(void) { segmentGpios().back().set();}

	void clearPeriod(void) { segmentGpios().back().clear();}

	void clear(void) {
		for(auto& gpio : segmentGpios())
			gpio.clear();
	}
};



#endif /* 7SEGMENTS_H_ */
