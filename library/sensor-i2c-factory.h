#pragma once

#include <cstdint>

//#include <sensor-i2c.h>
class I2CSensor;


class I2CSensorFactory
{
public:
    virtual ~I2CSensorFactory() {}

    // ATTENTION: return dynamically (new) allocated object
    virtual I2CSensor* create(unsigned int bus, uint8_t address) = 0;
};

