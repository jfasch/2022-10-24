#include "social-insurance.h"


std::unique_ptr<SocialInsurance> SocialInsurance::_instance;

SocialInsurance& SocialInsurance::instance()
{
    if (_instance == nullptr)
        _instance = std::unique_ptr<SocialInsurance>(new SocialInsurance("Die einzige Sozialversicherung"));
    return *_instance;
}
