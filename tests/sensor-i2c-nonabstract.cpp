#include <sensor-i2c-factory-nonabstract.h>
#include <string>
#include <iostream>

int main(int argc, char** argv)
{
    // program startup phase: parse huge XML file

    std::string vendor_str = argv[1];
    int vendor;

    if (vendor_str == "1")
        vendor = 1;
    else if (vendor_str == "2")
        vendor = 2;
    else {
        std::cerr << "nix gut vendor: " << vendor_str << std::endl;
        return 1;
    }

    // program startup phase: instantiate singletons
    I2CSensorFactory_NonAbstract factory(vendor);


    // program live phase
    Sensor* sensor = factory.create(1, 0x37);
    std::cout << sensor->get_temperature() << std::endl;

    return 0;
}
