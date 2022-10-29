#include <sensor-const.h>
#include <sensor-random.h>

#include <chrono>
#include <thread>
#include <vector>
#include <map>
#include <iostream>
#include <cassert>


using namespace std::chrono_literals;

class Logger
{
public:
    virtual ~Logger() {}
    virtual void log(const std::string& msg) = 0;
};

class Variables
{
public:
    virtual ~Variables() {}
    virtual void set(const std::string& name, double temperature) = 0;
};


class TestLogger : public Logger
{
public:
    void log(const std::string& msg) override
    {
        std::cerr << "TEST-LOGGER: " << msg << std::endl;
    }
};

class DBusLogger : public Logger
{
public:
    void log(const std::string& msg) override
    {
        assert(false);  // hier noch bissl brav sein ...
    }
};

class TestVariables : public Variables
{
public:
    void set(const std::string& name, double value) override
    {
        _store[name] = value;
    }
    double get(const std::string& name) const
    {
        return _store.at(name);
    }
    
private:
    std::map<std::string/*name*/, double/*temperature*/> _store;
};

class DBusVariables : public Variables
{
public:
    void set(const std::string& name, double value) override
    {
        assert(false);
    }
};

class LocalSensorReader
{
public:
    using NamedSensor = std::pair<std::string, Sensor*>;
    using Sensors = std::vector<NamedSensor>;

    LocalSensorReader(
        const Sensors& sensors,
        Logger& logger,
        Variables& variables)
    : _sensors(sensors),
      _logger(logger),
      _variables(variables) {}

    void doit()
    {
        for (auto [name, sensor]: _sensors){
            _logger.log(name);
            double temperature = sensor->get_temperature();
            _variables.set(name, temperature);
        }
    }
    
private:
    std::vector<NamedSensor> _sensors;    
    Logger& _logger;
    Variables& _variables;
};

int main()
{
    // TestLogger logger;
    // TestVariables variables;
    DBusLogger logger;
    DBusVariables variables;
    LocalSensorReader::Sensors sensors{
            {"sensorA", new ConstantSensor(3)},
            {"sensorB", new ConstantSensor(4)},
            {"sensorC", new RandomSensor(100, 200000)},
    };
    
    LocalSensorReader rdr(
        sensors,
        logger,
        variables
    );

    rdr.doit();
    // for (auto [name, _]: sensors)
    //     std::cout << name << ": " << variables.get(name) << std::endl;
    std::this_thread::sleep_for(0.5s);
    rdr.doit();
    // for (auto [name, _]: sensors)
    //     std::cout << name << ": " << variables.get(name) << std::endl;
    std::this_thread::sleep_for(0.5s);
    rdr.doit();
    // for (auto [name, _]: sensors)
    //     std::cout << name << ": " << variables.get(name) << std::endl;
    std::this_thread::sleep_for(0.5s);
    rdr.doit();
    // for (auto [name, _]: sensors)
    //     std::cout << name << ": " << variables.get(name) << std::endl;
    std::this_thread::sleep_for(0.5s);
    rdr.doit();
    // for (auto [name, _]: sensors)
    //     std::cout << name << ": " << variables.get(name) << std::endl;
    std::this_thread::sleep_for(0.5s);

    return 0;
}
