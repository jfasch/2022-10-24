#pragma once

#include <vector>


class AveragingSensor
{
public:
    void add(Sensor* s)
    {
        _sensors.push_back(s);
    }
    double get_temperature() {
        double sum = 0;
        for (std::vector<Sensor*>::const_iterator it=_sensors.begin(); it!=_sensors.end(); it++)
            sum += (*it)->get_temperature();
        return sum/_sensors.size();
    }

private:
    std::vector<Sensor*> _sensors;
};
