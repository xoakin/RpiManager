/*
 * gpioPolicies.h
 *
 *  Created on: May 13, 2017
 *      Author: joaquin
 */

#ifndef GPIOPOLICIES_H_
#define GPIOPOLICIES_H_

#include <vector>
#include <cstdint>
#include "gpio.hpp"

class RPi3Policy{

	const uint8_t segmentA =      19;
	const uint8_t segmentB =       6;
	const uint8_t segmentC =      12;
	const uint8_t segmentD =      20;
	const uint8_t segmentE =      21;
	const uint8_t segmentF =      13;
	const uint8_t segmentG =       7;
	const uint8_t segmentH = 	  16;

	const uint8_t enableDigit0 = 26;
	const uint8_t enableDigit1 =  5;
	const uint8_t enableDigit2 = 11;
	const uint8_t enableDigit3 =  8;

	const uint8_t motorIn1 = 0;
	const uint8_t motorIn2 = 0;
	const uint8_t motorIn3 = 0;
	const uint8_t motorIn4 = 0;

	std::vector<Gpio> segmentVector = { Gpio(segmentA), Gpio(segmentB), Gpio(segmentC),
										Gpio(segmentD), Gpio(segmentE), Gpio(segmentF),
										Gpio(segmentG), Gpio(segmentH)};

	std::vector<Gpio> enableVector  = { Gpio(enableDigit0), Gpio(enableDigit1),
			   	   	   	   	   	   	   	Gpio(enableDigit2), Gpio(enableDigit3)};

	std::vector<Gpio> motorVector = {Gpio(motorIn1), Gpio(motorIn2), Gpio(motorIn3), Gpio(motorIn4)};

protected:

	auto& segmentGpios() noexcept{ return segmentVector;}
	auto& enableGpios()  noexcept{ return enableVector; };
	auto& motorGpios()  noexcept {return motorVector; };
};

class RPi1Policy{

	 const uint8_t segmentA =      13;
	 const uint8_t segmentB =       3;
	 const uint8_t segmentC =       5;
	 const uint8_t segmentD =      10;
	 const uint8_t segmentE =      11;
	 const uint8_t segmentF =      12;
	 const uint8_t segmentG =       4;
	 const uint8_t segmentH =  	 	6;

	 const uint8_t enableDigit0 = 14;
	 const uint8_t enableDigit1 =  2;
	 const uint8_t enableDigit2 =  0;
	 const uint8_t enableDigit3 =  1;

	 const uint8_t motorIn1 = 8;
	 const uint8_t motorIn2 = 9;
	 const uint8_t motorIn3 = 15;
	 const uint8_t motorIn4 = 16;

	std::vector<Gpio> segmentVector = { Gpio(segmentA), Gpio(segmentB), Gpio(segmentC),
										Gpio(segmentD), Gpio(segmentE), Gpio(segmentF),
										Gpio(segmentG), Gpio(segmentH)};

	std::vector<Gpio> enableVector  = { Gpio(enableDigit0), Gpio(enableDigit1),
			   	   	   	   	   	   	   	Gpio(enableDigit2), Gpio(enableDigit3)};

	std::vector<Gpio> motorVector = {Gpio(motorIn1), Gpio(motorIn2), Gpio(motorIn3), Gpio(motorIn4)};

protected:

	auto& segmentGpios()  noexcept{ return segmentVector;}
	auto& enableGpios()   noexcept{ return enableVector; };
	auto& motorGpios()  noexcept {return motorVector; };

};


#endif /* GPIOPOLICIES_H_ */
