#include <memory>
#include <iostream>
#include <map>

#include <sensor-random.h>
#include <sensor-const.h>

std::shared_ptr<Sensor> create_random(double lo, double hi)
{
    auto sensor = std::make_shared<RandomSensor>(lo, hi);
    return sensor;
}

int main()
{
    std::map<std::string, std::shared_ptr<Sensor>> sensors;

    auto rs1 = create_random(34.1, 39.4);
    auto rs2 = create_random(38.5, 41.3);
    auto cs1 = std::make_shared<ConstantSensor>(36.7);

    sensors["my-first-random-sensor"] = std::move(rs1);
    sensors["my-second-random-sensor"] = rs2;
    sensors["my-boring-constant-sensor"] = cs1;

    std::cout << sensors["my-second-random-sensor"]->get_temperature() << std::endl;

    std::cout << rs2->get_temperature() << std::endl; // works
    std::cout << rs1->get_temperature() << std::endl; // LETHAL! (has been moved)

    return 0;
}
