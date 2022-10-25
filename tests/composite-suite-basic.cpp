#include <gtest/gtest.h>

#include <sensor-const.h>
#include <sensor-avg.h>


TEST(composite_suite, basic)
{
    ConstantSensor cs1(3);
    ConstantSensor cs2(4);

    Sensor* s1 = &cs1;     // <--- is-a Sensor
    Sensor* s2 = &cs2;     // <--- is-a Sensor

    AveragingSensor avg;   // <-- uses-many Sensor
    avg.add(s1);
    avg.add(s2);

    ASSERT_FLOAT_EQ(avg.get_temperature(), 3.5);
}

TEST(composite_suite, nicht_schummeln)
{
    ConstantSensor cs(2.5);

    AveragingSensor avg;
    avg.add(&cs);

    ASSERT_FLOAT_EQ(avg.get_temperature(), 2.5);
}

TEST(composite_suite, avg_is_a_sensor)
{
    AveragingSensor avg;
    Sensor* s = &avg;
    (void)s;
}

TEST(composite_suite, initializer_list)
{
    ConstantSensor cs1(3);
    ConstantSensor cs2(4);
    ConstantSensor cs3(5);

    AveragingSensor avg{&cs1, &cs2, &cs3};
    Sensor* s = &avg;

    ASSERT_FLOAT_EQ(s->get_temperature(), 4);
}



