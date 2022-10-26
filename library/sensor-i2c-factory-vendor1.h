#pragma once

#include <sensor-i2c-vendor1.h>
#include <sensor-i2c-factory.h>
#include <cstdint>


class I2CSensorFactory_Vendor1 : public I2CSensorFactory
{
public:
    I2CSensor* create(unsigned int bus, uint8_t address) override
    {
        I2CSensor_Vendor1* sensor = new I2CSensor_Vendor1(bus, address);
        return sensor;
    }
};
