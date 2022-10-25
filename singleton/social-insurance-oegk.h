#pragma once

#include "social-insurance.h"

#include <string>
#include <map>
#include <memory>


class SocialInsurance_OEGK : public SocialInsurance
{
public:
    void charge(const std::string& id, double euros) override
    {
        _db[id] += euros;
    }

    double debt(const std::string& svnr) const override
    {
        auto found = _db.find(svnr);
        if (found == _db.end())
            return 0;
        return found->second;
    }
    
private:
    std::map<std::string /*svnr*/, double /*debt*/> _db;

    friend class SocialInsurance;
    SocialInsurance_OEGK() : SocialInsurance("OEGK") {}
};
