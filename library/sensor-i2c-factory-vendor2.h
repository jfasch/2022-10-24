#pragma once

#include <sensor-i2c-vendor2.h>
#include <sensor-i2c-factory.h>


class I2CSensorFactory_Vendor2 : public I2CSensorFactory
{
public:
    I2CSensor* create(unsigned int bus, uint8_t address) override
    {
        I2CSensor_Vendor2* sensor = new I2CSensor_Vendor2(bus, address);
        return sensor;
    }
};
