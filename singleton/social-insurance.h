#pragma once

#include <string>
#include <map>
#include <memory>


class SocialInsurance
{
public:
    SocialInsurance(const SocialInsurance&) = delete;
    SocialInsurance& operator=(const SocialInsurance&) = delete;

    static SocialInsurance& instance();

    const std::string& name() const { return _name; }

    virtual void charge(const std::string& id, double euros) = 0;
    virtual double debt(const std::string& svnr) const = 0;
    
private:
    std::string _name;

    static std::unique_ptr<SocialInsurance> _instance;

protected:
    SocialInsurance(const std::string& name) : _name(name) {}
};
