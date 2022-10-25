#include "social-insurance-oegk.h"

#include <iostream>
#include <string>
#include <memory>


int main()
{
    std::string id("1037190666");

    SocialInsurance::instance().charge(id, 1254.60);
    SocialInsurance::instance().charge(id, 231.34);
    
    std::cout << id << " owes \"" << SocialInsurance::instance().name() << "\" " << SocialInsurance::instance().debt(id) << " Euros" << std::endl;

    return 0;
}
