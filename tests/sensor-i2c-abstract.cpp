#include <sensor-i2c-factory-vendor1.h>
#include <sensor-i2c-factory-vendor2.h>
#include <string>
#include <iostream>

int main(int argc, char** argv)
{
    // program startup phase: parse huge XML file

    std::string vendor_str = argv[1];
    I2CSensorFactory* factory;

    if (vendor_str == "1")
        factory = new I2CSensorFactory_Vendor1;
    else if (vendor_str == "2")
        factory = new I2CSensorFactory_Vendor2;
    else {
        std::cerr << "nix gut vendor: " << vendor_str << std::endl;
        return 1;
    }


    // program live phase
    Sensor* sensor = factory->create(1, 0x37);
    std::cout << sensor->get_temperature() << std::endl;

    return 0;
}
