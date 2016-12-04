/*
 * Digit.h
 *
 *  Created on: Nov 27, 2016
 *      Author: joaquin
 */

#ifndef DIGIT_H_
#define DIGIT_H_

#include <stdint.h>
#include <map>

using std::map;

typedef void (*DisplayValue)(void);

class Digit {
private:
    static uint8_t digit;
    const uint8_t currentDigit;

    uint8_t numValue;

    map<uint8_t, DisplayValue> displayValue;

public:
    Digit();
    void setValue(void);
    void enableDisplay(void);
    void updateValue(uint8_t);
};

#endif /* DIGIT_H_ */
