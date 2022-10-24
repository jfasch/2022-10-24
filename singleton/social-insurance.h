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

    void charge(const std::string& id, double euros)
    {
        _db[id] += euros;
    }

    double debt(const std::string& svnr) const
    {
        auto found = _db.find(svnr);
        if (found == _db.end())
            return 0;
        return found->second;
    }
    
private:
    std::string _name;
    std::map<std::string /*svnr*/, double /*debt*/> _db;

    static std::unique_ptr<SocialInsurance> _instance;

    SocialInsurance(const std::string& name) : _name(name) {}
};
