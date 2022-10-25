#pragma once

#include <vector>
#include <initializer_list>


class AveragingSensor : public Sensor
{
public:
    AveragingSensor() = default;
    AveragingSensor(std::initializer_list<Sensor*> init)
    : _sensors(init) {}

    void add(Sensor* s)
    {
        _sensors.push_back(s);
    }
    double get_temperature() override {
        double sum = 0;
        for (auto elem: _sensors)
            sum += elem->get_temperature();
        return sum/_sensors.size();
    }

private:
    std::vector<Sensor*> _sensors;
};
