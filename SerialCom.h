/*
 * SerialCom.h
 *
 *  Created on: Dec 6, 2016
 *      Author: joaquin
 */

#ifndef SERIALCOM_H_
#define SERIALCOM_H_
#include <string>

class SerialCom
{
public:
    SerialCom(std::string serialPort);
    uint8_t sendData(uint8_t * data, uint32_t len);
    uint32_t receiveData(uint32_t * );
private:
};



#endif /* SERIALCOM_H_ */
