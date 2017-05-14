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

class RPi3Policy{

	static constexpr auto segmentA =      19;
	static constexpr auto segmentB =       6;
	static constexpr auto segmentC =      12;
	static constexpr auto segmentD =      20;
	static constexpr auto segmentE =      21;
	static constexpr auto segmentF =      13;
	static constexpr auto segmentG =       7;

	static constexpr auto enableDigit0 = 26;
	static constexpr auto enableDigit1 =  5;
	static constexpr auto enableDigit2 = 11;
	static constexpr auto enableDigit3 =  8;

protected:
	static constexpr auto period   =      16;
	auto static segmentGpios() noexcept{
		std::vector<uint8_t> segmentGpios {segmentA, segmentB, segmentC, segmentD, segmentE, segmentF, segmentG};
		return std::move(segmentGpios);
	}
	auto static enableGpios() noexcept{
		std::vector<uint8_t> enableGpios {enableDigit0, enableDigit1, enableDigit2, enableDigit3};
		return std::move(enableGpios);
	}
};

class RPi1Policy{

	static constexpr auto segmentA =      13;
	static constexpr auto segmentB =       3;
	static constexpr auto segmentC =       5;
	static constexpr auto segmentD =      10;
	static constexpr auto segmentE =      11;
	static constexpr auto segmentF =      12;
	static constexpr auto segmentG =       4;

	static constexpr auto enableDigit0 = 14;
	static constexpr auto enableDigit1 =  2;
	static constexpr auto enableDigit2 =  0;
	static constexpr auto enableDigit3 =  1;

protected:
	static constexpr auto period   =       6;
	auto static segmentGpios() noexcept{
		std::vector<uint8_t> segmentGpios {segmentA, segmentB, segmentC, segmentD, segmentE, segmentF, segmentG};
		return std::move(segmentGpios);
	}
	auto static enableGpios() noexcept{
		std::vector<uint8_t> enableGpios {enableDigit0, enableDigit1, enableDigit2, enableDigit3};
		return std::move(enableGpios);
	}
};


#endif /* GPIOPOLICIES_H_ */
