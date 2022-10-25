#include "social-insurance.h"

#include "social-insurance-oegk.h"

#include <cstdlib>
#include <stdexcept>

std::unique_ptr<SocialInsurance> SocialInsurance::_instance;

SocialInsurance& SocialInsurance::instance()
{
    char* socinsur = std::getenv("SOCINSUR");
    if (socinsur == nullptr)
        throw std::runtime_error("SOCINSUR not set");

    std::string my_socinsur(socinsur);

    if (my_socinsur == "OEGK")
        _instance.reset(new SocialInsurance_OEGK);
    // else if (my_socinsur == "SVS")
    //     _instance.reset(new SocialInsurance_SVS);
    else
        throw std::runtime_error("bad SOCINSUR value");

    return *_instance;
}
