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

static constexpr auto nbSegments = 7;
constexpr auto nbDigits = 4;


template<typename GpioPolicy>
class SevenSegments: GpioPolicy{

	using GpioPolicy::segmentGpios;
	using GpioPolicy::enableGpios;

	static constexpr std::array<uint8_t, nbSegments> zero {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW};
	static constexpr std::array<uint8_t, nbSegments> one {LOW, HIGH, HIGH, LOW, LOW, LOW, LOW};
	static constexpr std::array<uint8_t, nbSegments> two {HIGH, HIGH, LOW, HIGH, HIGH, LOW, HIGH};
	static constexpr std::array<uint8_t, nbSegments> three {HIGH, HIGH, HIGH, HIGH, LOW, LOW, HIGH};
	static constexpr std::array<uint8_t, nbSegments> four {LOW, HIGH, HIGH, LOW, LOW, HIGH, HIGH};
	static constexpr std::array<uint8_t, nbSegments> five {HIGH, LOW, HIGH, HIGH, LOW, HIGH, HIGH};
	static constexpr std::array<uint8_t, nbSegments> six {HIGH, LOW, HIGH, HIGH, HIGH, HIGH, HIGH};
	static constexpr std::array<uint8_t, nbSegments> seven {HIGH, HIGH, HIGH, LOW, LOW, LOW, LOW};
	static constexpr std::array<uint8_t, nbSegments> eight {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH};
	static constexpr std::array<uint8_t, nbSegments> nine  {HIGH, HIGH, HIGH, LOW, LOW, HIGH, HIGH};

	static constexpr std::array<uint8_t, nbDigits> digitZero {LOW, HIGH, HIGH, HIGH};
	static constexpr std::array<uint8_t, nbDigits> digitOne {HIGH, LOW, HIGH, HIGH};
	static constexpr std::array<uint8_t, nbDigits> digitTwo {HIGH, HIGH, LOW, HIGH};
	static constexpr std::array<uint8_t, nbDigits> digitThree {HIGH, HIGH, HIGH, LOW};

	static std::vector<std::unique_ptr<const uint8_t>> enables;
	static std::vector<std::unique_ptr<const uint8_t>> numbers;

public:

	static void init() {
		numbers.emplace_back(zero.data());
		numbers.emplace_back(one.data());
		numbers.emplace_back(two.data());
		numbers.emplace_back(three.data());
		numbers.emplace_back(four.data());
		numbers.emplace_back(five.data());
		numbers.emplace_back(six.data());
		numbers.emplace_back(seven.data());
		numbers.emplace_back(eight.data());
		numbers.emplace_back(nine.data());

		enables.emplace_back(digitZero.data());
		enables.emplace_back(digitOne.data());
		enables.emplace_back(digitTwo.data());
		enables.emplace_back(digitThree.data());

	    wiringPiSetupGpio();

	    std::for_each(segmentGpios().begin(), segmentGpios().end(),
	    			  [](const auto& n){ pinMode(n, OUTPUT);
	    			  	  	  	  	  	  digitalWrite(n, LOW); });

	    std::for_each(enableGpios().begin(),enableGpios().end(),
	    			  [](const auto& n){ pinMode(n, OUTPUT);
	    			    				 digitalWrite(n, HIGH); });

	    pinMode(GpioPolicy::period, OUTPUT);
	    clearPeriod();
	}

	static void selectDigit(const uint8_t& digit) {
		if(digit >= nbDigits)
			throw std::out_of_range("Digit >= 4");

		for(auto i = 0; i < enableGpios().size(); i++)
			digitalWrite(enableGpios()[i], enables[digit].get()[i]);

	}

	static void displayNumber(const uint8_t number) {
		if(number < 0 || number > 9)
			throw std::out_of_range("0<=Number<10");

		for(auto i = 0; i < segmentGpios().size(); i++)
			digitalWrite(segmentGpios()[i], numbers[number].get()[i]);
	}

	static void displayPeriod(void) {
		digitalWrite(GpioPolicy::period, HIGH);
	}

	static void clearPeriod(void) {
		digitalWrite(GpioPolicy::period, LOW);
	}

	static void clear(void) {
		std::for_each( segmentGpios().begin(), segmentGpios().end(),
						[](const auto& n){ digitalWrite(n, LOW); });
	}
};

template<typename T>
std::vector<std::unique_ptr<const uint8_t>> SevenSegments<T>::numbers;
template<typename P>
std::vector<std::unique_ptr<const uint8_t>> SevenSegments<P>::enables;

#endif /* 7SEGMENTS_H_ */
