#include <gtest/gtest.h>

#include <sensor-A.h>          // <--- company A's sensor interface
#include <sensor-A-adapt-B.h>  // <--- to be implemented
#include <sensor.h>            // <--- company B's sensor interface
#include <sensor-const.h>      // <--- company B's most sophisticated sensor

TEST(adapter_suite, basic)
{
    // buy most sophisticated sensor from B, and see if it works
    ConstantSensor sensor_from_b(36.5);
    ASSERT_FLOAT_EQ(sensor_from_b.get_temperature(), 36.5);

    // adapt it into A's framework, converting its Celsius measurement
    // into Fahrenheit
    SensorB_Adapter b_adapter(&sensor_from_b);
    ASSERT_FLOAT_EQ(b_adapter.get_temperature_fahrenheit(), 36.5 * 5/9 + 32);

    SensorA* sensor_a = &b_adapter;
    ASSERT_FLOAT_EQ(sensor_a->get_temperature_fahrenheit(), 36.5 * 5/9 + 32);
}

// TEST(adapter_suite, next)
// {
//     ConstantSensor cs(42);
//     Sensor* s = &cs;

//     SensorB_Adapter b_adapter(s);
// }
