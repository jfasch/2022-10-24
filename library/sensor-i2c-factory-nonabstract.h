#pragma once

#include <cassert>

#include <sensor-i2c-vendor1.h>
#include <sensor-i2c-vendor2.h>


class I2CSensorFactory_NonAbstract
{
public:
    I2CSensorFactory_NonAbstract(int vendor) : _vendor(vendor) {}
    I2CSensor* create(unsigned int bus, uint8_t address)
    {
        switch (_vendor) {
            case 1:
                return new I2CSensor_Vendor1(bus, address);
            case 2:
                return new I2CSensor_Vendor2(bus, address);
            default:
                assert(false);
                return nullptr;
        }
    }

private:
    unsigned int _vendor;
};

