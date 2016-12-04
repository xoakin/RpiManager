#include <stdint.h>
#include <string>


int lib_gpio_export(const uint8_t gpio);
int lib_gpio_unexport(const uint8_t gpio);
int lib_gpio_set_dir(const uint8_t gpio, const bool out_flag);
int lib_gpio_set_value(const uint8_t gpio, const bool value);
int lib_gpio_get_value(const uint8_t gpio, bool *value);
int lib_gpio_set_edge(const uint8_t gpio, const std::string &edge);
