/*
 * Display.h
 *
 *  Created on: Nov 27, 2016
 *      Author: joaquin
 */

#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <vector>
#include "Digit.h"

using std::vector;

class Display {
private:
    vector<Digit> digits;

public:
    Display();
    void displayUnsignedValue(uint16_t);
    void displaySignedValue(int16_t);
    void enableDisplay(void);
    void beginDisplayTask(void);
};

#endif /* DISPLAY_H_ */
