#include <gtest/gtest.h>

#include <sensor-i2c-factory-nonabstract.h>


TEST(factory_suite, vendor1)
{
    int vendor = 1; // ... typically read from config file, environment variable, or commandline parameter
    I2CSensorFactory_NonAbstract factory(vendor);
    I2CSensor* sensor = factory.create(/*bus*/1, /*address*/0x37);

    ASSERT_TRUE(dynamic_cast<I2CSensor_Vendor1*>(sensor));

    // use? ...

    delete sensor;
}

TEST(factory_suite, vendor2)
{
    int vendor = 2; // ... typically read from config file, environment variable, or commandline parameter
    I2CSensorFactory_NonAbstract factory(vendor);
    I2CSensor* sensor = factory.create(/*bus*/1, /*address*/0x37);

    ASSERT_TRUE(dynamic_cast<I2CSensor_Vendor2*>(sensor));

    // use? ...

    delete sensor;
}
