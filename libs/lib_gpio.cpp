/**
 * @file lib_gpio.c
 *
 * @date 9 août 2013
 * @author joaquin
 * @description
 */

#include <fstream>
#include <stdlib.h>


using std::string;
using std::ofstream;
using std::ifstream;

static const string SysGpioDir = "/sys/class/gpio";

/****************************************************************
 * gpio_export
 ****************************************************************/

int8_t lib_gpio_export(const uint8_t gpio)
{
	ofstream fStream(SysGpioDir + string("/export"), ofstream::out);

	if (!fStream.is_open())
	{
		return -1;
	}

	fStream << gpio;
	fStream.close();

	return 0;
}

/****************************************************************
 * gpio_unexport
 ****************************************************************/
int8_t lib_gpio_unexport(const uint8_t gpio)
{
    ofstream fStream(SysGpioDir + string("/unexport"), ofstream::out);

    if (!fStream.is_open())
    {
        return -1;
    }

    fStream << gpio;
    fStream.close();

    return 0;
}

/****************************************************************
 * gpio_set_dir
 ****************************************************************/
int8_t lib_gpio_set_dir(const uint8_t gpio, const bool out_flag)
{

	ofstream fStream(SysGpioDir + string("/gpio") +
	                std::to_string(gpio) +
	                string("/direction"),
	                ofstream::out);

    if (!fStream.is_open())
    {
        return -1;
    }

	if (out_flag)
		fStream << "out" ;
	else
	    fStream << "in" ;

	fStream.close();
	return 0;
}

/****************************************************************
 * gpio_set_value
 ****************************************************************/
int8_t lib_gpio_set_value(const uint8_t gpio, const bool value)
{

    ofstream fStream(SysGpioDir + string("/gpio") +
                    std::to_string(gpio) +
                    string("/value"),
                    ofstream::out);

    if (!fStream.is_open())
    {
        return -1;
    }


	if (value)
		fStream << "1";
	else
		fStream << "0";

	fStream.close();
	return 0;
}

/****************************************************************
 * gpio_get_value
 ****************************************************************/
int8_t lib_gpio_get_value(const uint8_t gpio, bool *value)
{
    ifstream fStream(SysGpioDir + string("/gpio") +
                    std::to_string(gpio) +
                    string("/value"),
                    ifstream::in);

    if (!fStream.is_open())
    {
        return -1;
    }

    string valRead;

	fStream >> valRead;

	*value = valRead.compare("1");

	fStream.close();

	return 0;
}


/****************************************************************
 * gpio_set_edge
 ****************************************************************/

int8_t lib_gpio_set_edge(const uint8_t gpio, const string& edge)
{

    ofstream fStream(SysGpioDir + string("/gpio") +
                    std::to_string(gpio) +
                    string("/edge"),
                    ofstream::out);

    if (!fStream.is_open())
    {
        return -1;
    }

    fStream << edge;

    fStream.close();

	return 0;
}

